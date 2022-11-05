/**
* @author Hatash
* @date 2021-4
*/

#ifndef DISCARD_H_INCLUDED
#define DISCARD_H_INCLUDED

#include <vector>
#include <algorithm>
#include "Card.h"
#include "CardSet.h"

/**
* Implements Class for Discard.
*/
class Discard : public CardSet {
 public:
  /**
  * Default constructor.
  */
  Discard();

  /**
  * Destructor.
  */
  ~Discard();

  /**
  * Displayes the top card in the discard pile.
  */
  void display() const;
};

#endif
