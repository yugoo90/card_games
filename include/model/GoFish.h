/**
* @author Hatash
* @date 2021-4
*/

#ifndef GOFISH_H_INCLUDED
#define GOFISH_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "Game.h"
#include "Player.h"
#include "AI.h"
#include "GoFishAI.h"
#include "Card.h"
#include "Deck.h"
#include "StandardCard.h"
#include "Discard.h"

/**
* Implementation of Go Fish Game
*/
class GoFish : public Game {
 public:
  /**
  * Default constructor
  */
  GoFish(const int decks, std::vector<Player*> p);

  /**
  * Destructor
  */
  virtual ~GoFish();

  /**
  * resets the game setting all players' pints to zero.
  */
  void resetGame();

  /**
  * Prints rules of Go Fish
  * A player can ask for the rules at anytime throughout the game
  */
  void printRules();

  /**
  * Makes a book everytime a player gets 4 cards of equal rank.
  * @param cardRank an integer representing the value of a card.
  */
  void makeBook(const int cardRank);

  /**
  * When a request is denied, goFish calls transferCards
  * Takes a card from the stockpile and places it into the players hand.
  */
  void goFish();

  /**
  * Defines the turn of a human player.
  * @param p player whose turn is being defined.
  * @param userInput takes the response of the player.
  */
  void playerTurn(Player* p, std::istream& userInput);

  /**
  * Defines the turn of an AI player.
  * @param p thr player whose turn it is.
  */
  void AITurn(Player* p);

  /**
  * checks to see if a players turn should end or keep going.
  * @param requester the player who is requesting for a card.
  * @param requestee the player of whom a card is being requested.
  * @param v a container with a pointer to the cards.
  */
  void requestHandler(Player* requester, Player* requestee,
    std::vector<Card*> v);

  /**
  * Checks to see if a player has 4 cards of equal rank.
  * @param p the player whose hand is being checked for a book.
  * @ return returns 4 if a player has a book, 0 otherwise.
  */
  int hasBook(Player* p);

  /**
  * The container of the previously asked cards and the player who asked.
  */
  std::vector<std::vector<int>> previousAsk;

 private:
  int books;
};

#endif
