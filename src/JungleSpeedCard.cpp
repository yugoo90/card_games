#include <iostream>
#include <string>
#include "Card.h"
#include "JungleSpeedCard.h"


  JungleSpeedCard::JungleSpeedCard(std::string cardName,
    JungleSpeedCard::Colour cardColour) : Card{} {
    type = Card::JUNGLESPEED;
    setName(cardName);
    setColour(cardColour);
  }

  JungleSpeedCard::~JungleSpeedCard() {}

  void JungleSpeedCard::setColour(JungleSpeedCard::Colour c) {colour = c;}

  void JungleSpeedCard::setName(std::string s) {name = s;}

  JungleSpeedCard::Colour JungleSpeedCard::getColour() const {return colour;}

  std::string JungleSpeedCard::getName() const {return name;}

  bool JungleSpeedCard::operator==(const Card& c) {
    const JungleSpeedCard& temp = dynamic_cast<const JungleSpeedCard&>(c);
    if ((*this).sameName(temp) && (*this).sameColour(temp))
    return true;
    return false;
  }

  bool JungleSpeedCard::sameName(const JungleSpeedCard& c) {
    if (((*this).getName()).compare(c.getName()) == 0) {
      return true;
    } else {
      return false;
    }
  }

  bool JungleSpeedCard::sameColour(const JungleSpeedCard& c) {
    if ((*this).getColour() == c.getColour()) {
      return true;
    } else {
      return false;
    }
  }

  std::string JungleSpeedCard::ColourToString(JungleSpeedCard::Colour c) {
    switch (c) {
      case BLUE: {
        return "Blue";
      }
      case RED: {
        return "Red";
      }
      case GREEN: {
        return "Green";
      }
      case YELLOW: {
        return "Yellow";
      }
      default: {
        return "Special";
      }
  }
}

  std::string JungleSpeedCard::stringOfWholeCard() {
    return (*this).ColourToString((*this).getColour()) +  ' ' +
    (*this).getName();}
