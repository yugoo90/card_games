#include <string>
#include "Card.h"
#include "JungleSpeedCard.h"
#include "StandardCard.h"
#include "CardGenerator.h"

CardGenerator::CardGenerator() {}
CardGenerator::~CardGenerator() {}
StandardCard* CardGenerator::makeStandardCard(
  const int typeOfSuit, const int valueOfCard) {
      StandardCard::Suit suit;
      switch (typeOfSuit) {
        case 1: suit = StandardCard::DIAMONDS; break;
        case 2: suit = StandardCard::HEARTS; break;
        case 3: suit = StandardCard::CLUBS; break;
        default: suit = StandardCard::SPADES; break;
      }
      int num = valueOfCard;
      return new StandardCard(suit, num);}

JungleSpeedCard* CardGenerator::makeJungleSpeedCard(
  const std::string s, const int i) {
  JungleSpeedCard::Colour colour;
  switch (i) {
    case 1: colour = JungleSpeedCard::RED; break;
    case 2: colour = JungleSpeedCard::BLUE; break;
    case 3: colour = JungleSpeedCard::YELLOW; break;
    case 4: colour = JungleSpeedCard::GREEN; break;
    default: colour = JungleSpeedCard::SPECIAL; break;
  }
  return new JungleSpeedCard(s, colour);
}
