/**
* @author Hatash
* @date 2021-4
*/

#ifndef GOFISHAI_H_INCLUDED
#define GOFISHAI_H_INCLUDED

#include <string>
#include <vector>
#include "Player.h"
#include "AI.h"
#include "Game.h"

/**
* Implementation of the Go Fish AI
*/
class GoFishAI : public AI {
 public:
  /**
  * Default Constructor
  * @param playerLevel the selected level of the AI
  * @param playerID the ID of the AI
  */
  GoFishAI(Level playerLevel, int playerID);

  /**
  * Destructor
  */
  virtual ~GoFishAI();

  /**
  * Sets the strategy depending on the diffculty level of the AI.
  * @param v the container that stores the player their previously asked card.
  @ return a pointer to a card chosen to be played based on the level of the AI.
  */
  Card* strategy(std::vector<std::vector<int>> v);

  /**
  * choses a player to ask for a card.
  * @param g pointer to the game object.
  * @return returns a pointer to the player who is being asked.
  */
  Player* ChoosePlayer(Game* g);

 private:
  unsigned seed;
  int storePlayer = -1;
};

#endif
