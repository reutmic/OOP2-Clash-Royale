#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TroopCard.h"

const int VALKYRIE_UPGRADE_COST_1 = 72;
const int VALKYRIE_UPGRADE_COST_2 = 93;
const int VALKYRIE_UPGRADE_COST_3 = 110;
const int VALKYRIE_UPGRADE_COST_4 = 126;
const int VALKYRIE_UPGRADE_COST_5 = 143;

class Valkyrie : public TroopCard
{
public:
	Valkyrie(const int cardLevel);

	std::shared_ptr<Card> clone(const int cardLevel) {
		auto m = std::make_shared<Valkyrie>(cardLevel);
		return m;
	}

	int getPriority() const override;

private:
};