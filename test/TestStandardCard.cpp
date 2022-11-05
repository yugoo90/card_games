#include <vector>
#include <string>
#include <iostream>
#include "StandardCard.h"
#include "Card.h"
#include "gtest/gtest.h"


TEST(TestStandardCard, testStandardCardConstructor) {
  StandardCard* D1 = new StandardCard(StandardCard::DIAMONDS, 1);
  EXPECT_EQ(D1->getValue(), 1);
  EXPECT_EQ(D1->getSuit(), 1);
  delete D1;

  StandardCard* D2 = new StandardCard(StandardCard::DIAMONDS, 2);
  EXPECT_EQ(D2->getValue(), 2);
  EXPECT_EQ(D2->getSuit(), 1);
  delete D2;

  StandardCard* D3 = new StandardCard(StandardCard::DIAMONDS, 3);
  EXPECT_EQ(D3->getValue(), 3);
  EXPECT_EQ(D3->getSuit(), 1);
  delete D3;

  StandardCard* D4 = new StandardCard(StandardCard::DIAMONDS, 4);
  EXPECT_EQ(D4->getValue(), 4);
  EXPECT_EQ(D4->getSuit(), 1);
  delete D4;

  StandardCard* D5 = new StandardCard(StandardCard::DIAMONDS, 5);
  EXPECT_EQ(D5->getValue(), 5);
  EXPECT_EQ(D5->getSuit(), 1);
  delete D5;

  StandardCard* D6 = new StandardCard(StandardCard::DIAMONDS, 6);
  EXPECT_EQ(D6->getValue(), 6);
  EXPECT_EQ(D6->getSuit(), 1);
  delete D6;

  StandardCard* D7 = new StandardCard(StandardCard::DIAMONDS, 7);
  EXPECT_EQ(D7->getValue(), 7);
  EXPECT_EQ(D7->getSuit(), 1);
  delete D7;

  StandardCard* D8 = new StandardCard(StandardCard::DIAMONDS, 8);
  EXPECT_EQ(D8->getValue(), 8);
  EXPECT_EQ(D8->getSuit(), 1);
  delete D8;

  StandardCard* D9 = new StandardCard(StandardCard::DIAMONDS, 9);
  EXPECT_EQ(D9->getValue(), 9);
  EXPECT_EQ(D9->getSuit(), 1);
  delete D9;

  StandardCard* D10 = new StandardCard(StandardCard::DIAMONDS, 10);
  EXPECT_EQ(D10->getValue(), 10);
  EXPECT_EQ(D10->getSuit(), 1);
  delete D10;

  StandardCard* D11 = new StandardCard(StandardCard::DIAMONDS, 11);
  EXPECT_EQ(D11->getValue(), 11);
  EXPECT_EQ(D11->getSuit(), 1);
  delete D11;

  StandardCard* D12 = new StandardCard(StandardCard::DIAMONDS, 12);
  EXPECT_EQ(D12->getValue(), 12);
  EXPECT_EQ(D12->getSuit(), 1);
  delete D12;

  StandardCard* D13 = new StandardCard(StandardCard::DIAMONDS, 13);
  EXPECT_EQ(D13->getValue(), 13);
  EXPECT_EQ(D13->getSuit(), 1);
  delete D13;

  StandardCard* H1 = new StandardCard(StandardCard::HEARTS, 1);
  EXPECT_EQ(H1->getValue(), 1);
  EXPECT_EQ(H1->getSuit(), 2);
  delete H1;

  StandardCard* H2 = new StandardCard(StandardCard::HEARTS, 2);
  EXPECT_EQ(H2->getValue(), 2);
  EXPECT_EQ(H2->getSuit(), 2);
  delete H2;

  StandardCard* H3 = new StandardCard(StandardCard::HEARTS, 3);
  EXPECT_EQ(H3->getValue(), 3);
  EXPECT_EQ(H3->getSuit(), 2);
  delete H3;

  StandardCard* H4 = new StandardCard(StandardCard::HEARTS, 4);
  EXPECT_EQ(H4->getValue(), 4);
  EXPECT_EQ(H4->getSuit(), 2);
  delete H4;

  StandardCard* H5 = new StandardCard(StandardCard::HEARTS, 5);
  EXPECT_EQ(H5->getValue(), 5);
  EXPECT_EQ(H5->getSuit(), 2);
  delete H5;

  StandardCard* H6 = new StandardCard(StandardCard::HEARTS, 6);
  EXPECT_EQ(H6->getValue(), 6);
  EXPECT_EQ(H6->getSuit(), 2);
  delete H6;

  StandardCard* H7 = new StandardCard(StandardCard::HEARTS, 7);
  EXPECT_EQ(H7->getValue(), 7);
  EXPECT_EQ(H7->getSuit(), 2);
  delete H7;

  StandardCard* H8 = new StandardCard(StandardCard::HEARTS, 8);
  EXPECT_EQ(H8->getValue(), 8);
  EXPECT_EQ(H8->getSuit(), 2);
  delete H8;

  StandardCard* H9 = new StandardCard(StandardCard::HEARTS, 9);
  EXPECT_EQ(H9->getValue(), 9);
  EXPECT_EQ(H9->getSuit(), 2);
  delete H9;

  StandardCard* H10 = new StandardCard(StandardCard::HEARTS, 10);
  EXPECT_EQ(H10->getValue(), 10);
  EXPECT_EQ(H10->getSuit(), 2);
  delete H10;

  StandardCard* H11 = new StandardCard(StandardCard::HEARTS, 11);
  EXPECT_EQ(H11->getValue(), 11);
  EXPECT_EQ(H11->getSuit(), 2);
  delete H11;

  StandardCard* H12 = new StandardCard(StandardCard::HEARTS, 12);
  EXPECT_EQ(H12->getValue(), 12);
  EXPECT_EQ(H12->getSuit(), 2);
  delete H12;

  StandardCard* H13 = new StandardCard(StandardCard::HEARTS, 13);
  EXPECT_EQ(H13->getValue(), 13);
  EXPECT_EQ(H13->getSuit(), 2);
  delete H13;

  StandardCard* C1 = new StandardCard(StandardCard::CLUBS, 1);
  EXPECT_EQ(C1->getValue(), 1);
  EXPECT_EQ(C1->getSuit(), 3);
  delete C1;

  StandardCard* C2 = new StandardCard(StandardCard::CLUBS, 2);
  EXPECT_EQ(C2->getValue(), 2);
  EXPECT_EQ(C2->getSuit(), 3);
  delete C2;

  StandardCard* C3 = new StandardCard(StandardCard::CLUBS, 3);
  EXPECT_EQ(C3->getValue(), 3);
  EXPECT_EQ(C3->getSuit(), 3);
  delete C3;

  StandardCard* C4 = new StandardCard(StandardCard::CLUBS, 4);
  EXPECT_EQ(C4->getValue(), 4);
  EXPECT_EQ(C4->getSuit(), 3);
  delete C4;

  StandardCard* C5 = new StandardCard(StandardCard::CLUBS, 5);
  EXPECT_EQ(C5->getValue(), 5);
  EXPECT_EQ(C5->getSuit(), 3);
  delete C5;

  StandardCard* C6 = new StandardCard(StandardCard::CLUBS, 6);
  EXPECT_EQ(C6->getValue(), 6);
  EXPECT_EQ(C6->getSuit(), 3);
  delete C6;

  StandardCard* C7 = new StandardCard(StandardCard::CLUBS, 7);
  EXPECT_EQ(C7->getValue(), 7);
  EXPECT_EQ(C7->getSuit(), 3);
  delete C7;

  StandardCard* C8 = new StandardCard(StandardCard::CLUBS, 8);
  EXPECT_EQ(C8->getValue(), 8);
  EXPECT_EQ(C8->getSuit(), 3);
  delete C8;

  StandardCard* C9 = new StandardCard(StandardCard::CLUBS, 9);
  EXPECT_EQ(C9->getValue(), 9);
  EXPECT_EQ(C9->getSuit(), 3);
  delete C9;

  StandardCard* C10 = new StandardCard(StandardCard::CLUBS, 10);
  EXPECT_EQ(C10->getValue(), 10);
  EXPECT_EQ(C10->getSuit(), 3);
  delete C10;

  StandardCard* C11 = new StandardCard(StandardCard::CLUBS, 11);
  EXPECT_EQ(C11->getValue(), 11);
  EXPECT_EQ(C11->getSuit(), 3);
  delete C11;

  StandardCard* C12 = new StandardCard(StandardCard::CLUBS, 12);
  EXPECT_EQ(C12->getValue(), 12);
  EXPECT_EQ(C12->getSuit(), 3);
  delete C12;

  StandardCard* C13 = new StandardCard(StandardCard::CLUBS, 13);
  EXPECT_EQ(C13->getValue(), 13);
  EXPECT_EQ(C13->getSuit(), 3);
  delete C13;

  StandardCard* S1 = new StandardCard(StandardCard::SPADES, 1);
  EXPECT_EQ(S1->getValue(), 1);
  EXPECT_EQ(S1->getSuit(), 4);
  delete S1;

  StandardCard* S2 = new StandardCard(StandardCard::SPADES, 2);
  EXPECT_EQ(S2->getValue(), 2);
  EXPECT_EQ(S2->getSuit(), 4);
  delete S2;

  StandardCard* S3 = new StandardCard(StandardCard::SPADES, 3);
  EXPECT_EQ(S3->getValue(), 3);
  EXPECT_EQ(S3->getSuit(), 4);
  delete S3;

  StandardCard* S4 = new StandardCard(StandardCard::SPADES, 4);
  EXPECT_EQ(S4->getValue(), 4);
  EXPECT_EQ(S4->getSuit(), 4);
  delete S4;

  StandardCard* S5 = new StandardCard(StandardCard::SPADES, 5);
  EXPECT_EQ(S5->getValue(), 5);
  EXPECT_EQ(S5->getSuit(), 4);
  delete S5;

  StandardCard* S6 = new StandardCard(StandardCard::SPADES, 6);
  EXPECT_EQ(S6->getValue(), 6);
  EXPECT_EQ(S6->getSuit(), 4);
  delete S6;

  StandardCard* S7 = new StandardCard(StandardCard::SPADES, 7);
  EXPECT_EQ(S7->getValue(), 7);
  EXPECT_EQ(S7->getSuit(), 4);
  delete S7;

  StandardCard* S8 = new StandardCard(StandardCard::SPADES, 8);
  EXPECT_EQ(S8->getValue(), 8);
  EXPECT_EQ(S8->getSuit(), 4);
  delete S8;

  StandardCard* S9 = new StandardCard(StandardCard::SPADES, 9);
  EXPECT_EQ(S9->getValue(), 9);
  EXPECT_EQ(S9->getSuit(), 4);
  delete S9;

  StandardCard* S10 = new StandardCard(StandardCard::SPADES, 10);
  EXPECT_EQ(S10->getValue(), 10);
  EXPECT_EQ(S10->getSuit(), 4);
  delete S10;

  StandardCard* S11 = new StandardCard(StandardCard::SPADES, 11);
  EXPECT_EQ(S11->getValue(), 11);
  EXPECT_EQ(S11->getSuit(), 4);
  delete S11;

  StandardCard* S12 = new StandardCard(StandardCard::SPADES, 12);
  EXPECT_EQ(S12->getValue(), 12);
  EXPECT_EQ(S12->getSuit(), 4);
  delete S12;

  StandardCard* S13 = new StandardCard(StandardCard::SPADES, 13);
  EXPECT_EQ(S13->getValue(), 13);
  EXPECT_EQ(S13->getSuit(), 4);
  delete S13;
}

TEST(TestStandardCard, testSetValue) {
  StandardCard* Card = new StandardCard(StandardCard::DIAMONDS, 1);
  EXPECT_EQ(Card->getValue(), 1);
  Card->setValue(2);
  EXPECT_EQ(Card->getValue(), 2);
  Card->setValue(3);
  EXPECT_EQ(Card->getValue(), 3);
  Card->setValue(4);
  EXPECT_EQ(Card->getValue(), 4);
  Card->setValue(5);
  EXPECT_EQ(Card->getValue(), 5);
  Card->setValue(6);
  EXPECT_EQ(Card->getValue(), 6);
  Card->setValue(7);
  EXPECT_EQ(Card->getValue(), 7);
  Card->setValue(8);
  EXPECT_EQ(Card->getValue(), 8);
  Card->setValue(9);
  EXPECT_EQ(Card->getValue(), 9);
  Card->setValue(10);
  EXPECT_EQ(Card->getValue(), 10);
  Card->setValue(11);
  EXPECT_EQ(Card->getValue(), 11);
  Card->setValue(12);
  EXPECT_EQ(Card->getValue(), 12);
  Card->setValue(13);
  EXPECT_EQ(Card->getValue(), 13);
  Card->setValue(1);
  EXPECT_EQ(Card->getValue(), 1);
  delete Card;
}

TEST(TestStandardCard, testSetSuit) {
  StandardCard* Card = new StandardCard(StandardCard::DIAMONDS, 1);
  EXPECT_EQ(Card->getSuit(), 1);
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->getSuit(), 2);
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->getSuit(), 3);
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->getSuit(), 4);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->getSuit(), 1);
  delete Card;
}

TEST(TestStandardCard, testSetValueAndSetSuit) {
  StandardCard* Card = new StandardCard(StandardCard::DIAMONDS, 1);
  EXPECT_EQ(Card->getValue(), 1);
  EXPECT_EQ(Card->getSuit(), 1);
  Card->setValue(12);
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->getValue(), 12);
  EXPECT_EQ(Card->getSuit(), 3);
  Card->setSuit(StandardCard::SPADES);
  Card->setValue(5);
  EXPECT_EQ(Card->getValue(), 5);
  EXPECT_EQ(Card->getSuit(), 4);
  delete Card;
}

TEST(TestStandardCard, testStringOfWholeCard) {
  StandardCard* Card = new StandardCard(StandardCard::DIAMONDS, 1);
  EXPECT_EQ(Card->stringOfWholeCard(), "Ace of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "Ace of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "Ace of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "Ace of Spades");
  Card->setValue(2);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->stringOfWholeCard(), "2 of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "2 of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "2 of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "2 of Spades");
  Card->setValue(3);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->stringOfWholeCard(), "3 of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "3 of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "3 of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "3 of Spades");
  Card->setValue(4);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->stringOfWholeCard(), "4 of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "4 of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "4 of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "4 of Spades");
  Card->setValue(5);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->stringOfWholeCard(), "5 of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "5 of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "5 of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "5 of Spades");
  Card->setValue(6);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->stringOfWholeCard(), "6 of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "6 of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "6 of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "6 of Spades");
  Card->setValue(7);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->stringOfWholeCard(), "7 of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "7 of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "7 of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "7 of Spades");
  Card->setValue(8);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->stringOfWholeCard(), "8 of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "8 of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "8 of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "8 of Spades");
  Card->setValue(9);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->stringOfWholeCard(), "9 of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "9 of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "9 of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "9 of Spades");
  Card->setValue(10);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->stringOfWholeCard(), "10 of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "10 of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "10 of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "10 of Spades");
  Card->setValue(11);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->stringOfWholeCard(), "Jack of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "Jack of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "Jack of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "Jack of Spades");
  Card->setValue(12);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->stringOfWholeCard(), "Queen of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "Queen of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "Queen of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "Queen of Spades");
  Card->setValue(13);
  Card->setSuit(StandardCard::DIAMONDS);
  EXPECT_EQ(Card->stringOfWholeCard(), "King of Diamonds");
  Card->setSuit(StandardCard::HEARTS);
  EXPECT_EQ(Card->stringOfWholeCard(), "King of Hearts");
  Card->setSuit(StandardCard::CLUBS);
  EXPECT_EQ(Card->stringOfWholeCard(), "King of Clubs");
  Card->setSuit(StandardCard::SPADES);
  EXPECT_EQ(Card->stringOfWholeCard(), "King of Spades");
  delete Card;
}

TEST(TestStandardCard, testSuitToString) {
  StandardCard* Card = new StandardCard(StandardCard::DIAMONDS, 1);
  EXPECT_EQ(Card->suitToString(StandardCard::DIAMONDS), "Diamonds");
  EXPECT_EQ(Card->suitToString(StandardCard::HEARTS), "Hearts");
  EXPECT_EQ(Card->suitToString(StandardCard::CLUBS), "Clubs");
  EXPECT_EQ(Card->suitToString(StandardCard::SPADES), "Spades");
  delete Card;
}

TEST(TestStandardCard, testDisplayCard) {
  std::stringstream consoleCardDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleCardDisplay.rdbuf());
  StandardCard* Card = new StandardCard(StandardCard::DIAMONDS, 1);
  Card->displayCard();
  EXPECT_EQ(consoleCardDisplay.str(), "Ace of Diamonds");
  std::cout.rdbuf(sbuf);
  delete Card;
}

TEST(TestStandardCard, testGetType) {
  StandardCard* Card = new StandardCard(StandardCard::DIAMONDS, 1);
  EXPECT_EQ(Card->getType(), Card::STANDARD);
  delete Card;
}

TEST(TestStandardCard, testEqualsEqualsOperator) {
  StandardCard H12_1(StandardCard::HEARTS, 12);
  StandardCard H12_2(StandardCard::HEARTS, 12);
  EXPECT_TRUE(H12_1 == H12_2);
  EXPECT_TRUE(H12_1 == H12_1);
  EXPECT_TRUE(H12_2 == H12_2);
  StandardCard C10(StandardCard::CLUBS, 10);
  EXPECT_FALSE(H12_1 == C10);
  EXPECT_FALSE(H12_2 == C10);
  EXPECT_TRUE(C10 == C10);
  StandardCard H7(StandardCard::HEARTS, 7);
  EXPECT_FALSE(H12_1 == H7);
  EXPECT_FALSE(H12_2 == H7);
  EXPECT_FALSE(C10 == H7);
  EXPECT_TRUE(H7 == H7);
}
