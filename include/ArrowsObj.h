#pragma once
#include <iostream>
#include "SpellObj.h"

class ArrowsObj : public SpellObj
{
public:
	using SpellObj::SpellObj;
	ArrowsObj(sf::Vector2f position) : SpellObj(position)
	{}
	ArrowsObj(sf::Vector2f position, const int cardLevel, const int arena, const TURN_OWNER turnOwner, const int soundLevel);
	void setProperties(const int cardLevel) override;
	void mapDirectionToAnimation(const sf::Time deltaTime, const sf::Vector2f animationDirection, const sf::Vector2f direction) override;
	void movement(const sf::Time deltaTime, sf::Vector2f direction) override;


private:
	bool m_impact;

};