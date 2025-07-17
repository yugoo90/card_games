#include <iostream>
#include <string>
#include "Deck.h"
#include "Game.h"
#include "DeckGenerator.h"
#include "CardGenerator.h"

DeckGenerator::DeckGenerator() {}
DeckGenerator::~DeckGenerator() {}
std::shared_ptr<Deck> DeckGenerator::makeDeck(const Game::GameType t) {
  std::shared_ptr<Deck> d = std::make_shared<Deck>();
  switch (t) {
    case Game::JUNGLESPEED : {
      d = (*this).make72JungleSpeed(d);
      d = (*this).makeExtraJungleSpeed(d);
      return d;
    }
    default: {
      d = (*this).makeStandardDeck(d);
      return d;
    }
  }
}

std::shared_ptr<Deck> DeckGenerator::makeDeck(const Game::GameType t, const bool twoPlayers) {
  std::shared_ptr<Deck> d = std::make_shared<Deck>();
  switch (t) {
    case Game::JUNGLESPEED : {
      d = (*this).make72JungleSpeed(d);
      if (!twoPlayers) {
        d = (*this).makeExtraJungleSpeed(d);
      }
      return d;
    }
    default: {
      d = (*this).makeStandardDeck(d);
      return d;
    }
  }
}

std::shared_ptr<Deck> DeckGenerator::makeStandardDeck(std::shared_ptr<Deck> d) {
  CardGenerator generate;
  for (int i = 1; i <= 13; i++) {
    std::shared_ptr<Card> tempCard = generate.makeStandardCard(1, i);
    d->addCard(tempCard);
    tempCard = generate.makeStandardCard(2, i);
    d->addCard(tempCard);
    tempCard = generate.makeStandardCard(3, i);
    d->addCard(tempCard);
    tempCard = generate.makeStandardCard(4, i);
    d->addCard(tempCard);
  }
  return d;
}

std::shared_ptr<Deck> DeckGenerator::make72JungleSpeed(std::shared_ptr<Deck> d) {
  CardGenerator generate;
  for (int i = 1; i <= 4; i++) {
    std::shared_ptr<Card> tempCard = generate.makeJungleSpeedCard("FullCircleGrid", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("EmptyCircleGrid", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("LargeFourProngStar", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("SmallFourProngStar", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("LargeEightProngStar", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("SmallEightProngStar", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("FourOuterLoops", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("TwoLoops", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("ThreeLoops", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("FourLoops", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("XInsideCircle", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("XOutsideCircle", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("LineInsideCircle", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("LineOutsideCircle", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("CircleSquareCircle", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("SquareCircleSquare", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("OctagonSquareOctagon", i);
    d->addCard(tempCard);
    tempCard = generate.makeJungleSpeedCard("OctagonCircleOctagon", i);
    d->addCard(tempCard);
  }
  return d;
}

std::shared_ptr<Deck> DeckGenerator::makeExtraJungleSpeed(std::shared_ptr<Deck> d) {
  CardGenerator generate;
  std::shared_ptr<Card> tempCard = generate.makeJungleSpeedCard("AllOut1", 5);
  d->addCard(tempCard);
  tempCard = generate.makeJungleSpeedCard("AllOut2", 5);
  d->addCard(tempCard);
  tempCard = generate.makeJungleSpeedCard("AllOut3", 5);
  d->addCard(tempCard);
  tempCard = generate.makeJungleSpeedCard("AllIn1", 5);
  d->addCard(tempCard);
  tempCard = generate.makeJungleSpeedCard("AllIn2", 5);
  d->addCard(tempCard);
  tempCard = generate.makeJungleSpeedCard("AllIn3", 5);
  d->addCard(tempCard);
  tempCard = generate.makeJungleSpeedCard("Colors1", 5);
  d->addCard(tempCard);
  tempCard = generate.makeJungleSpeedCard("Colors2", 5);
  d->addCard(tempCard);
  return d;
}
