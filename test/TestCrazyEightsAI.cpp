#include <string>
#include "CrazyEightsAI.h"
#include "AI.h"
#include "Player.h"
#include "StandardCard.h"
#include "gtest/gtest.h"


TEST(TestCrazyEightsAI, testCrazyEightsAIConstructor) {
  CrazyEightsAI* ai1 = new CrazyEightsAI(AI::EASY, 1);
  CrazyEightsAI* ai2 = new CrazyEightsAI(AI::NORMAL, 5);
  CrazyEightsAI* ai3 = new CrazyEightsAI(AI::HARD, 9);

  EXPECT_EQ(ai1->getDifficultyLevel(), 1);
  EXPECT_EQ(ai2->getDifficultyLevel(), 2);
  EXPECT_EQ(ai3->getDifficultyLevel(), 3);

  EXPECT_EQ(ai1->getID(), 1);
  EXPECT_EQ(ai2->getID(), 5);
  EXPECT_EQ(ai3->getID(), 9);

  delete ai1;
  delete ai2;
  delete ai3;
}

TEST(TestCrazyEightsAI, testSetDifficultyLevel) {
  CrazyEightsAI* ai1 = new CrazyEightsAI(AI::EASY, 4);
  CrazyEightsAI* ai2 = new CrazyEightsAI(AI::NORMAL, 5);
  CrazyEightsAI* ai3 = new CrazyEightsAI(AI::HARD, 6);

  ai1->setDifficultyLevel(AI::NORMAL);
  ai2->setDifficultyLevel(AI::HARD);
  ai3->setDifficultyLevel(AI::EASY);

  EXPECT_EQ(ai1->getDifficultyLevel(), 2);
  EXPECT_EQ(ai2->getDifficultyLevel(), 3);
  EXPECT_EQ(ai3->getDifficultyLevel(), 1);

  EXPECT_EQ(ai1->getID(), 4);
  EXPECT_EQ(ai2->getID(), 5);
  EXPECT_EQ(ai3->getID(), 6);

  delete ai1;
  delete ai2;
  delete ai3;
}

TEST(TestCrazyEightsAI, testGetName) {
  CrazyEightsAI* ai1 = new CrazyEightsAI(AI::EASY, 1);
  CrazyEightsAI* ai2 = new CrazyEightsAI(AI::NORMAL, 2);
  CrazyEightsAI* ai3 = new CrazyEightsAI(AI::HARD, 3);

  EXPECT_EQ(ai1->getDifficultyLevel(), 1);
  EXPECT_EQ(ai2->getDifficultyLevel(), 2);
  EXPECT_EQ(ai3->getDifficultyLevel(), 3);

  EXPECT_EQ(ai1->getID(), 1);
  EXPECT_EQ(ai2->getID(), 2);
  EXPECT_EQ(ai3->getID(), 3);

  EXPECT_EQ(ai1->getName(), "AI 1");
  EXPECT_EQ(ai2->getName(), "AI 2");
  EXPECT_EQ(ai3->getName(), "AI 3");

  delete ai1;
  delete ai2;
  delete ai3;
}

TEST(TestCrazyEightsAI, testStrategy) {
  CrazyEightsAI* ai1 = new CrazyEightsAI(AI::EASY, 1);
  CrazyEightsAI* ai2 = new CrazyEightsAI(AI::NORMAL, 2);
  CrazyEightsAI* ai3 = new CrazyEightsAI(AI::HARD, 3);

  Card* c1 = new StandardCard(StandardCard::SPADES, 2);
  Card* c2 = new StandardCard(StandardCard::DIAMONDS, 1);
  Card* c3 = new StandardCard(StandardCard::DIAMONDS, 10);
  Card* c4 = new StandardCard(StandardCard::CLUBS, 5);

  Card* topCard = new StandardCard(StandardCard::DIAMONDS, 2);
  ai1->hand.addCard(c1);
  ai1->hand.addCard(c2);
  ai1->hand.addCard(c3);
  ai1->hand.addCard(c4);

  Card* returnedCard = ai1->strategy(topCard);
  EXPECT_EQ(returnedCard->stringOfWholeCard(), "Ace of Diamonds");

  ai1->hand.removeCard(c1);
  ai1->hand.removeCard(c2);
  ai1->hand.removeCard(c3);
  ai1->hand.removeCard(c4);

  ai2->hand.addCard(c1);
  ai2->hand.addCard(c2);
  ai2->hand.addCard(c3);
  ai2->hand.addCard(c4);

  returnedCard = ai2->strategy(topCard);
  EXPECT_EQ(returnedCard->stringOfWholeCard(), "2 of Spades");

  ai2->hand.removeCard(c1);
  ai2->hand.removeCard(c2);
  ai2->hand.removeCard(c3);
  ai2->hand.removeCard(c4);

  ai3->hand.addCard(c1);
  ai3->hand.addCard(c2);
  ai3->hand.addCard(c3);
  ai3->hand.addCard(c4);

  returnedCard = ai3->strategy(topCard);
  EXPECT_EQ(returnedCard->stringOfWholeCard(), "10 of Diamonds");
  delete ai1;
  delete ai2;
  delete ai3;
  delete topCard;
}

TEST(TestCrazyEightsAI, testStrategyNoLegalCards) {
  CrazyEightsAI* ai1 = new CrazyEightsAI(AI::EASY, 1);

  Card* c1 = new StandardCard(StandardCard::SPADES, 2);
  Card* c2 = new StandardCard(StandardCard::DIAMONDS, 1);
  Card* c3 = new StandardCard(StandardCard::DIAMONDS, 10);
  Card* c4 = new StandardCard(StandardCard::CLUBS, 5);

  Card* topCard = new StandardCard(StandardCard::HEARTS, 6);
  ai1->hand.addCard(c1);
  ai1->hand.addCard(c2);
  ai1->hand.addCard(c3);
  ai1->hand.addCard(c4);

  Card* returnedCard = ai1->strategy(topCard);
  EXPECT_EQ(returnedCard, nullptr);

  delete ai1;
  delete topCard;
}
