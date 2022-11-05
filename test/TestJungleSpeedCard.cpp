#include <iostream>
#include <string>
#include "JungleSpeedCard.h"
#include "Card.h"
#include "gtest/gtest.h"

TEST(TestJungleSpeedCard, testJungleSpeedCardConstructor) {
  JungleSpeedCard j1("FullCircleGrid", JungleSpeedCard::BLUE);
  EXPECT_EQ(j1.getName(), "FullCircleGrid");
  EXPECT_EQ(j1.getColour(), 2);
}

TEST(TestJungleSpeedCard, testSetColour) {
  JungleSpeedCard j1("FullCircleGrid", JungleSpeedCard::SPECIAL);
  j1.setColour(JungleSpeedCard::RED);
  EXPECT_EQ(j1.getColour(), 1);
  JungleSpeedCard j2("FullCircleGrid", JungleSpeedCard::RED);
  j2.setColour(JungleSpeedCard::BLUE);
  EXPECT_EQ(j2.getColour(), 2);
  JungleSpeedCard j3("FullCircleGrid", JungleSpeedCard::GREEN);
  j3.setColour(JungleSpeedCard::YELLOW);
  EXPECT_EQ(j3.getColour(), 3);
  JungleSpeedCard j4("FullCircleGrid", JungleSpeedCard::YELLOW);
  j4.setColour(JungleSpeedCard::GREEN);
  EXPECT_EQ(j4.getColour(), 4);
  JungleSpeedCard j5("FullCircleGrid", JungleSpeedCard::GREEN);
  j5.setColour(JungleSpeedCard::SPECIAL);
  EXPECT_EQ(j5.getColour(), 5);
}

TEST(TestJungleSpeedCard, testSetName) {
  JungleSpeedCard j1("FullCircleGrid", JungleSpeedCard::BLUE);
  j1.setName("ThreeLoops");
  EXPECT_EQ(j1.getName(), "ThreeLoops");
}

TEST(TestJungleSpeedCard, testGetColour) {
  JungleSpeedCard j1("XInsideCircle", JungleSpeedCard::GREEN);
  EXPECT_EQ(j1.getColour(), 4);
}

TEST(TestJungleSpeedCard, testGetName) {
  JungleSpeedCard j1("TwoLoops", JungleSpeedCard::GREEN);
  EXPECT_EQ(j1.getName(), "TwoLoops");
}

TEST(TestJungleSpeedCard, testColourToString) {
  JungleSpeedCard j1("XInsideCircle", JungleSpeedCard::RED);
  EXPECT_EQ(j1.ColourToString(j1.getColour()), "Red");
  JungleSpeedCard j2("XInsideCircle", JungleSpeedCard::BLUE);
  EXPECT_EQ(j2.ColourToString(j2.getColour()), "Blue");
  JungleSpeedCard j3("XInsideCircle", JungleSpeedCard::YELLOW);
  EXPECT_EQ(j3.ColourToString(j3.getColour()), "Yellow");
  JungleSpeedCard j4("XInsideCircle", JungleSpeedCard::GREEN);
  EXPECT_EQ(j4.ColourToString(j4.getColour()), "Green");
  JungleSpeedCard j5("XInsideCircle", JungleSpeedCard::SPECIAL);
  EXPECT_EQ(j5.ColourToString(j5.getColour()), "Special");
}

TEST(TestJungleSpeedCard, testDisplayCard) {
  std::stringstream consoleCardDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleCardDisplay.rdbuf());
  JungleSpeedCard* Card =
  new JungleSpeedCard("LineInsideCircle", JungleSpeedCard::RED);
  Card->displayCard();
  EXPECT_EQ(consoleCardDisplay.str(), "Red LineInsideCircle");
  std::cout.rdbuf(sbuf);
  delete Card;
}

TEST(TestJungleSpeedCard, testStringOfWholeCard) {
  JungleSpeedCard j1("SquareCircleSquare", JungleSpeedCard::GREEN);
  EXPECT_EQ(j1.stringOfWholeCard(), "Green SquareCircleSquare");
}

TEST(TestJungleSpeedCard, testEqualsEqualsOperator) {
  JungleSpeedCard OCOY_1("OctagonCircleOctagon", JungleSpeedCard::YELLOW);
  JungleSpeedCard OCOY_2("OctagonCircleOctagon", JungleSpeedCard::YELLOW);
  EXPECT_TRUE(OCOY_1 == OCOY_2);
  EXPECT_TRUE(OCOY_1 == OCOY_1);
  EXPECT_TRUE(OCOY_2 == OCOY_2);
  JungleSpeedCard LFPSB("LargeFourProngStar", JungleSpeedCard::BLUE);
  EXPECT_FALSE(OCOY_1 == LFPSB);
  EXPECT_FALSE(OCOY_2 == LFPSB);
  EXPECT_TRUE(LFPSB == LFPSB);
  JungleSpeedCard OCOB("OctagonCircleOctagon", JungleSpeedCard::BLUE);
  EXPECT_FALSE(OCOY_1 == OCOB);
  EXPECT_FALSE(OCOY_2 == OCOB);
  EXPECT_FALSE(LFPSB == OCOB);
  EXPECT_TRUE(OCOB == OCOB);
}
