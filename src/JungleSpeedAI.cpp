#include <string>
#include "AI.h"
#include "Player.h"
#include "JungleSpeedAI.h"


JungleSpeedAI::JungleSpeedAI(
  JungleSpeedAI::Level playerLevel, int playerID) : AI(playerLevel,
    playerID) {
      setResponseTime(playerLevel);
    }

JungleSpeedAI::~JungleSpeedAI() {}

double JungleSpeedAI::getResponseTime() {return responseTime;}

void JungleSpeedAI::setResponseTime(Level l) {
  switch (l) {
    case EASY: {
      responseTime = 3.49;
      break;
    }
    case NORMAL: {
      responseTime = 2.49;
      break;
    }
    default: {
      responseTime = 1.49;
    }
  }
}
