/**
* @author Hatash
* @date 2021-4
*/

#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "Player.h"
#include "GoFish.h"
#include "JungleSpeed.h"
#include "CrazyEights.h"
#include "InputHandling.h"


/**
* Implements UI
*/
class UI {
 public:
  static const int MAX_OPPONENTS = 3;
  InputHandling IH;

  /**
  * Default Constructor
  */
  UI();

  /**
  * Destructor
  */
  ~UI();

  /**
  * Determines which game the player wants to play by taking in a cin
  * @param input is the users choice of game
  * @return the selected Game
  */
  Game::GameType chooseGame(std::istream& input);

  /**
  * Creates and runs the specific game, by calling the constructor.
  * @param userInput
  * @return a Game pointer
  */
  std::shared_ptr<Game> createGame(std::istream& userInput);

  /**
  * @param userInput is the choice of the number of opponents
  * @return the number of opponents that they user chose to play against
  * Hard coded to 1 opponent
  */
  const int getNumOpponents(std::istream& userInput);

  /**
  * @param userInput is the choice of number of decks
  * @return the number of decks that the user chose to user
  * Hard coded to 1 deck
  */
  const int getNumDecks(std::istream& userInput);

  /**
  * Creates a new Player, returned to the game constructor
  * @param s the name of the player
  * @return The pointer to the player
  */
  std::shared_ptr<Player> createHuman(std::string s);

  /**
  * Generates AI depending on game choice.
  * Implemented in GoFish, JungleSpeed, and CrazyEights
  * @param l the level of the AI
  * @param t the type of Game
  * @param id the id of the AI player.
  */
  std::shared_ptr<Player> generateAI(Game::GameType t, AI::Level l, int id);

  /**
   * Creates the players vector so it can be passed into the
   * appropriate game constructor
   * @param gameChoice the game that the user chose to play
   * @param userInput
   * @return a vector of Player*
   */
  std::vector<std::shared_ptr<Player>> createPlayers(Game::GameType gameChoice,
    std::istream& userInput);
};

#endif
