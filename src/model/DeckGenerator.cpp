#include <iostream>
#include <string>
#include "Deck.h"
#include "Game.h"
#include "DeckGenerator.h"
#include "CardGenerator.h"

DeckGenerator::DeckGenerator() {}
DeckGenerator::~DeckGenerator() {}
Deck* DeckGenerator::makeDeck(const Game::GameType t) {
  Deck* d = new Deck();
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

Deck* DeckGenerator::makeDeck(const Game::GameType t, const bool twoPlayers) {
  Deck* d = new Deck();
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

Deck* DeckGenerator::makeStandardDeck(Deck* d) {
  CardGenerator generate;
  for (int i = 1; i <= 13; i++) {
    Card* tempCard = generate.makeStandardCard(1, i);
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

Deck* DeckGenerator::make72JungleSpeed(Deck* d) {
  CardGenerator generate;
  for (int i = 1; i <= 4; i++) {
    Card* tempCard = generate.makeJungleSpeedCard("FullCircleGrid", i);
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

Deck* DeckGenerator::makeExtraJungleSpeed(Deck* d) {
  CardGenerator generate;
  Card* tempCard = generate.makeJungleSpeedCard("AllOut1", 5);
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
