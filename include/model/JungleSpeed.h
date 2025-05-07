/**
* @author Hatash
* @date 2021-4
*/

#ifndef JUNGLESPEED_H_INCLUDED
#define JUNGLESPEED_H_INCLUDED

#include <iostream>
#include <vector>
#include <ctime>
#include "JungleSpeedAI.h"
#include "Game.h"
#include "Player.h"
#include "Discard.h"
#include "Card.h"
#include "AI.h"
#include "Deck.h"

/**
* Implements the Jungle Speed Game
*/

class JungleSpeed : public Game {
 public:
  bool nameCriteria = true;
  /**
  * Default constructor
  * @param decks if the number of decks to be used
  * @param p is the vector of players
  */
  JungleSpeed(const int decks, std::vector <Player*> p);

  /**
  * Destructor
  */
  virtual ~JungleSpeed();

  /**
  * After a game has been played and the player chooses to play another game
  * resetGame will reset the decks and re-deal
  */
  void resetGame();

  /**
  * Prints out rules of Jungle JungleSpeed
  * A player can ask for the rules at anytime time throughout the game.
  */
  void printRules();

  /**
  * Defines the pre game set up
  * Uses Players
  */
  void preGame();


  /**
  * Implement the timer function to determine the players reaction time.
  * Used in declareWinner
  * @return a double represent the reation time in seconds.
  */
  double reactionTime(std::istream& userInput);

  /**
  * If the players time is less than the AI's, then the player will be declared
  * the winner. Else, the AI is declared the winner.
  * @param reactionTimes a vector of doubles representing the players'
  * reaction time.
  * @return a pointer to a player whose reaction time is being determined.
  */
  Player* declareLoser(std::vector<double> reactionTimes);

  /**
  * Controls the duel when the same card is flipped by both players.
  * Calls reactionTime and passes it into declareWinner.
  * Duel handles with the card transfer to the loser.
  * After the card transfer is complete, it will check is any hands are empty.
  * @param playersDuel a vector of Player pointers representingall the players
  * in a duel.
  * @param userinput an istream used to read the user response.
  * @return a pointer to the player who wins the duel.
  */
  Player* duel(std::vector<Player*> playersDuel, std::istream& userInput);

  /**
  * Runs a human's turn.
  * @param p is a the player who is taking their turn
  */
  void playerTurn(Player* p, std::istream& userInput);

  /**
  * A getter function that returns the size of the flipped card stack.
  * @return an integer representing the size of the stack.
  */
  int getFlippedCardsSize() {return flippedCards.size();}

  /**
  * Runs an AI's turn.
  * @param p the player whose turn it is.
  */
  void AITurn(Player* p);

  /**
  * Determines if 2 cards match.
  * @param c the card to compare to.
  * @return -1 if the cards do not match and 1 if they match.
  */
  int isMatch(Card* c);

  /**
  * The structure of a round calls playerturn and AITurn.
  * @param userinput an istream to read in the user response.
  */
  void round(std::istream& userInput);

  /**
  * Declares the winner of a duel.
  * @param reactionTime a vector of doubles containing players reaction times.
  * @return a pointer to the player with the best reaction time.
  */
  Player* declareWinner(std::vector<double> reactionTimes);

  /**
  * A getter function that returns the size of the stockpile.
  * @return an integer representing the size of the stockpile.
  */
  int getStockPileSize() {return stockPile.getSize();}

  /**
  * Handles the players in a duel.
  * @param c the card that is triggered the duel.
  * @param pos the position of the player
  * @return a vector of player pointers in the duel.
  */
  std::vector<Player*> inDuel(Card* c, int pos);

  std::vector<Discard*> flippedCards;
};

#endif
