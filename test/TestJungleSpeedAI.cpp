#include <string>
#include "JungleSpeedAI.h"
#include "AI.h"
#include "Player.h"
#include "gtest/gtest.h"


TEST(TestJungleSpeedAI, testJungleSpeedAIConstructor) {
  JungleSpeedAI* ai1 = new JungleSpeedAI(AI::EASY, 1);
  JungleSpeedAI* ai2 = new JungleSpeedAI(AI::NORMAL, 5);
  JungleSpeedAI* ai3 = new JungleSpeedAI(AI::HARD, 9);

  EXPECT_EQ(ai1->getDifficultyLevel(), 1);
  EXPECT_EQ(ai2->getDifficultyLevel(), 2);
  EXPECT_EQ(ai3->getDifficultyLevel(), 3);

  EXPECT_EQ(ai1->getID(), 1);
  EXPECT_EQ(ai2->getID(), 5);
  EXPECT_EQ(ai3->getID(), 9);

  EXPECT_EQ(ai1->getResponseTime(), 3.49);
  EXPECT_EQ(ai2->getResponseTime(), 2.49);
  EXPECT_EQ(ai3->getResponseTime(), 1.49);

  delete ai1;
  delete ai2;
  delete ai3;
}

TEST(TestJungleSpeedAI, testSetDifficultyLevel) {
  JungleSpeedAI* ai1 = new JungleSpeedAI(AI::EASY, 4);
  JungleSpeedAI* ai2 = new JungleSpeedAI(AI::NORMAL, 5);
  JungleSpeedAI* ai3 = new JungleSpeedAI(AI::HARD, 6);

  ai1->setDifficultyLevel(AI::NORMAL);
  ai2->setDifficultyLevel(AI::HARD);
  ai3->setDifficultyLevel(AI::EASY);

  ai1->setResponseTime(AI::NORMAL);
  ai2->setResponseTime(AI::HARD);
  ai3->setResponseTime(AI::EASY);

  EXPECT_EQ(ai1->getDifficultyLevel(), 2);
  EXPECT_EQ(ai2->getDifficultyLevel(), 3);
  EXPECT_EQ(ai3->getDifficultyLevel(), 1);

  EXPECT_EQ(ai1->getID(), 4);
  EXPECT_EQ(ai2->getID(), 5);
  EXPECT_EQ(ai3->getID(), 6);

  EXPECT_EQ(ai1->getResponseTime(), 2.49);
  EXPECT_EQ(ai2->getResponseTime(), 1.49);
  EXPECT_EQ(ai3->getResponseTime(), 3.49);

  delete ai1;
  delete ai2;
  delete ai3;
}

TEST(TestJungleSpeedAI, testGetName) {
  JungleSpeedAI* ai1 = new JungleSpeedAI(AI::EASY, 1);
  JungleSpeedAI* ai2 = new JungleSpeedAI(AI::NORMAL, 2);
  JungleSpeedAI* ai3 = new JungleSpeedAI(AI::HARD, 3);

  EXPECT_EQ(ai1->getDifficultyLevel(), 1);
  EXPECT_EQ(ai2->getDifficultyLevel(), 2);
  EXPECT_EQ(ai3->getDifficultyLevel(), 3);

  EXPECT_EQ(ai1->getID(), 1);
  EXPECT_EQ(ai2->getID(), 2);
  EXPECT_EQ(ai3->getID(), 3);

  EXPECT_EQ(ai1->getResponseTime(), 3.49);
  EXPECT_EQ(ai2->getResponseTime(), 2.49);
  EXPECT_EQ(ai3->getResponseTime(), 1.49);

  EXPECT_EQ(ai1->getName(), "AI 1");
  EXPECT_EQ(ai2->getName(), "AI 2");
  EXPECT_EQ(ai3->getName(), "AI 3");

  delete ai1;
  delete ai2;
  delete ai3;
}
