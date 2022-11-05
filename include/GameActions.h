/**
* @author Hatash
* @date 2021-4
*/

#ifndef GAMEACTION_H_INCLUDED
#define GAMEACTION_H_INCLUDED
#include <vector>
#include "Player.h"
#include "AI.h"
#include "GoFishAI.h"
#include "CrazyEightsAI.h"
#include "Human.h"
#include "JungleSpeedAI.h"
#include "Game.h"
#include "CardSet.h"
#include "Hand.h"
#include "Card.h"
#include "StandardCard.h"

/**
* Implements GameActions class.
*/
class GameActions {
 public:
  /**
  * Default constructor.
  */
  GameActions();

  /**
  * Destructor.
  */
  virtual ~GameActions();

  /**
  * Asks a player for a particular rank of card in GoFish.
  * @param reciever the player recieving the card.
  * @param cardRank the rank of the card being asked for.
  * @return returns a vector of pointers to all the cards the receiver gets.
  */
  std::vector<Card*> makeRequest(Player* receiver, const int cardRank);

  /**
  * Finds the most prevalent suit in a hand.
  * Used in CrazyEightsAI strategy when changing the suit after placing an 8.
  * @param hand is the hand we will be searching through.
  * @return Suit of the most prevalent suit in the players hand.
  */
  StandardCard::Suit mostPrevalentSuit(std::vector<Card*> hand);
};

#endif
