#ifndef AILEVELMAPPER_HPP
#define AILEVELMAPPER_HPP

#include "../../include/model/AI.h"
#include "../DTO/AILevelDTO.hpp"

class AILevelMapper {
public:
    static oatpp::Enum<AILevel>::AsString toOatppEnum(AI::Level aiLevel){
        
        switch(aiLevel){
            case AI::EASY:
                return AILevel::EASY;
            case AI::NORMAL:
                return AILevel::NORMAL;
            case AI::HARD:
                return AILevel::HARD;
            default: 
                return nullptr;
        }
    }

    static AI::Level toCppEnum(const oatpp::Enum<AILevel>::AsString& oatppType) {

        if(oatppType == AILevel::EASY){
            return AI::EASY;
        }
        
        if(oatppType == AILevel::NORMAL){
            return AI::NORMAL;
        }

        if(oatppType == AILevel::HARD){
            return AI::HARD;
        }
    }


};
#endif // GAMETYPEMAPPER_HPP