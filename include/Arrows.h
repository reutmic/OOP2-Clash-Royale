#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpellCard.h"

const int ARROWS_UPGRADE_COST_1 = 40;
const int ARROWS_UPGRADE_COST_2 = 52;
const int ARROWS_UPGRADE_COST_3 = 60;
const int ARROWS_UPGRADE_COST_4 = 70;
const int ARROWS_UPGRADE_COST_5 = 85;

class Arrows : public SpellCard
{
public:
	Arrows(const int cardLevel);

	std::shared_ptr<Card> clone(const int cardLevel) {
		auto m = std::make_shared<Arrows>(cardLevel);
		return m;
	}

	int getPriority() const override;

private:
};