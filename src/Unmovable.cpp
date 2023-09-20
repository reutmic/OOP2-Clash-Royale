#include "Unmovable.h"

sf::RectangleShape& Unmovable::getObjBorder()
{
	return m_objBorder;
}


sf::Vector2f Unmovable::getCenter() const
{
	sf::Vector2f center;

	center.x = m_objBorder.getPosition().x + (m_objBorder.getSize().x / 2);
	center.y = m_objBorder.getPosition().y + (m_objBorder.getSize().y / 2);

	return center;
}


bool Unmovable::getIsBigTower() const
{
	return m_bigTower;
}




