#include <iostream>
#include <string>
#include <vector>
#include "CrazyEightsAI.h"
#include "StandardCard.h"
#include "AI.h"
#include "Player.h"

CrazyEightsAI::CrazyEightsAI(AI::Level playerLevel,
  int playerID) : AI(playerLevel, playerID) {}

CrazyEightsAI::~CrazyEightsAI() {}

std::shared_ptr<Card> CrazyEightsAI::strategy(std::shared_ptr<Card> c) {
  legalCards.clear();
  const std::shared_ptr<StandardCard> tempCard = std::dynamic_pointer_cast<StandardCard>(c);
  std::shared_ptr<StandardCard> tempHandCard;
  std::vector<std::shared_ptr<Card>> temp;
  temp = (*this).hand->getHand();
  for (auto itr = temp.begin(); itr != temp.end(); itr++) {
    tempHandCard = std::dynamic_pointer_cast<StandardCard>(*itr);
    if (tempHandCard->sameSuit(tempCard) || tempHandCard->sameRank(tempCard)
    || tempHandCard->getValue() == 8) {
      legalCards.push_back((*itr));
    }
  }
  if (legalCards.size() == 0) {
    return nullptr;
  }
  switch (aiLevel) {
    case AI::EASY: {
      std::shared_ptr<Card> minCard = legalCards[0];
      for (int i = 1; i < legalCards.size(); i++) {
        if (std::dynamic_pointer_cast<StandardCard>(legalCards[i])->getValue() <
        std::dynamic_pointer_cast<StandardCard>(minCard)->getValue()) {
          minCard = legalCards[i];
        }
      }
      return minCard;
      break;
    }
    case AI::NORMAL: {
      return legalCards[0];
      break;
    }
    default: {
      std::shared_ptr<Card> maxCard = legalCards[0];
      for (int i = 1; i < legalCards.size(); i++) {
        if (std::dynamic_pointer_cast<StandardCard>(legalCards[i])->getValue() >
        std::dynamic_pointer_cast<StandardCard>(maxCard)->getValue()) {
          maxCard = legalCards[i];
        }
      }
      return maxCard;
      break;
    }
  }
}
