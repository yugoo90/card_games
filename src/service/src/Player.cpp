#include <string>
#include <iostream>
#include <vector>
#include "Card.h"
#include "Player.h"
#include "StandardCard.h"


  Player::Player(int playerID) {
    totalPoints = 0;
    id = playerID;
    pointsFromOneRound = 0;
    myTurn = false;
  }

  Player::~Player() {}

  bool Player::getMyTurn() const {return myTurn;}

  void Player::setMyTurn(bool b) {myTurn = b;}

  void Player::setTotalPoints() {totalPoints += pointsFromOneRound;}

  void Player::setRoundPoints(const int i) {pointsFromOneRound = i;}

  int Player::getTotalPoints() const {return totalPoints;}

  int Player::getRoundPoints() const {return pointsFromOneRound;}

  int Player::getID() const {return id;}

  Player::PlayerType Player::getType() const {return type;}

  bool Player::isInHand(const int cardRank) {
    Card* tempCard;
    StandardCard* temp2;
    std::vector<Card*> temp = hand.getHand();
    for (auto it = temp.begin(); it != temp.end(); it++) {
      tempCard = (*it);
      temp2 = dynamic_cast<StandardCard*>(tempCard);
      if (temp2->getValue() == cardRank) {
        return true;
      }
    }
    return false;
}
