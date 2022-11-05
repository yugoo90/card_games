/**
* @author Hatash
* @date 2021-4
*/

#ifndef JUNGLESPEEDCARD_H_INCLUDED
#define JUNGLESPEEDCARD_H_INCLUDED

#include <string>
#include <iostream>
#include "Card.h"

/**
* Implements Jungle Speed Card
*/
class JungleSpeedCard : public Card {
 public:
  enum Colour {RED = 1, BLUE, YELLOW, GREEN, SPECIAL};

  /**
  * Default Constructor.
  * @param cardName the name of the card.
  * @param cardColour the card.
  */
  JungleSpeedCard(std::string cardName, Colour cardColour);

  /**
  * Destructor
  */
  virtual ~JungleSpeedCard();

  /**
  * Sets for colour of card.
  * @param c the card colour
  */
  void setColour(Colour c);

  /**
  * Setter for the name of the card.
  * @param s the name of the card
  */
  void setName(std::string s);

  /**
  * Getter for the colour of the card.
  * @return the Colour
  */
  Colour getColour() const;

  /**
  * Getter for the name of the card.
  * @return the name of the card as a string
  */
  std::string getName() const;

  /**
  * Converts the enum colour to a string
  * @param Colour c is the colour of the card as an enum
  * @return the colour as a string
  */
  std::string ColourToString(Colour c);

  /**
  * Converts the card information into one string
  * @return as CardColour + ' ' + CardName
  */
  std::string stringOfWholeCard();

  /**
  * Overloaded == operator to compare two cards
  * @param Card& c card to compare to.
  * @return true if both card objects are the same thing.
  */
  bool operator==(const Card& c);

  /**
  * To compare two cards and see if they have the same colour
  * @param JungleSpeedCard& c the card to compare to.
  * @return true if both cards have same color, false otherwise.
  */
  bool sameColour(const JungleSpeedCard& c);

  /**
  * To compare two cards and see if they have the same name
  * @param JungleSpeedCard& c the card to compare to.
  * @return true if both cards have same name, false otherwise.
  */
  bool sameName(const JungleSpeedCard& c);

 private:
  std::string name;
  Colour colour;
};

#endif
