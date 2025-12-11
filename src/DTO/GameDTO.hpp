#ifndef GAMEDTO_HPP
#define GAMEDTO_HPP

#include "GameTypeDTO.hpp"
#include "AILevelDTO.hpp"

#include "oatpp/Types.hpp"
#include "oatpp/macro/codegen.hpp"

#include <string>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Game Data Transfer Object
 */
class GameDTO : public oatpp::DTO {
  DTO_INIT(GameDTO, DTO)

  DTO_FIELD(Int32, numPlayers);     // Current number of players in the game
  DTO_FIELD(String, status);       // Current status of the game
  DTO_FIELD(oatpp::Enum<GameType>::AsString, gameType);  // Enum field for game type
  DTO_FIELD(oatpp::Enum<AILevel>::AsString, aiLevel);    // Enum field for AI level
};


#include OATPP_CODEGEN_END(DTO)
#endif /* GAMEDTO_HPP */