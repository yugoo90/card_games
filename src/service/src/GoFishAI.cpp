#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include "GoFishAI.h"
#include "AI.h"
#include "Player.h"
#include "Game.h"
#include "Deck.h"
#include "GameActions.h"
#include "Card.h"

  GoFishAI::GoFishAI(AI::Level playerLevel,
    int playerID) : AI(playerLevel, playerID) {
      seed = time(NULL);
    }

  GoFishAI::~GoFishAI() {}

  Card* GoFishAI::strategy(std::vector<std::vector<int>> v) {
    storePlayer = -1;
    int storeRank = -1;
    GameActions selfRequest;
    std::vector<Card*> crd;
    switch (aiLevel) {
    case AI::EASY: break;
      case AI::HARD: {
        for (int i = 0; i < v.size(); i++) {
          if (i == (*this).getID()) {
            continue;
          }
          if ((*this).isInHand(v[i].back())) {
            storePlayer = i;
            storeRank = v[i].back();
          }
        }
        break;
      }
      default: {
        for (int i = 0; i < v.size(); i++) {
          if (i == (*this).getID()) {
            continue;
          }
          for (int j = 0; j < v[i].size(); j++) {
            if ((*this).isInHand(v[i][j])) {
              if (j > 3) {
                continue;
              }
              storePlayer = i;
              storeRank = v[i][j];
          }
        }
      }
      break;
    }
  }
  if (storePlayer != -1 && storeRank != -1) {
    crd = selfRequest.makeRequest(this, storeRank);
    return crd[0];
  } else {
    hand.shuffleCardSet(); return hand.getTop();
  }
}

  Player* GoFishAI::ChoosePlayer(Game* g) {
    std::vector<Player*> temp = g->getPlayers();

    if (storePlayer != -1) {
      return temp[storePlayer];
    } else {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(temp), std::end(temp), g);
    Player* requestedPlayer = temp[0];
    if (requestedPlayer->getID() == (id)) {
      requestedPlayer = temp[1];
    }
    return requestedPlayer;
  }
}
