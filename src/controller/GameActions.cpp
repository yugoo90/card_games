#include <iostream>
#include <vector>
#include <algorithm>
#include "GameActions.h"
#include "Player.h"
#include "AI.h"
#include "GoFishAI.h"
#include "CrazyEightsAI.h"
#include "Human.h"
#include "JungleSpeedAI.h"
#include "Game.h"
#include "CardSet.h"
#include "Card.h"
#include "StandardCard.h"
#include "Hand.h"

GameActions::GameActions() {}

GameActions::~GameActions() {}

std::vector<Card*> GameActions::makeRequest(Player* receiver,
  const int cardRank) {
  std::vector<Card*> v1;
  std::vector<Card*> v2;
  StandardCard* temp2;
  v1 = receiver->hand.getHand();
  if (!receiver-> isInHand(cardRank)) {
    return v2;
  } else {
    for (auto it = v1.begin(); it != v1.end(); it++) {
      temp2 = dynamic_cast<StandardCard*>(*it);
      if (temp2->getValue() == cardRank) {
        v2.push_back(*it);
      }
    }
    return v2;
  }
}

StandardCard::Suit GameActions::mostPrevalentSuit(std::vector<Card*> hand) {
  std::vector<int> cardFrequency = {0, 0, 0, 0};
  StandardCard::Suit s;
  for (int i = 0; i < hand.size(); i++) {
    s = dynamic_cast<StandardCard*>(hand[i])->getSuit();
    switch (s) {
      case StandardCard::DIAMONDS: {
        cardFrequency[0]++;
        break;
      }
      case StandardCard::HEARTS: {
        cardFrequency[1]++;
        break;
      }
      case StandardCard::CLUBS: {
        cardFrequency[2]++;
        break;
      }
      default: {
        cardFrequency[3]++;
        break;
      }
    }
  }
  int mostFrequentCard = 0;
  for (int i = 1; i < cardFrequency.size(); i++) {
    if (cardFrequency[i] > cardFrequency[mostFrequentCard]) {
      mostFrequentCard = i;
    }
  }
  switch (mostFrequentCard) {
    case 0: {
      return StandardCard::DIAMONDS;
    }
    case 1: {
      return StandardCard::HEARTS;
    }
    case 2: {
      return StandardCard::CLUBS;
    }
    default: {
      return StandardCard::SPADES;
    }
  }
}
