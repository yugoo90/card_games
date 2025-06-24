#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"
#include "CardSet.h"
#include "StandardCard.h"

CardSet::CardSet() {
  seed = time(NULL);
}

CardSet::~CardSet() {
  for (auto c : cards) {
    delete c;
  }
}

int CardSet::getSize() const {
  return cards.size();
}

CardSet::CardSetType CardSet::getType() const {
  return type;
}

void CardSet::addCard(Card* c) {
  cards.push_back(c);
}

Card* CardSet::getCard(const Card* c) {
  for (auto it = cards.begin(); it != cards.end(); it++) {
    if (*(*it) == *c) {
      return *it;
    }
  }
  return nullptr;
}

void CardSet::removeCard(const Card* c) {
  for (auto it = cards.begin(); it != cards.end(); it++) {
    if (*(*it) == *c) {
      cards.erase(it);
      return;
    }
  }
}

Card* CardSet::getTop() {
  Card* c = cards[cards.size()-1];
  return c;
}

void CardSet::shuffleCardSet() {
  std::shuffle(std::begin(cards), std::end(cards),
  std::default_random_engine(seed));
}
