#include <iostream>
#include <string>
#include "Card.h"



Card::Card() {}
Card::~Card() {}
Card::CardType Card::getType() const {return type;}
void Card::displayCard() {
  std::cout << (*this).stringOfWholeCard();
}
