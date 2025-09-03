#ifndef PLAYERDTO_hpp
#define PLAYERDTO_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include <string>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Player Data Transfer Object
 */
class PlayerDTO : public oatpp::DTO {
  DTO_INIT(PlayerDTO, DTO)

  DTO_FIELD(String, name);          // Player's name
  DTO_FIELD(Int32, score);          // Player's score
  DTO_FIELD(Int32, id);             // Player's ID
  DTO_FIELD(String, type);          // Player's type (e.g., "human", "AI")
  DTO_FIELD(Int32, statusCode);     // Status code for the player (e.g., 0 for active, 1 for inactive)
};

#include OATPP_CODEGEN_END(DTO)
#endif /* PlayerDTO_hpp */