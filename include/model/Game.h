/**
* @author Hatash
* @date 2021-4
*/

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include "Player.h"
#include "AI.h"
#include "Card.h"
#include "CardSet.h"
#include "Discard.h"
#include "Deck.h"
#include "InputHandling.h"
/**
* Implementation of a Game.
*/
class Game {
 public:
  bool gameOver = false;
  InputHandling IH;
  enum GameType {GOFISH = 1, CRAZYEIGHTS, JUNGLESPEED};

  /**
  * Default Constructor.
  * Creates a card game with a specific number of players and decks.
  * Calls createPlayer to create player objects.
  * @param players the number of players.
  * @param decks the number of decks to be used.
  */
  Game(const int decks, std::vector <Player*> p);

  /**
  * Destructor.
  */
  virtual ~Game();

  /**
  * Reset the selected game.
  */
  virtual void resetGame();

  /**
  * Displays the rules of the selected game.
  */
  virtual void printRules() = 0;

  /**
  * Output the scores of each player.
  */
  void printScore();

  /**
  * Getter function that returns the size of the selected hand.
  * @return an int for the size of a hand.
  */
  int getHandSize() {return HAND_SIZE;}

  /**
  * Output the game rankings, using the player names.
  */
  void printWinner();

  /**
  * Deal cards out to each player. Uses Players and transferCards.
  * @param handSize how many cards may be dealt to each players hand.
  */
  void dealCards(int handSize);

  /**
  * Initializes pregame set up of the selected game.
  * Calls the Deck Generator to create a deck of size (numDecks) * deckSize.
  */
  virtual void preGame();

  /**
  * Controls how a round starts, functions, and ends of the selected game.
  * @param userInput is the iStream for the human player inputs.
  */
  virtual void round(std::istream& userInput);

  /**
  * Getter function that returns the number of players.
  * @return an integer indicating the number of players in a game.
  */
  int getNumPlayers() const;

  /**
  * Getter function that returns the number of decks.
  * @return an integer indicating the number of decks.
  */
  int getNumDecks() const;

  /**
  * Getter function that returns all the players in the game.
  * @return a vector container with pointers to all the players in it.
  */
  std::vector<Player*> getPlayers() const;

  /**
  * In charge of picking up cards, giving cards away, putting down cards.
  * Called by dealCards.
  * @param location the initial location of the card.
  * @param detination the final destination of the card.
  * @param c the card to be transfered.
  */
  void transferCards(CardSet* location, CardSet* destination,
  const Card* c);

  /**
  * The structure of a game.
  * @param userInput handles the human player's inputs.
  */
  virtual void play(std::istream& userInput);

  /**
  * Defines the turn of a human player.
  * @param p the player whose turn is being defined.
  * @param userInput handles the human player's inputs.
  */
  virtual void playerTurn(Player* p, std::istream& userInput) = 0;

  /**
  * Defines the turn of an AI player.
  * @param p the player whose turn is being defined.
  */
  virtual void AITurn(Player* p) = 0;

  /**
  * Defines the end of a game.
  * Called at the end of the game or when a player inputs '~'.
  */
  void quitGame();

  /**
  * Getter function for the rank of the topCard.
  */
  int getTopNumber();

 protected:
  int numPlayers;
  int numDecks;
  GameType type;
  int HAND_SIZE;
  std::vector<Player*> Players;
  Deck* mainDeck = nullptr;
  Discard stockPile;
};

#endif
