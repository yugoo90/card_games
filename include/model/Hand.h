/**
* @author Hatash
* @date 2021-4
*/

#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED

#include <vector>
#include <algorithm>
#include "Card.h"
#include "CardSet.h"

/**
* Implementation of Hand
*/
class Hand : public CardSet {
 public:
   /**
   * Default constructor
   */
  Hand();

  /**
  * Destructor
  */
  ~Hand();

  /**
  * displays the hand of the player uses unicode to display the cards.
  */
  void display() const;

  /**
  * @returns the hand of a player.
  */
  std::vector<Card*> getHand();
};

#endif
