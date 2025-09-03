#ifndef GAMEDTO_HPP
#define GAMEDTO_HPP

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include <string>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Game Data Transfer Object
 */
class GameDTO : public oatpp::DTO {
  DTO_INIT(GameDTO, DTO)

  DTO_FIELD(String, gameType);          // Type of game (e.g., "CrazyEights", "GoFish", etc.)
  DTO_FIELD(Int32, maxPlayers);         // Maximum number of players allowed in the game
  DTO_FIELD(Int32, currentPlayers);     // Current number of players in the game
  DTO_FIELD(String, status);            // Status of the game (e.g., "waiting", "in_progress", "finished")
  DTO_FIELD(String, topCard);           // Top card in play (e.g., "2 of Hearts")
};


#include OATPP_CODEGEN_END(DTO)
#endif /* GAMEDTO_HPP */