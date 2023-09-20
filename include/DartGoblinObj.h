#pragma once
#include <iostream>
#include "TroopObj.h"

class DartGoblinObj : public TroopObj
{
public:
	using TroopObj::TroopObj;
	DartGoblinObj(sf::Vector2f position) : TroopObj(position)
	{}
	DartGoblinObj(sf::Vector2f position, const int cardLevel, const int arena, const TURN_OWNER turnOwner, const int soundLevel);
	void setProperties(const int cardLevel) override;
	void mapDirectionToAnimation(const sf::Time deltaTime, const sf::Vector2f animationDirection, const sf::Vector2f direction) override;
	void movement(const sf::Time deltaTime, sf::Vector2f direction) override;

private:
};