/**
* @author Hatash
* @date 2021-4
*/

#ifndef CRAZYEIGHTS_H_INCLUDED
#define CRAZYEIGHTS_H_INCLUDED

#include <iostream>
#include <vector>
#include "Player.h"
#include "Game.h"
#include "Deck.h"
#include "Card.h"
#include "CrazyEightsAI.h"
#include "StandardCard.h"
#include "AI.h"
#include "Discard.h"

/**
* Crazy Eights Game Implementation.
*/
class CrazyEights : public Game {
 public:
  StandardCard::Suit gameSuit = StandardCard::HEARTS;

  /**
  * Default constructor.
  * @param decks an integer representing the number of decks.
  * @param p a container for all the players in the game.
  */
  CrazyEights(const int decks, std::vector <Player*> p);

  /**
  * Destructor.
  */
  virtual ~CrazyEights();

  /**
  * Prints the rules of Crazy 8's.
  */
  void printRules();

  /**
  * Defines pregame set up.
  */
  void preGame();

  /**
  * Called at the end of each round.
  * @param winner the player who won the round.
  */
  void scoringSystem(Player* winner);

  /**
  * Defines the turn of a human player.
  * @param p the player whose turn is being defined.
  * @param userInput the iStream for the player.
  */
  void playerTurn(Player* p, std::istream& userInput);

  /**
  * Defines the turn of an AI player.
  * @param p the player whose turn is being defined.
  */
  void AITurn(Player* p);

  /**
  * Determines if a player has a playable card in their hand.
  * @param p the player who's hand is being searched.
  */
  bool hasValidCard(Player* p);
};

#endif
