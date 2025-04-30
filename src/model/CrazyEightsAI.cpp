#include <string>
#include <vector>
#include "CrazyEightsAI.h"
#include "StandardCard.h"
#include "AI.h"
#include "Player.h"

CrazyEightsAI::CrazyEightsAI(AI::Level playerLevel,
  int playerID) : AI(playerLevel, playerID) {}

CrazyEightsAI::~CrazyEightsAI() {}

Card* CrazyEightsAI::strategy(Card* c) {
  legalCards.clear();
  const StandardCard& tempCard = dynamic_cast<const StandardCard&>(*c);
  StandardCard* tempHandCard;
  std::vector<Card*> temp;
  temp = (*this).hand.getHand();
  for (auto itr = temp.begin(); itr != temp.end(); itr++) {
    tempHandCard = dynamic_cast<StandardCard*>(*itr);
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
      Card* minCard = legalCards[0];
      for (int i = 1; i < legalCards.size(); i++) {
        if (dynamic_cast<StandardCard*>(legalCards[i])->getValue() <
        dynamic_cast<StandardCard*>(minCard)->getValue()) {
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
      Card* maxCard = legalCards[0];
      for (int i = 1; i < legalCards.size(); i++) {
        if (dynamic_cast<StandardCard*>(legalCards[i])->getValue() >
        dynamic_cast<StandardCard*>(maxCard)->getValue()) {
          maxCard = legalCards[i];
        }
      }
      return maxCard;
      break;
    }
  }
}
