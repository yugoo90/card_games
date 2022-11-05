#include <string>
#include "AI.h"
#include "Player.h"



AI::AI(Level AILevel, int playerID): Player(playerID) {
  setDifficultyLevel(AILevel);}

AI::~AI() {}

std::string AI::getName() const {
  std::string temp = "AI ";
  std::string newID = std::to_string(id);
  return temp + newID;
}

void AI::setDifficultyLevel(AI::Level l) {aiLevel = l;}

AI::Level AI::getDifficultyLevel() const {return aiLevel;}
