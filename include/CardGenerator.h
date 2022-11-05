/**
* @author Hatash
* @date 2021-4
*/

#ifndef CARDGENERATOR_H_INCLUDED
#define CARDGENERATOR_H_INCLUDED

#include <string>
#include "Card.h"
#include "StandardCard.h"
#include "JungleSpeedCard.h"

/*
* Implements the CardGenerator Class.
*/
class CardGenerator {
 public:
  /**
  * Default constructor.
  */
  CardGenerator();

  /**
  * Destructor.
  */
  virtual ~CardGenerator();

  /**
  * Makes a StandardCard with a suit and value.
  * @param typeOfSuit an integer represtenting the suit of a card.
  * @param valueOfCard an integer representing the value of a card.
  * @return A pointer to the StandardCard that was made.
  */
  StandardCard* makeStandardCard(const int typeOfSuit, const int valueOfCard);

  /**
  * Makes a JungleSpeedCard with a name and color.
  * @param s a string representing the name of a card.
  * @param i an integer representing the colour of a card.
  * @return A pointer to the JungleSpeedCard that was made.
  */
  JungleSpeedCard* makeJungleSpeedCard(const std::string s, const int i);
};

#endif
