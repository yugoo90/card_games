#include <iostream>
#include <string>
#include "DeckGenerator.h"
#include "Deck.h"
#include "Game.h"
#include "Card.h"
#include "CardSet.h"
#include "CardGenerator.h"
#include "gtest/gtest.h"


TEST(TestDeckGenerator, testStandardCardMakeDeckSizeCheck) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::GOFISH);
  EXPECT_EQ(d->getSize(), 52);
  delete d;
}

TEST(TestDeckGenerator, testStandardCardMakeDeckTwoPlayersTrue) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::GOFISH, true);
  EXPECT_EQ(d->getSize(), 52);
  delete d;
}

TEST(TestDeckGenerator, testStandardCardMakeDeckTwoPlayersFalse) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::GOFISH, false);
  EXPECT_EQ(d->getSize(), 52);
  delete d;
}

TEST(TestDeckGenerator, testStandardCardGetTopsDeckVerification) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::GOFISH);

  for (int i = 1; i<= 52; i++) {
    Card* temp = d->getTop();
    d->removeCard(temp);
    delete temp;
  }
  EXPECT_EQ(d->getSize(), 0);
  delete d;
}

TEST(TestDeckGenerator, testStandardCardLastCard) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::GOFISH);

  StandardCard* temp = dynamic_cast<StandardCard*>(d->getTop());
  d->removeCard(temp);
  EXPECT_EQ(temp->getSuit(), 4);
  EXPECT_EQ(temp->getValue(), 13);

  delete temp;
  delete d;
}

TEST(TestDeckGenerator, testStandardCardFirstCard) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::GOFISH);

  for (int i = 1; i<= 51; i++) {
    Card* temp = d->getTop();
    d->removeCard(temp);
    delete temp;
  }

  StandardCard* temp = dynamic_cast<StandardCard*>(d->getTop());
  d->removeCard(temp);
  EXPECT_EQ(temp->getSuit(), 1);
  EXPECT_EQ(temp->getValue(), 1);
  delete temp;
  delete d;
}

TEST(TestDeckGenerator, testStandardCardMiddleCard) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::GOFISH);

  for (int i = 1; i<= 24; i++) {
    Card* temp = d->getTop();
    d->removeCard(temp);
    delete temp;
  }

  StandardCard* temp = dynamic_cast<StandardCard*>(d->getTop());
  d->removeCard(temp);
  EXPECT_EQ(temp->getSuit(), 4);
  EXPECT_EQ(temp->getValue(), 7);
  delete temp;
  delete d;
}

TEST(TestDeckGenerator, testJungleSpeedMakeDeckSizeCheck) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::JUNGLESPEED);
  EXPECT_EQ(d->getSize(), 80);
  delete d;
}

TEST(TestDeckGenerator, testJungleSpeedMakeDeckTwoPlayersTrue) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::JUNGLESPEED, true);
  EXPECT_EQ(d->getSize(), 72);
  delete d;
}

TEST(TestDeckGenerator, testJungleSpeedMakeDeckTwoPlayersFalse) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::JUNGLESPEED, false);
  EXPECT_EQ(d->getSize(), 80);
  delete d;
}

TEST(TestDeckGenerator, testJungleSpeedGetTopDeckVerification) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::JUNGLESPEED);

  for (int i = 1; i <= 80; i++) {
    Card* temp = d->getTop();
    d->removeCard(temp);
    delete temp;
  }
  EXPECT_EQ(d->getSize(), 0);
  delete d;
}

TEST(TestDeckGenerator, testJungleSpeedLastCard) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::JUNGLESPEED);

  JungleSpeedCard* temp = dynamic_cast<JungleSpeedCard*>(d->getTop());
  d->removeCard(temp);
  EXPECT_EQ(temp->getColour(), 5);
  EXPECT_EQ(temp->getName(), "Colors2");

  delete temp;
  delete d;
}

TEST(TestDeckGenerator, testJungleSpeedFirstCard) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::JUNGLESPEED);

  for (int i = 1; i<= 79; i++) {
    Card* temp = d->getTop();
    d->removeCard(temp);
    delete temp;
  }

  JungleSpeedCard* temp = dynamic_cast<JungleSpeedCard*>(d->getTop());
  d->removeCard(temp);
  EXPECT_EQ(temp->getColour(), 1);
  EXPECT_EQ(temp->getName(), "FullCircleGrid");
  delete temp;
  delete d;
}

TEST(TestDeckGenerator, testJungleSpeedMiddleCard) {
  DeckGenerator generate;
  Deck* d = generate.makeDeck(Game::JUNGLESPEED);

  for (int i = 1; i<= 17; i++) {
    Card* temp = d->getTop();
    d->removeCard(temp);
    delete temp;
  }

  JungleSpeedCard* temp = dynamic_cast<JungleSpeedCard*>(d->getTop());
  d->removeCard(temp);
  EXPECT_EQ(temp->getColour(), 4);
  EXPECT_EQ(temp->getName(), "ThreeLoops");
  delete temp;
  delete d;
}
