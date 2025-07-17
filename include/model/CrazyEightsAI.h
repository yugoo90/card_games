/**
* @author Hatash
* @date 2021-4
*/

#ifndef CRAZYEIGHTSAI_H_INCLUDED
#define CRAZYEIGHTSAI_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "AI.h"
#include "Player.h"
#include "Card.h"

/**
* Implementation of the Crazy Eights AI.
*/
class CrazyEightsAI : public AI {
 public:
/**
* Default Constructor.
* @param playerLevel the selected level of the AI.
* @param playerID the ID of the AI.
*/
  CrazyEightsAI(Level playerLevel, int playerID);

/**
* Destructor.
*/
  virtual ~CrazyEightsAI();

/**
* Sets the strategy depending on the difficulty level of the AI.
* @param c is the top card of the StockPile.
* @return the card that strategy chose to play.
*/
  std::shared_ptr<Card> strategy(std::shared_ptr<Card> c);

 private:
  std::vector<std::shared_ptr<Card>> legalCards = {};
};

#endif
