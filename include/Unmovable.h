#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"

class Unmovable : public Object
{
public:
	using Object::Object;

	Unmovable() :
		Object({ 0,0 })
	{}

	sf::Vector2f getCenter() const override;
	sf::RectangleShape& getObjBorder();
	bool getIsBigTower() const;

protected:
	bool m_bigTower;

private:
};