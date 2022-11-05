#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "UI.h"
#include "Game.h"
#include "GoFish.h"
#include "JungleSpeed.h"
#include "CrazyEights.h"
#include "gtest/gtest.h"
#include "AI.h"
#include "Player.h"
#include "Human.h"

TEST(TestUI, testGetNumOpponents) {
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "3" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  if (inputStream.fail()) {
    std::cout << std::endl << "THIS DOESN'T WORK" << std::endl;
  }
  EXPECT_EQ(ui.getNumOpponents(inputStream), 3);
  inputStream.close();
}

TEST(TestUI, testGetNumOpponentsInvalid1) {
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "test" << std::endl << "3" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  if (inputStream.fail()) {
    std::cout << std::endl << "THIS DOESN'T WORK" << std::endl;
  }
  EXPECT_EQ(ui.getNumOpponents(inputStream), 3);
  inputStream.close();
}

TEST(TestUI, testGetNumOpponentsInvalid2) {
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "5" << std::endl << "3" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  if (inputStream.fail()) {
    std::cout << std::endl << "THIS DOESN'T WORK" << std::endl;
  }
  EXPECT_EQ(ui.getNumOpponents(inputStream), 3);
  inputStream.close();
}

TEST(TestUI, testGetNumDecks) {
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "1" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  EXPECT_EQ(ui.getNumDecks(inputStream), 1);
  inputStream.close();
}

TEST(TestUI, testGetNumDecksInvalid) {
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << std::endl << "Hiiiii" << std::endl << "1" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  EXPECT_EQ(ui.getNumDecks(inputStream), 1);
  inputStream.close();
}



TEST(TestUI, testGenerateAI) {
  UI ui;

  GoFishAI* p = dynamic_cast<GoFishAI*>(ui.generateAI(Game::GOFISH,
    AI::EASY, 1));
  EXPECT_EQ(p->getDifficultyLevel(), 1);
  EXPECT_EQ(p->getID(), 1);
  EXPECT_EQ(p->getName(), "AI 1");
  delete p;
}

TEST(TestUI, testCreateHuman) {
  UI ui;
  Player* p = ui.createHuman("Cadence");
  EXPECT_EQ(p->getID(), 0);
  EXPECT_EQ(p->getName(), "Cadence");
  delete p;
}

TEST(TestUI, testChooseGameGoFish) {
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "gaga" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  EXPECT_EQ(ui.chooseGame(inputStream), Game::GOFISH);
  inputStream.close();
}

TEST(TestUI, testChooseGameCrazyEights) {
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "crazyyyyyy" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  EXPECT_EQ(ui.chooseGame(inputStream), Game::CRAZYEIGHTS);
  inputStream.close();
}

TEST(TestUI, testChooseGameJungleSpeed) {
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "hello" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  EXPECT_EQ(ui.chooseGame(inputStream), Game::JUNGLESPEED);
  inputStream.close();
}

TEST(TestUI, testCreatePlayersEasy) {
  std::vector<Player*> returnedPlayers;
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "Ugo" << std::endl << "2" << std::endl << "EASY"
  << std::endl << "HARD" << std::endl;

  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  returnedPlayers = ui.createPlayers(Game::GOFISH, inputStream);
  EXPECT_EQ(returnedPlayers.size(), 3);
  EXPECT_EQ(returnedPlayers[0]->getID(), 0);
  EXPECT_EQ(returnedPlayers[0]->getName(), "Ugo");
  EXPECT_EQ(returnedPlayers[1]->getID(), 1);
  EXPECT_EQ(returnedPlayers[1]->getName(), "AI 1");
  EXPECT_EQ(returnedPlayers[2]->getID(), 2);
  EXPECT_EQ(returnedPlayers[2]->getName(), "AI 2");
  inputStream.close();

  for (auto p : returnedPlayers)
    delete p;
}

TEST(TestUI, testCreatePlayersNormal) {
  std::vector<Player*> returnedPlayers;
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "Ugo" << std::endl << "1" << std::endl << "NEVER"
  << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  returnedPlayers = ui.createPlayers(Game::GOFISH, inputStream);
  EXPECT_EQ(returnedPlayers.size(), 2);
  EXPECT_EQ(returnedPlayers[0]->getID(), 0);
  EXPECT_EQ(returnedPlayers[0]->getName(), "Ugo");
  EXPECT_EQ(returnedPlayers[1]->getID(), 1);
  EXPECT_EQ(returnedPlayers[1]->getName(), "AI 1");
  inputStream.close();

  for (auto p : returnedPlayers)
    delete p;
}

TEST(TestUI, testCreatePlayersInvalidLevel) {
  std::vector<Player*> returnedPlayers;
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "Ugo" << std::endl << "2" << std::endl << "David wuz here"
  << std::endl << "Normal" << std::endl << "Hard" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  returnedPlayers = ui.createPlayers(Game::GOFISH, inputStream);
  EXPECT_EQ(returnedPlayers.size(), 3);
  EXPECT_EQ(returnedPlayers[0]->getID(), 0);
  EXPECT_EQ(returnedPlayers[0]->getName(), "Ugo");
  EXPECT_EQ(returnedPlayers[1]->getID(), 1);
  EXPECT_EQ(returnedPlayers[1]->getName(), "AI 1");
  EXPECT_EQ(returnedPlayers[2]->getID(), 2);
  EXPECT_EQ(returnedPlayers[2]->getName(), "AI 2");
  inputStream.close();

  for (auto p : returnedPlayers)
    delete p;
}

TEST(TestUI, testCreatePlayersHard) {
  std::vector<Player*> returnedPlayers;
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "Ugo" << std::endl << "3" << std::endl << "HARD"
  << std::endl << "EASY" << std::endl << "NORMAL" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  returnedPlayers = ui.createPlayers(Game::GOFISH, inputStream);
  EXPECT_EQ(returnedPlayers.size(), 4);
  EXPECT_EQ(returnedPlayers[0]->getID(), 0);
  EXPECT_EQ(returnedPlayers[0]->getName(), "Ugo");
  EXPECT_EQ(returnedPlayers[1]->getID(), 1);
  EXPECT_EQ(returnedPlayers[1]->getName(), "AI 1");
  EXPECT_EQ(returnedPlayers[2]->getID(), 2);
  EXPECT_EQ(returnedPlayers[2]->getName(), "AI 2");
  EXPECT_EQ(returnedPlayers[3]->getID(), 3);
  EXPECT_EQ(returnedPlayers[3]->getName(), "AI 3");
  inputStream.close();

  for (auto p : returnedPlayers)
    delete p;
}

TEST(TestUI, testCreatePlayersDuplicateCheck1) {
  std::vector<Player*> returnedPlayers;
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "Ugo" << std::endl << "3" << std::endl << "HARD"
  << std::endl << "HARD" << std::endl << "EASY" << std::endl << "EASY"
  << std::endl << "NORMAL" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  returnedPlayers = ui.createPlayers(Game::GOFISH, inputStream);
  EXPECT_EQ(returnedPlayers.size(), 4);
  EXPECT_EQ(returnedPlayers[0]->getID(), 0);
  EXPECT_EQ(returnedPlayers[0]->getName(), "Ugo");
  EXPECT_EQ(returnedPlayers[1]->getID(), 1);
  EXPECT_EQ(returnedPlayers[1]->getName(), "AI 1");
  EXPECT_EQ(returnedPlayers[2]->getID(), 2);
  EXPECT_EQ(returnedPlayers[2]->getName(), "AI 2");
  EXPECT_EQ(returnedPlayers[3]->getID(), 3);
  EXPECT_EQ(returnedPlayers[3]->getName(), "AI 3");
  inputStream.close();

  for (auto p : returnedPlayers)
    delete p;
}

TEST(TestUI, testCreatePlayersDuplicateCheck2) {
  std::vector<Player*> returnedPlayers;
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "Ugo" << std::endl << "3" << std::endl << "NORMAL"
  << std::endl << "NORMAL" << std::endl << "EASY" << std::endl << "HARD"
  << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  returnedPlayers = ui.createPlayers(Game::GOFISH, inputStream);
  EXPECT_EQ(returnedPlayers.size(), 4);
  EXPECT_EQ(returnedPlayers[0]->getID(), 0);
  EXPECT_EQ(returnedPlayers[0]->getName(), "Ugo");
  EXPECT_EQ(returnedPlayers[1]->getID(), 1);
  EXPECT_EQ(returnedPlayers[1]->getName(), "AI 1");
  EXPECT_EQ(returnedPlayers[2]->getID(), 2);
  EXPECT_EQ(returnedPlayers[2]->getName(), "AI 2");
  EXPECT_EQ(returnedPlayers[3]->getID(), 3);
  EXPECT_EQ(returnedPlayers[3]->getName(), "AI 3");
  inputStream.close();

  for (auto p : returnedPlayers)
    delete p;
}

TEST(TestUI, testCreateGameGoFish) {
  std::vector<Player*> returnedPlayers;
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "Gooooo" << std::endl << "David" << std::endl << "1"
  << std::endl << "EASY" << std::endl << "1" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  Game* g = ui.createGame(inputStream);

  EXPECT_EQ(g->getNumPlayers(), 2);
  EXPECT_EQ(g->getNumDecks(), 1);
  returnedPlayers = g->getPlayers();
  EXPECT_EQ(returnedPlayers[0]->getID(), 0);
  EXPECT_EQ(returnedPlayers[0]->getName(), "David");
  EXPECT_EQ(returnedPlayers[1]->getID(), 1);
  EXPECT_EQ(returnedPlayers[1]->getName(), "AI 1");
  inputStream.close();

  delete g;
}

TEST(TestUI, testCreateGameCrazyEights) {
  std::vector<Player*> returnedPlayers;
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "crazyyyyyy" << std::endl << "Noel" << std::endl << "1"
  << std::endl << "EASY" << std::endl << "1" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  Game* g = ui.createGame(inputStream);

  EXPECT_EQ(g->getNumPlayers(), 2);
  EXPECT_EQ(g->getNumDecks(), 1);
  returnedPlayers = g->getPlayers();
  EXPECT_EQ(returnedPlayers[0]->getID(), 0);
  EXPECT_EQ(returnedPlayers[0]->getName(), "Noel");
  EXPECT_EQ(returnedPlayers[1]->getID(), 1);
  EXPECT_EQ(returnedPlayers[1]->getName(), "AI 1");
  inputStream.close();

  delete g;
}

TEST(TestUI, testCreateGameJungleSpeed) {
  std::vector<Player*> returnedPlayers;
  UI ui;
  std::ifstream inputStream;
  std::ofstream outputStream;
  outputStream.open("./test/userInput.txt");
  outputStream << "hello" << std::endl << "Cadence" << std::endl << "1"
  << std::endl << "HARD" << std::endl << "1" << std::endl;
  outputStream.close();
  inputStream.open("./test/userInput.txt", std::ifstream::in);
  Game* g = ui.createGame(inputStream);

  EXPECT_EQ(g->getNumPlayers(), 2);
  EXPECT_EQ(g->getNumDecks(), 1);
  returnedPlayers = g->getPlayers();
  EXPECT_EQ(returnedPlayers[0]->getID(), 0);
  EXPECT_EQ(returnedPlayers[0]->getName(), "Cadence");
  EXPECT_EQ(returnedPlayers[1]->getID(), 1);
  EXPECT_EQ(returnedPlayers[1]->getName(), "AI 1");
  inputStream.close();

  delete g;
}
