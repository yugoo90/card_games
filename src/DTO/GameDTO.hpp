#ifndef GAMEDTO_HPP
#define GAMEDTO_HPP

#include "oatpp/Types.hpp"
#include "oatpp/macro/codegen.hpp"

#include <string>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Game Data Transfer Object
 */
class GameDTO : public oatpp::DTO {
  DTO_INIT(GameDTO, DTO)

  DTO_FIELD(String, gameType);          // Type of game (e.g., "CrazyEights", "GoFish", etc.)
  DTO_FIELD(Int32, numPlayers);     // Current number of players in the game
  DTO_FIELD(String, status);            // Status of the game (e.g., "waiting", "in_progress", "finished")
};


#include OATPP_CODEGEN_END(DTO)
#endif /* GAMEDTO_HPP */