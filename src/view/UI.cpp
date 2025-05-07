#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Game.h"
#include "Player.h"
#include "Human.h"
#include "UI.h"
#include "GoFish.h"
#include "JungleSpeed.h"
#include "CrazyEights.h"

UI::UI() {}
UI::~UI() {}

Game::GameType UI::chooseGame(std::istream& userInput) {
  std::string gameChoice = "";

  std::cout << std::endl << "What game would you like to play?" << std::endl;
  std::cout << "Enter G for GoFish, C for CrazyEights, or J for JungleSpeed: ";
  userInput >> gameChoice;
  IH.clearStream(userInput);

  if ((std::tolower(gameChoice[0])) == 'g') {
    std::cout << "You chose Go Fish." << std::endl;
    return Game::GOFISH;
  } else if ((std::tolower(gameChoice[0])) == 'c') {
    std::cout << "You chose Crazy Eights." << std::endl;
    return Game::CRAZYEIGHTS;
  } else {
    std::cout << "You chose Jungle Speed." << std::endl;
    std::vector<Player*> P;
    Player* H1 = new Human("H1", 0);
    P.push_back(H1);
    Player* A1 =  new JungleSpeedAI(AI::EASY, 1);
    P.push_back(A1);
    JungleSpeed J(1, P);
    J.printRules();
    return Game::JUNGLESPEED;
  }
}

const int UI::getNumOpponents(std::istream& userInput) {
  int i = 0;
  std::string response = "";
  do {
    std::cout << std::endl << "How many opponents would you like " <<
    "to play against";
    std::cout << "?: ";
    userInput >> response;
    IH.clearStream(userInput);
    if (!IH.isLegalInt(response)) {
      std::cout << "\nInvalid response, please try again.\n" << std::endl;
      continue;
    } else {
      i = std::stoi(response);
    }
    if (!(i > 0 && i <= MAX_OPPONENTS)) {
      std::cout << "Please enter a number between 0 and " << MAX_OPPONENTS
      << " inclusive." << std::endl << std::endl;
    }
  } while (!(i > 0 && i <= MAX_OPPONENTS) || (!IH.isLegalInt(response)));
  std::cout << "You are playing against " << i << " opponent" <<
  ((i > 1)? "s." : ".") << std::endl;
  return i;
}

const int UI::getNumDecks(std::istream& userInput) {
  int i;
  std::string response;
  do {
  std::cout << std::endl << "How many decks would you like to play with? ";
  userInput >> response;
  IH.clearStream(userInput);
  if (!IH.isLegalInt(response)) {
    std::cout << "\nInvalid response, please try again.\n" << std::endl;
    continue;
  } else {
    i = std::stoi(response);
  }
  i = 1;
} while ((!IH.isLegalInt(response)) || i != 1); //MAX AND MIN
  std::cout << "The current version can only be played with";
  std::cout << " one deck of cards." << std::endl << std::endl;
  return i;
}

Game* UI::createGame(std::istream& userInput) {
  Game::GameType gameChoice = chooseGame(userInput);
  std::vector<Player*> v = createPlayers(gameChoice, userInput);
  const int numDecks = getNumDecks(userInput);
  Game* g;
  switch (gameChoice) {
  case Game::GOFISH: {
    g = new GoFish(numDecks, v);
    break;
  }
  case Game::CRAZYEIGHTS: {
    g = new CrazyEights(numDecks, v);
    break;
  }
  default: g = new JungleSpeed(numDecks, v);
  }
  return g;
}

Player* UI::createHuman(std::string s) {
  return new Human(s, 0);
}

Player* UI::generateAI(Game::GameType t, AI::Level l, int id) {
    switch (t) {
    case Game::GOFISH: {
      return new GoFishAI(l, id);
      break;
    }
    case Game::CRAZYEIGHTS: {
      return new CrazyEightsAI(l, id);
      break;
    }
    default: return new JungleSpeedAI(l, id);
  }
}

std::vector<Player*> UI::createPlayers(Game::GameType gameChoice,
  std::istream& userInput) {
  std::string name = "";
  std::string aiChoice = "";
  std::vector<Player*> temp;
  AI::Level aiLevel;
  bool easyChosen = false;
  bool normalChosen = false;
  bool hardChosen = false;

  std::cout << std ::endl << "Enter your name: ";
  userInput >> name;
  IH.clearStream(userInput);

  std::cout << "Welcome, " << name << "." << std::endl;
  temp.push_back(createHuman(name));

  const int tempInt = getNumOpponents(userInput);
  std::cout << std::endl;
  if (tempInt > 1) {
    for (int i = 1; i <= tempInt; i++) {
      std::cout << std::endl << "Set the level of AI " << i
      << ". You may only select a particular level once " << std::endl;
      std::cout << "\nEnter (E)asy, (N)ormal, or (H)ard): ";
      userInput >> aiChoice;
      IH.clearStream(userInput);

      if (tolower(aiChoice[0]) == 'e') {
        if (easyChosen) {
          std::cout << std::endl;
          std::cout << "Easy has already been chosen," <<
          " please pick another level.";
          std::cout << std::endl;
          i--;
          continue;
        }
        easyChosen = true;
        std::cout << "You chose AI level easy." << std::endl;
        aiLevel = AI::EASY;
        temp.push_back(generateAI(gameChoice, aiLevel, i));
      } else if (tolower(aiChoice[0]) == 'n') {
        if (normalChosen) {
          std::cout << std::endl;
          std::cout << "Normal has already been chosen," <<
          " please pick another level.";
          std::cout << std::endl;
          i--;
          continue;
        }
        normalChosen = true;
        std::cout << "You chose AI level normal." << std::endl;
        aiLevel = AI::NORMAL;
        temp.push_back(generateAI(gameChoice, aiLevel, i));
      } else if (tolower(aiChoice[0]) == 'h') {
        if (hardChosen) {
          std::cout << std::endl;
          std::cout << "Hard has already been chosen," <<
          " please pick another level.";
          std::cout << std::endl;
          i--;
          continue;
        }
        hardChosen = true;
        std::cout << "You chose AI level hard." << std::endl;
        aiLevel = AI::HARD;
        temp.push_back(generateAI(gameChoice, aiLevel, i));
      } else {
        std::cout << std::endl;
        std::cout << "Invalid choice please choose a valid " <<
        " level to play against." << std::endl;
        i--;
        continue;
      }
    }
} else {
  std::cout << "What level of AI would you like to play against? ";
  std::cout << "\nEnter (E)asy, (N)ormal, or (H)ard): ";
  userInput >> aiChoice;
  IH.clearStream(userInput);

  switch (std::tolower(aiChoice[0])) {
    case 'h': {
        aiLevel = AI::HARD;
        std::cout << "You chose AI level hard." << std::endl;
        break;
      }
    case 'n': {
      aiLevel = AI::NORMAL;
      std::cout << "You chose AI level normal." << std::endl;
      break;
    }
    default: aiLevel = AI::EASY;
    std::cout << "You chose AI level easy." << std::endl;
  }

  temp.push_back(generateAI(gameChoice, aiLevel, 1));
}
  return temp;
}
