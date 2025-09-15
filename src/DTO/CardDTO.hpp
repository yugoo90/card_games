#ifndef CARDDTO_HPP
#define CARDDTO_HPP

#include "oatpp/Types.hpp"
#include "oatpp/macro/codegen.hpp"

#include <string>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Card Data Transfer Object
 */
class CardDTO : public oatpp::DTO {
  
  DTO_INIT(CardDTO, DTO)

  DTO_FIELD(String, suit);      // Card's suit (e.g., "Hearts", "Diamonds")
  DTO_FIELD(String, rank);      // Card's rank (e.g., "2", "King", "Ace")
  DTO_FIELD(Int32, value);      // Card's value (e.g., 2 for "2", 10 for "10", 11 for "Jack", etc.)
  DTO_FIELD(Int32, id);         // Unique identifier for the card
  DTO_FIELD(String, type);       // Type of card (e.g., "Standard", "JungleSpeed")
  DTO_FIELD(Int32, statusCode); // Status code for the card (e.g., 0 for normal, 1 for special)

};

#include OATPP_CODEGEN_END(DTO)
#endif /* CARDDTO_HPP */