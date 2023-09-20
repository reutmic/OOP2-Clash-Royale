#include "Movable.h"

sf::Sprite& Movable::getCurrObjSprite()
{
	return m_currObjSprite;
}


sf::Sprite& Movable::getBulletSprite()
{
	return m_bulletSprite;
}


sf::Vector2f Movable::getCenter() const
{
	sf::Vector2f center;

	center.x = m_currObjSprite.getPosition().x + (m_currObjSprite.getGlobalBounds().width / 2);
	center.y = m_currObjSprite.getPosition().y + (m_currObjSprite.getGlobalBounds().height / 2);

	return center;
}


void Movable::changeAnimationDirection(const sf::Vector2f newAnimationDirection)
{
	if (m_animationDirection != newAnimationDirection)
	{
		m_changeAnimationDirection = true;
		m_animationDirection.x = newAnimationDirection.x;
		m_animationDirection.y = newAnimationDirection.y;
	}
}

sf::Vector2f& Movable::getDirection()
{
	return m_direction;
}

sf::Vector2f& Movable::getAnimationDirection()
{
	return m_animationDirection;
}

// This function checks if there's a need to change the animation direction of a game objec's animation:
void Movable::oppositeDirectionHandler(const float curr_x, const float curr_y, const float new_x, const float new_y)
{
	if (curr_x == new_x && curr_y == new_y)
	{
		mirrorSprite();
	}
}

void Movable::mirrorSprite()
{
	sf::Vector2f scale = m_currObjSprite.getScale();
	m_currObjSprite.setScale(-scale.x, scale.y);
}

// This function sets the game objects life bars:
void Movable::setLifeBarRects()
{
	m_lifeBarBackground.setFillColor(sf::Color(54, 66, 71));
	m_lifeBarBackground.setOutlineThickness(1);
	m_lifeBarBackground.setOutlineColor(sf::Color::Black);
	m_lifeBarBackground.setSize(sf::Vector2f(40, 8));

	m_lifeBar.setSize(sf::Vector2f(36, 6));
	m_originalLifeBarWidth = 36;

	// this is for distinguishing between player's objects and PC's objects:
	if (m_owner == PLAYER)
	{
		m_lifeBar.setFillColor(sf::Color(50, 154, 170, 255));
	}
	else
	{
		m_lifeBar.setFillColor(sf::Color::Red);
	}

	m_lifeBarBackground.setPosition(m_currObjSprite.getPosition().x + 10, m_currObjSprite.getPosition().y - 3);	// update once or always(?)
	m_lifeBar.setPosition(m_lifeBarBackground.getPosition().x + 2, m_lifeBarBackground.getPosition().y + 1);	// update once or always(?)
}

// This function updates the game object's life bar size according to their current life points remained:
void Movable::setLifeBar()
{
	float livesPerrcentageRemained = (m_lives * 100) / m_originalLives;
	float livesRectPercentage = (livesPerrcentageRemained * m_originalLifeBarWidth) / 100;

	m_lifeBar.setSize(sf::Vector2f(livesRectPercentage, m_lifeBar.getSize().y));
	m_lifeBarBackground.setPosition(m_currObjSprite.getPosition().x + 10, m_currObjSprite.getPosition().y - m_lifeBarBackground.getSize().y - 3);
	m_lifeBar.setPosition(m_lifeBarBackground.getPosition().x + 2, m_lifeBarBackground.getPosition().y + 1);
}


bool Movable::getIsSpell() const
{
	return m_isSpell;
}


sf::CircleShape& Movable::getSpellTargetArea()
{
	return m_spellTargetArea;
}

// This function sets the spell cards' target areas of impact:
void Movable::setSpellTargetArea(const sf::Vector2f targetLocation)
{
	m_spellTargetArea.setFillColor(sf::Color(20, 96, 154, 130));
	m_spellTargetArea.setRadius(50);
	if (m_owner == PLAYER)
	{
		m_spellTargetArea.setOutlineColor(sf::Color(112, 212, 176, 255));
	}
	else
	{
		m_spellTargetArea.setOutlineColor(sf::Color::Red);
	}
	m_spellTargetArea.setOutlineColor(sf::Color(112, 212, 176, 255));
	m_spellTargetArea.setOutlineThickness(2);
	m_spellTargetArea.setPosition(targetLocation.x - m_spellTargetArea.getRadius(), targetLocation.y - m_spellTargetArea.getRadius());
}

// This function returns the max amount of troop objects that can be affected by a spell:
int Movable::getMaxAffectedTroops() const
{
	return m_maxAffectedTroops;
}

void Movable::setPcSpellDest(sf::Vector2f dest)
{
	m_destLocation.x = dest.x;
	m_destLocation.y = dest.y;

	m_spellTargetArea.setPosition(m_destLocation.x - m_spellTargetArea.getRadius(), m_destLocation.y - m_spellTargetArea.getRadius());
}


void Movable::setLives()
{
	m_lives = -1;
}