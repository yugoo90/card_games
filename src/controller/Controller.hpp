#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "oatpp/macro/component.hpp"
#include "oatpp/macro/codegen.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/json/ObjectMapper.hpp"

#include "../DTO/GameDTO.hpp"
#include "../DTO/CardDTO.hpp"
#include "../DTO/PlayerDTO.hpp"
#include "../DTO/ResponseDTO.hpp"
#include "../../include/model/Player.h"
#include "../../include/model/Game.h"
#include "../../include/model/UI.h"

#include <memory>
#include <iostream>
#include <vector>


#include OATPP_CODEGEN_BEGIN(ApiController)

class Controller : public oatpp::web::server::api::ApiController {
 public:
    Controller(OATPP_COMPONENT(std::shared_ptr<oatpp::json::ObjectMapper>, ObjectMapper)) 
        : oatpp::web::server::api::ApiController(ObjectMapper) {}

    static std::shared_ptr<Controller> createShared(OATPP_COMPONENT(std::shared_ptr<oatpp::json::ObjectMapper>, ObjectMapper)) {
        return std::make_shared<Controller>(ObjectMapper);
    }
    
    ENDPOINT("GET", "/" , root) {
        return createResponse(Status::CODE_200, "Welcome to the Card Games API!");
    }

    ENDPOINT("GET", "game/players", getPlayers) {
        
        std::vector<std::shared_ptr<Player>> gamePlayers = gameModel()->getPlayers();
        auto players = oatpp::Vector<oatpp::Object<PlayerDTO>>::createShared();
        auto responseDTO = ResponseDTO::createShared();

        if(gamePlayers.empty()){
            responseDTO->message = "No players found";
            return createDtoResponse(Status::CODE_404, responseDTO);
        }

        for(auto& p : gamePlayers){
            if(!p){
                responseDTO->message = "No players found";
                return createDtoResponse(Status::CODE_404, responseDTO);
            }
            else{
                auto playerDTO = PlayerDTO::createShared();
                playerDTO->name = p->getName().c_str();
                playerDTO->type = p->getType() == Player::HUMAN ? "human" : "AI";
                playerDTO->score = p->getTotalPoints();
                playerDTO->id = p->getID();
                players->push_back(playerDTO);
            }
        }
        return createDtoResponse(Status::CODE_200, players);  
    }

    ENDPOINT("GET", "game/info", getGameInfo) {
        auto gameDTO = GameDTO::createShared();
        auto responseDTO = ResponseDTO::createShared();
        if(!gameModel()){
            responseDTO->message = "No game found";
            return createDtoResponse(Status::CODE_404, responseDTO);
        }
        else{
            gameDTO->gameType = gameModel()->getType() == Game::GOFISH ? "Go Fish" : 
                gameModel()->getType() == Game::CRAZYEIGHTS ? "Crazy Eights" : "Jungle Speed";
            gameDTO->numPlayers =  gameModel()->getNumPlayers();
            gameDTO->status = gameModel()->gameOver ? "finished" : "in_progress";
            return createDtoResponse(Status::CODE_200, gameDTO);
        }
    }

    ENDPOINT("POST", "game/start", startGame) {
        auto responseDTO = ResponseDTO::createShared();
        if(!gameModel()){
            responseDTO->message = "Game has not started";
            return createDtoResponse(Status::CODE_500, responseDTO);
        }
        else{
            gameModel()->preGame();
            responseDTO->message = "Game has started!";
            return createDtoResponse(Status::CODE_200, responseDTO);
        }
    }

 private:
    UI mainMenu;
    std::shared_ptr<Game> gameInstance;

    std::shared_ptr<Game> gameModel() {
        if(!gameInstance){
            gameInstance = mainMenu.createGame(std::cin);
            gameInstance->play(std::cin);
        }
        return gameInstance;
    }
};

#include OATPP_CODEGEN_END(ApiController)

#endif