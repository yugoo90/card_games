/**
* @author Hatash
* @date 2021-4
*/

#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED

#include <string>
#include "Player.h"

/**
* Class for AI.
*/
class AI : public Player {
 public:
  enum Level {EASY = 1, NORMAL, HARD};

/**
* Default constructor, uses Player and setDifficultyLevel.
* @param AILevel the selected level of the AI.
* @param playerID the ID of the AI.
*/
  AI(Level AILevel, int playerID);

/**
* Destructor.
*/
  virtual ~AI();

/**
* Sets the difficulty level of  an AI player.
* @param l the level of difficulty of the AI.
*/
  void setDifficultyLevel(AI::Level l);

/**
* Getter for AI difficulty level.
* @return the level of the AI.
*/
  Level getDifficultyLevel() const;

/**
* Returns the name of an AI player.
* @return a string indicating the name of the AI.
*/
  std::string getName() const;

 protected:
  Level aiLevel;
};

#endif
