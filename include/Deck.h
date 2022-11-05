/**
* @author Hatash
* @date 2021-4
*/

#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include <vector>
#include <algorithm>
#include "Card.h"
#include "CardSet.h"

/**
* Implements Class for Deck. Acts like a Stack.
*/
class Deck : public CardSet {
 public:
  /**
  * Default constructor.
  */
  Deck();

  /**
  * Destructor.
  */
  virtual ~Deck();

  /**
  * This function does nothing because we do not want to display the cards in
  * the deck.
  */
  void display() const;
};

#endif
