#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TroopCard.h"

const int KNIGHT_UPGRADE_COST_1 = 78;
const int KNIGHT_UPGRADE_COST_2 = 96;
const int KNIGHT_UPGRADE_COST_3 = 123;
const int KNIGHT_UPGRADE_COST_4 = 147;
const int KNIGHT_UPGRADE_COST_5 = 160;

class Knight : public TroopCard
{
public:
	Knight(const int cardLevel);

	std::shared_ptr<Card> clone(const int cardLevel) {
		auto m = std::make_shared<Knight>(cardLevel);
		return m;
	}

	int getPriority() const override;

private:
};