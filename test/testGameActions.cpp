#include <string>
#include <vector>
#include "GoFishAI.h"
#include "AI.h"
#include "Player.h"
#include "gtest/gtest.h"
#include "StandardCard.h"
#include "Game.h"
#include "Card.h"
#include "GoFish.h"
#include "Hand.h"
#include "GameActions.h"

TEST(TestGameActions, testMakeRequest1Card) {
  GameActions request;
  std::vector<Card*> returnedCards;
  Player* h1 = new Human("Player1", 0);
  Card* c1 = new StandardCard(StandardCard::SPADES, 11);
  Card* c2 = new StandardCard(StandardCard::DIAMONDS, 8);
  Card* c3 = new StandardCard(StandardCard::CLUBS, 5);
  Card* c4 = new StandardCard(StandardCard::HEARTS, 5);
  Card* c5 = new StandardCard(StandardCard::SPADES, 5);

  h1->hand.addCard(c1);
  h1->hand.addCard(c2);
  h1->hand.addCard(c3);
  h1->hand.addCard(c4);
  h1->hand.addCard(c5);

  returnedCards = request.makeRequest(h1, 11);

  EXPECT_EQ(returnedCards.size(), 1);
  EXPECT_EQ(returnedCards[0]->stringOfWholeCard(), "Jack of Spades");

  returnedCards = request.makeRequest(h1, 8);

  EXPECT_EQ(returnedCards.size(), 1);
  EXPECT_EQ(returnedCards[0]->stringOfWholeCard(), "8 of Diamonds");

  delete h1;
}

TEST(TestGameActions, testMakeRequestNoCards) {
  GameActions request;
  std::vector<Card*> returnedCards;
  Player* h1 = new Human("Player1", 0);
  Card* c1 = new StandardCard(StandardCard::SPADES, 11);
  Card* c2 = new StandardCard(StandardCard::DIAMONDS, 8);
  Card* c3 = new StandardCard(StandardCard::CLUBS, 5);
  Card* c4 = new StandardCard(StandardCard::HEARTS, 5);
  Card* c5 = new StandardCard(StandardCard::SPADES, 5);

  h1->hand.addCard(c1);
  h1->hand.addCard(c2);
  h1->hand.addCard(c3);
  h1->hand.addCard(c4);
  h1->hand.addCard(c5);

  returnedCards = request.makeRequest(h1, 1);

  EXPECT_EQ(returnedCards.size(), 0);

  delete h1;
}

TEST(TestGameActions, testMakeRequestMultipleCards) {
  GameActions request;
  std::vector<Card*> returnedCards;
  Player* h1 = new Human("Player1", 0);
  Card* c1 = new StandardCard(StandardCard::SPADES, 11);
  Card* c2 = new StandardCard(StandardCard::DIAMONDS, 8);
  Card* c3 = new StandardCard(StandardCard::CLUBS, 5);
  Card* c4 = new StandardCard(StandardCard::HEARTS, 5);
  Card* c5 = new StandardCard(StandardCard::SPADES, 5);

  h1->hand.addCard(c1);
  h1->hand.addCard(c2);
  h1->hand.addCard(c3);
  h1->hand.addCard(c4);
  h1->hand.addCard(c5);

  returnedCards = request.makeRequest(h1, 5);

  EXPECT_EQ(returnedCards.size(), 3);

  StandardCard* temp1 = dynamic_cast<StandardCard*>(returnedCards[0]);
  StandardCard* temp2 = dynamic_cast<StandardCard*>(returnedCards[1]);
  StandardCard* temp3 = dynamic_cast<StandardCard*>(returnedCards[2]);

  EXPECT_EQ(temp1->getValue(), 5);
  EXPECT_EQ(temp2->getValue(), 5);
  EXPECT_EQ(temp3->getValue(), 5);

  delete h1;
}

TEST(TestGameActions, testMostPrevalentSuitSpades) {
Hand hand;
GameActions g;
StandardCard::Suit s;

Card* c1 = new StandardCard(StandardCard::SPADES, 11);
Card* c2 = new StandardCard(StandardCard::DIAMONDS, 8);
Card* c3 = new StandardCard(StandardCard::CLUBS, 5);
Card* c4 = new StandardCard(StandardCard::HEARTS, 5);
Card* c5 = new StandardCard(StandardCard::SPADES, 5);

hand.addCard(c1);
hand.addCard(c2);
hand.addCard(c3);
hand.addCard(c4);
hand.addCard(c5);
std::vector<Card*> hnd = hand.getHand();
s = g.mostPrevalentSuit(hnd);

EXPECT_EQ(s, StandardCard::SPADES);
}

TEST(TestGameActions, testMostPrevalentSuitHearts) {
Hand hand;
GameActions g;

Card* c1 = new StandardCard(StandardCard::SPADES, 11);
Card* c2 = new StandardCard(StandardCard::DIAMONDS, 8);
Card* c3 = new StandardCard(StandardCard::CLUBS, 5);
Card* c4 = new StandardCard(StandardCard::HEARTS, 5);
Card* c5 = new StandardCard(StandardCard::HEARTS, 6);

hand.addCard(c1);
hand.addCard(c2);
hand.addCard(c3);
hand.addCard(c4);
hand.addCard(c5);

std::vector<Card*> hnd = hand.getHand();

EXPECT_EQ(g.mostPrevalentSuit(hnd), StandardCard::HEARTS);
}

TEST(TestGameActions, testMostPrevalentSuitDiamonds) {
Hand hand;
GameActions g;

Card* c1 = new StandardCard(StandardCard::SPADES, 11);
Card* c2 = new StandardCard(StandardCard::DIAMONDS, 8);
Card* c3 = new StandardCard(StandardCard::CLUBS, 5);
Card* c4 = new StandardCard(StandardCard::HEARTS, 5);
Card* c5 = new StandardCard(StandardCard::DIAMONDS, 5);

hand.addCard(c1);
hand.addCard(c2);
hand.addCard(c3);
hand.addCard(c4);
hand.addCard(c5);

std::vector<Card*> hnd = hand.getHand();

EXPECT_EQ(g.mostPrevalentSuit(hnd), StandardCard::DIAMONDS);
}

TEST(TestGameActions, testMostPrevalentSuitClubs) {
Hand hand;
GameActions g;

Card* c1 = new StandardCard(StandardCard::SPADES, 11);
Card* c2 = new StandardCard(StandardCard::DIAMONDS, 8);
Card* c3 = new StandardCard(StandardCard::CLUBS, 5);
Card* c4 = new StandardCard(StandardCard::HEARTS, 5);
Card* c5 = new StandardCard(StandardCard::CLUBS, 5);

hand.addCard(c1);
hand.addCard(c2);
hand.addCard(c3);
hand.addCard(c4);
hand.addCard(c5);
std::vector<Card*> hnd = hand.getHand();

EXPECT_EQ(g.mostPrevalentSuit(hnd), StandardCard::CLUBS);
}

TEST(TestGameActions, testMostPrevalentSuitTie) {
Hand hand;
GameActions g;

Card* c1 = new StandardCard(StandardCard::SPADES, 11);
Card* c2 = new StandardCard(StandardCard::DIAMONDS, 8);
Card* c3 = new StandardCard(StandardCard::CLUBS, 5);
Card* c4 = new StandardCard(StandardCard::HEARTS, 5);

hand.addCard(c1);
hand.addCard(c2);
hand.addCard(c3);
hand.addCard(c4);
std::vector<Card*> hnd = hand.getHand();

EXPECT_EQ(g.mostPrevalentSuit(hnd), StandardCard::DIAMONDS);
}
