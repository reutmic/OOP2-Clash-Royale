#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TroopCard.h"

const int PEKKA_UPGRADE_COST_1 = 135;
const int PEKKA_UPGRADE_COST_2 = 157;
const int PEKKA_UPGRADE_COST_3 = 179;
const int PEKKA_UPGRADE_COST_4 = 204;
const int PEKKA_UPGRADE_COST_5 = 237;

class Pekka : public TroopCard
{
public:
	Pekka(const int cardLevel);

	std::shared_ptr<Card> clone(const int cardLevel) {
		auto m = std::make_shared<Pekka>(cardLevel);
		return m;
	}

	int getPriority() const override;

private:
};