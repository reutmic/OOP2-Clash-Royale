#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Factory.h"
#include "Movable.h"

class Bullet : public Movable
{
public:
	using Movable::Movable;

	Bullet(sf::Vector2f position) : Movable(position)
	{}
	Bullet(sf::Vector2f position, const TURN_OWNER turnOwner, const int arena);
	void setLifeBar() override {};
	void setProperties(const int cardLevel) override;
	void mapDirectionToAnimation(const sf::Time deltaTime, const sf::Vector2f animationDirection, const sf::Vector2f direction) override {};
	void movement(const sf::Time deltaTime, sf::Vector2f direction) override;

private:
};