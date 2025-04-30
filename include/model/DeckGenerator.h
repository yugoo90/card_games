/**
* @author Hatash
* @date 2021-4
*/

#ifndef DECKGENERATOR_H_INCLUDED
#define DECKGENERATOR_H_INCLUDED

#include <string>
#include "Deck.h"
#include "Game.h"
#include "JungleSpeedCard.h"

/**
* Implements the DeckGenerator class.
*/
class DeckGenerator {
 public:
  /**
  * Default constructor.
  */
  DeckGenerator();

  /**
  * Destructor.
  */
  virtual ~DeckGenerator();

  /**
  * Makes a deck.
  * @param t a string representing the type of game deck to be created.
  * @return a deck of cards.
  */
  Deck* makeDeck(const Game::GameType t);

  /**
  * Makes a deck
  * @param t a string representing the type of game deck to be created.
  * @param MoreThan2Players allows us to check if there are two or more players
  * when creating a deck.
  * @return a deck of cards.
  */
  Deck* makeDeck(const Game::GameType t, const bool twoPlayers);

  /**
  * Makes a deck
  * @param d empty deck*
  * @return a deck of cards.
  */
  Deck* makeStandardDeck(Deck* d);

  /**
  * Makes a deck
  * @param d empty deck*
  * @return a deck of cards.
  */
  Deck* make72JungleSpeed(Deck* d);

  /**
  * Adds special cards to a JungleSpeed deck.
  * Used when there are more than 2 players.
  * @param d JungleSpeed deck with 72 cards.
  * @return an 80 card deck.
  */
  Deck* makeExtraJungleSpeed(Deck* d);
};

#endif
