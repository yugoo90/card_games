#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GoFish.h"
#include "Game.h"
#include "Player.h"
#include "GoFishAI.h"
#include "Card.h"
#include "AI.h"
#include "Human.h"
#include "gtest/gtest.h"

TEST(TestGoFish, testGoFishConstructor) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  EXPECT_EQ(G.getNumPlayers(), 4);
  EXPECT_EQ(G.getNumDecks(), 1);
  EXPECT_EQ(G.getPlayers(), P);
}

TEST(TestGoFish, testPrintScore) {
  std::stringstream consoleScoreDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleScoreDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  H1->setRoundPoints(34);
  A1->setRoundPoints(23);
  A2->setRoundPoints(5);
  A3->setRoundPoints(143);
  G.printScore();
  EXPECT_EQ(consoleScoreDisplay.str(),
  "      GAME OVER.\n\nYour score for this round is: 34\nAI 1's score is: 23\n"
  "AI 2's score is: 5\nAI 3's score is: 143\n\n");
  std::cout.rdbuf(sbuf);
}

TEST(TestGoFish, testPrintWinnerHuman) {
  std::stringstream consoleScoreDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleScoreDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  H1->setRoundPoints(475);
  A1->setRoundPoints(4);
  A2->setRoundPoints(256);
  A3->setRoundPoints(17);
  H1->setTotalPoints();
  A1->setTotalPoints();
  A2->setTotalPoints();
  A3->setTotalPoints();
  H1->setRoundPoints(6);
  A1->setRoundPoints(78);
  A2->setRoundPoints(90);
  A3->setRoundPoints(255);
  H1->setTotalPoints();
  A1->setTotalPoints();
  A2->setTotalPoints();
  A3->setTotalPoints();
  G.printWinner();
  EXPECT_EQ(consoleScoreDisplay.str(),
  "Your total score is: 481\nAI 1's total score is: 82\nAI 2's total score is: "
  "346\nAI 3's total score is: 272\n\nYou won the game with 481 "
  "points.\nCongrats!! Good game H1!!\n");
  std::cout.rdbuf(sbuf);
}

TEST(TestGoFish, testPrintWinnerAI) {
  std::stringstream consoleScoreDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleScoreDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  H1->setRoundPoints(5);
  A1->setRoundPoints(88);
  A2->setRoundPoints(2433);
  A3->setRoundPoints(37);
  H1->setTotalPoints();
  A1->setTotalPoints();
  A2->setTotalPoints();
  A3->setTotalPoints();
  H1->setRoundPoints(7);
  A1->setRoundPoints(55);
  A2->setRoundPoints(5677);
  A3->setRoundPoints(99);
  H1->setTotalPoints();
  A1->setTotalPoints();
  A2->setTotalPoints();
  A3->setTotalPoints();
  G.printWinner();
  EXPECT_EQ(consoleScoreDisplay.str(),
  "Your total score is: 12\nAI 1's total score is: 143\nAI 2's total score is: "
  "8110\nAI 3's total score is: 136\n\nAI 2 won the game with 8110 "
  "points.\nBetter luck next time H1!\n");
  std::cout.rdbuf(sbuf);
}

TEST(TestGoFish, testPrintWinnerTieWithHuman) {
  std::stringstream consoleScoreDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleScoreDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  H1->setRoundPoints(88);
  A1->setRoundPoints(88);
  A2->setRoundPoints(88);
  A3->setRoundPoints(37);
  H1->setTotalPoints();
  A1->setTotalPoints();
  A2->setTotalPoints();
  A3->setTotalPoints();
  G.printWinner();
  EXPECT_EQ(consoleScoreDisplay.str(),
  "Your total score is: 88\nAI 1's total score is: 88\nAI 2's total score is: "
  "88\nAI 3's total score is: 37\n\nThere was a tie between you and AI 1 and "
  "AI 2 with 88 points.\nCongrats!! Good game H1!!\n");
  std::cout.rdbuf(sbuf);
}

TEST(TestGoFish, testPrintWinnerTieWithoutHuman) {
  std::stringstream consoleScoreDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleScoreDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  H1->setRoundPoints(5);
  A1->setRoundPoints(88);
  A2->setRoundPoints(88);
  A3->setRoundPoints(37);
  H1->setTotalPoints();
  A1->setTotalPoints();
  A2->setTotalPoints();
  A3->setTotalPoints();
  G.printWinner();
  EXPECT_EQ(consoleScoreDisplay.str(),
  "Your total score is: 5\nAI 1's total score is: 88\nAI 2's total score is: "
  "88\nAI 3's total score is: 37\n\nThere was a tie between AI 1 and AI 2"
  " with 88 points.\nBetter luck next time H1!\n");
  std::cout.rdbuf(sbuf);
}

TEST(TestGoFish, testDealCards) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  G.dealCards(7);
  EXPECT_EQ(H1->hand.getSize(), 7);
  EXPECT_EQ(A1->hand.getSize(), 7);
  EXPECT_EQ(A2->hand.getSize(), 7);
  EXPECT_EQ(A3->hand.getSize(), 7);
}

TEST(TestGoFishAI, testTransferCardsHandToHand) {
  Player* ai1 = new GoFishAI(AI::EASY, 1);
  Player* ai2 = new GoFishAI(AI::NORMAL, 2);
  Player* ai3 = new GoFishAI(AI::HARD, 3);

  Card* c1 = new StandardCard(StandardCard::SPADES, 13);
  Card* c2 = new StandardCard(StandardCard::DIAMONDS, 1);
  Card* c3 = new StandardCard(StandardCard::CLUBS, 5);

  std::vector<Player*> v;
  v.push_back(ai1);
  v.push_back(ai2);
  v.push_back(ai3);

  Game* g = new GoFish(1, v);

  ai1->hand.addCard(c1);
  ai1->hand.addCard(c2);
  ai1->hand.addCard(c3);
  g->transferCards(&(ai1->hand), &(ai2->hand), c1);

  EXPECT_EQ(ai1->hand.getSize(), 2);
  EXPECT_EQ(ai2->hand.getSize(), 1);
  EXPECT_EQ(ai3->hand.getSize(), 0);
  delete g;
}

TEST(TestGoFish, testResetGame) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  for (int i = 0; i < 52; i++) {
  }
  G.makeBook(1);
  G.makeBook(2);
  G.makeBook(3);
  G.makeBook(4);
  G.makeBook(5);
  G.makeBook(6);
  G.makeBook(7);
  G.makeBook(8);
  G.makeBook(9);
  G.makeBook(10);
  G.makeBook(11);
  G.makeBook(12);
  G.makeBook(13);
  H1->setRoundPoints(348);
  A1->setRoundPoints(120);
  A2->setRoundPoints(3);
  A3->setRoundPoints(986);
  G.resetGame();
  EXPECT_EQ(H1->getRoundPoints(), 0);
  EXPECT_EQ(A1->getRoundPoints(), 0);
  EXPECT_EQ(A2->getRoundPoints(), 0);
  EXPECT_EQ(A3->getRoundPoints(), 0);
}

TEST(TestGoFish, testPrintRules) {
  std::stringstream consoleScoreDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleScoreDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  G.printRules();
  EXPECT_EQ(consoleScoreDisplay.str(),
  "RULES FOR GOFISH:\nEach player is dealt 7 cards, with the remaining cards "
  "placed in the deck. \nWhen it is your turn you may choose an opponent "
  "for a card. \nThe requested card must have the same rank as a card in your "
  "hand. \nIf the opponent has the card in their hand, they will give all of "
  "their cards of that rank. \nAfter an affirmative request you may make "
  "another request. \nIf the opponent does not have the card in their hand, "
  "they will tell you to GoFish. \nIf the opponent says GoFish, draw a card "
  "from the stockpile. \nIf you have no cards in your hand, you may draw from "
  "the stockpile and make a request based on the card you drew. \nThe players "
  "turn ends after they are told to GoFish. \nA book will be made automatically"
  " when there are 4 cards of the same rank in a players hand. \nThe game ends "
  "when all 13 books have been made. \nThe winner is the player with the most "
  "books. \nAfter the game is over the player will be given the option to play "
  "another game or to quit. \n\n");
  std::cout.rdbuf(sbuf);
}

TEST(TestGoFish, testPreGame) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  G.preGame();
  EXPECT_EQ(H1->hand.getSize(), 7);
  EXPECT_EQ(A1->hand.getSize(), 7);
  EXPECT_EQ(A2->hand.getSize(), 7);
  EXPECT_EQ(A3->hand.getSize(), 7);
}

TEST(TestGoFish, testRoundAIWins) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  GoFish G(1, P);

  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 13);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 13);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 13);
  Card* S3 = new StandardCard(StandardCard::SPADES, 3);

  A1->hand.addCard(D2);
  A1->hand.addCard(H2);
  A1->hand.addCard(C2);
  H1->hand.addCard(S3);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "3" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.makeBook(1);
  G.makeBook(2);
  G.makeBook(3);
  G.makeBook(4);
  G.makeBook(5);
  G.makeBook(6);
  G.makeBook(7);
  G.makeBook(8);
  G.makeBook(9);
  G.makeBook(10);
  G.makeBook(11);
  G.makeBook(12);

  G.round(inputStream);
  inputStream.close();
  EXPECT_TRUE(G.gameOver);
}

TEST(TestGoFish, testRoundHumanWins) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  GoFish G(1, P);

  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 13);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 13);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 13);
  Card* S2 = new StandardCard(StandardCard::SPADES, 13);
  Card* S3 = new StandardCard(StandardCard::SPADES, 3);

  A1->hand.addCard(D2);
  A1->hand.addCard(H2);
  A1->hand.addCard(C2);
  H1->hand.addCard(S2);
  H1->hand.addCard(S3);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "k" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.makeBook(1);
  G.makeBook(2);
  G.makeBook(3);
  G.makeBook(4);
  G.makeBook(5);
  G.makeBook(6);
  G.makeBook(7);
  G.makeBook(8);
  G.makeBook(9);
  G.makeBook(10);
  G.makeBook(11);
  G.makeBook(12);

  G.round(inputStream);
  inputStream.close();
  EXPECT_TRUE(G.gameOver);
}

TEST(TestGoFish, testGoFish) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);;
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  A1->setMyTurn(true);
  G.goFish();
  EXPECT_EQ(A1->hand.getSize(), 1);
}

TEST(TestGoFish, testMakeBook) {
  std::stringstream consoleScoreDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleScoreDisplay.rdbuf());
  std::vector<Player*> P;
  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 2);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 2);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 2);
  Card* S2 = new StandardCard(StandardCard::SPADES, 2);
  Player* H1 = new Human("H1", 0);
  H1->hand.addCard(D2);
  H1->hand.addCard(H2);
  H1->hand.addCard(C2);
  H1->hand.addCard(S2);
  P.push_back(H1);
  Card* D3 = new StandardCard(StandardCard::DIAMONDS, 3);
  Card* H3 = new StandardCard(StandardCard::HEARTS, 3);
  Card* C3 = new StandardCard(StandardCard::CLUBS, 3);
  Card* S3 = new StandardCard(StandardCard::SPADES, 3);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  A1->hand.addCard(D3);
  A1->hand.addCard(H3);
  A1->hand.addCard(C3);
  A1->hand.addCard(S3);
  P.push_back(A1);
  Card* D4 = new StandardCard(StandardCard::DIAMONDS, 4);
  Card* H4 = new StandardCard(StandardCard::HEARTS, 4);
  Card* C4 = new StandardCard(StandardCard::CLUBS, 4);
  Card* S4 = new StandardCard(StandardCard::SPADES, 4);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  A2->hand.addCard(D4);
  A2->hand.addCard(H4);
  A2->hand.addCard(C4);
  A2->hand.addCard(S4);
  P.push_back(A2);
  Card* D5 = new StandardCard(StandardCard::DIAMONDS, 5);
  Card* H5 = new StandardCard(StandardCard::HEARTS, 5);
  Card* C5 = new StandardCard(StandardCard::CLUBS, 5);
  Card* S5 = new StandardCard(StandardCard::SPADES, 5);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  A3->hand.addCard(D5);
  A3->hand.addCard(H5);
  A3->hand.addCard(C5);
  A3->hand.addCard(S5);
  P.push_back(A3);
  GoFish G(1, P);
  H1->setMyTurn(true);
  G.makeBook(2);
  EXPECT_EQ(consoleScoreDisplay.str(),
  "You made a book of 2's\n\n");
  std::cout.rdbuf(sbuf);
}

TEST(TestGoFish, testMakeBookGameOver) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  EXPECT_EQ(G.gameOver, false);
  G.makeBook(1);
  G.makeBook(2);
  G.makeBook(3);
  G.makeBook(4);
  G.makeBook(5);
  G.makeBook(6);
  G.makeBook(7);
  G.makeBook(8);
  G.makeBook(9);
  G.makeBook(10);
  G.makeBook(11);
  G.makeBook(12);
  G.makeBook(13);
  EXPECT_EQ(G.gameOver, true);
}

TEST(TestGoFish, testRequestHandlerGoFish) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  std::vector<Card*> Cards;
  A1->setMyTurn(true);
  G.requestHandler(A1, H1, Cards);
  EXPECT_EQ(A1->hand.getSize(), 1);
  EXPECT_FALSE(A1->getMyTurn());
}

TEST(TestGoFish, testRequestHandlerGoFishWithBook) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  std::vector<Card*> Cards;
  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 13);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 13);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 13);
  A1->hand.addCard(D2);
  A1->hand.addCard(H2);
  A1->hand.addCard(C2);
  A1->setMyTurn(true);
  G.requestHandler(A1, H1, Cards);
  EXPECT_EQ(A1->hand.getSize(), 0);
  EXPECT_FALSE(A1->getMyTurn());
}

TEST(TestGoFish, testRequestHandlerEmptyDeck) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  G.dealCards(13);
  std::vector<Card*> Cards;
  A1->setMyTurn(true);
  G.requestHandler(A1, H1, Cards);
  EXPECT_EQ(A1->hand.getSize(), 13);
  EXPECT_FALSE(A1->getMyTurn());
}

TEST(TestGoFish, testRequestHandlerWithBook) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  std::vector<Card*> Cards;
  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 2);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 2);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 2);
  Card* S2 = new StandardCard(StandardCard::SPADES, 2);

  H1->hand.addCard(D2);
  H1->hand.addCard(H2);
  H1->hand.addCard(C2);
  A1->hand.addCard(S2);

  Cards.push_back(D2);
  Cards.push_back(H2);
  Cards.push_back(C2);

  A1->setMyTurn(true);
  G.requestHandler(A1, H1, Cards);
  EXPECT_EQ(A1->hand.getSize(), 0);
  EXPECT_EQ(H1->hand.getSize(), 0);
  EXPECT_TRUE(A1->getMyTurn());
}

TEST(TestGoFish, testHasBookTrue) {
  std::vector<Player*> P;
  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 2);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 2);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 2);
  Card* S2 = new StandardCard(StandardCard::SPADES, 2);
  Player* H1 = new Human("H1", 0);
  H1->hand.addCard(D2);
  H1->hand.addCard(H2);
  H1->hand.addCard(C2);
  H1->hand.addCard(S2);
  P.push_back(H1);
  Card* S8 = new StandardCard(StandardCard::SPADES, 8);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  A1->hand.addCard(S8);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  EXPECT_EQ(G.hasBook(H1), 2);
}

TEST(TestGoFish, testHasBookFalse) {
  std::vector<Player*> P;
  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 2);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 2);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 2);
  Card* S2 = new StandardCard(StandardCard::SPADES, 2);
  Player* H1 = new Human("H1", 0);
  H1->hand.addCard(D2);
  H1->hand.addCard(H2);
  H1->hand.addCard(C2);
  H1->hand.addCard(S2);
  P.push_back(H1);
  Card* S8 = new StandardCard(StandardCard::SPADES, 8);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  A1->hand.addCard(S8);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  EXPECT_EQ(G.hasBook(A1), 0);
}

TEST(TestGoFish, testQuitGame) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  G.quitGame();
  EXPECT_TRUE(G.gameOver);
}

TEST(TestGoFish, testAITurnSkipTurn) {
  std::stringstream consoleScoreDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleScoreDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  Player* A4 = new GoFishAI(AI::EASY, 4);
  GoFish G(1, P);
  G.dealCards(13);
  G.AITurn(A4);

  EXPECT_EQ(consoleScoreDisplay.str(),
  "There are no cards left in the deck and in AI 4's hand.... skipping turn."
  "\n\n");
  std::cout.rdbuf(sbuf);
  delete A4;
}

TEST(TestGoFish, testAITurnActual) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 2);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 2);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 2);
  Card* S2 = new StandardCard(StandardCard::SPADES, 2);
  A1->hand.addCard(D2);
  A1->hand.addCard(H2);
  A1->hand.addCard(C2);
  A1->hand.addCard(S2);
  G.AITurn(A1);
  EXPECT_EQ(A1->hand.getSize(), 2);
}

TEST(TestGoFish, testTurnDisrupted) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);
  G.gameOver = true;
  G.AITurn(A1);
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(A1->hand.getSize(), 0);
  EXPECT_EQ(H1->hand.getSize(), 0);
}

TEST(TestGoFish, testPlayerTurnSkipTurn) {
  std::stringstream consoleScoreDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleScoreDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  Player* A4 = new GoFishAI(AI::EASY, 4);
  P.push_back(A4);
  GoFish G(1, P);
  G.dealCards(13);
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  G.playerTurn(H1, inputStream);
  inputStream.close();

  EXPECT_EQ(consoleScoreDisplay.str(),
  "There are no cards left in the deck and in your hand H1, skipping turn."
  "\n");
  std::cout.rdbuf(sbuf);
  delete H1;
}

TEST(TestGoFish, testPlayerTurnGoodRequest) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "K" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  //EXPECT_EQ(ui.getNumDecks(inputStream), 1);
  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 2);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 2);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 2);
  Card* S2 = new StandardCard(StandardCard::SPADES, 2);
  H1->hand.addCard(D2);
  H1->hand.addCard(H2);
  H1->hand.addCard(C2);
  H1->hand.addCard(S2);
  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 2);
}

TEST(TestGoFish, testPlayerTurnInvalidResponse) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "K" << std::endl << "Teehee" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  //EXPECT_EQ(ui.getNumDecks(inputStream), 1);
  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 2);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 2);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 2);
  Card* S2 = new StandardCard(StandardCard::SPADES, 2);
  H1->hand.addCard(D2);
  H1->hand.addCard(H2);
  H1->hand.addCard(C2);
  H1->hand.addCard(S2);
  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 2);
}

TEST(TestGoFish, testPlayerTurnInvalidAIAsk) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "K" << std::endl << "4" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 2);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 2);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 2);
  Card* S2 = new StandardCard(StandardCard::SPADES, 2);
  H1->hand.addCard(D2);
  H1->hand.addCard(H2);
  H1->hand.addCard(C2);
  H1->hand.addCard(S2);
  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 2);
}



TEST(TestGoFish, testPlayerTurnHelp) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "h" << std::endl << "K" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 2);
}

TEST(TestGoFish, testPlayerTurnQuit) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "~" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_TRUE(G.gameOver);
}

TEST(TestGoFish, testPlayerTurnBadRequest) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "2" << std::endl << "K" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 2);
}

TEST(TestGoFish, testPlayerTurnAskDifferentCards) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new GoFishAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new GoFishAI(AI::EASY, 3);
  P.push_back(A3);
  GoFish G(1, P);

  Card* D1 = new StandardCard(StandardCard::DIAMONDS, 1);
  H1->hand.addCard(D1);
  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 2);
  H1->hand.addCard(D2);
  Card* D3 = new StandardCard(StandardCard::DIAMONDS, 3);
  H1->hand.addCard(D3);
  Card* D4 = new StandardCard(StandardCard::DIAMONDS, 4);
  H1->hand.addCard(D4);
  Card* D5 = new StandardCard(StandardCard::DIAMONDS, 5);
  H1->hand.addCard(D5);
  Card* D6 = new StandardCard(StandardCard::DIAMONDS, 6);
  H1->hand.addCard(D6);
  Card* D7 = new StandardCard(StandardCard::DIAMONDS, 7);
  H1->hand.addCard(D7);
  Card* D8 = new StandardCard(StandardCard::DIAMONDS, 8);
  H1->hand.addCard(D8);
  Card* D9 = new StandardCard(StandardCard::DIAMONDS, 9);
  H1->hand.addCard(D9);
  Card* D10 = new StandardCard(StandardCard::DIAMONDS, 10);
  H1->hand.addCard(D10);
  Card* D11 = new StandardCard(StandardCard::DIAMONDS, 11);
  H1->hand.addCard(D11);
  Card* D12 = new StandardCard(StandardCard::DIAMONDS, 12);
  H1->hand.addCard(D12);


  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "a" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 13);

  outputStream.open("./test/userInput.txt");
  outputStream << "2" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 14);

  outputStream.open("./test/userInput.txt");
  outputStream << "3" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 15);

  outputStream.open("./test/userInput.txt");
  outputStream << "4" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 12);

  outputStream.open("./test/userInput.txt");
  outputStream << "5" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 13);

  outputStream.open("./test/userInput.txt");
  outputStream << "6" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 14);

  outputStream.open("./test/userInput.txt");
  outputStream << "7" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 11);

  outputStream.open("./test/userInput.txt");
  outputStream << "8" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 12);

  outputStream.open("./test/userInput.txt");
  outputStream << "9" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 13);

  outputStream.open("./test/userInput.txt");
  outputStream << "10" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 14);

  outputStream.open("./test/userInput.txt");
  outputStream << "j" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 11);

  outputStream.open("./test/userInput.txt");
  outputStream << "q" << std::endl << "2" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 12);
}

TEST(TestGoFish, testPlayerTurnVersus1AI) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  GoFish G(1, P);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "K" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 2);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 2);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 2);
  Card* S2 = new StandardCard(StandardCard::SPADES, 2);
  H1->hand.addCard(D2);
  H1->hand.addCard(H2);
  H1->hand.addCard(C2);
  H1->hand.addCard(S2);
  G.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->hand.getSize(), 2);
}

TEST(TestGoFish, testPlayGoingToMainMenu) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  GoFish G(1, P);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "~" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.play(inputStream);
  inputStream.close();
  EXPECT_TRUE(G.gameOver);
}

TEST(TestGoFish, testPlayGameOverNotPlayAgain) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  GoFish G(1, P);

  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 13);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 13);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 13);
  Card* S2 = new StandardCard(StandardCard::SPADES, 13);
  Card* S3 = new StandardCard(StandardCard::SPADES, 3);

  A1->hand.addCard(D2);
  A1->hand.addCard(H2);
  A1->hand.addCard(C2);
  H1->hand.addCard(S2);
  H1->hand.addCard(S3);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "k" << std::endl << "no" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.makeBook(1);
  G.makeBook(2);
  G.makeBook(3);
  G.makeBook(4);
  G.makeBook(5);
  G.makeBook(6);
  G.makeBook(7);
  G.makeBook(8);
  G.makeBook(9);
  G.makeBook(10);
  G.makeBook(11);
  G.makeBook(12);

  G.play(inputStream);
  inputStream.close();
  EXPECT_TRUE(G.gameOver);
}

TEST(TestGoFish, testPlayGameOverPlayAgain) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new GoFishAI(AI::EASY, 1);
  P.push_back(A1);
  GoFish G(1, P);

  Card* D2 = new StandardCard(StandardCard::DIAMONDS, 13);
  Card* H2 = new StandardCard(StandardCard::HEARTS, 13);
  Card* C2 = new StandardCard(StandardCard::CLUBS, 13);
  Card* S2 = new StandardCard(StandardCard::SPADES, 13);
  Card* S3 = new StandardCard(StandardCard::SPADES, 3);

  A1->hand.addCard(D2);
  A1->hand.addCard(H2);
  A1->hand.addCard(C2);
  H1->hand.addCard(S2);
  H1->hand.addCard(S3);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "k" << std::endl << "yes" << std::endl << "~" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  G.makeBook(1);
  G.makeBook(2);
  G.makeBook(3);
  G.makeBook(4);
  G.makeBook(5);
  G.makeBook(6);
  G.makeBook(7);
  G.makeBook(8);
  G.makeBook(9);
  G.makeBook(10);
  G.makeBook(11);
  G.makeBook(12);

  G.play(inputStream);
  inputStream.close();
  EXPECT_TRUE(G.gameOver);
}
