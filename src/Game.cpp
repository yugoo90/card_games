#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "AI.h"
#include "Player.h"
#include "Card.h"
#include "JungleSpeed.h"
#include "CrazyEights.h"
#include "GoFish.h"
#include "Human.h"
#include "Player.h"
#include "CardSet.h"
#include "Deck.h"
#include "Hand.h"
#include "Game.h"

  Game::Game(const int decks, std::vector <Player*> p) {
    numPlayers = p.size();
    numDecks = decks;
    Players = p;
  }

  Game::~Game() {
    for (auto p : Players) {
      delete p;
    }
    delete mainDeck;
    mainDeck = nullptr;
  }

  std::vector<Player*> Game::getPlayers() const {
    return Players;
  }

  void Game::printScore() {
    if (type != JUNGLESPEED) {
  std::cout << "      GAME OVER.\n\nYour score for this round is: " <<
  Players[0]->getRoundPoints() << std::endl;
  for (auto it = Players.begin()+1; it != Players.end(); it++) {
    std::cout << (*it)->getName() << "\'s score is: " << (*it)->getRoundPoints()
    << std::endl;
  }
  std::cout << std::endl;
} else {
  std::cout << "      GAME OVER.\n\n";
}
}

  int Game::getNumPlayers() const {
    return numPlayers;
  }

  void Game::printWinner() {
    std::cout << "Your total score is: " << Players[0]->getTotalPoints()
    << std::endl;
    for (auto it = Players.begin()+1; it != Players.end(); it++) {
      std::cout << (*it)->getName() << "\'s total score is: "
      << (*it)->getTotalPoints() << std::endl;
  }
  std::vector<int> v;
  for (auto it = Players.begin(); it != Players.end(); it++) {
    v.push_back((*it)->getTotalPoints());
  }
  std::vector<int>::iterator itr = v.begin();
  int temp = *std::max_element(itr, (itr + (*this).getNumPlayers()));
  std::vector<Player*> p1;
  for (auto it = Players.begin(); it != Players.end(); it++) {
    if ((*it)->getTotalPoints() == temp) {
      p1.push_back(*it);
    }
  }
  std::cout << std::endl;
  if (p1.size() > 1) {
    std::cout << "There was a tie between ";
    std::cout << ((p1[0] == Players[0])? "you" : p1[0]->getName());
    for (auto it = p1.begin()+1; it != p1.end(); it++) {
      std::cout << " and ";
      std::cout << (*it)->getName();
    }
  } else {
    std::cout << ((p1[0] == Players[0])? "You" : p1[0]->getName())
    << " won the game";
    }
    std::cout << " with " << temp << " points." << std::endl;
    if (p1[0]->getID() == 0) {
      std::cout << "Congrats!! Good game " << Players[0]->getName() << "!!"
      << std::endl;
    } else {
      std::cout << "Better luck next time " << Players[0]->getName() << "!"
      << std::endl;
    }
      return; }

  void Game::dealCards(int handSize) {
    for (int i = 0; i< handSize; i++) {
      for (auto it = Players.begin(); it != Players.end(); it++) {
        transferCards(mainDeck, &((*it)->hand), mainDeck->getTop());
    }
  }
}

void Game::transferCards(CardSet* location, CardSet* destination,
  const Card* c) {
  Card* temp = location->getCard(c);
  location->removeCard(c);
  destination->addCard(temp);
}

int Game::getNumDecks() const {
  return numDecks;
}

void Game::round(std::istream& userInput) {
  while (!gameOver) {
    playerTurn(Players[0], userInput);
    for (int i = 1; i <= numPlayers-1; i++) {
      if (gameOver) {
        return;
      }
      AITurn(Players[i]);
    }
  }
}

void Game::resetGame() {
  std::vector<Card*> hnd;
  const int stockPileSize = stockPile.getSize();
  for (int i = 0; i < stockPileSize; i++) {
    transferCards(&stockPile, mainDeck, stockPile.getTop());
  }
  for (auto it = Players.begin(); it != Players.end(); it++) {
    hnd = (*it)-> hand.getHand();
    for (int i = 0; i < hnd.size(); i++) {
      transferCards(&((*it)->hand), mainDeck, hnd[i]);
    }
  }
  for (int i = 0; i < Players.size(); i++) {
    Players[i]->setRoundPoints(0);
    Players[i]-> setMyTurn(false);
  }
  gameOver = false;
  (*this).preGame();
}

void Game::play(std::istream& userInput) {
  std:: string response = "";
  preGame();
  do {
    round(userInput);
    if (Players[0]->getMyTurn()) {
      std::cout << "Returning to the main menu." <<std::endl << std::endl;
      return;
    }
    for (auto it = Players.begin(); it != Players.end(); it++) {
    (*it)->setTotalPoints();
    }
    printScore();
    std::cout << "Would you like to play another round? (y/n) ";
    userInput >> response;
    IH.clearStream(userInput);

    if (tolower(response[0]) == 'y') {
      resetGame();
      std::cout << std::endl;
      //usleep(1000000);
    }
  } while (tolower(response[0]) == 'y');

  std::cout << std::endl;
  printWinner();
  std::cout << "Returning to the main menu." <<std::endl << std::endl;
  //usleep(1000000);
}

void Game::preGame() {
  mainDeck->shuffleCardSet();
  dealCards(HAND_SIZE);
}

void Game::quitGame() {
  std::cout << "quitting game..." << std::endl;
  gameOver = true;
}

int Game::getTopNumber() {
  StandardCard* topCard = dynamic_cast<StandardCard*>(stockPile.getTop());
  return topCard->getValue();
}
