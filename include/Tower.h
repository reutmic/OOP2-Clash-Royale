#pragma once
#include <iostream>
#include "Unmovable.h"
#include "Factory.h"

class Tower : public Unmovable
{
public:
	using Unmovable::Unmovable;

	Tower(sf::Vector2f position) : Unmovable(position)
	{}

	Tower(sf::Vector2f position, const int cardLevel, const int arena, const bool bigTower, const TURN_OWNER turnOwner);
	void setLifeBar() override;

private:

};