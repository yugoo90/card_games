#include <string>
#include <vector>
#include "GoFishAI.h"
#include "AI.h"
#include "Player.h"
#include "gtest/gtest.h"
#include "StandardCard.h"
#include "Game.h"
#include "GoFish.h"
#include "Deck.h"

TEST(TestGoFishAI, testGoFishAIConstructor) {
  GoFishAI* ai1 = new GoFishAI(AI::EASY, 1);
  GoFishAI* ai2 = new GoFishAI(AI::NORMAL, 5);
  GoFishAI* ai3 = new GoFishAI(AI::HARD, 9);

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

TEST(TestGoFishAI, testSetDifficultyLevel) {
  GoFishAI* ai1 = new GoFishAI(AI::EASY, 4);
  GoFishAI* ai2 = new GoFishAI(AI::NORMAL, 5);
  GoFishAI* ai3 = new GoFishAI(AI::HARD, 6);

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

TEST(TestGoFishAI, testGetName) {
  GoFishAI* ai1 = new GoFishAI(AI::EASY, 1);
  GoFishAI* ai2 = new GoFishAI(AI::NORMAL, 2);
  GoFishAI* ai3 = new GoFishAI(AI::HARD, 3);

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

TEST(TestGoFishAI, testStrategy) {
  std::vector<std::vector<int>> V;
  for (int i = 0; i < 3; i++) {
    std::vector<int> v;
    v.push_back(0);
    V.push_back(v);
  }

  V[0][0] = 1;
  V[0].push_back(5);
  V[1][0] = 13;
  V[2][0] = 5;

  GoFishAI* ai1 = new GoFishAI(AI::EASY, 1);
  GoFishAI* ai2 = new GoFishAI(AI::NORMAL, 2);
  GoFishAI* ai3 = new GoFishAI(AI::HARD, 3);

  Card* c1 = new StandardCard(StandardCard::SPADES, 13);
  Card* c2 = new StandardCard(StandardCard::DIAMONDS, 1);
  Card* c3 = new StandardCard(StandardCard::CLUBS, 5);

  ai1->hand.addCard(c1);
  ai1->hand.addCard(c2);
  ai1->hand.addCard(c3);

  Card* returnedCard = ai1->strategy(V);
  EXPECT_TRUE((returnedCard->stringOfWholeCard() == "King of Spades") ||
  (returnedCard->stringOfWholeCard() == "Ace of Diamonds") ||
  (returnedCard->stringOfWholeCard() == "5 of Clubs"));

  ai1->hand.removeCard(c1);
  ai1->hand.removeCard(c2);
  ai1->hand.removeCard(c3);

  ai2->hand.addCard(c1);
  ai2->hand.addCard(c2);
  ai2->hand.addCard(c3);

  returnedCard = ai2->strategy(V);
  EXPECT_TRUE((returnedCard->stringOfWholeCard() == "King of Spades"));

  ai2->hand.removeCard(c1);
  ai2->hand.removeCard(c2);
  ai2->hand.removeCard(c3);

  ai3->hand.addCard(c1);
  ai3->hand.addCard(c2);
  ai3->hand.addCard(c3);

  returnedCard = ai3->strategy(V);
  EXPECT_TRUE((returnedCard->stringOfWholeCard() == "5 of Clubs"));

  delete ai1;
  delete ai2;
  delete ai3;
}

TEST(TestGoFishAI, testChoosePlayer) {
  Player* ai1 = new GoFishAI(AI::EASY, 1);
  Player* ai2 = new GoFishAI(AI::NORMAL, 2);
  Player* ai3 = new GoFishAI(AI::HARD, 3);
  std::vector<Player*> v;
  v.push_back(ai1);
  v.push_back(ai2);
  v.push_back(ai3);
  GoFish g(1, v);
  Player* p;
  p = (dynamic_cast<GoFishAI*>(ai1))->ChoosePlayer(&g);
  EXPECT_TRUE(p -> getID() != ai1-> getID());
}

TEST(TestGoFishAI, testChoosePlayerTargeted) {
  Player* ai2 = new GoFishAI(AI::NORMAL, 0);
  Player* ai3 = new GoFishAI(AI::HARD, 1);
  std::vector<Player*> players;
  players.push_back(ai2);
  players.push_back(ai3);
  GoFish g(1, players);

  std::vector<std::vector<int>> V;
  for (int i = 0; i < 2; i++) {
    std::vector<int> v;
    v.push_back(0);
    V.push_back(v);
  }
  V[0][0] = 1;

  Card* c2 = new StandardCard(StandardCard::DIAMONDS, 1);
  ai3->hand.addCard(c2);

  Card* returnedCard = dynamic_cast<GoFishAI*>(ai3)->strategy(V);

  Player* p;
  p = (dynamic_cast<GoFishAI*>(ai3))->ChoosePlayer(&g);
  EXPECT_TRUE(p -> getID() == ai2-> getID());
}

TEST(TestGoFishAI, testStrategyAskItself) {
  std::vector<std::vector<int>> V;
  for (int i = 0; i < 2; i++) {
    std::vector<int> v;
    v.push_back(0);
    V.push_back(v);
  }

  V[0][0] = 5;
  V[0].push_back(10);
  V[0].push_back(4);
  V[0].push_back(2);
  V[0].push_back(13);
  V[1][0] = 5;

  GoFishAI* ai2 = new GoFishAI(AI::NORMAL, 1);
  GoFishAI* ai3 = new GoFishAI(AI::HARD, 0);

  Card* c1 = new StandardCard(StandardCard::SPADES, 13);
  Card* c2 = new StandardCard(StandardCard::DIAMONDS, 1);
  Card* c3 = new StandardCard(StandardCard::CLUBS, 5);


  ai2->hand.addCard(c1);
  ai2->hand.addCard(c2);
  ai2->hand.addCard(c3);

  Card* returnedCard = ai2->strategy(V);
  EXPECT_TRUE((returnedCard->stringOfWholeCard() == "5 of Clubs"));

  ai2->hand.removeCard(c1);
  ai2->hand.removeCard(c2);
  ai2->hand.removeCard(c3);

  ai3->hand.addCard(c1);
  ai3->hand.addCard(c2);
  ai3->hand.addCard(c3);

  returnedCard = ai3->strategy(V);
  EXPECT_TRUE((returnedCard->stringOfWholeCard() == "5 of Clubs"));

  delete ai2;
  delete ai3;
}
