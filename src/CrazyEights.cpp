#include <unistd.h>
#include <iostream>
#include <vector>
#include <string>
#include "CrazyEights.h"
#include "Game.h"
#include "Player.h"
#include "CrazyEightsAI.h"
#include "DeckGenerator.h"
#include "StandardCard.h"
#include "Deck.h"
#include "Card.h"
#include "GoFish.h"
#include "AI.h"
#include "GameActions.h"


  CrazyEights::CrazyEights(const int decks, std::vector <Player*> p) :
Game{decks, p} {
    type = Game::CRAZYEIGHTS;
    HAND_SIZE = 5;
    DeckGenerator d;
    mainDeck = d.makeDeck(Game::CRAZYEIGHTS);
  }

  CrazyEights::~CrazyEights() {}

  void CrazyEights::printRules() {
    std::cout << "RULES FOR CRAZY EIGHTS: " << std::endl;
    std::cout << "The objective of this game is to have the highest number of ";
    std::cout << "points after the completion of all the rounds." << std::endl;
    std::cout << "Each player is dealt 5 cards. The remaining cards will be ";
    std::cout << "placed in the deck. The top card of the deck will be ";
    std::cout << "placed upright onto the stockpile." << std::endl;
    std::cout << "When it is your turn, you may place a card from your hand ";
    std::cout << "that matches the suit or rank of the card on the stockpile."
    << std::endl;
    std::cout << "Or you may place an eight to change to a suit ";
    std::cout << "of your choice." << std::endl;
    std::cout << "If you do not have a valid card to place, you must draw a ";
    std::cout << "card from the deck." << std::endl;
    std::cout << "You may draw as many cards as you like from the deck, ";
    std::cout << "but you must play a card at the end of your turn."
    << std::endl;
    std::cout << "A round is over when a player runs out of cards. ";
    std::cout << "The player will then be awarded points from the ";
    std::cout << "opponents hand." << std::endl;
    std::cout << "The scoring system is as follows: " << std::endl;
    std::cout << "8: 50 points." << std::endl;
    std::cout << "10, J, Q, & K: 10 points." << std::endl;
    std::cout << "A: 1 point." << std::endl;
    std::cout << "Every other card is awarded its face value." << std::endl;
    std::cout << "The winner of the game will be declared after the player ";
    std::cout << "decides to quit the game." << std::endl;
  }

  void CrazyEights::preGame() {
    Game::preGame();
    while (dynamic_cast<StandardCard*>(mainDeck-> getTop())->getValue() == 8) {
      mainDeck->shuffleCardSet();
    }
    gameSuit = dynamic_cast<StandardCard*>(mainDeck->getTop())->getSuit();
    transferCards(mainDeck, &stockPile, mainDeck->getTop());
  }

  void CrazyEights::scoringSystem(Player* winner) {
    int totalPoints = 0;
    std::vector<Card*> hnd;
    Player* temp;
    for (auto it = Players.begin(); it != Players.end(); it++) {
      hnd = (*it)-> hand.getHand();
      for (int i = 0; i < hnd.size(); i++) {
        if ((dynamic_cast<StandardCard*>(hnd[i])-> getValue() < 11 &&
        dynamic_cast<StandardCard*>(hnd[i])-> getValue() != 8)) {
          totalPoints += dynamic_cast<StandardCard*>(hnd[i])-> getValue();
        } else if (dynamic_cast<StandardCard*>(hnd[i])-> getValue() > 10) {
          totalPoints += 10;
        } else {
          totalPoints += 50;
        }
      }
    }
    winner-> setRoundPoints(totalPoints);
  }

  void CrazyEights::playerTurn(Player* p, std::istream& userInput) {
    bool legalRequest = false;
    bool playTurn = false;
    std::string response = "";
    std::string placeCardRank = "";
    std::string placeCardSuit = "";
    StandardCard::Suit suitChoice;
    int cardChoice;
    //usleep(1000000);
    p->setMyTurn(true);

    do {
  if (!hasValidCard(p)) {
    std::cout << "You do not have a valid card in your hand, " << p->getName()
    << "." << std::endl;
    //usleep(1000000);
    if (mainDeck->getSize() == 0) {
      std::cout << "There are no cards left in the deck, skipping your turn."
      << std::endl << std::endl;
      //usleep(1000000);
      p->setMyTurn(false);
      return;
        }
        std::cout << "You picked up a " <<
        (mainDeck->getTop())->stringOfWholeCard() << "." << std::endl
        << std::endl;
        //usleep(1000000);
        transferCards(mainDeck, &(p->hand), mainDeck->getTop());
      }
  } while (!hasValidCard(p));
  do {
    p->hand.display();
    //usleep(2000000);
    std::cout << "The top card is ";
    stockPile.display();
    std::cout << std::endl;
    if (gameSuit !=
      (dynamic_cast<StandardCard*>(stockPile.getTop()))->getSuit()) {
        std::cout << "The game suit has been changed to "
        << dynamic_cast<StandardCard*>(
          stockPile.getTop())->suitToString(gameSuit) << "." << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Would you like to play a card, " << p->getName()
    << "? (y/n): ";
    userInput >> response;
    IH.clearStream(userInput);

    if (tolower(response[0]) == '~') {
    quitGame();
    return;
  }

    if (tolower(response[0]) == 'y') {
    playTurn = true;

    do {
    std::cout << "\nTo play a card, enter a digit from 2-10, J, Q, K, of A.";
    std::cout << "\nThen enter the suit of the card as (S)pades, (C)lubs, " <<
    "(D)iamonds, or (H)earts." << std::endl;
    std::cout << "For example \"3 H\"" << std::endl;
    std::cout<< "To quit the game, enter \"~\". To see the rules, enter H.";
    std::cout << std::endl << std::endl << "What card would you like to play, "
    << p->getName() << "?: ";
    userInput >> placeCardRank;

    if (tolower(placeCardRank[0]) == '~') {
      quitGame();
      return;
    }

    if (placeCardRank[0] == 'h') {
      std::cout << std::endl;
      printRules();
      continue;
    }
    userInput >> placeCardSuit;
    IH.clearStream(userInput);

    switch (tolower(placeCardRank[0])) {
      case '2': cardChoice = 2; break;
      case '3': cardChoice = 3; break;
      case '4': cardChoice = 4; break;
      case '5': cardChoice = 5; break;
      case '6': cardChoice = 6; break;
      case '7': cardChoice = 7; break;
      case '8': cardChoice = 8; break;
      case '9': cardChoice = 9; break;
      case '1': cardChoice = 10; break;
      case 'a': cardChoice = 1; break;
      case 'j': cardChoice = 11; break;
      case 'q': cardChoice = 12; break;
      default: cardChoice = 13; break;
    }

    switch (tolower(placeCardSuit[0])) {
      case 's': suitChoice = StandardCard::SPADES; break;
      case 'c': suitChoice = StandardCard::CLUBS; break;
      case 'd': suitChoice = StandardCard::DIAMONDS; break;
      case '~': quitGame(); return; break;
      default: suitChoice = StandardCard::HEARTS; break;
    }

    Card* selectedCard = new StandardCard(suitChoice, cardChoice);
    StandardCard* checker = dynamic_cast<StandardCard*>(
      p->hand.getCard(selectedCard));

    if (checker == nullptr) {
      std::cout << "\nSorry " <<p->getName()
      << ", you don't have this card." <<
      "\nPlease choose another card." << std::endl << std::endl;
      continue;
    }

    StandardCard& topCardCopy = dynamic_cast<StandardCard&>(
      *(stockPile.getTop()));
      if (checker->getValue() == 8) {
        bool validSuit = false;
        do {
          std::cout << "What suit would you like to change it to? ";
          userInput >> placeCardSuit;
          IH.clearStream(userInput);
          switch (tolower(placeCardSuit[0])) {
            case 's': suitChoice = StandardCard::SPADES; validSuit = true;
            break;
            case 'c': suitChoice = StandardCard::CLUBS; validSuit = true;
            break;
            case 'd': suitChoice = StandardCard::DIAMONDS; validSuit = true;
            break;
            case 'h': suitChoice = StandardCard::HEARTS; validSuit = true;
            break;
            default: break;
          }
          if (!validSuit) {
            std::cout << "\nSorry " <<p->getName()
            << ", this is not a valid suit." <<
            "\nPlease choose another suit." << std::endl << std::endl;
            continue;
          }
        } while (!validSuit);
        gameSuit = suitChoice;
        std::cout << "You changed the suit to " <<
        checker->suitToString(gameSuit) << std::endl << std::endl;
        //usleep(1000000);
      } else if ((checker->getSuit() == gameSuit) ||
      (topCardCopy.sameRank(*checker))) {
      } else {
        std::cout << "\nSorry " <<p->getName()
        << ", this is not a valid card." <<
        "\nPlease choose another card." << std::endl << std::endl;
        continue;
      }
      std::cout << "You placed a " <<
      (p->hand.getCard(selectedCard))->stringOfWholeCard() << "."
      << std::endl << std::endl;
      //usleep(1000000);
      transferCards(&(p->hand), &stockPile, (p->hand.getCard(selectedCard)));
      if (dynamic_cast<StandardCard*>(stockPile.getTop())->getValue() != 8) {
        gameSuit = dynamic_cast<StandardCard*>(stockPile.getTop())->getSuit();
      }
      legalRequest = true;
    if (p->hand.getSize() == 0) {
      gameOver = true;
      std::cout << "You have no more cards in your hand " << p->getName()
      << "!" <<
      std::endl << std::endl;
      //usleep(1000000);
      scoringSystem(p);
    }
    delete selectedCard;
  } while (!legalRequest);
} else {
  //usleep(1000000);
  if (mainDeck->getSize() > 0) {
  std::cout << "You picked up a ";
  mainDeck->getTop()->displayCard();
  std::cout << std::endl;
  //usleep(1000000);
  transferCards(mainDeck, &(p->hand), mainDeck->getTop());
} else {
  std::cout << "There are no cards left in the deck, skipping your turn."
  << std::endl << std::endl;
  //usleep(1000000);
  p->setMyTurn(false);
  return;
}
}
} while (!playTurn);
p->setMyTurn(false);
}

void CrazyEights::AITurn(Player* p) {
  CrazyEightsAI* castedAI = dynamic_cast<CrazyEightsAI*>(p);
  std::vector<Card*> tempHand;
  bool placedCard = false;
  Card* temp;
  p->setMyTurn(true);

  do {
    Card* topCard = new StandardCard(gameSuit,
      dynamic_cast<StandardCard*>(stockPile.getTop())->getValue());
    temp = castedAI->strategy(topCard);
    delete topCard;
  if (temp != nullptr) {
    if (dynamic_cast<StandardCard*>(temp)->getValue() == 8) {
      tempHand = (p->hand).getHand();
      switch (castedAI->getDifficultyLevel()) {
        case AI::EASY :
        gameSuit = dynamic_cast<StandardCard*>(temp)->getSuit(); break;
        case AI::NORMAL :
        gameSuit = dynamic_cast<StandardCard*>(tempHand[0])->getSuit(); break;
        default:
        GameActions ga;
        std::vector<Card*> hnd = (p->hand).getHand();
        gameSuit = ga.mostPrevalentSuit(hnd);
        break;
      }
    }
    std::cout << p->getName() << " has placed a ";
    temp->displayCard();
    std::cout << " on the stockPile." << std::endl << std::endl;
    //usleep(1000000);
    if (dynamic_cast<StandardCard*>(temp)->getValue() == 8) {
      std::cout << p->getName() << " changed the suit to "
      << dynamic_cast<StandardCard*>(temp)->suitToString(gameSuit) << "."
      << std::endl << std::endl;
      //usleep(1000000);
    }
    placedCard = true;
    transferCards(&(p->hand), &stockPile, temp);
    if (dynamic_cast<StandardCard*>(stockPile.getTop())->getValue() != 8) {
      gameSuit = dynamic_cast<StandardCard*>(stockPile.getTop())->getSuit();
    }
    if (p->hand.getSize() == 0) {
      std::cout << p->getName() << " has no more cards in their hand!" <<
      std::endl << std::endl;
      gameOver = true;
      //usleep(1000000);
      scoringSystem(p);
    }
  } else {
    if (mainDeck->getSize() == 0) {
      bool noValidCard = true;
      for (auto it = Players.begin(); it != Players.end(); it++) {
        if (hasValidCard(*it)) {
          noValidCard = false;
          break;
        }
      }
      if (noValidCard) {
        gameOver = true;
        std::cout << "It's a draw..." << std::endl << std::endl;
        //usleep(1000000);
        return;
      }
      std::cout << "There are no cards left in the deck, skipping turn."
      << std::endl << std::endl;
      p->setMyTurn(false);
      //usleep(1000000);
      return;
    }
    std::cout << p->getName() << " picked up a card." << std::endl;
    //usleep(1000000);
    transferCards(mainDeck, &(p->hand), mainDeck->getTop());
  }
} while (!placedCard);
p->setMyTurn(false);
}

bool CrazyEights::hasValidCard(Player* p) {
  const StandardCard& topCard = dynamic_cast<const StandardCard&>(
    *(stockPile.getTop()));
    std::vector<Card*> temp = p->hand.getHand();
    for (auto itr = temp.begin(); itr != temp.end(); itr++) {
      StandardCard& tempHandCard = dynamic_cast<StandardCard&>(*(*itr));
      if ((tempHandCard.getSuit() == gameSuit) || tempHandCard.sameRank(topCard)
      || (tempHandCard.getValue() == 8)) {
        return true;
      }
    }
    return false;
  }
