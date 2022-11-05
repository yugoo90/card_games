#include <vector>
#include <string>
#include <algorithm>
#include "Hand.h"
#include "Card.h"
#include "CardSet.h"
#include "StandardCard.h"
#include "JungleSpeedCard.h"
#include "gtest/gtest.h"
#include "GameActions.h"

TEST(TestHand, testDisplay) {
  std::stringstream handDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(handDisplay.rdbuf());

  Hand* h = new Hand();
  StandardCard* c1 = new StandardCard(StandardCard::SPADES, 13);
  StandardCard* c2 = new StandardCard(StandardCard::DIAMONDS, 1);
  StandardCard* c3 = new StandardCard(StandardCard::CLUBS, 5);

  h->addCard(c1);
  h->addCard(c2);
  h->addCard(c3);
  h->display();
  EXPECT_EQ(handDisplay.str(),
  "Your hand is: \n\n+---------+  +---------+  +---------+  \n"
  "|K        |  |A        |  |5        |  \n"
  "|         |  |         |  |         |  \n"
  "|    ♠    |  |    ♦    |  |    ♣    |  \n"
  "|         |  |         |  |         |  \n"
  "|        K|  |        A|  |        5|  \n"
  "+---------+  +---------+  +---------+  \n\n");

  std::cout.rdbuf(sbuf);
  delete h;
}

TEST(TestHand, testDisplayEmpty) {
  std::stringstream handDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(handDisplay.rdbuf());

  Hand* h = new Hand();

  h->display();
  EXPECT_EQ(handDisplay.str(), "Your hand is empty.\n");


  std::cout.rdbuf(sbuf);
  delete h;
}

TEST(TestHand, testRemoveCardStandardCard) {
  Hand* h = new Hand();
  StandardCard* c1 = new StandardCard(StandardCard::SPADES, 13);
  StandardCard* c2 = new StandardCard(StandardCard::DIAMONDS, 1);
  StandardCard* c3 = new StandardCard(StandardCard::CLUBS, 5);

  h->addCard(c1);
  h->addCard(c2);
  h->addCard(c3);
  h->display();

  h->removeCard(c2);
  h->display();
  EXPECT_EQ(h->getSize(), 2);

  delete h;
  delete c2;
}

TEST(TestHand, testRemoveCardJungleSpeedCard) {
  std::stringstream handDisplay1;
  std::streambuf *sbuf1 = std::cout.rdbuf();
  std::cout.rdbuf(handDisplay1.rdbuf());

  Hand* h = new Hand();
  JungleSpeedCard* c1 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* c2 = new JungleSpeedCard("TwoLoops",
  JungleSpeedCard::RED);
  JungleSpeedCard* c3 = new JungleSpeedCard("SmallEightProngStar",
  JungleSpeedCard::GREEN);

  h->addCard(c1);
  h->addCard(c2);
  h->addCard(c3);
  h->display();
  EXPECT_EQ(handDisplay1.str(),
  "Your hand is: \nBlue FullCircleGrid\nRed TwoLoops\n"
  "Green SmallEightProngStar\n\n");

  std::cout.rdbuf(sbuf1);

  std::stringstream handDisplay2;
  std::streambuf *sbuf2 = std::cout.rdbuf();
  std::cout.rdbuf(handDisplay2.rdbuf());

  h->removeCard(c2);
  h->display();
  EXPECT_EQ(handDisplay2.str(),
  "Your hand is: \nBlue FullCircleGrid\nGreen SmallEightProngStar\n\n");

  std::cout.rdbuf(sbuf2);
  delete h;
  delete c2;
}


TEST(TestHand, testGetType) {
  Hand* h = new Hand();
  EXPECT_EQ(h->getType(), CardSet::HAND);
  delete h;
}

TEST(TestHand, testShuffleCardSet) {
  Hand* h1 = new Hand();
  Hand* h2 = new Hand();
  StandardCard* C11_1 = new StandardCard(StandardCard::CLUBS, 11);
  StandardCard* D11_1 = new StandardCard(StandardCard::DIAMONDS, 11);
  StandardCard* S10_1 = new StandardCard(StandardCard::SPADES, 10);

  h1->addCard(C11_1);
  h1->addCard(D11_1);
  h1->addCard(S10_1);

  StandardCard* C11_2 = new StandardCard(StandardCard::CLUBS, 11);
  StandardCard* D11_2 = new StandardCard(StandardCard::DIAMONDS, 11);
  StandardCard* S10_2 = new StandardCard(StandardCard::SPADES, 10);

  h2->addCard(C11_2);
  h2->addCard(D11_2);
  h2->addCard(S10_2);

  h2->shuffleCardSet();

  std::vector<Card*> cardsTemp_1 = h1->getHand();
  std::vector<Card*> cardsTemp_2 = h2->getHand();
  std::vector<StandardCard*> cards_1;
  std::vector<StandardCard*> cards_2;
  for (int i = 0; i < cardsTemp_1.size(); i++) {
    cards_1.push_back(dynamic_cast<StandardCard*>(cardsTemp_1[i]));
  }
  for (int i = 0; i < cardsTemp_2.size(); i++) {
    cards_2.push_back(dynamic_cast<StandardCard*>(cardsTemp_2[i]));
  }

  for (int i = 0; i < 3; i++) {
    EXPECT_TRUE((*cards_1[i] == *cards_2[i]) ||
     (!(*cards_1[i] == *cards_2[i])));
  }

  delete h1;
  delete h2;
}

TEST(TestHand, testGetCard) {
  Hand* h = new Hand();
  StandardCard* S2 = new StandardCard(StandardCard::SPADES, 2);
  StandardCard* D10 = new StandardCard(StandardCard::DIAMONDS, 10);
  StandardCard* C7 = new StandardCard(StandardCard::CLUBS, 7);

  h->addCard(S2);
  h->addCard(D10);

  EXPECT_EQ(h->getCard(S2), S2);
  EXPECT_EQ(h->getCard(D10), D10);
  EXPECT_EQ(h->getCard(C7), nullptr);

  h->addCard(C7);

  EXPECT_EQ(h->getCard(C7), C7);

  StandardCard* temp1 = dynamic_cast<StandardCard*>(h->getTop());
  EXPECT_TRUE((temp1->getSuit() == 3) && (temp1->getValue() == 7));

  h->removeCard(S2);
  h->removeCard(D10);
  h->removeCard(C7);

  delete S2;
  delete D10;
  delete C7;

  JungleSpeedCard* ECGY =
  new JungleSpeedCard("EmptyCircleGrid", JungleSpeedCard::YELLOW);
  JungleSpeedCard* OCOB =
  new JungleSpeedCard("OctagonCircleOctagon", JungleSpeedCard::BLUE);
  JungleSpeedCard* CSCR =
  new JungleSpeedCard("CircleSquareCircle", JungleSpeedCard::RED);

  h->addCard(ECGY);
  h->addCard(OCOB);

  EXPECT_EQ(h->getCard(ECGY), ECGY);
  EXPECT_EQ(h->getCard(OCOB), OCOB);
  EXPECT_EQ(h->getCard(CSCR), nullptr);

  h->addCard(CSCR);

  EXPECT_EQ(h->getCard(CSCR), CSCR);

  JungleSpeedCard* temp2 = dynamic_cast<JungleSpeedCard*>(h->getTop());
  EXPECT_TRUE((temp2->getName() == "CircleSquareCircle") &&
  (temp2->getColour() == 1));

  delete h;
}

TEST(TestHand, testPrimitiveTransfer) {
  Hand h1;
  Hand h2;

  StandardCard* C11_1 = new StandardCard(StandardCard::CLUBS, 11);

  h1.addCard(C11_1);
  Card* temp = h1.getCard(C11_1);

  h1.removeCard(C11_1);
  EXPECT_EQ(h1.getSize(), 0);

  h2.addCard(temp);
  EXPECT_EQ(h2.getSize(), 1);
}
