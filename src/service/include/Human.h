/**
* @author Hatash
* @date 2021-4
*/

#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

#include <string>
#include "Player.h"

/**
* Implementation of Human
*/
class Human : public Player {
 public:
   /**
   * Default constructor
   * @param playerName is the name of the player
   * @param playerID is the identifier for the player.
   */
  Human(std::string playerName, int playerID);

  /**
  * Destructor
  */
  virtual ~Human() {}

  /**
  * Allows a player to input a name of their choice.
  * @param s the name of the player
  */
  void setName(std::string s);

  /**
  * Getter function for player names
  * @return the name of the player
  */
  std::string getName() const;

 private:
  std::string name;
};

#endif
