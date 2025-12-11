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
#include "../DTO/GameTypeDTO.hpp"
#include "../DTO/AILevelDTO.hpp"
#include "../mappers/GameTypeMapper.hpp"
#include "../mappers/AILevelMapper.hpp"
#include "../../include/model/Player.h"
#include "../../include/model/human.h"
#include "../../include/model/AI.h"
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
        
        auto players = oatpp::Vector<oatpp::Object<PlayerDTO>>::createShared();
        auto responseDTO = ResponseDTO::createShared();

        if(gamePlayers.empty()){
            responseDTO->message = "No players found";
            return createDtoResponse(Status::CODE_404, responseDTO);
        }

        for(auto& p : gamePlayers){
            if(!p){
                responseDTO->message = "No existing players found";
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

    ENDPOINT("POST", "game/human", createHuman, QUERY(String, name)) {
        auto responseDTO = ResponseDTO::createShared();
        
        if(name->empty()){ 
            responseDTO->message = "Name cannot be empty";
            return createDtoResponse(Status::CODE_400, responseDTO);
        }
        else{
            gamePlayers.push_back(std::make_shared<Human>(name, 0));
            responseDTO->message = "Player " + name + " created successfully";
            return createDtoResponse(Status::CODE_200, responseDTO);
        }
    }

    ENDPOINT("POST", "game/AI", createAI, 
        QUERY(oatpp::Enum<AILevel>::AsString, level),
        QUERY(oatpp::Enum<GameType>::AsString, gameChoice)) {

        auto responseDTO = ResponseDTO::createShared();
        
        Game::GameType gType = GameTypeMapper::toCppEnum(gameChoice);
        AI::Level aiLevel = AILevelMapper::toCppEnum(level);
        
        /*
        if(numOpps > 1) {
            for(int i = 1; i <= numOpps; i++){
                gamePlayers.push_back(mainMenu.generateAI(gType, aiLevel, i));
            }
        }else {
            gamePlayers.push_back(mainMenu.generateAI(gType, aiLevel, 1));
        }
        */
       if(gType == Game::GOFISH) {
            gamePlayers.push_back(std::make_shared<GoFishAI>(aiLevel, gamePlayers.size() + 1));
            responseDTO->message = "AI player created successfully";
            return createDtoResponse(Status::CODE_200, responseDTO);
       }
       else if(gType == Game::CRAZYEIGHTS) {
            gamePlayers.push_back(std::make_shared<CrazyEightsAI>(aiLevel, gamePlayers.size() + 1));
            responseDTO->message = "AI player created successfully";
            return createDtoResponse(Status::CODE_200, responseDTO);
       }
       else {
            responseDTO->message = "Invalid game type for AI creation";
            return createDtoResponse(Status::CODE_400, responseDTO);
       }
    }

    ENDPOINT("POST", "game/startGame", createGame, 
        QUERY(oatpp::Enum<GameType>::AsString, gameChoice)) {
        
        auto responseDTO = ResponseDTO::createShared();
        auto gameDTO = GameDTO::createShared();
        Game::GameType gtype = GameTypeMapper::toCppEnum(gameChoice);

        if(!gtype){
            responseDTO->message = "Game type must be specified to start the game";
            return createDtoResponse(Status::CODE_400, responseDTO);
        }
        else if(gtype == Game::GOFISH) {
            gameInstance = std::make_shared<GoFish>(1, gamePlayers);
            gameDTO->gameType = GameTypeMapper::toOatppEnum(gtype);
            gameDTO->numPlayers = gameInstance->getPlayers().size();
            return createDtoResponse(Status::CODE_200, gameDTO);
        }
        else if(gtype == Game::CRAZYEIGHTS) {
            gameInstance = std::make_shared<CrazyEights>(1, gamePlayers);
            gameDTO->gameType = GameTypeMapper::toOatppEnum(gtype);
            gameDTO->numPlayers = gameInstance->getPlayers().size();
            return createDtoResponse(Status::CODE_200, gameDTO);
        }
        else {
            responseDTO->message = "Invalid game type";
            return createDtoResponse(Status::CODE_400, responseDTO);
        }
    }

    ENDPOINT("POST", "game/numOpps", getNumOpps, 
        QUERY(Int32, numOpps)) {
            
        auto responseDTO = ResponseDTO::createShared();
        if(numOpps <= 0 || numOpps > MAX_OPPONENTS){
            responseDTO->message = "Number of opponents must be between 1 and " + std::to_string(MAX_OPPONENTS);
            return createDtoResponse(Status::CODE_400, responseDTO);
        }
        else{
            this->numOpps = numOpps;
            responseDTO->message = "Number of opponents set to " + std::to_string(numOpps);
            return createDtoResponse(Status::CODE_200, responseDTO);
        }

    }


 private:
    int MAX_OPPONENTS = 3;
    int numOpps = 0;
    oatpp::Enum<GameType>::AsString choice;
    UI mainMenu;
    std::shared_ptr<Game> gameInstance;
    std::vector<std::shared_ptr<Player>> gamePlayers;
};

#include OATPP_CODEGEN_END(ApiController)

#endif