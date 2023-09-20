#pragma once
#include <iostream>
#include "Unmovable.h"
#include "Factory.h"

class PlayerTerritory : public Unmovable
{
public:
	using Unmovable::Unmovable;

	PlayerTerritory(sf::Vector2f position) : Unmovable(position)
	{
		m_owner = PLAYER;
		m_territoryRect.setSize(sf::Vector2f(475, 300));
		m_territoryRect.setFillColor(sf::Color::Transparent);
	}

	PlayerTerritory();

	void setLifeBar() override {};

private:
};