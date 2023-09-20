#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TroopCard.h"

const int DART_GOBLIN_UPGRADE_COST_1 = 35;
const int DART_GOBLIN_UPGRADE_COST_2 = 50;
const int DART_GOBLIN_UPGRADE_COST_3 = 60;
const int DART_GOBLIN_UPGRADE_COST_4 = 73;
const int DART_GOBLIN_UPGRADE_COST_5 = 88;

class DartGoblin : public TroopCard
{
public:
	DartGoblin(const int cardLevel);

	std::shared_ptr<Card> clone(const int cardLevel) {
		auto m = std::make_shared<DartGoblin>(cardLevel);
		return m;
	}

	int getPriority() const override;

private:
};