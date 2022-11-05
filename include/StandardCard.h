/**
* @author Hatash
* @date 2021-4
*/

#ifndef STANDARDCARD_H_INCLUDED
#define STANDARDCARD_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "Card.h"

/**
* Implements a Standard Card
*/
class StandardCard : public Card {
 public:
  enum Suit
    {DIAMONDS = 1, HEARTS, CLUBS, SPADES};

  /**
  * Default Constructor
  * @param nameOfSuit the suit of the standard Card
  * @param cardNumber ranges from 1-13
  */
  StandardCard(Suit nameOfSuit, int cardNumber);

  /**
  * Destructor
  */
  virtual ~StandardCard();

  /**
  * Sets the value of the standard card.
  * @param v cardNumber ranges from 1-13
  */
  void setValue(int v);

  /**
  * Sets the suit of a standard card.
  * @param s the suit of the standard card.
  */
  void setSuit(Suit s);

  /**
  * Getter function for the value of the standard card.
  * @return the integer value of the standard card.
  */
  int getValue() const;

  /**
  * Getter function for the suit of a standard card. Calls suitToString
  * @return a string version of the suit
  */
  Suit getSuit() const;

  /**
  * Compares two cards to see if they have the same rank.
  * @param StandardCard* c the card to compare to.
  * @return a true if the card objecct has the same rank as c,
  * false otherwise.
  */
  bool sameRank(const StandardCard& c);

  /**
  * Compares two cards to see if they have the same suit
  * @param StandardCard* c the card to compare to.
  * @return true if the  card object rank has same the same suit as c,
  * false otherwise.
  */
  bool sameSuit(const StandardCard& c);

  /**
  * Displays the number/face of the standard card.
  * @return a string version of the number/face value of the standard card.
  */
  std::string stringOfWholeCard();

  /**
  * Converts a suit to a string.
  * @param s the suit of the standard card.
  * @return a string version of the suit of the standard card.
  */
  std::string suitToString(Suit s);

  /**
  * Overloads the == operator to be able to determine equalivalence between
  * two cards
  * @param Card& c this is the card to be compared to.
  * @return true if the card passed in ane the card object are equal.
  */
  bool operator==(const Card& c);

  /**
  * COnverts the rank of a card which is an integer to a name which is a string.
  * @param int cardRank 
  */
  std::string rankToName(const int cardRank);

  std::string cardValue();

  const std::string suitValue();

 private:
  Suit suitName;
  int number;
};

#endif
