#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "Game.h"
#include "Player.h"
#include "DeckGenerator.h"
#include "GoFishAI.h"
#include "Card.h"
#include "AI.h"
#include "GoFish.h"
#include "StandardCard.h"
#include "GameActions.h"
#include "InputHandling.h"

  GoFish::GoFish(const int decks, std::vector <Player*> p) :
  Game{decks, p} {
    type = Game::GOFISH;
    HAND_SIZE = 7;
    books = 0;
    DeckGenerator d;
    mainDeck = d.makeDeck(Game::GOFISH);
    for (int i = 0; i < p.size(); i++) {
      std::vector<int> v;
      v.push_back(0);
      previousAsk.push_back(v);
    }
  }

  GoFish::~GoFish() {}

  void GoFish::resetGame() {
    books = 0;
    Game::resetGame();
  }

  void GoFish::printRules() {
    std::cout << "RULES FOR GOFISH:" << std::endl;
    std::cout << "Each player is dealt 7 cards, with the remaining cards";
    std::cout << " placed in the deck. \n"
    << "When it is your turn you may choose an opponent for a card. \n"
    << "The requested card must have the same rank as a card in your hand. \n"
    << "If the opponent has the card in their hand, they will give all of";
    std::cout << " their cards of that rank. \n"
    << "After an affirmative request you may make another request. \n"
    << "If the opponent does not have the card in their hand, they will tell";
    std::cout << " you to GoFish. \n"
    << "If the opponent says GoFish, draw a card from the stockpile. \n"
    << "If you have no cards in your hand, you may draw from the stockpile";
    std::cout << " and make a request based on the card you drew. \n"
    << "The players turn ends after they are told to GoFish. \n"
    << "A book will be made automatically when there are 4 cards of the same";
    std::cout << " rank in a players hand. \n"
    << "The game ends when all 13 books have been made. \n"
    << "The winner is the player with the most books. \n"
    << "After the game is over the player will be given the option to play";
    std::cout << " another game or to quit. \n"
    << std::endl;
  }

  void GoFish::makeBook(const int cardRank) {
    GameActions selfRequest;
    std::vector<Card*> v1;
    StandardCard* temp;
    for (auto it = Players.begin(); it != Players.end(); it++) {
      if ((*it)->getMyTurn()) {
        v1 = selfRequest.makeRequest((*it), cardRank);
        temp = dynamic_cast<StandardCard*>(v1[0]);
        for (auto itr = v1.begin(); itr != v1.end(); itr++) {
          transferCards(&((*it)->hand), &stockPile, (*itr));
        }
        (*it)->setRoundPoints((*it)->getRoundPoints()+1);
        std::cout << ((*it == Players[0])? "You" : (*it)->getName());
        std::cout << " made a book of " << temp-> rankToName(cardRank) <<
        "\'s" << std::endl << std::endl;
        //usleep(1000000);
        break;
      }
  }
  books++;
  if (books == (13*numDecks)) {
    gameOver = true;
    if (Players[0]->getMyTurn()) {
      Players[0]->setMyTurn(false);
      //usleep(1000000);
    }
  }
}

  void GoFish::goFish() {
    for (auto it = Players.begin(); it != Players.end(); it++) {
      if ((*it)->getMyTurn()) {
        transferCards(mainDeck, &((*it)->hand), mainDeck->getTop());
      }
    }
  }

  void GoFish::playerTurn(Player* p, std::istream& userInput) {
    std::string requestedRank;
    Player* requestedAI;
    GameActions request;
    int convertedString;
    std::vector<Card*> temporaryHand;
    p->setMyTurn(true);
    if (hasBook(p) > 0) {
      makeBook(hasBook(p));
    }
    do {
      if (gameOver) {
      //usleep(1000000);
        return;
      }
      do {
        if ((p-> hand.getSize() == 0) && (mainDeck-> getSize() == 0)) {
          std::cout << "There are no cards left in the deck and in your" <<
          " hand " << p->getName() << ", skipping turn." << std::endl;
          p->setMyTurn(false);
          //usleep(1000000);
          return;
        }
        //usleep(1000000);
        p->hand.display();
        temporaryHand = p->hand.getHand();
        if (temporaryHand.size() == 0) {
          std::cout << "A card has been added to your hand" << std::endl;
          transferCards(mainDeck, &(p->hand), mainDeck->getTop());
          //usleep(1000000);
          p->hand.display();
        }
        std::cout << "What would you like to do, " << p->getName() << "?"
        << std::endl << std::endl;
        std::cout << "To request a card, enter a digit from 2-10, J, Q, K, "
        << "or A.\nTo quit the game, enter \"~\". To see the rules, enter H.";
        std::cout << std::endl << std::endl << "Response: ";
        userInput >> requestedRank;
        IH.clearStream(userInput);

        if (tolower(requestedRank[0]) == 'h') {
          std::cout << std::endl;
          printRules();
        }
        switch (tolower(requestedRank[0])) {
          case '2': convertedString = 2; break;
          case '3': convertedString = 3; break;
          case '4': convertedString = 4; break;
          case '5': convertedString = 5; break;
          case '6': convertedString = 6; break;
          case '7': convertedString = 7; break;
          case '8': convertedString = 8; break;
          case '9': convertedString = 9; break;
          case '1': convertedString = 10; break;
          case 'a': convertedString = 1; break;
          case 'j': convertedString = 11; break;
          case 'q': convertedString = 12; break;
          case '~': quitGame(); return; break;
          default: convertedString = 13; break;
        }
        if (!(p->isInHand(convertedString))) {
          std::cout << "\nSorry " << p->getName()
          << ", you may only request a rank that is already" <<
          " in your hand.\nPlease make another request." << std::endl
          << std::endl;
        }
      } while (tolower(requestedRank[0] == 'h') ||
       !(p->isInHand(convertedString)));
       previousAsk[0].push_back(convertedString);

    int numAI = getNumPlayers() - 1;
    std::string response = "";
    int aiNumber = 0;
    if (numAI > 1) {
      do {
      std::cout << "\nWho would you like to ask, " << p->getName() << "?\n"
      << std::endl;
      for (int i = 1; i <= numAI; i++) {
        std::cout << "To ask AI " << i << ", enter " << i << std::endl;
      }
      std::cout << "Response: ";
      userInput >> response;
      IH.clearStream(userInput);

      if (!IH.isLegalInt(response)) {
        std::cout << "\nInvalid response " << p->getName()
        << ", please try again.\n" << std::endl;
      } else {
        aiNumber = std::stoi(response);
        if (aiNumber < 1  || aiNumber > numAI) {
        std::cout << "\nInvalid AI number " << p->getName()
        << ", please try again.\n" << std::endl;
      }
    }
  } while (!IH.isLegalInt(response) || aiNumber < 1  || aiNumber > numAI);
} else {
  aiNumber = 1;
}
std::cout << std::endl;

    requestedAI = Players.at(aiNumber);

     int vectorSize = temporaryHand.size();
     temporaryHand.erase(temporaryHand.begin(),
     temporaryHand.begin()+vectorSize);

    requestHandler(p, Players.at(requestedAI->getID()),
    request.makeRequest(Players.at(requestedAI->getID()), convertedString));
  } while (p->getMyTurn() && !gameOver);
}

  void GoFish::AITurn(Player* p) {
    GoFishAI* temp = dynamic_cast<GoFishAI*>(p);
    GameActions selfRequest;
    std::vector<Card*> temporaryHand;
    p->setMyTurn(true);
    if (hasBook(p) > 0) {
      makeBook(hasBook(p));
    }

    do {
      if ((p-> hand.getSize() == 0) && (mainDeck-> getSize() == 0)) {
        std::cout << "There are no cards left in the deck and in ";
        std::cout << p->getName() << "\'s hand.... skipping turn.\n"
        << std::endl;
        p->setMyTurn(false);
        //usleep(1000000);
        return;
      }
      if (gameOver) {
        //usleep(1000000);
        return;
      }
      temporaryHand = p->hand.getHand();
      int requestedRank;
      Player* requestedPlayer;
      StandardCard* returnedCard;
      if (temporaryHand.size() == 0) {
        transferCards(mainDeck, &(p->hand), mainDeck->getTop());
      }
      returnedCard = dynamic_cast<StandardCard*>(temp->strategy(previousAsk));
      requestedRank = returnedCard-> getValue();

      previousAsk[p->getID()].push_back(requestedRank);

      requestedPlayer = temp->ChoosePlayer(this);

      std::cout << p->getName() << " wants a "
      << returnedCard-> rankToName(requestedRank) << " from " <<
      ((requestedPlayer == Players[0])? "you" : requestedPlayer->getName())
      << std::endl;

      requestHandler(p, requestedPlayer,
        selfRequest.makeRequest(requestedPlayer, requestedRank));
    } while (p->getMyTurn() && !gameOver);
  }

  void GoFish::requestHandler(Player* requester, Player* requestee,
    std::vector<Card*> returnedVector) {
    if (returnedVector.size() == 0) {
    std::cout << ((requester == Players[0])? "You" : requester->getName())
    << " had to go fish." << std::endl;
    //usleep(1000000);
    if (mainDeck->getSize() > 0) {
      goFish();
      std::cout << "A card has been added to " <<
      ((requester == Players[0])? "your" : "it's") << " hand." << std::endl
      << std::endl;
      //usleep(1000000);
      if (hasBook(requester) > 0) {
        makeBook(hasBook(requester));
      }
    } else {
      std::cout << "The deck is empty, no card could be picked up"
      << std::endl << std::endl;
      //usleep(1000000);
    }

    requester->setMyTurn(false);
} else {
  StandardCard* temp2;
  for (int i = 0; i < returnedVector.size(); i++) {
  temp2 = dynamic_cast<StandardCard*>(returnedVector.at(i));
  transferCards(&(requestee->hand), &(requester->hand), temp2);
  }

  std::cout << std::endl << requestee->getName() << " gave " <<
  ((requester == Players[0])? "you" : requester->getName()) << " " <<
   returnedVector.size() << " card" <<
   ((returnedVector.size() > 1)? "s." : ".") << std::endl << std::endl;
  //usleep(1000000);

  if (hasBook(requester) > 0) {
    makeBook(hasBook(requester));
    }
  }
}

int GoFish::hasBook(Player* p) {
  std::vector<Card*> returnedCards;
  GameActions selfRequest;

  for (int i = 1; i <= 13; i++) {
    returnedCards = selfRequest.makeRequest(p, i);
    if (returnedCards.size() >= 4) {
      return i;
    }
  }
  return 0;
}
