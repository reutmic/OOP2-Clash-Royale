#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpellCard.h"

const int FIREBALL_UPGRADE_COST_1 = 70;
const int FIREBALL_UPGRADE_COST_2 = 92;
const int FIREBALL_UPGRADE_COST_3 = 110;
const int FIREBALL_UPGRADE_COST_4 = 130;
const int FIREBALL_UPGRADE_COST_5 = 144;

class Fireball : public SpellCard
{
public:
	Fireball(const int cardLevel);

	std::shared_ptr<Card> clone(const int cardLevel) {
		auto m = std::make_shared<Fireball>(cardLevel);
		return m;
	}

	int getPriority() const override;

private:
};