#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpellCard.h"

const int FREEZE_UPGRADE_COST_1 = 65;
const int FREEZE_UPGRADE_COST_2 = 81;
const int FREEZE_UPGRADE_COST_3 = 98;
const int FREEZE_UPGRADE_COST_4 = 124;
const int FREEZE_UPGRADE_COST_5 = 140;

class Freeze : public SpellCard
{
public:
	Freeze(const int cardLevel);

	std::shared_ptr<Card> clone(const int cardLevel) {
		auto m = std::make_shared<Freeze>(cardLevel);
		return m;
	}

	int getPriority() const override;

private:
};