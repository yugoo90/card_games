/**
* @author Hatash
* @date 2021-4
*/

#ifndef DECKGENERATOR_H_INCLUDED
#define DECKGENERATOR_H_INCLUDED

#include <memory>
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
  std::shared_ptr<Deck> makeDeck(const Game::GameType t);

  /**
  * Makes a deck
  * @param t a string representing the type of game deck to be created.
  * @param twoPlayers allows us to check if there are two or more players
  * when creating a deck.
  * @return a deck of cards.
  */
  std::shared_ptr<Deck> makeDeck(const Game::GameType t, const bool twoPlayers);

  /**
  * Makes a deck
  * @param d empty deck*
  * @return a deck of cards.
  */
  std::shared_ptr<Deck> makeStandardDeck(std::shared_ptr<Deck> d);

  /**
  * Makes a deck
  * @param d empty deck*
  * @return a deck of cards.
  */
  std::shared_ptr<Deck> make72JungleSpeed(std::shared_ptr<Deck> d);

  /**
  * Adds special cards to a JungleSpeed deck.
  * Used when there are more than 2 players.
  * @param d JungleSpeed deck with 72 cards.
  * @return an 80 card deck.
  */
  std::shared_ptr<Deck> makeExtraJungleSpeed(std::shared_ptr<Deck> d);
};

#endif
