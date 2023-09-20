#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TroopCard.h"

const int ARCHERS_UPGRADE_COST_1 = 30;
const int ARCHERS_UPGRADE_COST_2 = 55;
const int ARCHERS_UPGRADE_COST_3 = 70;
const int ARCHERS_UPGRADE_COST_4 = 95;
const int ARCHERS_UPGRADE_COST_5 = 110;

class Archers : public TroopCard
{
public:
	Archers(const int cardLevel);

	std::shared_ptr<Card> clone(const int cardLevel) {
		auto m = std::make_shared<Archers>(cardLevel);
		return m;
	}

	int getPriority() const override;

private:
};