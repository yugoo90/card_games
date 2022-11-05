#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "Discard.h"
#include "StandardCard.h"
#include "JungleSpeedCard.h"
#include "Card.h"
#include "CardSet.h"
#include "gtest/gtest.h"


TEST(TestDiscard, testDiscardConstructor) {
  Discard* Pile = new Discard();
  EXPECT_EQ(Pile->getSize(), 0);
  delete Pile;
}

TEST(TestDiscard, testDisplay) {
  std::stringstream consoleDiscardDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleDiscardDisplay.rdbuf());
  StandardCard* S13 = new StandardCard(StandardCard::SPADES, 13);
  StandardCard* D5 = new StandardCard(StandardCard::DIAMONDS, 5);
  StandardCard* C7 = new StandardCard(StandardCard::CLUBS, 7);
  JungleSpeedCard* XOCY =
  new JungleSpeedCard("XOutsideCircle", JungleSpeedCard::YELLOW);
  JungleSpeedCard* TLB =
  new JungleSpeedCard("TwoLoops", JungleSpeedCard::BLUE);
  JungleSpeedCard* ECGG =
  new JungleSpeedCard("EmptyCircleGrid", JungleSpeedCard::GREEN);
  Discard* Pile = new Discard();
  Pile->addCard(S13);
  Pile->display();
  EXPECT_EQ(consoleDiscardDisplay.str(),
  "\n+---------+\n"
  "|░░░░░░░░░|\n"
  "|░+---------+\n"
  "|░|░░░░░░░░░|\n"
  "|░|░+---------+\n"
  "|░|░|K        |\n"
  "+-|░|         |\n"
  "  |░|    ♠    |\n"
  "  +-|         |\n"
  "    |        K|\n"
  "    +---------+\n\n");
  Pile->addCard(D5);
  Pile->display();
  EXPECT_EQ(consoleDiscardDisplay.str(),
  "\n+---------+\n"
  "|░░░░░░░░░|\n"
  "|░+---------+\n"
  "|░|░░░░░░░░░|\n"
  "|░|░+---------+\n"
  "|░|░|K        |\n"
  "+-|░|         |\n"
  "  |░|    ♠    |\n"
  "  +-|         |\n"
  "    |        K|\n"
  "    +---------+\n\n"
  "\n+---------+\n"
  "|░░░░░░░░░|\n"
  "|░+---------+\n"
  "|░|░░░░░░░░░|\n"
  "|░|░+---------+\n"
  "|░|░|5        |\n"
  "+-|░|         |\n"
  "  |░|    ♦    |\n"
  "  +-|         |\n"
  "    |        5|\n"
  "    +---------+\n\n");
  Pile->addCard(C7);
  Pile->display();

  EXPECT_EQ(consoleDiscardDisplay.str(),
  "\n+---------+\n"
  "|░░░░░░░░░|\n"
  "|░+---------+\n"
  "|░|░░░░░░░░░|\n"
  "|░|░+---------+\n"
  "|░|░|K        |\n"
  "+-|░|         |\n"
  "  |░|    ♠    |\n"
  "  +-|         |\n"
  "    |        K|\n"
  "    +---------+\n\n"
  "\n+---------+\n"
  "|░░░░░░░░░|\n"
  "|░+---------+\n"
  "|░|░░░░░░░░░|\n"
  "|░|░+---------+\n"
  "|░|░|5        |\n"
  "+-|░|         |\n"
  "  |░|    ♦    |\n"
  "  +-|         |\n"
  "    |        5|\n"
  "    +---------+\n\n"
  "\n+---------+\n"
  "|░░░░░░░░░|\n"
  "|░+---------+\n"
  "|░|░░░░░░░░░|\n"
  "|░|░+---------+\n"
  "|░|░|7        |\n"
  "+-|░|         |\n"
  "  |░|    ♣    |\n"
  "  +-|         |\n"
  "    |        7|\n"
  "    +---------+\n\n");
  consoleDiscardDisplay.str(std::string());
  Pile->removeCard(S13);
  Pile->removeCard(D5);
  Pile->removeCard(C7);
  Pile->addCard(XOCY);
  Pile->display();
  EXPECT_EQ(consoleDiscardDisplay.str(), "Yellow XOutsideCircle\n");
  Pile->addCard(TLB);
  Pile->display();
  EXPECT_EQ(consoleDiscardDisplay.str(),
  "Yellow XOutsideCircle\nBlue TwoLoops\n");
  Pile->addCard(ECGG);
  Pile->display();
  EXPECT_EQ(consoleDiscardDisplay.str(),
  "Yellow XOutsideCircle\nBlue TwoLoops\nGreen EmptyCircleGrid\n");
  std::cout.rdbuf(sbuf);
  delete S13;
  delete D5;
  delete C7;
  delete Pile;
}

TEST(TestDiscard, testGetType) {
  Discard* Pile = new Discard();
  EXPECT_EQ(Pile->getType(), CardSet::DISCARD);
  delete Pile;
}

TEST(TestDiscard, testGetCard) {
  Discard* Pile = new Discard();
  StandardCard* S2 = new StandardCard(StandardCard::SPADES, 2);
  StandardCard* D10 = new StandardCard(StandardCard::DIAMONDS, 10);
  StandardCard* C7 = new StandardCard(StandardCard::CLUBS, 7);

  Pile->addCard(S2);
  Pile->addCard(D10);

  EXPECT_EQ(Pile->getCard(S2), S2);
  EXPECT_EQ(Pile->getCard(D10), D10);
  EXPECT_EQ(Pile->getCard(C7), nullptr);

  Pile->addCard(C7);

  EXPECT_EQ(Pile->getCard(C7), C7);

  StandardCard* temp1 = dynamic_cast<StandardCard*>(Pile->getTop());
  EXPECT_TRUE((temp1->getSuit() == 3) && (temp1->getValue() == 7));

  Pile->removeCard(S2);
  Pile->removeCard(D10);
  Pile->removeCard(C7);

  delete S2;
  delete D10;
  delete C7;

  JungleSpeedCard* ECGY =
  new JungleSpeedCard("EmptyCircleGrid", JungleSpeedCard::YELLOW);
  JungleSpeedCard* OCOB =
  new JungleSpeedCard("OctagonCircleOctagon", JungleSpeedCard::BLUE);
  JungleSpeedCard* CSCR =
  new JungleSpeedCard("CircleSquareCircle", JungleSpeedCard::RED);

  Pile->addCard(ECGY);
  Pile->addCard(OCOB);

  EXPECT_EQ(Pile->getCard(ECGY), ECGY);
  EXPECT_EQ(Pile->getCard(OCOB), OCOB);
  EXPECT_EQ(Pile->getCard(CSCR), nullptr);

  Pile->addCard(CSCR);

  EXPECT_EQ(Pile->getCard(CSCR), CSCR);

  JungleSpeedCard* temp2 = dynamic_cast<JungleSpeedCard*>(Pile->getTop());
  EXPECT_TRUE((temp2->getName() == "CircleSquareCircle") &&
  (temp2->getColour() == 1));

  delete Pile;
}

TEST(TestDiscard, testShuffleCardSet) {
  Discard* Pile1 = new Discard();
  Discard* Pile2 = new Discard();
  StandardCard* C11_1 = new StandardCard(StandardCard::CLUBS, 11);
  StandardCard* D11_1 = new StandardCard(StandardCard::DIAMONDS, 11);
  StandardCard* S10_1 = new StandardCard(StandardCard::SPADES, 10);

  Pile1->addCard(C11_1);
  Pile1->addCard(D11_1);
  Pile1->addCard(S10_1);

  StandardCard* C11_2 = new StandardCard(StandardCard::CLUBS, 11);
  StandardCard* D11_2 = new StandardCard(StandardCard::DIAMONDS, 11);
  StandardCard* S10_2 = new StandardCard(StandardCard::SPADES, 10);

  Pile2->addCard(C11_2);
  Pile2->addCard(D11_2);
  Pile2->addCard(S10_2);

  Pile2->shuffleCardSet();
  for (int i = 0; i < 3; i++) {
    StandardCard* temp1 = dynamic_cast<StandardCard*>(Pile1->getTop());
    StandardCard* temp2 = dynamic_cast<StandardCard*>(Pile2->getTop());
    EXPECT_TRUE((*temp1 == *temp2) || (!(*temp1 == *temp2)));
    Pile1->removeCard(temp1);
    Pile2->removeCard(temp2);
    delete temp1;
    delete temp2;
  }

  delete Pile1;
  delete Pile2;
}
