#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TroopCard.h"

const int MINIONS_UPGRADE_COST_1 = 52;
const int MINIONS_UPGRADE_COST_2 = 76;
const int MINIONS_UPGRADE_COST_3 = 93;
const int MINIONS_UPGRADE_COST_4 = 112;
const int MINIONS_UPGRADE_COST_5 = 136;

class Minions : public TroopCard
{
public:
	Minions(const int cardLevel);

	std::shared_ptr<Card> clone(const int cardLevel) {
		auto m = std::make_shared<Minions>(cardLevel);
		return m;
	}

	int getPriority() const override;

private:
};