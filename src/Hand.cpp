#include <vector>
#include <algorithm>
#include "Card.h"
#include "CardSet.h"
#include "StandardCard.h"
#include "Hand.h"

Hand::Hand() {type = CardSet::HAND;}

Hand::~Hand() {}

void Hand::display() const {
  if ((*this).cards.size() == 0) {
    std::cout << "Your hand is empty." << std::endl;
  } else if (cards[0]->getType() == Card::JUNGLESPEED) {
    std::cout << "Your hand is: " << std::endl;
    for (int i = 0; i < (*this).cards.size(); i++) {
      (*this).cards.at(i)->displayCard();
      std::cout << std::endl;
      }
    std::cout << std::endl;
    } else {
  int cardsInRow = 4;
  int remainder = cards.size() % cardsInRow;
  int numRows = cards.size() / cardsInRow;

  std::cout << "Your hand is: " << std::endl << std::endl;
  int cardPosn = 0;

  for (int j = 0; j < numRows; j++) {
  for (int i = 0; i < cardsInRow; i++) {
    std::cout << "+------+  ";
  }
  std::cout << std::endl;
  cardPosn = cardsInRow*j;
  for (int i = 0; i < cardsInRow; i++) {
    std::cout << "|" << dynamic_cast<StandardCard*>(
      cards[cardPosn])->cardValue()
    << (dynamic_cast<StandardCard*>(
      cards[cardPosn])->getValue() == 10? "       |  " :
    "        |  ");
    cardPosn++;
  }
  cardPosn = cardsInRow*j;
  std::cout << std::endl;
  for (int i = 0; i < cardsInRow; i++) {
    std::cout << "|         |  ";
  }
  std::cout << std::endl;
  for (int i = 0; i < cardsInRow; i++) {
    std::cout << "|    " << dynamic_cast<StandardCard*>(
      cards[cardPosn])->suitValue() << "    |  ";
    cardPosn++;
  }
  cardPosn = cardsInRow*j;
  std::cout << std::endl;
  for (int i = 0; i < cardsInRow; i++) {
    std::cout << "|         |  ";
  }
  std::cout << std::endl;
  for (int i = 0; i < cardsInRow; i++) {
    std::cout << (dynamic_cast<StandardCard*>(
      cards[cardPosn])->getValue() == 10? "|       " :
    "|        ") << dynamic_cast<StandardCard*>(cards[cardPosn])->cardValue()
    << "|  ";
    cardPosn++;
  }
  cardPosn = cardsInRow*j;
  std::cout << std::endl;
  for (int i = 0; i < cardsInRow; i++) {
    std::cout << "+---------+  ";
  }
  std::cout << std::endl << std::endl;
}

if (remainder != 0)  {
cardPosn = cards.size() - remainder;
for (int i = 0; i < remainder; i++) {
  std::cout << "+---------+  ";
}
std::cout << std::endl;
for (int i = 0; i < remainder; i++) {
  std::cout << "|" << dynamic_cast<StandardCard*>(cards[cardPosn])->cardValue()
  << (dynamic_cast<StandardCard*>(
    cards[cardPosn])->getValue() == 10? "       |  " :
  "        |  ");
  cardPosn++;
}
cardPosn = cards.size() - remainder;
std::cout << std::endl;
for (int i = 0; i < remainder; i++) {
  std::cout << "|         |  ";
}
std::cout << std::endl;
for (int i = 0; i < remainder; i++) {
  std::cout << "|    "
  << dynamic_cast<StandardCard*>(cards[cardPosn])->suitValue() << "    |  ";
  cardPosn++;
}
cardPosn = cards.size() - remainder;
std::cout << std::endl;
for (int i = 0; i < remainder; i++) {
  std::cout << "|         |  ";
}
std::cout << std::endl;
for (int i = 0; i < remainder; i++) {
  std::cout << (dynamic_cast<StandardCard*>(
    cards[cardPosn])->getValue() == 10? "|       " :
  "|        ") << dynamic_cast<StandardCard*>(cards[cardPosn])->cardValue()
  << "|  ";
  cardPosn++;
}
cardPosn = cards.size() - remainder;
std::cout << std::endl;
for (int i = 0; i < remainder; i++) {
  std::cout << "+---------+  ";
}
std::cout << std::endl << std::endl;
}
}
}

std::vector<Card*> Hand::getHand() {
  return cards;
}
