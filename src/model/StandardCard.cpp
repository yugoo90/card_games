#include <vector>
#include <string>
#include <iostream>
#include "Card.h"
#include "StandardCard.h"


  StandardCard::StandardCard(StandardCard::Suit nameOfSuit,
    int cardNumber) : Card{} {
    type = Card::STANDARD;
    setSuit(nameOfSuit);
    setValue(cardNumber);
  }

  StandardCard::~StandardCard() {}

  void StandardCard::setValue(int v) {
    number = v;
  }

  void StandardCard::setSuit(StandardCard::Suit s) {
    suitName = s;
  }

  int StandardCard::getValue() const {
    return number;
  }

  StandardCard::Suit StandardCard::getSuit() const {
    return suitName;
  }

  bool StandardCard::sameRank(const StandardCard& c) {
    if ((((*this).getValue()) == (c.getValue()))) {
      return true;
    } else {
      return false;
    }
  }

  bool StandardCard::sameSuit(const StandardCard& c) {
    if ((((*this).getSuit()) == (c.getSuit()))) {
      return true;
    } else {
      return false;
    }
  }

  std::string StandardCard::stringOfWholeCard() {
    std::string display = suitToString(suitName);
    std::string of = "of";
    std::string toDisplay = rankToName((*this).getValue()) + ' ' + of
    + ' ' + display;
    return toDisplay;
  }

  bool StandardCard::operator==(const Card& c) {
    const StandardCard& temp = dynamic_cast<const StandardCard&>(c);
    if ((*this).sameSuit(temp) && (*this).sameRank(temp))
    return true;
    return false;
  }

  std::string StandardCard::suitToString(StandardCard::Suit s) {
    switch (s) {
      case DIAMONDS: {
        return "Diamonds";
      }
      case HEARTS: {
        return "Hearts";
      }
      case CLUBS: {
        return "Clubs";
      }
      default: {
        return "Spades";
      }
    }
  }

  std::string StandardCard::rankToName(const int cardRank) {
    if ((cardRank > 1) && (cardRank < 11)) {
      return std::to_string(cardRank);
    } else if (cardRank == 1) {
      return "Ace";
    } else if (cardRank == 11) {
      return "Jack";
    } else if (cardRank == 12) {
      return "Queen";
    } else {
      return "King";
    }
  }

  std::string StandardCard::cardValue() {
    switch (number) {
      case 1: return "A"; break;
      case 2: return "2"; break;
      case 3: return "3"; break;
      case 4: return "4"; break;
      case 5: return "5"; break;
      case 6: return "6"; break;
      case 7: return "7"; break;
      case 8: return "8"; break;
      case 9: return "9"; break;
      case 10: return "10"; break;
      case 11: return "J"; break;
      case 12: return "Q"; break;
      default: return "K"; break;
    }
  }

const std::string StandardCard::suitValue() {
  switch (suitName) {
    case SPADES: return "\u2660"; break;
    case CLUBS: return "\u2663"; break;
    case DIAMONDS: return "\u2666"; break;
    default: return "\u2665"; break;
  }
}
