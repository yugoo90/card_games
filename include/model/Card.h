/**
* @author Hatash
* @date 2021-4
*/

#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <memory>
#include <string>
#include <iostream>

/**
* Class for Card.
*/
class Card {
 public:
  enum CardType {STANDARD = 1, JUNGLESPEED};

/**
* Default constructor.
*/
Card();

/**
* Destructor.
*/
virtual ~Card();

/**
* Returns the type of a card: StandardCard or JungleSpeedCard.
* @return the CardType of the card.
*/
CardType getType() const;

/**
* Uses the stringOfWholeCard function to display a card.
* ie. it's rank, and it's suit.
*/
void displayCard();

/**
* Converts the rank and suit of a card to a string that enables it to be
* displayed.
*/
virtual std::string stringOfWholeCard() = 0;

/**
* Determines if two cards are indentical.
* @param c a card to compare to this one.
* @return true if the cards are identical, false otherwise.
*/
virtual bool equals(const std::shared_ptr<Card> c) = 0;

inline bool operator==(const std::shared_ptr<Card> c) {
  return this->equals(c);
}

 protected:
  CardType type;
};

#endif
