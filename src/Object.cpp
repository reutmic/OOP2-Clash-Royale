#include "Object.h"


// This function checks and returns if there's a collision with an object:
bool Object::checkCollision(Object& other)
{
	if (&other == this)
		return false;

	bool result1 = (m_owner != other.getOwner()) && (m_currObjSprite.getGlobalBounds().intersects(other.m_currObjSprite.getGlobalBounds())) ||
		(m_owner != other.getOwner()) && (m_currObjSprite.getGlobalBounds().intersects(other.m_objBorder.getGlobalBounds()));

	bool result2 = (m_owner != other.getOwner()) && (m_currObjSprite.getGlobalBounds().intersects(other.m_territoryRect.getGlobalBounds()));

	bool result3 = (m_owner != other.getOwner()) && (m_currObjSprite.getGlobalBounds().intersects(other.m_bulletSprite.getGlobalBounds()));

	bool result4 = (m_owner != other.getOwner()) && (m_currObjSprite.getGlobalBounds().intersects(other.m_spellTargetArea.getGlobalBounds()));

	if (result1)
		m_hitMode = true;

	return (result1 || result2 || result3 || result4);
}


int Object::getLives() const
{
	return m_lives;
}


int Object::getAtk() const
{
	return m_atk;
}


void Object::decLives(const int atk)
{
	m_lives -= atk;
}

// This function returns the picture counter of an attack animation of an object:
int Object::getSpriteSheetCounter() const
{
	return m_spriteSheetCounter;
}

// This function returns if an object is in a hit animation:
bool Object::getHitAction() const
{
	return m_hitAction;
}


void Object::setHitAction(const bool hitAction)
{
	m_hitAction = hitAction;
}


sf::RectangleShape& Object::getLifeBar()
{
	return m_lifeBar;
}


sf::Sprite& Object::getLifeBarCrown()
{
	return m_life_bar_crown;
}


sf::Text& Object::getLifeBarCount()
{
	return m_life_bar_count;
}


sf::Vector2f Object::getPos() const
{
	return m_position;
}


TURN_OWNER Object::getOwner() const
{
	return m_owner;
}

// This function returns a rectangle that represents a territory in the battle (player's or PC's territory):
sf::RectangleShape& Object::getRect()
{
	return m_territoryRect;
}


void Object::setCollidedWithTerritory(const bool collided)
{
	m_collidedWithTerritory = collided;
}


void Object::setPcTerritoryCollision(const bool collision)
{
	m_pcTerritoryCollision = collision;
}


void Object::setPlayerTerritoryCollision(const bool collision)
{
	m_playerTerritoryCollision = collision;
}


bool Object::getCollidedWithTerritory() const
{
	return m_collidedWithTerritory;
}


bool Object::getPcTerritoryCollision() const
{
	return m_pcTerritoryCollision;
}


bool Object::getPlayerTerritoryCollision() const
{
	return m_playerTerritoryCollision;
}


sf::RectangleShape& Object::getLifeBarBackground()
{
	return m_lifeBarBackground;
}

void Object::setFrozenState(bool isFrozen)
{
	m_frozen = isFrozen;
}

int Object::getFrozenAmount() const
{
	return m_freezeTroopsAmount;
}

void Object::addToFrozenAmount()
{
	m_freezeTroopsAmount++;
}

bool Object::getHitByFireball()
{
	return m_hitByFireball;
}

void Object::setHitByFireball(const bool hitByFireball)
{
	m_hitByFireball = hitByFireball;
}

bool Object::getHitByArrows()
{
	return m_hitByArrows;
}

void Object::setHitByArrows(const bool hitByArrows)
{
	m_hitByArrows = hitByArrows;
}