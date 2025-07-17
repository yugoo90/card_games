#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include "JungleSpeed.h"
#include "Game.h"
#include "JungleSpeedAI.h"
#include "Player.h"
#include "Human.h"
#include "AI.h"
#include "Card.h"
#include "Discard.h"
#include "DeckGenerator.h"
#include "JungleSpeedCard.h"


  JungleSpeed::JungleSpeed(const int decks, std::vector <std::shared_ptr<Player>> p) :
  Game{decks, p} {
    type = Game::JUNGLESPEED;
    DeckGenerator d;
    if (numPlayers == 2) {
      mainDeck = d.makeDeck(Game::JUNGLESPEED, true);
    } else {
      mainDeck = d.makeDeck(Game::JUNGLESPEED);
    }
    HAND_SIZE = (numDecks * mainDeck-> getSize()) / numPlayers;

    for (auto it = Players.begin(); it != Players.end(); it++) {
      flippedCards.push_back(std::make_shared<Discard>());
    }
    std::cout << std::endl << std::endl;
  }

  JungleSpeed::~JungleSpeed() {}

  void JungleSpeed::round(std::istream& userInput) {
    while (!gameOver) {
      int posOfLastPlayedTurn = -1;

      for (int i = 0; i <= numPlayers-1; i++) {
        for (auto it = Players.begin(); it!= Players.end(); it++) {
          if ((*it)->getMyTurn()) {
            if ((*it)->getID() == 0) {
              playerTurn(Players[0], userInput);
              posOfLastPlayedTurn = 0;
              it = Players.begin();
            } else {
              AITurn((*it));
              posOfLastPlayedTurn = (*it)->getID();
              it = Players.begin();
              }
            }
          }
        if (posOfLastPlayedTurn != -1) {
          if (posOfLastPlayedTurn == numPlayers - 1) {
            i = 0;
          } else {
            i = posOfLastPlayedTurn + 1;
          }
          posOfLastPlayedTurn = -1;
        }

        if (gameOver) {
          return;
        }
        if (i == 0) {
          playerTurn(Players[0], userInput);
        } else {
        AITurn(Players[i]);
      }
      }
    }
  }

  void JungleSpeed::resetGame() {
    for (auto it = Players.begin(); it != Players.end(); it++) {
      int stockPileSize = flippedCards[(*it)->getID()]->getSize();
      for (int i = 0; i < stockPileSize; i++) {
        transferCards(flippedCards[(*it)->getID()], stockPile,
        flippedCards[(*it)->getID()]->getTop());
      }
    }
    Game::resetGame();
  }

  void JungleSpeed::printRules() {
    std::cout << "RULES FOR JUNGLESPEED:" << std::endl;
    std::cout << "The objective of this game is to get rid of all cards in "
    << "your hand and your personal discard pile. \n";
    std::cout << "The deck is divided as evenly as possible between the "
    << "players, with the remaining cards placed onto the stockPile. \n";
    std::cout << "The cards are placed face down. \n";
    std::cout << "Players alternate flipping the top card of their hand, and"
    << " placing them in the stockPile. \n";
    std::cout << "If two cards match in shape, a duel is initiated. \n";
    std::cout << "During a duel, the first player to press the letter \"J\" "
    << "and hit the enter/return key, is declared the winner of that duel. \n";
    std::cout << "The loser of the duel takes the cards from its own discard "
    << "pile and the winners discard pile "
    << "and puts them at the bottom of their hand. \n";
    std::cout << "The player who lost the duel, starts the card flipping"
    << " process again. \n";
    std::cout << "If a player accidentally presses any key, they"
    << " automatically take all the cards from each players discard pile. \n";
    std::cout << "If an all-in-card is placed, then a duel is called between"
    << " all players.\nThe winner will place their discard pile into the main "
    << "stockPile, and then restart the card flipping process. \n";
    std::cout << "If an all-out-card is placed, then all players must flip a"
    << " card from their hand, if no matches are found, "
    << "the round continues. \n";
    std::cout << "A colours card changes the matching criteria from shapes to"
    << " colors. This remains in effect until the colours card is covered. \n";
    std::cout << "Other rules: \n";
    std::cout << "If a players last flipped card is a special card, they "
    << "automatically win the round. \n"
    << std::endl;
  }

  void JungleSpeed::preGame() {
    Game::preGame();
    const int remainingCards = mainDeck->getSize();
    for (int i = 0; i < remainingCards; i++) {
      transferCards(mainDeck, stockPile, mainDeck->getTop());
    }
  }

  double JungleSpeed::reactionTime(std::istream& userInput) {
    std::time_t now;
    std::time_t then;
    double seconds;

    std::string input = "";
    std::time(&now);
    userInput >> input;
    std::time(&then);

    if (input[0] == 'j') {
      seconds = std::difftime(then, now);
    } else {
      std::cout << "You knocked over the totem!!";
      seconds = 10;
    }

    return seconds;
  }

 std::shared_ptr<Player> JungleSpeed::declareLoser(std::vector<double> reactionTimes) {
    std::vector<double>::iterator itr = reactionTimes.begin();
    double maxTime = *std::max_element(itr, (itr + reactionTimes.size()));

    for (auto it = (Players.begin()+1); it != Players.end(); it++) {
      if ((std::dynamic_pointer_cast<JungleSpeedAI>(*it)->getResponseTime()) == maxTime) {
        std::cout << (*it)->getName() << " lost the duel!!" << std::endl;
        return (*it);
      }
    }
    std::cout << "You lost the duel :(" << std::endl;
    return Players[0];
  }

  std::shared_ptr<Player> JungleSpeed::declareWinner(std::vector<double> reactionTimes) {
    std::vector<double>::iterator itr = reactionTimes.begin();
    double maxTime = *std::min_element(itr, (itr + reactionTimes.size()));

    for (auto it = (Players.begin()+1); it != Players.end(); it++) {
      if ((std::dynamic_pointer_cast<JungleSpeedAI>(*it)->getResponseTime()) == maxTime) {
        std::cout << (*it)->getName() << " won the duel!!" << std::endl;
        return (*it);
      }
    }
    std::cout << "You won the duel!!" << std::endl;
    return Players[0];
  }

std::shared_ptr<Player> JungleSpeed::duel(std::vector<std::shared_ptr<Player>> playersDuel,
    std::istream& userInput) {
      bool allInCardHasBeenPlayed = false;
      int allInID = -1;

    for (auto it = playersDuel.begin(); it != playersDuel.end(); it++) {
      if ((*it)->getMyTurn()) {
        std::shared_ptr<JungleSpeedCard> temp1 = std::dynamic_pointer_cast<JungleSpeedCard>(
          flippedCards[(*it)->getID()]->getTop());
          if (((temp1->getName() == "AllIn1")
          || (temp1->getName() == "AllIn2")
          || (temp1->getName() == "AllIn3"))) {
            allInCardHasBeenPlayed  = true;
            allInID = (*it)->getID();
          }
      }
    }

    if (!allInCardHasBeenPlayed) {
    for (auto it = playersDuel.begin(); it != playersDuel.end(); it++) {
      int stockPileSize = flippedCards[(*it)->getID()]->getSize();
      for (int i = 0; i < stockPileSize; i++) {
        transferCards(flippedCards[(*it)->getID()], stockPile,
        flippedCards[(*it)->getID()]->getTop());
      }
    }
  }

    std::vector<double> playersReactionTimes;
    for (int i = 0; i < playersDuel.size(); i++) {
      if (playersDuel[i]->getID() == 0) {
        double d = reactionTime(userInput);
        playersReactionTimes.push_back(d);
      } else {
        playersReactionTimes.push_back(
          std::dynamic_pointer_cast<JungleSpeedAI>(playersDuel[i])->getResponseTime());
      }
    }

    std::shared_ptr<Player> loser = nullptr;
    std::shared_ptr<Player> winner = nullptr;
    if (!allInCardHasBeenPlayed) {
      loser = declareLoser(playersReactionTimes);
    } else {
      winner = declareWinner(playersReactionTimes);
      const int pileSize = flippedCards[winner->getID()]->getSize();
      for (int i = 0; i < pileSize; i++) {
        transferCards(flippedCards[winner->getID()], stockPile,
        flippedCards[winner->getID()]->getTop());
      }
      stockPile->shuffleCardSet();
      return winner;
    }

    stockPile->shuffleCardSet();
    const int pileSize = stockPile->getSize();
    for (int i = 0; i < pileSize; i++) {
      transferCards(stockPile, (loser->hand), stockPile->getTop());
    }
    for (auto it = Players.begin(); it != Players.end(); it++) {
      if ((((*it)->hand)->getSize() == 0) &&
      (flippedCards[(*it)->getID()]->getSize() == 0)) {
        gameOver = true;
        (*it)->setRoundPoints(1);

        if ((*it)->getID() == 0) {
          std::cout << "You have no cards in your hand!" << std::endl
          << "You win the game!";
        } else {
          std::cout << (*it)->getName() << " has no cards in their hand!"
          << std::endl <<(*it)->getName() << " wins the game!";
      }
        std::cout << std::endl << std::endl;
        Players[0]->setMyTurn(false);
      }
    }
    return loser;
  }

  void JungleSpeed::playerTurn(std::shared_ptr<Player> p, std::istream& userInput) {
    std::vector<std::shared_ptr<Player>> returnedPlayers;

    if (numPlayers == 2 && Players[0]->hand->getSize() == 0
    && Players[1]->hand->getSize() == 0) {
      gameOver = true;
      std::cout << std::endl << "It's a draw between you and AI 1" << std::endl
      << std::endl;
      p->setMyTurn(false);
      //usleep(1000000);
      Players[0]->setRoundPoints(1);
      Players[1]->setRoundPoints(1);
      return;
    }

    do {
    if (p->hand->getSize() == 0) {
      std::cout << ((p->getID() == 0)? "Your" : p->getName());
      std::cout << " top card is: ";
      flippedCards[p->getID()]->display();
      return;
    }
    p->setMyTurn(true);
    if (gameOver) {
      p->setMyTurn(false);
      return;
    }
    std::cout <<((p->getID() == 0)? "You" : p->getName());
    std::cout << " flipped a ";
    p->hand->getTop()->displayCard();
    std::cout << std::endl;
    //usleep(2000000);
    std::this_thread::sleep_for(std::chrono::seconds(2000000));
    transferCards((p->hand), flippedCards[p->getID()], p-> hand->getTop());
    std::shared_ptr<JungleSpeedCard> temp1 = std::dynamic_pointer_cast<JungleSpeedCard>
    (flippedCards[p->getID()]-> getTop());

    if (((p->hand)->getSize() == 0) && (temp1->getColour() == 5)) {
      gameOver = true;
      if (p->getID() == 0) {
        std::cout << "You have no cards in your hand!" << std::endl
        << "You win the game!";
      } else {
        std::cout << p->getName() << " has no cards in their hand!"
        << std::endl << p->getName() << " wins the game!";
    }
      std::cout << std::endl << std::endl;
      p->setMyTurn(false);
      p->setRoundPoints(1);
      return;
    }

    int matchCheck = isMatch(flippedCards[p->getID()]->getTop());
    if (matchCheck != -1) {
      std::vector<std::shared_ptr<Player>> matchedPlayers = inDuel((
        flippedCards[p->getID()])->getTop(), matchCheck);

      std::shared_ptr<Player> loser = duel(matchedPlayers, userInput);
      if (loser->getID() == p->getID()) {
        continue;
      } else {
        loser->setMyTurn(true);
      }
    }
    if ((temp1->getName() == "AllOut1") || (temp1->getName() == "AllOut2") ||
    (temp1->getName() == "AllOut3")) {
      returnedPlayers = inDuel(flippedCards[p->getID()]->getTop(), -1);
      if (returnedPlayers.size() > 0) {
        if (duel(returnedPlayers, userInput)->getID() == p->getID()) {
          continue;
        }
      } else {
        continue;
      }
    }
    if ((temp1->getName() == "AllIn1") || (temp1->getName() == "AllIn2") ||
    (temp1->getName() == "AllIn3")) {
      std::shared_ptr<Player> winner = duel(Players, userInput);
      if (winner->getID() == p->getID()) {
        continue;
      } else {
        winner->setMyTurn(true);
      }
    }
    p->setMyTurn(false);
  } while (p->getMyTurn() && !gameOver);
}

  void JungleSpeed::AITurn(std::shared_ptr<Player> p) {
    playerTurn(p, std::cin);
  }

  int JungleSpeed::isMatch(std::shared_ptr<Card> c) {
    const std::shared_ptr<JungleSpeedCard> temp = std::dynamic_pointer_cast<JungleSpeedCard>(c);
    std::shared_ptr<JungleSpeedCard> topCard;
    for (int i = 0; i < flippedCards.size(); i++) {
      if (flippedCards[i]->getSize() > 0) {
    topCard = std::dynamic_pointer_cast<JungleSpeedCard>(flippedCards[i]->getTop());
    if ((topCard->getName() == "Colors1")
    || (topCard->getName() == "Colors2")) {
      nameCriteria = false;
      break;
    } else {
      nameCriteria = true;
    }
  }
  }

    std::shared_ptr<JungleSpeedCard> j;
    for (int i = 0; i < flippedCards.size(); i++) {
      if (flippedCards[i]->getSize() > 0) {
      j = std::dynamic_pointer_cast<JungleSpeedCard>(flippedCards[i]->getTop());
      if (nameCriteria) {
        if ((j->sameName(temp)) && !(j->sameColour(temp))) {
            return i;
          }
      } else {
        if (!(j->sameName(temp)) && (j->sameColour(temp)) &&
        j->getColour() != JungleSpeedCard::SPECIAL) {
            return i;
          }
      }
    }
    }
    return -1;
  }

  std::vector<std::shared_ptr<Player>> JungleSpeed::inDuel(std::shared_ptr<Card> c, int pos) {
    std::vector<std::shared_ptr<Player>> returnedPlayers;
    std::shared_ptr<JungleSpeedCard> temp1 = std::dynamic_pointer_cast<JungleSpeedCard>(c);

    if ((temp1->getName() == "AllOut1") ||
    (temp1->getName() == "AllOut2") ||
    (temp1->getName() == "AllOut3")) {
      for (auto it = Players.begin(); it !=Players.end(); it++) {
        if (((*it)->hand)->getSize() > 0) {
        std::cout <<(((*it)->getID() == 0)? "You" : (*it)->getName());
        std::cout << " flipped a ";
        (*it)->hand->getTop()->displayCard();
        std::cout << std::endl;
        //usleep(1000000);
        transferCards(((*it)->hand), flippedCards[(*it)->getID()],
        (*it)->hand->getTop());
      }
      }
      for (auto it = Players.begin(); it !=Players.end(); it++) {
        if (isMatch((flippedCards[(*it)->getID()])->getTop()) != -1) {
          returnedPlayers.push_back(Players[isMatch(
            (flippedCards[(*it)->getID()])->getTop())]);
        }
      }
      return returnedPlayers;
    } else {
      for (auto it = Players.begin(); it != Players.end(); it++) {
        if ((*it)->getMyTurn()) {
        returnedPlayers.push_back(*it);
        break;
      }
    }
    returnedPlayers.push_back(Players[pos]);
    return returnedPlayers;
    }
  }
