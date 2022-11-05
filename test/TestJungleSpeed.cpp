#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "JungleSpeed.h"
#include "JungleSpeedCard.h"
#include "Game.h"
#include "JungleSpeedAI.h"
#include "Player.h"
#include "Human.h"
#include "AI.h"
#include "gtest/gtest.h"


TEST(TestJungleSpeed, testJungleSpeedConstructorMultiplayer) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::EASY, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);
  EXPECT_EQ(J.getNumPlayers(), 4);
  EXPECT_EQ(J.getNumDecks(), 1);
  EXPECT_EQ(J.getPlayers(), P);
  EXPECT_EQ(J.getHandSize(), 20);
}

TEST(TestJungleSpeed, testJungleSpeedConstructorTwoPlayer) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  JungleSpeed J(1, P);
  EXPECT_EQ(J.getNumPlayers(), 2);
  EXPECT_EQ(J.getNumDecks(), 1);
  EXPECT_EQ(J.getPlayers(), P);
  EXPECT_EQ(J.getHandSize(), 36);
}

TEST(TestJungleSpeed, testPrintRules) {
  std::stringstream consoleScoreDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleScoreDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::EASY, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);
  J.printRules();
  EXPECT_EQ(consoleScoreDisplay.str(),
  "\n\nRULES FOR JUNGLESPEED:\nThe objective of this game is to get rid of all "
  "cards in your hand and your personal discard pile. \nThe deck is divided "
  "as evenly as possible between the players, with the remaining cards placed "
  "onto the stockPile. \nThe cards are placed face down. \nPlayers "
  "alternate flipping the top card of their hand, and placing them in the "
  "stockPile. \nIf two cards match in shape, a duel is initiated. \nDuring "
  "a duel, the first player to press the letter \"J\" and hit the enter/return "
  "key, is declared the winner of that duel. \nThe loser of the duel takes "
  "the cards from its own discard pile and the winners discard pile and puts "
  "them at the bottom of their hand. \nThe player who lost the duel, "
  "starts the card flipping process again. \nIf a player accidentally presses "
  "any key, they automatically take all the cards from each players "
  "discard pile. \nIf an all-in-card is placed, then a duel is called between "
  "all players.\nThe winner will place their discard pile into the main "
  "stockPile, and then restart the card flipping process. \nIf an all-out-card "
  "is placed, then all players must flip a card from their hand, if no matches "
  "are found, the round continues. \nA colours card changes the matching "
  "criteria from shapes to colors. This remains in effect until the colours "
  "card is covered. \nOther rules: \nIf a players last flipped card is a "
  "special card, they automatically win the round. \n\n");
  std::cout.rdbuf(sbuf);
}

TEST(TestJungleSpeed, testPreGame) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::EASY, 2);
  P.push_back(A2);
  JungleSpeed J(1, P);
  J.preGame();
  EXPECT_EQ(H1->hand.getSize(), 26);
  EXPECT_EQ(A1->hand.getSize(), 26);
  EXPECT_EQ(A2->hand.getSize(), 26);
  EXPECT_EQ(J.getFlippedCardsSize(), 3);
  EXPECT_EQ(J.getStockPileSize(), 2);
}

TEST(TestJungleSpeed, testResetGame) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::RED);
  JungleSpeedCard* j2 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j3 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::RED);

  J.flippedCards[0]->addCard(j1);
  J.flippedCards[2]->addCard(j3);
  J.flippedCards[3]->addCard(j2);

  J.resetGame();
  EXPECT_EQ(H1->hand.getSize(), 20);
  EXPECT_EQ(A1->hand.getSize(), 20);
  EXPECT_EQ(A2->hand.getSize(), 20);
  EXPECT_EQ(A3->hand.getSize(), 20);
  EXPECT_EQ(J.getStockPileSize(), 3);
}

TEST(TestJungleSpeed, testReactionTimeWrongKey) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "a" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  double d = J.reactionTime(inputStream);
  EXPECT_EQ(d, 10);
  inputStream.close();
}

TEST(TestJungleSpeed, testReactionTimeRightKey) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "j" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  double d = J.reactionTime(inputStream);
  EXPECT_EQ(d, 0);
  inputStream.close();
}

TEST(TestJungleSpeed, testDeclareLoserWithPlayer) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);
  std::vector<double> times = {5, 1.49, 3.49};
  EXPECT_EQ((J.declareLoser(times))->getID(), 0);

  std::vector<double> times1 = {2.99, 1.49, 3.49};
  EXPECT_EQ((J.declareLoser(times1))->getID(), 1);
}

TEST(TestJungleSpeed, testDeclareWinnerWithPlayer) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);
  std::vector<double> times = {1, 1.49, 3.49};
  EXPECT_EQ((J.declareWinner(times))->getID(), 0);

  std::vector<double> times1 = {2.99, 1.49, 3.49};
  EXPECT_EQ((J.declareWinner(times1))->getID(), 3);
}

TEST(TestJungleSpeed, testIsMatchShapes) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::RED);
  JungleSpeedCard* j2 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j3 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::RED);
  JungleSpeedCard* j4 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::RED);

  J.flippedCards[0]->addCard(j1);
  J.flippedCards[1]->addCard(j4);
  J.flippedCards[2]->addCard(j3);
  J.flippedCards[3]->addCard(j2);

  int posn = J.isMatch(j1);
  EXPECT_EQ(posn, 3);
  posn = J.isMatch(j3);
  EXPECT_EQ(posn, -1);
}

TEST(TestJungleSpeed, testIsMatchColors) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("Colors1",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j2 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j3 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::RED);
  JungleSpeedCard* j4 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::RED);

  J.flippedCards[0]->addCard(j1);
  J.flippedCards[1]->addCard(j4);
  J.flippedCards[2]->addCard(j3);
  J.flippedCards[3]->addCard(j2);

  int posn = J.isMatch(j3);
  EXPECT_EQ(posn, 1);
  posn = J.isMatch(j2);
  EXPECT_EQ(posn, -1);
}

TEST(TestJungleSpeed, testInDuelShapes) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::RED);
  JungleSpeedCard* j2 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j3 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::RED);
  JungleSpeedCard* j4 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::RED);

  J.flippedCards[0]->addCard(j1);
  H1->setMyTurn(true);
  J.flippedCards[1]->addCard(j4);
  J.flippedCards[2]->addCard(j3);
  J.flippedCards[3]->addCard(j2);

  int posn = J.isMatch(j1);

  std::vector<Player*> returnedPlayers = J.inDuel(j1, posn);
  EXPECT_EQ(returnedPlayers.size(), 2);
  EXPECT_TRUE((returnedPlayers[0]->getID() == 0) ||
  (returnedPlayers[0]->getID() == 3));
  EXPECT_TRUE((returnedPlayers[1]->getID() == 0) ||
  (returnedPlayers[1]->getID() == 3));
}

TEST(TestJungleSpeed, testInDuelColors) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("Colors1",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j2 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j3 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::RED);
  JungleSpeedCard* j4 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::RED);

  J.flippedCards[0]->addCard(j1);
  J.flippedCards[1]->addCard(j4);
  J.flippedCards[2]->addCard(j3);
  A2->setMyTurn(true);
  J.flippedCards[3]->addCard(j2);

  int posn = J.isMatch(j3);
  std::vector<Player*> returnedPlayers = J.inDuel(j3, posn);
  EXPECT_EQ(returnedPlayers.size(), 2);
  EXPECT_TRUE((returnedPlayers[0]->getID() == 1) ||
  (returnedPlayers[0]->getID() == 2));
  EXPECT_TRUE((returnedPlayers[1]->getID() == 1) ||
  (returnedPlayers[1]->getID() == 2));
}

TEST(TestJungleSpeed, testInDuelAllOutNoMatch) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("AllOut3",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j2 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j3 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::RED);
  JungleSpeedCard* j4 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::RED);

  JungleSpeedCard* j5 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::GREEN);
  JungleSpeedCard* j6 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j7 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::YELLOW);
  JungleSpeedCard* j8 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::BLUE);

  (H1->hand).addCard(j5);
  (A1->hand).addCard(j6);
  (A2->hand).addCard(j7);
  (A3->hand).addCard(j8);

  J.flippedCards[0]->addCard(j1);
  J.flippedCards[1]->addCard(j4);
  J.flippedCards[2]->addCard(j3);
  H1->setMyTurn(true);
  J.flippedCards[3]->addCard(j2);

  int posn = J.isMatch(j1);
  std::vector<Player*> returnedPlayers = J.inDuel(j1, posn);
  EXPECT_EQ(returnedPlayers.size(), 0);
}

TEST(TestJungleSpeed, testInDuelAllOutShapesMatch) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("AllOut3",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j2 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j3 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::RED);
  JungleSpeedCard* j4 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::RED);

  JungleSpeedCard* j5 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::GREEN);
  JungleSpeedCard* j6 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j7 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::YELLOW);
  JungleSpeedCard* j8 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::BLUE);

  (H1->hand).addCard(j5);
  (A1->hand).addCard(j6);
  (A2->hand).addCard(j7);
  (A3->hand).addCard(j8);

  J.flippedCards[0]->addCard(j1);
  J.flippedCards[1]->addCard(j4);
  J.flippedCards[2]->addCard(j3);
  H1->setMyTurn(true);
  J.flippedCards[3]->addCard(j2);

  int posn = J.isMatch(j1);
  std::vector<Player*> returnedPlayers = J.inDuel(j1, posn);
  EXPECT_EQ(returnedPlayers.size(), 3);
  EXPECT_TRUE((returnedPlayers[0]->getID() == 1) ||
  (returnedPlayers[0]->getID() == 2) || (returnedPlayers[0]->getID() == 0));
  EXPECT_TRUE((returnedPlayers[1]->getID() == 1) ||
  (returnedPlayers[1]->getID() == 2) || (returnedPlayers[1]->getID() == 0));
  EXPECT_TRUE((returnedPlayers[2]->getID() == 1) ||
  (returnedPlayers[2]->getID() == 2) || (returnedPlayers[2]->getID() == 0));
}

TEST(TestJungleSpeed, testInDuelAllOutColorsMatch) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("AllOut3",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j2 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j3 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::RED);
  JungleSpeedCard* j4 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::RED);

  JungleSpeedCard* j5 = new JungleSpeedCard("Colors2",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j6 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j7 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::YELLOW);
  JungleSpeedCard* j8 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::BLUE);

  (H1->hand).addCard(j5);
  (A1->hand).addCard(j6);
  (A2->hand).addCard(j7);
  (A3->hand).addCard(j8);

  J.flippedCards[0]->addCard(j1);
  J.flippedCards[1]->addCard(j4);
  J.flippedCards[2]->addCard(j3);
  H1->setMyTurn(true);
  J.flippedCards[3]->addCard(j2);

  int posn = J.isMatch(j1);
  std::vector<Player*> returnedPlayers = J.inDuel(j1, posn);
  EXPECT_EQ(returnedPlayers.size(), 2);
  EXPECT_TRUE((returnedPlayers[0]->getID() == 1) ||
  (returnedPlayers[0]->getID() == 3));
  EXPECT_TRUE((returnedPlayers[1]->getID() == 1) ||
  (returnedPlayers[1]->getID() == 3));
}

TEST(TestJungleSpeed, testDuelBetweenAI) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::RED);
  JungleSpeedCard* j2 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j3 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::RED);
  JungleSpeedCard* j4 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::RED);

  J.flippedCards[0]->addCard(j3);
  A2->setMyTurn(true);
  J.flippedCards[1]->addCard(j4);
  J.flippedCards[2]->addCard(j1);
  J.flippedCards[3]->addCard(j2);

  std::vector<Player*> returnedPlayers = J.inDuel(j1, J.isMatch(j1));

  Player* loser = J.duel(returnedPlayers, std::cin);
  EXPECT_EQ(J.flippedCards[loser->getID()]->getSize(), 0);
  EXPECT_EQ(J.flippedCards[3]->getSize(), 0);
  EXPECT_EQ(J.flippedCards[1]->getSize(), 1);
  EXPECT_EQ(J.flippedCards[0]->getSize(), 1);
  EXPECT_EQ(loser->getID(), 2);
  EXPECT_EQ((loser->hand).getSize(), 2);
}

TEST(TestJungleSpeed, testDuelWithHuman) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::RED);
  JungleSpeedCard* j2 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j3 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::RED);
  JungleSpeedCard* j4 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::RED);

  J.flippedCards[0]->addCard(j1);
  H1->setMyTurn(true);
  J.flippedCards[1]->addCard(j4);
  J.flippedCards[2]->addCard(j3);
  J.flippedCards[3]->addCard(j2);

  std::vector<Player*> returnedPlayers = J.inDuel(j1, J.isMatch(j1));

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "j" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  Player* loser = J.duel(returnedPlayers, inputStream);
  EXPECT_EQ(loser->getID(), 3);
  EXPECT_EQ(J.flippedCards[loser->getID()]->getSize(), 0);
  EXPECT_EQ(J.flippedCards[1]->getSize(), 1);
  EXPECT_EQ(J.flippedCards[2]->getSize(), 1);
  EXPECT_EQ(J.flippedCards[0]->getSize(), 0);
  EXPECT_EQ((loser->hand).getSize(), 2);
  inputStream.close();
}

TEST(TestJungleSpeed, testDuelAllInHumanWins) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("AllIn3",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j2 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j3 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::RED);
  JungleSpeedCard* j4 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::RED);

  J.flippedCards[0]->addCard(j1);
  H1->setMyTurn(true);
  J.flippedCards[1]->addCard(j4);
  J.flippedCards[2]->addCard(j3);
  J.flippedCards[3]->addCard(j2);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "j" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  Player* winner = J.duel(P, inputStream);
  EXPECT_EQ(winner->getID(), 0);
  EXPECT_EQ(J.flippedCards[winner->getID()]->getSize(), 0);
  EXPECT_EQ(J.flippedCards[1]->getSize(), 1);
  EXPECT_EQ(J.flippedCards[2]->getSize(), 1);
  EXPECT_EQ(J.flippedCards[3]->getSize(), 1);
  inputStream.close();
}

TEST(TestJungleSpeed, testDuelAllInAIWins) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("AllIn3",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j2 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j3 = new JungleSpeedCard("XInsideCircle",
  JungleSpeedCard::RED);
  JungleSpeedCard* j4 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::RED);

  J.flippedCards[0]->addCard(j1);
  H1->setMyTurn(true);
  J.flippedCards[1]->addCard(j4);
  J.flippedCards[2]->addCard(j3);
  J.flippedCards[3]->addCard(j2);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "a" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  Player* winner = J.duel(P, inputStream);
  EXPECT_EQ(winner->getID(), 3);
  EXPECT_EQ(J.flippedCards[winner->getID()]->getSize(), 0);
  EXPECT_EQ(J.flippedCards[1]->getSize(), 1);
  EXPECT_EQ(J.flippedCards[2]->getSize(), 1);
  EXPECT_EQ(J.flippedCards[0]->getSize(), 1);
  inputStream.close();
}

TEST(TestJungleSpeed, testPlayerTurnGameOver) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::RED);
  (H1->hand).addCard(j1);
  H1->setMyTurn(true);
  J.gameOver = true;
  J.playerTurn(H1, std::cin);
  EXPECT_FALSE(H1->getMyTurn());
}

TEST(TestJungleSpeed, testPlayerTurnLastCardIsSpecial) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("AllIn1",
  JungleSpeedCard::SPECIAL);
  (H1->hand).addCard(j1);
  H1->setMyTurn(true);
  J.playerTurn(H1, std::cin);
  EXPECT_EQ(H1->getRoundPoints(), 1);
}

TEST(TestJungleSpeed, testPlayerTurnAllInHumanWins) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("AllIn1",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j2 = new JungleSpeedCard("AllIn2",
  JungleSpeedCard::SPECIAL);
  (H1->hand).addCard(j1);
  (H1->hand).addCard(j2);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "j" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  J.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->getRoundPoints(), 1);
}

TEST(TestJungleSpeed, testPlayerTurnAllInAIWins) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("AllIn1",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j2 = new JungleSpeedCard("AllIn2",
  JungleSpeedCard::SPECIAL);
  (H1->hand).addCard(j1);
  (H1->hand).addCard(j2);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "a" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  J.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_TRUE(A3->getMyTurn());
  EXPECT_FALSE(H1->getMyTurn());
  EXPECT_FALSE(A1->getMyTurn());
  EXPECT_FALSE(A2->getMyTurn());
}


TEST(TestJungleSpeed, testPlayerTurnNoCardsInHandButCardInStockpile) {
  std::stringstream consoleCardDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleCardDisplay.rdbuf());

  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::RED);
  J.flippedCards[0]->addCard(j1);
  J.playerTurn(H1, std::cin);
  EXPECT_EQ(consoleCardDisplay.str(), "\n\nYour top card is: Red "
  "FullCircleGrid\n");
  std::cout.rdbuf(sbuf);
}

TEST(TestJungleSpeed, testPlayerTurnNoMatch) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::RED);
  (H1->hand).addCard(j1);
  H1->setMyTurn(true);
  J.playerTurn(H1, std::cin);
  EXPECT_FALSE(H1->getMyTurn());
}

TEST(TestJungleSpeed, testPlayerTurnAllOutNoMatch) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("AllOut1",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j2 = new JungleSpeedCard("AllOut3",
  JungleSpeedCard::SPECIAL);
  (H1->hand).addCard(j1);
  (H1->hand).addCard(j2);

  JungleSpeedCard* j6 = new JungleSpeedCard("SquareCircleSquare",
  JungleSpeedCard::RED);
  JungleSpeedCard* j7 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::YELLOW);
  JungleSpeedCard* j8 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::BLUE);

  (A1->hand).addCard(j6);
  (A2->hand).addCard(j7);
  (A3->hand).addCard(j8);

  J.playerTurn(H1, std::cin);
  EXPECT_EQ((H1->hand).getSize(), 0);
}

TEST(TestJungleSpeed, testPlayTurnAllOutShapesMatchPlayerLoses) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("AllOut1",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j2 = new JungleSpeedCard("AllOut3",
  JungleSpeedCard::SPECIAL);

  JungleSpeedCard* j5 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::GREEN);
  JungleSpeedCard* j6 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j7 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::YELLOW);
  JungleSpeedCard* j8 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::BLUE);

  (H1->hand).addCard(j1);
  (H1->hand).addCard(j5);
  (H1->hand).addCard(j2);
  (A1->hand).addCard(j6);
  (A2->hand).addCard(j7);
  (A3->hand).addCard(j8);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "a" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  J.playerTurn(H1, inputStream);
  inputStream.close();

  EXPECT_EQ(A1->getRoundPoints(), 1);
}

TEST(TestJungleSpeed, testPlayTurnShapesMatchPlayerWins) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j5 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::GREEN);
  JungleSpeedCard* j6 = new JungleSpeedCard("OctagonCircleOctagon",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j7 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::YELLOW);
  JungleSpeedCard* j8 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::BLUE);

  (H1->hand).addCard(j5);
  J.flippedCards[1]->addCard(j6);
  J.flippedCards[2]->addCard(j7);
  J.flippedCards[3]->addCard(j8);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "j" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  J.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(H1->getRoundPoints(), 1);
}

TEST(TestJungleSpeed, testPlayTurnShapesMatchPlayerLoses) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j5 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::GREEN);
  JungleSpeedCard* j6 = new JungleSpeedCard("OctagonCircleOctagon",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j7 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::YELLOW);
  JungleSpeedCard* j8 = new JungleSpeedCard("XOutsideCircle",
  JungleSpeedCard::BLUE);

  (H1->hand).addCard(j5);
  J.flippedCards[1]->addCard(j6);
  J.flippedCards[2]->addCard(j7);
  J.flippedCards[3]->addCard(j8);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "a" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  J.playerTurn(H1, inputStream);
  inputStream.close();

  EXPECT_EQ(A2->getRoundPoints(), 1);
}

TEST(TestJungleSpeed, testAITurnNoMatch) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("FullCircleGrid",
  JungleSpeedCard::RED);
  (A1->hand).addCard(j1);
  A1->setMyTurn(true);
  J.AITurn(A1);
  EXPECT_FALSE(A1->getMyTurn());
}

TEST(TestJungleSpeed, testPrintScore) {
  std::stringstream consoleScoreDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleScoreDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("AllIn1",
  JungleSpeedCard::SPECIAL);
  (H1->hand).addCard(j1);
  H1->setMyTurn(true);
  J.playerTurn(H1, std::cin);
  J.printScore();
  EXPECT_EQ(H1->getRoundPoints(), 1);
  EXPECT_EQ(consoleScoreDisplay.str(),
  "\n\nYou flipped a Special AllIn1\nYou have no cards in your hand!\nYou win "
  "the game!\n\n      GAME OVER.\n\n");
  std::cout.rdbuf(sbuf);
}

TEST(TestJungleSpeed, testAITurnLastCardIsSpecial) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j1 = new JungleSpeedCard("AllIn1",
  JungleSpeedCard::SPECIAL);
  (A1->hand).addCard(j1);
  A1->setMyTurn(true);
  J.AITurn(A1);
  EXPECT_EQ(A1->getRoundPoints(), 1);
}

TEST(TestJungleSpeed, testRoundNoDuel) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j5 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::GREEN);
  JungleSpeedCard* j6 = new JungleSpeedCard("OctagonCircleOctagon",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j7 = new JungleSpeedCard("SquareCircleSquare",
  JungleSpeedCard::YELLOW);
  JungleSpeedCard* j8 = new JungleSpeedCard("AllIn1",
  JungleSpeedCard::SPECIAL);

  (H1->hand).addCard(j5);
  (A1->hand).addCard(j6);
  (A2->hand).addCard(j7);
  (A3->hand).addCard(j8);

  J.round(std::cin);
  EXPECT_EQ(A3->getRoundPoints(), 1);
}

TEST(TestJungleSpeed, testRoundHumanLosesDuel) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j5 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::GREEN);
  JungleSpeedCard* j6 = new JungleSpeedCard("OctagonCircleOctagon",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j7 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::YELLOW);
  JungleSpeedCard* j8 = new JungleSpeedCard("AllIn1",
  JungleSpeedCard::SPECIAL);
  JungleSpeedCard* j9 = new JungleSpeedCard("LineInsideCircle",
  JungleSpeedCard::YELLOW);

  H1->setMyTurn(true);
  (H1->hand).addCard(j5);
  (A1->hand).addCard(j6);
  (A2->hand).addCard(j7);
  (A2->hand).addCard(j9);
  (A3->hand).addCard(j8);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "a" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  J.round(inputStream);
  EXPECT_EQ(A3->getRoundPoints(), 1);
  inputStream.close();
}

TEST(TestJungleSpeed, testRoundAI3LosesDuel) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new JungleSpeedAI(AI::NORMAL, 2);
  P.push_back(A2);
  Player* A3 = new JungleSpeedAI(AI::HARD, 3);
  P.push_back(A3);
  JungleSpeed J(1, P);

  JungleSpeedCard* j5 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::GREEN);
  JungleSpeedCard* j6 = new JungleSpeedCard("OctagonCircleOctagon",
  JungleSpeedCard::BLUE);
  JungleSpeedCard* j7 = new JungleSpeedCard("SquareCircleSquare",
  JungleSpeedCard::YELLOW);
  JungleSpeedCard* j9 = new JungleSpeedCard("CircleSquareCircle",
  JungleSpeedCard::GREEN);
  JungleSpeedCard* j8 = new JungleSpeedCard("AllIn1",
  JungleSpeedCard::SPECIAL);

  A3->setMyTurn(true);
  (A1->hand).addCard(j6);
  (A2->hand).addCard(j7);
  (A3->hand).addCard(j9);
  (H1->hand).addCard(j8);
  (H1->hand).addCard(j5);

  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "j" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);

  J.round(inputStream);
  EXPECT_EQ(H1->getRoundPoints(), 1);
  inputStream.close();
}

TEST(TestJungleSpeed, testPlayerTurnDraw) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
  P.push_back(A1);
  JungleSpeed J(1, P);

  J.playerTurn(H1, std::cin);
  EXPECT_EQ(H1->getRoundPoints(), 1);
  EXPECT_EQ(A1->getRoundPoints(), 1);
}
