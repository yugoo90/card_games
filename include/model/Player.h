/**
* @author Hatash
* @date 2021-4
*/

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include "Card.h"
#include "Hand.h"

/**
* Abstract Class Player
*/
class Player {
 public:
  enum PlayerType {HUMAN, AI};

  /**
  * Default constructor
  * @param playerID the ID of the player, assigned by the system
  */
  Player(int playerID);

  /**
  * Destructor
  */
  virtual ~Player();

  /**
  * Getter for the type of a player
  * @return the type of player, either human or AI
  */
  PlayerType getType() const;

  /**
  * Getter for myTurn
  * @return a bool signifying whether it's the players turn or not
  */
  bool getMyTurn() const;

  /**
  * Sets the value of myTurn
  * @param bool b, sets player turn to be either true or false.
  */
  void setMyTurn(bool b);

  /**
  * Assign points to a player.
  */
  void setTotalPoints();

  /**
  * Setter for round points
  * @param i is the points
  */
  void setRoundPoints(const int i);

  /**
  * Getter function for the total points earned by a player.
  * @return the Player's points
  */
  int getTotalPoints() const;

  /**
  * Getter function for the round points earned by a player.
  * @return the Player's points from that round
  */
  int getRoundPoints() const;

  /**
  * Allows a player to make a card request to their opponent.
  * Uses Players
  */

  int getID() const;

  /**
  * The players hand.
  * TransferCards will use this as a location or destination
  */
  Hand hand;

  /**
  * Getter for a players name
  * @return the players name as a string
  */
  virtual std::string getName() const = 0;

  /**
  * Checks if a certain cardRank is in a players hand
  * @param cardRank is the rank of the card to check
  * @return true or false
  */
  bool isInHand(const int cardRank);

 protected:
  bool myTurn;
  PlayerType type;
  int totalPoints;
  int pointsFromOneRound;
  int id;
};

#endif
