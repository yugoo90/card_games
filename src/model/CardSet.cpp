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

CardSet::~CardSet() {}

int CardSet::getSize() const {
  return cards.size();
}

CardSet::CardSetType CardSet::getType() const {
  return type;
}

void CardSet::addCard(std::shared_ptr<Card> c) {
  cards.push_back(c);
}

std::shared_ptr<Card> CardSet::getCard(const std::shared_ptr<Card> c) {
  for (auto it = cards.begin(); it != cards.end(); it++) {
    if ((*it) == c) {
      return *it;
    }
  }
  return nullptr;
}

void CardSet::removeCard(const std::shared_ptr<Card> c) {
  for (auto it = cards.begin(); it != cards.end(); it++) {
    if ((*it) == c) {
      cards.erase(it);
      return;
    }
  }
}

std::shared_ptr<Card> CardSet::getTop() {
  std::shared_ptr<Card> c = cards[cards.size()-1];
  return c;
}

void CardSet::shuffleCardSet() {
  std::shuffle(std::begin(cards), std::end(cards),
  std::default_random_engine(seed));
}
