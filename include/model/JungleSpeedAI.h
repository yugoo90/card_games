/**
* @author Hatash
* @date 2021-4
*/

#ifndef JUNGLESPEEDAI_H_INCLUDED
#define JUNGLESPEEDAI_H_INCLUDED


#include <string>
#include "Player.h"
#include "AI.h"

/**
* Implements Jungle Speed AI
*/
class JungleSpeedAI : public AI {
 public:
  /**
  * Default Constructor
  * Sets AI difficultyLevel and its ID
  * @param playerLevel is the desired difficulty level of the AI
  * @param playerID is the identifier for the AI
  */
  JungleSpeedAI(Level playerLevel, int playerID);

  /**
  * Destructor
  */
  virtual ~JungleSpeedAI();


  /**
  * Getter function for the response time of the AI
  * @return the response time of the AI as a double
  */
  double getResponseTime();

  /**
  * Sets the response time of the AI depending on its difficulty level.
  * @param l is the level of the AI
  */
  void setResponseTime(Level l);

 private:
  double responseTime;
};

#endif
