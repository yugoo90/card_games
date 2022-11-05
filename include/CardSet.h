/**
* @author Hatash
* @date 2021-4
*/

#ifndef CARDSET_H_INCLUDED
#define CARDSET_H_INCLUDED

#include <vector>
#include <algorithm>
#include "Card.h"

/**
* Abstract Class for CardSet.
*/
class CardSet {
 public:
  enum CardSetType {DECK, HAND, DISCARD};

  /**
  * Default Constructor.
  */
  CardSet();

  /**
  * Destructor.
  */
  virtual ~CardSet();

  /**
  * Displays the cards, depending on the type of CardSet.
  */
  virtual void display() const = 0;

  /**
  * Getter function that returns size of a CardSet.
  * @return an int the size of the CardSet.
  */
  int getSize() const;

  /**
  * Shuffles a CardSet.
  */
  void shuffleCardSet();

  /**
  * Getter function that returns the type of a CardSet.
  * @return the CardSetType of the CardSet.
  */
  CardSetType getType() const;

  /**
  * Getter function that searches through a CardSet to find a particular card.
  * @param c the card to find in the CardSet.
  * @return returns the card if found and nullptr otherwise.
  */
  Card* getCard(const Card* c);

  /**
  * Adds a card to a CardSet.
  * @param c the card to add to the CardSet.
  */
  void addCard(Card* c);

  /**
  * Removes a card from a CardSet.
  * @param c the card to be removed from the  CardSet.
  */
  void removeCard(const Card* c);

  /**
  * Retuns the card at the top of the deck.
  * @return the card at the top of the deck.
  */
  Card* getTop();

 protected:
  CardSetType type;
  std::vector <Card*> cards;
  unsigned seed;
};

#endif
