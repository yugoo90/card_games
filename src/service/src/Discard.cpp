#include <vector>
#include <algorithm>
#include <iostream>
#include "Card.h"
#include "StandardCard.h"
#include "Discard.h"
#include "CardSet.h"

Discard::Discard() {
  type = CardSet::DISCARD;
}
Discard::~Discard() {}

void Discard::display() const {
  if (((*this).cards.size() > 0) && cards[0]->getType() == Card::STANDARD) {
std::cout << std::endl << "+---------+" << std::endl;
std::cout << "|░░░░░░░░░|" << std::endl;
std::cout << "|░+---------+" << std::endl;
std::cout << "|░|░░░░░░░░░|" << std::endl;
std::cout << "|░|░+---------+" << std::endl;
std::cout << "|░|░|" << dynamic_cast<StandardCard*>(
  cards[cards.size()-1])->cardValue()
<< (dynamic_cast<StandardCard*>(
  cards[cards.size()-1])->getValue() == 10? "       |" :
"        |") << std::endl;
std::cout << "+-|░|         |" << std::endl;
std::cout << "  |░|    " << dynamic_cast<StandardCard*>(
  cards[cards.size()-1])->suitValue() << "    |" << std::endl;
std::cout << "  +-|         |" << std::endl;
std::cout << "    " << (dynamic_cast<StandardCard*>(
  cards[cards.size()-1])->getValue() == 10? "|       " :
"|        ") << dynamic_cast<StandardCard*>(cards[cards.size()-1])->cardValue()
<< "|" << std::endl;
std::cout << "    +---------+" << std::endl << std::endl;
} else {
  (*(((*this).cards.end())-1))->displayCard();
  std::cout << std::endl;
}
}
