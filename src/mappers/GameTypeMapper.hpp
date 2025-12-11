#ifndef GAMETYPEMAPPER_HPP
#define GAMETYPEMAPPER_HPP

#include "../../include/model/Game.h"
#include "../DTO/GameTypeDTO.hpp"

class GameTypeMapper {
public:
    static oatpp::Enum<GameType>::AsString toOatppEnum(Game::GameType gType){
        
        switch(gType){
            case Game::GOFISH:
                return GameType::GOFISH;
            case Game::CRAZYEIGHTS:
                return GameType::CRAZYEIGHTS;
            default: 
                return nullptr;
        }
    }

    static Game::GameType toCppEnum(const oatpp::Enum<GameType>::AsString& oatppType) {

        if(oatppType == GameType::GOFISH){
            return Game::GOFISH;
        }
        
        if(oatppType == GameType::CRAZYEIGHTS){
            return Game::CRAZYEIGHTS;
        }
    }
};
#endif // GAMETYPEMAPPER_HPP