#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "CrazyEights.h"
#include "Game.h"
#include "Player.h"
#include "Human.h"
#include "CrazyEightsAI.h"
#include "Deck.h"
#include "Card.h"
#include "AI.h"
#include "gtest/gtest.h"


//Default constructor.
//CrazyEights(int players, int decks);
TEST(TestCrazyEights, testCrazyEightsConstructor) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  EXPECT_EQ(C.getNumPlayers(), 4);
  EXPECT_EQ(C.getNumDecks(), 1);
  EXPECT_EQ(C.getPlayers(), P);
}

//Prints the rules of Crazy 8's.
//void printRules();
TEST(TestCrazyEights, testPrintRules) {
  std::stringstream consoleRulesDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleRulesDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.printRules();
  EXPECT_EQ(consoleRulesDisplay.str(),
  "RULES FOR CRAZY EIGHTS: \nThe objective of this game is to have the highest "
  "number of points after the completion of all the rounds.\nEach player is "
  "dealt 5 cards. The remaining cards will be placed in the deck. The top card "
  "of the deck will be placed upright onto the stockpile.\nWhen it is your "
  "turn, you may place a card from your hand that matches the suit or rank of "
  "the card on the stockpile.\nOr you may place an eight to change to a suit of"
  " your choice.\nIf you do not have a valid card to place, you must draw a "
  "card from the deck.\nYou may draw as many cards as you like from the deck, "
  "but you must play a card at the end of your turn.\nA round is over when a "
  "player runs out of cards. The player will then be awarded points from the "
  "opponents hand.\nThe scoring system is as follows: \n8: 50 points.\n10, J, "
  "Q, & K: 10 points.\nA: 1 point.\nEvery other card is awarded its face "
  "value.\nThe winner of the game will be declared after the player decides to "
  "quit the game.\n");
  std::cout.rdbuf(sbuf);
}

//Defines pregame set up, using players.
//void preGame();
TEST(TestCrazyEights, testPreGame) {
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  EXPECT_EQ(H1->hand.getSize(), 5);
  EXPECT_EQ(A1->hand.getSize(), 5);
  EXPECT_EQ(A2->hand.getSize(), 5);
  EXPECT_EQ(A3->hand.getSize(), 5);
}

//Called at the end of each round. Uses Players
//void scoringSystem();
TEST(TestCrazyEights, testScoringSystem) {
  std::stringstream consoleScoreDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleScoreDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  Card* D7 = new StandardCard(StandardCard::DIAMONDS, 7);
  Card* H12 = new StandardCard(StandardCard::HEARTS, 12);
  Card* C8 = new StandardCard(StandardCard::CLUBS, 8);
  A1->hand.addCard(D7);
  A2->hand.addCard(H12);
  A3->hand.addCard(C8);
  C.scoringSystem(H1);
  C.printScore();
  EXPECT_EQ(consoleScoreDisplay.str(),
  "      GAME OVER.\n\nYour score for this round is: 67\nAI 1's score is: 0\n"
  "AI 2's score is: 0\nAI 3's score is: 0\n\n");
  std::cout.rdbuf(sbuf);
}

//Defines the turn of an AI player.
//@param p the player whose turn is being defined.
TEST(TestCrazyEights, testAITurnPlaceRandomCard) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = A1->hand.getTop();
    A1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp1;
  StandardCard* temp2;
  switch (C.gameSuit) {
    case StandardCard::DIAMONDS:
    temp1 = new StandardCard(StandardCard::DIAMONDS, 2);
    A1->hand.addCard(temp1);
    temp2 = new StandardCard(StandardCard::HEARTS, 2);
    A1->hand.addCard(temp2);
    C.AITurn(A1);
    EXPECT_EQ(consoleGameDisplay.str(), "AI 1 has placed a 2 of Diamonds on "
    "the stockPile.\n\n");
    break;
    case StandardCard::HEARTS:
    temp1 = new StandardCard(StandardCard::HEARTS, 2);
    A1->hand.addCard(temp1);
    temp2 = new StandardCard(StandardCard::CLUBS, 2);
    A1->hand.addCard(temp2);
    C.AITurn(A1);
    EXPECT_EQ(consoleGameDisplay.str(), "AI 1 has placed a 2 of Hearts on the "
    "stockPile.\n\n");
    break;
    case StandardCard::CLUBS:
    temp1 = new StandardCard(StandardCard::CLUBS, 2);
    A1->hand.addCard(temp1);
    temp2 = new StandardCard(StandardCard::SPADES, 2);
    A1->hand.addCard(temp2);
    C.AITurn(A1);
    EXPECT_EQ(consoleGameDisplay.str(), "AI 1 has placed a 2 of Clubs on the "
    "stockPile.\n\n");
    break;
    default:
    temp1 = new StandardCard(StandardCard::SPADES, 2);
    A1->hand.addCard(temp1);
    temp2 = new StandardCard(StandardCard::DIAMONDS, 2);
    A1->hand.addCard(temp2);
    C.AITurn(A1);
    EXPECT_EQ(consoleGameDisplay.str(), "AI 1 has placed a 2 of Spades on the "
    "stockPile.\n\n");
    break;
  }
  EXPECT_EQ(A1->hand.getSize(), 1);
  std::cout.rdbuf(sbuf);
}

TEST(TestCrazyEights, testAITurnPickUpCard) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = A1->hand.getTop();
    A1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp;
  switch (C.gameSuit) {
    case StandardCard::DIAMONDS:
    temp = new StandardCard(StandardCard::HEARTS, 14);
    A1->hand.addCard(temp);
    C.AITurn(A1);
    EXPECT_EQ(consoleGameDisplay.str().substr(0, 23),
    "AI 1 picked up a card.\n");
    break;
    case StandardCard::HEARTS:
    temp = new StandardCard(StandardCard::CLUBS, 14);
    A1->hand.addCard(temp);
    C.AITurn(A1);
    EXPECT_EQ(consoleGameDisplay.str().substr(0, 23),
    "AI 1 picked up a card.\n");
    break;
    case StandardCard::CLUBS:
    temp = new StandardCard(StandardCard::SPADES, 14);
    A1->hand.addCard(temp);
    C.AITurn(A1);
    EXPECT_EQ(consoleGameDisplay.str().substr(0, 23),
    "AI 1 picked up a card.\n");
    break;
    default:
    temp = new StandardCard(StandardCard::DIAMONDS, 14);
    A1->hand.addCard(temp);
    C.AITurn(A1);
    EXPECT_EQ(consoleGameDisplay.str().substr(0, 23),
    "AI 1 picked up a card.\n");
    break;
  }
  std::cout.rdbuf(sbuf);
  EXPECT_GE(A1->hand.getSize(), 1);
}

TEST(TestCrazyEights, testAITurnEmptyHand) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = A1->hand.getTop();
    A1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp;
  switch (C.gameSuit) {
    case StandardCard::DIAMONDS:
    temp = new StandardCard(StandardCard::DIAMONDS, 2);
    A1->hand.addCard(temp);
    C.AITurn(A1);
    EXPECT_EQ(consoleGameDisplay.str().substr(0, 90), "AI 1 has placed a 2 of "
    "Diamonds on the stockPile.\n\nAI 1 has no more cards in their hand!\n\n");
    break;
    case StandardCard::HEARTS:
    temp = new StandardCard(StandardCard::HEARTS, 2);
    A1->hand.addCard(temp);
    C.AITurn(A1);
    EXPECT_EQ(consoleGameDisplay.str().substr(0, 88), "AI 1 has placed a 2 of "
    "Hearts on the stockPile.\n\nAI 1 has no more cards in their hand!\n\n");
    break;
    case StandardCard::CLUBS:
    temp = new StandardCard(StandardCard::CLUBS, 2);
    A1->hand.addCard(temp);
    C.AITurn(A1);
    EXPECT_EQ(consoleGameDisplay.str().substr(0, 87), "AI 1 has placed a 2 of "
    "Clubs on the stockPile.\n\nAI 1 has no more cards in their hand!\n\n");
    break;
    default:
    temp = new StandardCard(StandardCard::SPADES, 2);
    A1->hand.addCard(temp);
    C.AITurn(A1);
    EXPECT_EQ(consoleGameDisplay.str().substr(0, 88), "AI 1 has placed a 2 of "
    "Spades on the stockPile.\n\nAI 1 has no more cards in their hand!\n\n");
    break;
  }
  EXPECT_EQ(A1->hand.getSize(), 0);
  std::cout.rdbuf(sbuf);
}

TEST(TestCrazyEights, testAITurnEightEasy) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = A1->hand.getTop();
    A1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* C8 = new StandardCard(StandardCard::CLUBS, 8);
  A1->hand.addCard(C8);
  C.AITurn(A1);
  EXPECT_EQ(consoleGameDisplay.str().substr(0, 81), "AI 1 has placed a 8 of "
  "Clubs on the stockPile.\n\nAI 1 changed the suit to Clubs.\n\n");
  EXPECT_EQ(A1->hand.getSize(), 0);
  std::cout.rdbuf(sbuf);
}

TEST(TestCrazyEights, testAITurnEightNormal) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::NORMAL, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = A1->hand.getTop();
    A1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* C8 = new StandardCard(StandardCard::CLUBS, 8);
  A1->hand.addCard(C8);
  C.AITurn(A1);
  EXPECT_EQ(consoleGameDisplay.str().substr(0, 81), "AI 1 has placed a 8 of "
  "Clubs on the stockPile.\n\nAI 1 changed the suit to Clubs.\n\n");
  EXPECT_EQ(A1->hand.getSize(), 0);
  std::cout.rdbuf(sbuf);
}

TEST(TestCrazyEights, testAITurnEightHard) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::HARD, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = A1->hand.getTop();
    A1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* C8 = new StandardCard(StandardCard::CLUBS, 8);
  A1->hand.addCard(C8);
  C.AITurn(A1);
  EXPECT_EQ(consoleGameDisplay.str().substr(0, 81), "AI 1 has placed a 8 of "
  "Clubs on the stockPile.\n\nAI 1 changed the suit to Clubs.\n\n");
  EXPECT_EQ(A1->hand.getSize(), 0);
  std::cout.rdbuf(sbuf);
}

TEST(TestCrazyEights, testAITurnDeckEmpty) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = A1->hand.getTop();
    A1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp;
  for (int i = 0; i < 52; i++) {
    switch (C.gameSuit) {
      case StandardCard::DIAMONDS:
      temp = new StandardCard(StandardCard::HEARTS, 14);
      A1->hand.addCard(temp);
      C.AITurn(A1);
      break;
      case StandardCard::HEARTS:
      temp = new StandardCard(StandardCard::CLUBS, 14);
      A1->hand.addCard(temp);
      C.AITurn(A1);
      break;
      case StandardCard::CLUBS:
      temp = new StandardCard(StandardCard::SPADES, 14);
      A1->hand.addCard(temp);
      C.AITurn(A1);
      break;
      default:
      temp = new StandardCard(StandardCard::DIAMONDS, 14);
      A1->hand.addCard(temp);
      C.AITurn(A1);
      break;
    }
    const int j = A1->hand.getSize();
    for (int i = 0; i < j; i++) {
      Card* temp = A1->hand.getTop();
      A1->hand.removeCard(temp);
      delete temp;
    }
  }
  EXPECT_EQ(consoleGameDisplay.str().substr(consoleGameDisplay.str().size()-53,
  consoleGameDisplay.str().size()), "There are no cards left in the deck, "
  "skipping turn.\n\n");
  std::cout.rdbuf(sbuf);
  EXPECT_GE(A1->hand.getSize(), 0);
}

TEST(TestCrazyEights, testAITurnDraw) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = A1->hand.getTop();
    A1->hand.removeCard(temp);
    delete temp;
  }
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp;
  for (int i = 0; i < 52; i++) {
    switch (C.gameSuit) {
      case StandardCard::DIAMONDS:
      temp = new StandardCard(StandardCard::HEARTS, 14);
      A1->hand.addCard(temp);
      C.AITurn(A1);
      break;
      case StandardCard::HEARTS:
      temp = new StandardCard(StandardCard::CLUBS, 14);
      A1->hand.addCard(temp);
      C.AITurn(A1);
      break;
      case StandardCard::CLUBS:
      temp = new StandardCard(StandardCard::SPADES, 14);
      A1->hand.addCard(temp);
      C.AITurn(A1);
      break;
      default:
      temp = new StandardCard(StandardCard::DIAMONDS, 14);
      A1->hand.addCard(temp);
      C.AITurn(A1);
      break;
    }
    const int j = A1->hand.getSize();
    for (int i = 0; i < j; i++) {
      Card* temp = A1->hand.getTop();
      A1->hand.removeCard(temp);
      delete temp;
    }
  }

  StandardCard* temp2;
  StandardCard* temp3;
  if (C.gameSuit == StandardCard::DIAMONDS) {
    temp2 = new StandardCard(StandardCard::SPADES, 14);
    temp3 = new StandardCard(StandardCard::SPADES, 15);
  } else {
    temp2 = new StandardCard(StandardCard::DIAMONDS, 14);
    temp3 = new StandardCard(StandardCard::DIAMONDS, 15);
  }
  A1->hand.addCard(temp2);
  H1->hand.addCard(temp3);

  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  C.AITurn(A1);
  EXPECT_EQ(consoleGameDisplay.str(), "It's a draw...\n\n");
  std::cout.rdbuf(sbuf);
}


TEST(TestCrazyEights, testPlayerTurnPlaceRandomCard) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp1;
  StandardCard* temp2;
  std::ifstream inputStream;
  std::ofstream outputStream;
  switch (C.gameSuit) {
    case StandardCard::DIAMONDS:
    temp1 = new StandardCard(StandardCard::DIAMONDS, 2);
    H1->hand.addCard(temp1);
    temp2 = new StandardCard(StandardCard::HEARTS, 2);
    H1->hand.addCard(temp2);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 d" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-29, consoleGameDisplay.str().size()),
      "You placed a 2 of Diamonds.\n\n");
    break;
    case StandardCard::HEARTS:
    temp1 = new StandardCard(StandardCard::HEARTS, 2);
    H1->hand.addCard(temp1);
    temp2 = new StandardCard(StandardCard::CLUBS, 2);
    H1->hand.addCard(temp2);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 h" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-27, consoleGameDisplay.str().size()),
      "You placed a 2 of Hearts.\n\n");
    break;
    case StandardCard::CLUBS:
    temp1 = new StandardCard(StandardCard::CLUBS, 2);
    H1->hand.addCard(temp1);
    temp2 = new StandardCard(StandardCard::SPADES, 2);
    H1->hand.addCard(temp2);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 c" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-26, consoleGameDisplay.str().size()),
      "You placed a 2 of Clubs.\n\n");
    break;
    default:
    temp1 = new StandardCard(StandardCard::SPADES, 2);
    H1->hand.addCard(temp1);
    temp2 = new StandardCard(StandardCard::DIAMONDS, 2);
    H1->hand.addCard(temp2);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 s" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-27, consoleGameDisplay.str().size()),
      "You placed a 2 of Spades.\n\n");
    break;
  }
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 1);
}

TEST(TestCrazyEights, testPlayerTurnNumberQuit) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp1;
  StandardCard* temp2;
  std::ifstream inputStream;
  std::ofstream outputStream;
  switch (C.gameSuit) {
    case StandardCard::DIAMONDS:
    temp1 = new StandardCard(StandardCard::DIAMONDS, 2);
    H1->hand.addCard(temp1);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 ~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-17, consoleGameDisplay.str().size()),
      "quitting game...\n");
    break;
    case StandardCard::HEARTS:
    temp1 = new StandardCard(StandardCard::HEARTS, 2);
    H1->hand.addCard(temp1);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 ~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-17, consoleGameDisplay.str().size()),
      "quitting game...\n");
    break;
    case StandardCard::CLUBS:
    temp1 = new StandardCard(StandardCard::CLUBS, 2);
    H1->hand.addCard(temp1);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 ~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-17, consoleGameDisplay.str().size()),
      "quitting game...\n");
    break;
    default:
    temp1 = new StandardCard(StandardCard::SPADES, 2);
    H1->hand.addCard(temp1);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 ~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-17, consoleGameDisplay.str().size()),
      "quitting game...\n");
    break;
  }
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 1);
}

TEST(TestCrazyEights, testPlayerTurnNoValidCard) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp;
  std::ifstream inputStream;
  std::ofstream outputStream;
  switch (C.gameSuit) {
    case StandardCard::DIAMONDS:
    temp = new StandardCard(StandardCard::HEARTS, 14);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(0, 47), "You do not have a valid "
    "card in your hand, H1.\n");
    break;
    case StandardCard::HEARTS:
    temp = new StandardCard(StandardCard::CLUBS, 14);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(0, 47), "You do not have a valid "
    "card in your hand, H1.\n");
    break;
    case StandardCard::CLUBS:
    temp = new StandardCard(StandardCard::SPADES, 14);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(0, 47), "You do not have a valid "
    "card in your hand, H1.\n");
    break;
    default:
    temp = new StandardCard(StandardCard::DIAMONDS, 14);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(0, 47), "You do not have a valid "
    "card in your hand, H1.\n");
    break;
  }
  std::cout.rdbuf(sbuf);
  EXPECT_GE(H1->hand.getSize(), 2);
}

TEST(TestCrazyEights, testPlayerTurnQuitAtYN) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp;
  std::ifstream inputStream;
  std::ofstream outputStream;
  switch (C.gameSuit) {
    case StandardCard::DIAMONDS:
    temp = new StandardCard(StandardCard::DIAMONDS, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-59, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): quitting game...\n");
    break;
    case StandardCard::HEARTS:
    temp = new StandardCard(StandardCard::HEARTS, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-59, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): quitting game...\n");
    break;
    case StandardCard::CLUBS:
    temp = new StandardCard(StandardCard::CLUBS, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-59, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): quitting game...\n");
    break;
    default:
    temp = new StandardCard(StandardCard::SPADES, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-59, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): quitting game...\n");
    break;
  }
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 1);
}

TEST(TestCrazyEights, testPlayerTurnQuitAtPlayCard) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp;
  std::ifstream inputStream;
  std::ofstream outputStream;
  switch (C.gameSuit) {
    case StandardCard::DIAMONDS:
    temp = new StandardCard(StandardCard::DIAMONDS, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-309, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): \nTo play a card, enter a "
      "digit "
      "from 2-10, J, Q, K, of A.\nThen enter the suit of the card as (S)pades, "
      "(C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo quit the "
      "game, enter \"~\". To see the rules, enter H.\n\nWhat card would you"
      " like to play, H1?: quitting game...\n");
    break;
    case StandardCard::HEARTS:
    temp = new StandardCard(StandardCard::HEARTS, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-309, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): \nTo play a card, enter a "
      "digit "
      "from 2-10, J, Q, K, of A.\nThen enter the suit of the card as (S)pades, "
      "(C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo quit the "
      "game, enter \"~\". To see the rules, enter H.\n\nWhat card would you"
      " like to play, H1?: quitting game...\n");
    break;
    case StandardCard::CLUBS:
    temp = new StandardCard(StandardCard::CLUBS, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-309, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): \nTo play a card, enter a "
      "digit "
      "from 2-10, J, Q, K, of A.\nThen enter the suit of the card as (S)pades, "
      "(C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo quit the "
      "game, enter \"~\". To see the rules, enter H.\n\nWhat card would you"
      " like to play, H1?: quitting game...\n");
    break;
    default:
    temp = new StandardCard(StandardCard::SPADES, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-309, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): \nTo play a card, enter a "
      "digit "
      "from 2-10, J, Q, K, of A.\nThen enter the suit of the card as (S)pades, "
      "(C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo quit the "
      "game, enter \"~\". To see the rules, enter H.\n\nWhat card would you"
      " like to play, H1?: quitting game...\n");
    break;
  }
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 1);
}

TEST(TestCrazyEights, testPlayerTurnHelp) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp;
  std::ifstream inputStream;
  std::ofstream outputStream;
  switch (C.gameSuit) {
    case StandardCard::DIAMONDS:
    temp = new StandardCard(StandardCard::DIAMONDS, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "h" << std::endl;
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-1527, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): \nTo play a card, enter a "
      "digit from 2-10, J, Q, K, of A.\nThen enter the suit of the card as "
      "(S)pades, (C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo "
      "quit the game, enter \"~\". To see the rules, enter H.\n\nWhat card "
      "would you like to play, H1?: \nRULES FOR CRAZY EIGHTS: \nThe objective "
      "of this game is to have the highest number of points after the "
      "completion of all the rounds.\nEach player is dealt 5 cards. The "
      "remaining cards will be placed in the deck. The top card of the deck "
      "will be placed upright onto the stockpile.\nWhen it is your turn, you "
      "may place a card from your hand that matches the suit or rank of the "
      "card on the stockpile.\nOr you may place an eight to change to a suit "
      "of your choice.\nIf you do not have a valid card to place, you must "
      "draw a card from the deck.\nYou may draw as many cards as you like "
      "from the deck, but you must play a card at the end of your turn.\nA "
      "round is over when a player runs out of cards. The player will then "
      "be awarded points from the opponents hand.\nThe scoring system is as "
      "follows: \n8: 50 points.\n10, J, Q, & K: 10 points.\nA: 1 point.\n"
      "Every other card is awarded its face value.\nThe winner of the game "
      "will be declared after the player decides to quit the game.\n\nTo "
      "play a card, enter a digit from 2-10, J, Q, K, of A.\nThen enter the "
      "suit of the card as (S)pades, (C)lubs, (D)iamonds, or (H)earts.\nFor "
      "example \"3 H\"\nTo quit the game, enter \"~\". To see the rules, "
      "enter H.\n\nWhat card would you like to play, H1?: quitting game...\n");
    break;
    case StandardCard::HEARTS:
    temp = new StandardCard(StandardCard::HEARTS, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "h" << std::endl;
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-1527, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): \nTo play a card, enter a "
      "digit from 2-10, J, Q, K, of A.\nThen enter the suit of the card as "
      "(S)pades, (C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo "
      "quit the game, enter \"~\". To see the rules, enter H.\n\nWhat card "
      "would you like to play, H1?: \nRULES FOR CRAZY EIGHTS: \nThe objective "
      "of this game is to have the highest number of points after the "
      "completion of all the rounds.\nEach player is dealt 5 cards. The "
      "remaining cards will be placed in the deck. The top card of the deck "
      "will be placed upright onto the stockpile.\nWhen it is your turn, you "
      "may place a card from your hand that matches the suit or rank of the "
      "card on the stockpile.\nOr you may place an eight to change to a suit "
      "of your choice.\nIf you do not have a valid card to place, you must "
      "draw a card from the deck.\nYou may draw as many cards as you like "
      "from the deck, but you must play a card at the end of your turn.\nA "
      "round is over when a player runs out of cards. The player will then "
      "be awarded points from the opponents hand.\nThe scoring system is as "
      "follows: \n8: 50 points.\n10, J, Q, & K: 10 points.\nA: 1 point.\n"
      "Every other card is awarded its face value.\nThe winner of the game "
      "will be declared after the player decides to quit the game.\n\nTo "
      "play a card, enter a digit from 2-10, J, Q, K, of A.\nThen enter the "
      "suit of the card as (S)pades, (C)lubs, (D)iamonds, or (H)earts.\nFor "
      "example \"3 H\"\nTo quit the game, enter \"~\". To see the rules, "
      "enter H.\n\nWhat card would you like to play, H1?: quitting game...\n");
    break;
    case StandardCard::CLUBS:
    temp = new StandardCard(StandardCard::CLUBS, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "h" << std::endl;
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-1527, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): \nTo play a card, enter a "
      "digit from 2-10, J, Q, K, of A.\nThen enter the suit of the card as "
      "(S)pades, (C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo "
      "quit the game, enter \"~\". To see the rules, enter H.\n\nWhat card "
      "would you like to play, H1?: \nRULES FOR CRAZY EIGHTS: \nThe objective "
      "of this game is to have the highest number of points after the "
      "completion of all the rounds.\nEach player is dealt 5 cards. The "
      "remaining cards will be placed in the deck. The top card of the deck "
      "will be placed upright onto the stockpile.\nWhen it is your turn, you "
      "may place a card from your hand that matches the suit or rank of the "
      "card on the stockpile.\nOr you may place an eight to change to a suit "
      "of your choice.\nIf you do not have a valid card to place, you must "
      "draw a card from the deck.\nYou may draw as many cards as you like "
      "from the deck, but you must play a card at the end of your turn.\nA "
      "round is over when a player runs out of cards. The player will then "
      "be awarded points from the opponents hand.\nThe scoring system is as "
      "follows: \n8: 50 points.\n10, J, Q, & K: 10 points.\nA: 1 point.\n"
      "Every other card is awarded its face value.\nThe winner of the game "
      "will be declared after the player decides to quit the game.\n\nTo "
      "play a card, enter a digit from 2-10, J, Q, K, of A.\nThen enter the "
      "suit of the card as (S)pades, (C)lubs, (D)iamonds, or (H)earts.\nFor "
      "example \"3 H\"\nTo quit the game, enter \"~\". To see the rules, "
      "enter H.\n\nWhat card would you like to play, H1?: quitting game...\n");
    break;
    default:
    temp = new StandardCard(StandardCard::SPADES, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "h" << std::endl;
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-1527, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): \nTo play a card, enter a "
      "digit from 2-10, J, Q, K, of A.\nThen enter the suit of the card as "
      "(S)pades, (C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo "
      "quit the game, enter \"~\". To see the rules, enter H.\n\nWhat card "
      "would you like to play, H1?: \nRULES FOR CRAZY EIGHTS: \nThe objective "
      "of this game is to have the highest number of points after the "
      "completion of all the rounds.\nEach player is dealt 5 cards. The "
      "remaining cards will be placed in the deck. The top card of the deck "
      "will be placed upright onto the stockpile.\nWhen it is your turn, you "
      "may place a card from your hand that matches the suit or rank of the "
      "card on the stockpile.\nOr you may place an eight to change to a suit "
      "of your choice.\nIf you do not have a valid card to place, you must "
      "draw a card from the deck.\nYou may draw as many cards as you like "
      "from the deck, but you must play a card at the end of your turn.\nA "
      "round is over when a player runs out of cards. The player will then "
      "be awarded points from the opponents hand.\nThe scoring system is as "
      "follows: \n8: 50 points.\n10, J, Q, & K: 10 points.\nA: 1 point.\n"
      "Every other card is awarded its face value.\nThe winner of the game "
      "will be declared after the player decides to quit the game.\n\nTo "
      "play a card, enter a digit from 2-10, J, Q, K, of A.\nThen enter the "
      "suit of the card as (S)pades, (C)lubs, (D)iamonds, or (H)earts.\nFor "
      "example \"3 H\"\nTo quit the game, enter \"~\". To see the rules, "
      "enter H.\n\nWhat card would you like to play, H1?: quitting game...\n");
    break;
  }
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 1);
}

TEST(TestCrazyEights, testPlayerTurnValidDeckEmpty) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp;
  std::ifstream inputStream;
  std::ofstream outputStream;


  temp = new StandardCard(StandardCard::DIAMONDS, 14);
  H1->hand.addCard(temp);
  outputStream.open("./test/userInput.txt");
  for (int i = 0; i < 32; i++) {
    outputStream << "n" << std::endl;
  }
  outputStream << "~" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  C.playerTurn(H1, inputStream);
  inputStream.close();

  EXPECT_EQ(consoleGameDisplay.str().substr(
    consoleGameDisplay.str().size()-58, consoleGameDisplay.str().size()),
    "There are no cards left in the deck, skipping your turn.\n\n");
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 32);
}

TEST(TestCrazyEights, testPlayerTurnInvalidDeckEmpty) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp1;
  StandardCard* temp2;
  std::ifstream inputStream;
  std::ofstream outputStream;
  std::ifstream inputStream1;
  std::ofstream outputStream1;

  temp1 = new StandardCard(StandardCard::DIAMONDS, 14);
  H1->hand.addCard(temp1);
  outputStream.open("./test/userInput.txt");
  for (int i = 0; i < 52; i++) {
    outputStream << "n" << std::endl;
  }
  outputStream << "~" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  C.playerTurn(H1, inputStream);
  inputStream.close();

  const int sze = H1->hand.getSize();
  for (int i = 0; i < sze; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }

  if (C.gameSuit == StandardCard::DIAMONDS) {
  temp2 = new StandardCard(StandardCard::SPADES, 14);
} else {
  temp2 = new StandardCard(StandardCard::DIAMONDS, 14);
}
  H1->hand.addCard(temp2);

  outputStream1.open("./test/userInput.txt");
  outputStream1 << "~" << std::endl;
  outputStream1.close();
  inputStream1.open("./test/userInput.txt", std::ifstream::in);
  C.playerTurn(H1, inputStream1);
  inputStream1.close();

  EXPECT_EQ(consoleGameDisplay.str().substr(
    consoleGameDisplay.str().size()-105, consoleGameDisplay.str().size()),
    "You do not have a valid card in your hand, H1.\nThere are no cards left in"
    " the deck, skipping your turn.\n\n");
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 1);
}

TEST(TestCrazyEights, testPlayerTurnWin) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp;
  std::ifstream inputStream;
  std::ofstream outputStream;
  switch (C.gameSuit) {
    case StandardCard::DIAMONDS:
    temp = new StandardCard(StandardCard::DIAMONDS, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 d" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-70, consoleGameDisplay.str().size()),
      "You placed a 2 of Diamonds.\n\nYou have no more cards in your "
      "hand H1!\n\n");
    break;
    case StandardCard::HEARTS:
    temp = new StandardCard(StandardCard::HEARTS, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 h" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-68, consoleGameDisplay.str().size()),
      "You placed a 2 of Hearts.\n\nYou have no more cards in your hand H1!"
      "\n\n");
    break;
    case StandardCard::CLUBS:
    temp = new StandardCard(StandardCard::CLUBS, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 c" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-67, consoleGameDisplay.str().size()),
      "You placed a 2 of Clubs.\n\nYou have no more cards in your hand H1!"
      "\n\n");
    break;
    default:
    temp = new StandardCard(StandardCard::SPADES, 2);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 s" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-68, consoleGameDisplay.str().size()),
      "You placed a 2 of Spades.\n\nYou have no more cards in your hand H1!"
      "\n\n");
    break;
  }
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 0);
}

TEST(TestCrazyEights, DISABLED_testPlayerTurnNotInHand) {
  //causes mem leak
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp = new StandardCard(StandardCard::DIAMONDS, 2);
  std::ifstream inputStream;
  std::ofstream outputStream;

    temp->setSuit(C.gameSuit);
    H1->hand.addCard(temp);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 h" << std::endl;
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-625, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): \nTo play a card, enter a "
      "digit from 2-10, J, Q, K, of A.\nThen enter the suit of the card as "
      "(S)pades, (C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo "
      "quit the game, enter \"~\". To see the rules, enter H.\n\nWhat card "
      "would you like to play, H1?: \nSorry H1, you don't have this card.\n"
      "Please choose another card.\n\n\nTo play a card, enter a digit from "
      "2-10, J, Q, K, of A.\nThen enter the suit of the card as (S)pades, "
      "(C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo quit the "
      "game, enter \"~\". To see the rules, enter H.\n\nWhat card would you "
      "like to play, H1?: quitting game...\n");
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 1);
}

TEST(TestCrazyEights, testPlayerTurn8ValidSuit) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }

  StandardCard* temp;
  temp = new StandardCard(StandardCard::DIAMONDS, 8);
  H1->hand.addCard(temp);
  temp = new StandardCard(StandardCard::SPADES, 8);
  H1->hand.addCard(temp);
  temp = new StandardCard(StandardCard::CLUBS, 8);
  H1->hand.addCard(temp);
  temp = new StandardCard(StandardCard::HEARTS, 8);
  H1->hand.addCard(temp);
  temp = new StandardCard(StandardCard::DIAMONDS, 14);
  H1->hand.addCard(temp);
  for (int i = 0; i < 4; i++) {
    std::ifstream inputStream;
    std::ofstream outputStream;
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;

    if (i == 0) {
      outputStream << "8 s" << std::endl;
      outputStream << "s" << std::endl;
    } else if (i == 1) {
      outputStream << "8 c" << std::endl;
      outputStream << "c" << std::endl;
    } else if (i == 2) {
      outputStream << "8 h" << std::endl;
      outputStream << "d" << std::endl;
    } else {
      outputStream << "8 d" << std::endl;
      outputStream << "h" << std::endl;
    }
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
  }
  EXPECT_EQ(consoleGameDisplay.str().substr(
    consoleGameDisplay.str().size()-29, consoleGameDisplay.str().size()),
    "You placed a 8 of Diamonds.\n\n");
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 1);
}

TEST(TestCrazyEights, testPlayerTurn8InvalidSuit) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp1;
  StandardCard* temp2;
  temp1 = new StandardCard(StandardCard::DIAMONDS, 8);
  H1->hand.addCard(temp1);
  temp2 = new StandardCard(StandardCard::DIAMONDS, 14);
  H1->hand.addCard(temp2);
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "y" << std::endl;
  outputStream << "8 d" << std::endl;
  outputStream << "e" << std::endl;
  outputStream << "d" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  C.playerTurn(H1, inputStream);
  inputStream.close();
  EXPECT_EQ(consoleGameDisplay.str().substr(
    consoleGameDisplay.str().size()-505, consoleGameDisplay.str().size()),
    "Would you like to play a card, H1? (y/n): \nTo play a card, enter a digit"
    " from 2-10, J, Q, K, of A.\nThen enter the suit of the card as (S)pades, "
    "(C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo quit the game,"
    " enter \"~\". To see the rules, enter H.\n\nWhat card would you like to "
    "play, H1?: What suit would you like to change it to? \nSorry H1, this is "
    "not a valid suit.\nPlease choose another suit.\n\nWhat suit would you like"
    " to change it to? You changed the suit to Diamonds\n\nYou placed a 8 of "
    "Diamonds.\n\n");
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 1);
}

TEST(TestCrazyEights, DISABLED_testPlayerTurnInvalidCard) {
  //causes mem leak
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp1;
  StandardCard* temp2;
  std::ifstream inputStream;
  std::ofstream outputStream;
    temp1 = new StandardCard(StandardCard::DIAMONDS, 14);
    temp2 = new StandardCard(StandardCard::DIAMONDS, 2);
    temp1->setSuit(C.gameSuit);
    temp2->setSuit(C.gameSuit);
    H1->hand.addCard(temp1);
    H1->hand.addCard(temp2);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "14 d" << std::endl;
    outputStream << "~" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    EXPECT_EQ(consoleGameDisplay.str().substr(
      consoleGameDisplay.str().size()-625, consoleGameDisplay.str().size()),
      "Would you like to play a card, H1? (y/n): \nTo play a card, enter a "
      "digit from 2-10, J, Q, K, of A.\nThen enter the suit of the card as"
      " (S)pades, (C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo "
      "quit the game, enter \"~\". To see the rules, enter H.\n\nWhat card "
      "would you like to play, H1?: \nSorry H1, you don't have this card.\n"
      "Please choose another card.\n\n\nTo play a card, enter a digit from "
      "2-10, J, Q, K, of A.\nThen enter the suit of the card as (S)pades, "
      "(C)lubs, (D)iamonds, or (H)earts.\nFor example \"3 H\"\nTo quit the "
      "game, enter \"~\". To see the rules, enter H.\n\nWhat card would you "
      "like to play, H1?: quitting game...\n");

  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 2);
}

TEST(TestCrazyEights, testPlayerTurnAllNumbers) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp;
  std::ifstream inputStream;
  std::ofstream outputStream;
  temp = new StandardCard(StandardCard::DIAMONDS, 14);
  H1->hand.addCard(temp);
  for (int i = 1; i <= 13; i++) {
    if (i == 8) {
      continue;
    }
    switch (C.gameSuit) {
      case StandardCard::DIAMONDS:
      temp = new StandardCard(StandardCard::DIAMONDS, i);
      H1->hand.addCard(temp);
      outputStream.open("./test/userInput.txt");
      outputStream << "y" << std::endl;
      outputStream << temp->cardValue() << " d" << std::endl;
      outputStream.close();
      inputStream.open("./test/userInput.txt", std::ifstream::in);
      C.playerTurn(H1, inputStream);
      inputStream.close();
      EXPECT_EQ(consoleGameDisplay.str().substr(
        consoleGameDisplay.str().size()-28-(temp->rankToName(
          temp->getValue()).size()), consoleGameDisplay.str().size()),
        ("You placed a " + temp->rankToName(
          temp->getValue()) + " of Diamonds.\n\n"));
      break;
      case StandardCard::HEARTS:
      temp = new StandardCard(StandardCard::HEARTS, i);
      H1->hand.addCard(temp);
      outputStream.open("./test/userInput.txt");
      outputStream << "y" << std::endl;
      outputStream << temp->cardValue() << " h" << std::endl;
      outputStream.close();
      inputStream.open("./test/userInput.txt", std::ifstream::in);
      C.playerTurn(H1, inputStream);
      inputStream.close();
      EXPECT_EQ(consoleGameDisplay.str().substr(
        consoleGameDisplay.str().size()-26-(temp->rankToName(
          temp->getValue()).size()),
        consoleGameDisplay.str().size()),
        ("You placed a " + temp->rankToName(
          temp->getValue()) + " of Hearts.\n\n"));
      break;
      case StandardCard::CLUBS:
      temp = new StandardCard(StandardCard::CLUBS, i);
      H1->hand.addCard(temp);
      outputStream.open("./test/userInput.txt");
      outputStream << "y" << std::endl;
      outputStream << temp->cardValue() << " c" << std::endl;
      outputStream.close();
      inputStream.open("./test/userInput.txt", std::ifstream::in);
      C.playerTurn(H1, inputStream);
      inputStream.close();
      EXPECT_EQ(consoleGameDisplay.str().substr(
        consoleGameDisplay.str().size()-25-(temp->rankToName(
          temp->getValue()).size()),
        consoleGameDisplay.str().size()),
        ("You placed a " + temp->rankToName(
          temp->getValue()) + " of Clubs.\n\n"));
      break;
      default:
      temp = new StandardCard(StandardCard::SPADES, i);
      H1->hand.addCard(temp);
      outputStream.open("./test/userInput.txt");
      outputStream << "y" << std::endl;
      outputStream << temp->cardValue() << " s" << std::endl;
      outputStream.close();
      inputStream.open("./test/userInput.txt", std::ifstream::in);
      C.playerTurn(H1, inputStream);
      inputStream.close();
      EXPECT_EQ(consoleGameDisplay.str().substr(
        consoleGameDisplay.str().size()-26-(temp->rankToName(
          temp->getValue()).size()),
        consoleGameDisplay.str().size()),
        ("You placed a " + temp->rankToName(
          temp->getValue()) + " of Spades.\n\n"));
    }
  }
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(H1->hand.getSize(), 1);
}

TEST(TestCrazyEights, testGetTopNumber) {
  std::stringstream consoleGameDisplay;
  std::streambuf *sbuf = std::cout.rdbuf();
  std::cout.rdbuf(consoleGameDisplay.rdbuf());
  std::vector<Player*> P;
  Player* H1 = new Human("H1", 0);
  P.push_back(H1);
  Player* A1 =  new CrazyEightsAI(AI::EASY, 1);
  P.push_back(A1);
  Player* A2 = new CrazyEightsAI(AI::EASY, 2);
  P.push_back(A2);
  Player* A3 = new CrazyEightsAI(AI::EASY, 3);
  P.push_back(A3);
  CrazyEights C(1, P);
  C.preGame();
  for (int i = 0; i < 5; i++) {
    Card* temp = H1->hand.getTop();
    H1->hand.removeCard(temp);
    delete temp;
  }
  StandardCard* temp1;
  StandardCard* temp2;
  std::ifstream inputStream;
  std::ofstream outputStream;
  switch (C.gameSuit) {
    case StandardCard::DIAMONDS:
    temp1 = new StandardCard(StandardCard::DIAMONDS, 2);
    H1->hand.addCard(temp1);
    temp2 = new StandardCard(StandardCard::HEARTS, 2);
    H1->hand.addCard(temp2);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 d" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    break;
    case StandardCard::HEARTS:
    temp1 = new StandardCard(StandardCard::HEARTS, 2);
    H1->hand.addCard(temp1);
    temp2 = new StandardCard(StandardCard::CLUBS, 2);
    H1->hand.addCard(temp2);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 h" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    break;
    case StandardCard::CLUBS:
    temp1 = new StandardCard(StandardCard::CLUBS, 2);
    H1->hand.addCard(temp1);
    temp2 = new StandardCard(StandardCard::SPADES, 2);
    H1->hand.addCard(temp2);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 c" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    break;
    default:
    temp1 = new StandardCard(StandardCard::SPADES, 2);
    H1->hand.addCard(temp1);
    temp2 = new StandardCard(StandardCard::DIAMONDS, 2);
    H1->hand.addCard(temp2);
    outputStream.open("./test/userInput.txt");
    outputStream << "y" << std::endl;
    outputStream << "2 s" << std::endl;
    outputStream.close();
    inputStream.open("./test/userInput.txt", std::ifstream::in);
    C.playerTurn(H1, inputStream);
    inputStream.close();
    break;
  }
  std::cout.rdbuf(sbuf);
  EXPECT_EQ(C.getTopNumber(), 2);
}
