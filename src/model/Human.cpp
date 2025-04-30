#include "Human.h"
#include "Player.h"
#include <string>
#include "Player.h"

Human::Human(std::string playerName, int playerID) : Player{playerID} {
  type = Player::HUMAN;
  setName(playerName);}

void Human::setName(std::string s) {name = s;}

std::string Human::getName() const {return name;}
