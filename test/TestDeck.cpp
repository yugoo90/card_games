#include <algorithm>
#include "Deck.h"
#include "Card.h"
#include "CardSet.h"
#include "gtest/gtest.h"
#include "StandardCard.h"
#include "DeckGenerator.h"
#include "JungleSpeedCard.h"


TEST(TestDeck, DefaultDeckConstructor) {
  Deck* d = new Deck();
  EXPECT_EQ(d->getSize(), 0);
  delete d;
}

TEST(TestDeck, DeckConstructor) {
  Deck* d = new Deck();
  StandardCard* c1 = new StandardCard(StandardCard::DIAMONDS, 1);
  d-> addCard(c1);
  StandardCard* c2 = new StandardCard(StandardCard::DIAMONDS, 2);
  d-> addCard(c2);
  StandardCard* c3 = new StandardCard(StandardCard::DIAMONDS, 3);
  d-> addCard(c3);

  StandardCard* temp = dynamic_cast<StandardCard*>(d->getTop());
  EXPECT_TRUE((temp->getSuit() == 1) && (temp->getValue() == 3));

  EXPECT_EQ(d-> getSize(), 3);
  delete d;
}

TEST(TestDeck, testDeckConstructorWithGenerator) {
  DeckGenerator gd;
  Deck* d = gd.makeDeck(Game::GOFISH);
  EXPECT_EQ(d->getSize(), 52);
  StandardCard* temp = dynamic_cast<StandardCard*>(d->getTop());
  EXPECT_TRUE((temp->getSuit() == 4) && (temp->getValue() == 13));
  delete d;
}

TEST(TestDeck, testShuffleCardSet) {
  DeckGenerator gd;
  Deck* d1 = gd.makeDeck(Game::GOFISH);
  Deck* d2 = gd.makeDeck(Game::GOFISH);
  d2->shuffleCardSet();
  for (int i = 0; i < 52; i++) {
    StandardCard* temp1 = dynamic_cast<StandardCard*>(d1->getTop());
    StandardCard* temp2 = dynamic_cast<StandardCard*>(d2->getTop());
    EXPECT_TRUE((*temp1 == *temp2) || (!(*temp1 == *temp2)));
    d1->removeCard(temp1);
    d2->removeCard(temp2);
    delete temp1;
    delete temp2;
  }
  delete d1;
  delete d2;
}

TEST(TestDeck, testGetType) {
  Deck* d = new Deck();
  EXPECT_EQ(d->getType(), CardSet::DECK);
  delete d;
}

TEST(TestDeck, testGetCard) {
  Deck* d = new Deck();
  StandardCard* S2 = new StandardCard(StandardCard::SPADES, 2);
  StandardCard* D10 = new StandardCard(StandardCard::DIAMONDS, 10);
  StandardCard* C7 = new StandardCard(StandardCard::CLUBS, 7);

  d->addCard(S2);
  d->addCard(D10);

  EXPECT_EQ(d->getCard(S2), S2);
  EXPECT_EQ(d->getCard(D10), D10);
  EXPECT_EQ(d->getCard(C7), nullptr);

  d->addCard(C7);

  EXPECT_EQ(d->getCard(C7), C7);

  StandardCard* temp1 = dynamic_cast<StandardCard*>(d->getTop());
  EXPECT_TRUE((temp1->getSuit() == 3) && (temp1->getValue() == 7));

  d->removeCard(S2);
  d->removeCard(D10);
  d->removeCard(C7);

  delete S2;
  delete D10;
  delete C7;

  JungleSpeedCard* ECGY =
  new JungleSpeedCard("EmptyCircleGrid", JungleSpeedCard::YELLOW);
  JungleSpeedCard* OCOB =
  new JungleSpeedCard("OctagonCircleOctagon", JungleSpeedCard::BLUE);
  JungleSpeedCard* CSCR =
  new JungleSpeedCard("CircleSquareCircle", JungleSpeedCard::RED);

  d->addCard(ECGY);
  d->addCard(OCOB);

  EXPECT_EQ(d->getCard(ECGY), ECGY);
  EXPECT_EQ(d->getCard(OCOB), OCOB);
  EXPECT_EQ(d->getCard(CSCR), nullptr);

  d->addCard(CSCR);

  EXPECT_EQ(d->getCard(CSCR), CSCR);

  JungleSpeedCard* temp2 = dynamic_cast<JungleSpeedCard*>(d->getTop());
  EXPECT_TRUE((temp2->getName() == "CircleSquareCircle") &&
  (temp2->getColour() == 1));

  delete d;
}
