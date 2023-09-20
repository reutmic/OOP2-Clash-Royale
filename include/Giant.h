#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TroopCard.h"

const int GIANT_UPGRADE_COST_1 = 88;
const int GIANT_UPGRADE_COST_2 = 120;
const int GIANT_UPGRADE_COST_3 = 146;
const int GIANT_UPGRADE_COST_4 = 230;
const int GIANT_UPGRADE_COST_5 = 267;

class Giant : public TroopCard
{
public:
	Giant(const int cardLevel);

	std::shared_ptr<Card> clone(const int cardLevel) {
		auto m = std::make_shared<Giant>(cardLevel);
		return m;
	}

	int getPriority() const override;

private:
};