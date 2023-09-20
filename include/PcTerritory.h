#pragma once
#include <iostream>
#include "Unmovable.h"
#include "Factory.h"

class PcTerritory : public Unmovable
{
public:
	using Unmovable::Unmovable;

	PcTerritory(sf::Vector2f position) : Unmovable(position)
	{
		m_owner = PC;
		m_territoryRect.setSize(sf::Vector2f(475, 300));
		m_territoryRect.setFillColor(sf::Color::Transparent);
	}

	PcTerritory();

	void setLifeBar() override {};

private:

};