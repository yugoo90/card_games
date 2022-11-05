#include <string>
#include "Card.h"
#include "StandardCard.h"
#include "Human.h"
#include "gtest/gtest.h"
#include "Player.h"

TEST(TestHuman, testHumanConstructor) {
Human h1("Ugo", 1);
EXPECT_EQ(h1.getName(), "Ugo");
EXPECT_EQ(h1.getID(), 1);
}

TEST(TestHuman, testSetName) {
  Human h1("David", 1);
  h1.setName("Cadence");
  EXPECT_EQ(h1.getName(), "Cadence");
}

TEST(TestHuman, testGetName) {
  Human h1("Noel", 1);
  EXPECT_EQ(h1.getName(), "Noel");
}

TEST(TestHuman, testSetAndGetTurn) {
  Human h1("Cadence", 1);
  h1.setMyTurn(true);
  EXPECT_TRUE(h1.getMyTurn());
}

TEST(TestHuman, testGetType) {
  Human h1("David", 1);
  EXPECT_EQ(h1.getType(), 0);
}

TEST(TestHuman, testGetTotalPoints) {
  Human h1("Ugo", 1);
  EXPECT_EQ(h1.getTotalPoints(), 0);
}

TEST(TestHuman, testGetRoundPoints) {
  Human h1("Ugo", 1);
  EXPECT_EQ(h1.getRoundPoints(), 0);
}


TEST(TestHuman, testSetRoundPoints) {
  Human h1("David", 1);
  h1.setRoundPoints(25);
  EXPECT_EQ(h1.getRoundPoints(), 25);
}

TEST(TestHuman, testSetTotalPoints) {
  Human h1("Ugo", 1);
  h1.setTotalPoints();
  EXPECT_EQ(h1.getTotalPoints(), 0);
  h1.setRoundPoints(25);
  h1.setTotalPoints();
  EXPECT_EQ(h1.getTotalPoints(), 25);
  h1.setRoundPoints(27);
  h1.setTotalPoints();
  EXPECT_EQ(h1.getTotalPoints(), 52);
}

TEST(TestHuman, testIsInHand) {
  Player* h1 = new Human("Cadence", 1);

  Card* c1 = new StandardCard(StandardCard::DIAMONDS, 12);
  Card* c2 = new StandardCard(StandardCard::CLUBS, 4);
  Card* c3 = new StandardCard(StandardCard::CLUBS, 9);
  Card* c4 = new StandardCard(StandardCard::HEARTS, 1);
  Card* c5 = new StandardCard(StandardCard::SPADES, 2);

  h1->hand.addCard(c1);
  h1->hand.addCard(c2);
  h1->hand.addCard(c3);
  h1->hand.addCard(c4);
  h1->hand.addCard(c5);

  EXPECT_TRUE(h1->isInHand(12));
  EXPECT_TRUE(h1->isInHand(4));
  EXPECT_TRUE(h1->isInHand(9));
  EXPECT_TRUE(h1->isInHand(1));
  EXPECT_TRUE(h1->isInHand(2));

  EXPECT_FALSE(h1->isInHand(8));
  EXPECT_FALSE(h1->isInHand(7));
  EXPECT_FALSE(h1->isInHand(5));
  EXPECT_FALSE(h1->isInHand(11));
  EXPECT_FALSE(h1->isInHand(13));

  delete h1;
}
