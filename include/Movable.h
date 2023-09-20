#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Unmovable.h"

class Movable : public Object
{
public:
	using Object::Object;

	Movable() : Object({ 0,0 }), m_changeAnimationDirection(false), m_oppositeDirection(false)
	{}

	sf::Vector2f getCenter() const override;
	sf::Sprite& getCurrObjSprite();
	sf::Sprite& getBulletSprite();
	virtual void setProperties(const int cardLevel) = 0;
	virtual void mapDirectionToAnimation(const sf::Time deltaTime, const sf::Vector2f animationDirection, const sf::Vector2f direction) = 0;
	virtual void movement(const sf::Time deltaTime, sf::Vector2f direction) = 0;
	void changeAnimationDirection(const sf::Vector2f newAnimationDirection);
	void oppositeDirectionHandler(const float curr_x, const float curr_y, const float new_x, const float new_y);
	void setLifeBarRects();
	void setLifeBar() override;
	sf::CircleShape& getSpellTargetArea();
	void setSpellTargetArea(const sf::Vector2f targetLocation);
	bool getIsSpell() const;
	sf::Vector2f& getDirection();
	sf::Vector2f& getAnimationDirection();
	void setPcSpellDest(sf::Vector2f dest);
	int getMaxAffectedTroops() const;
	void mirrorSprite();
	void setLives();

protected:
	float m_spd;
	float m_duration;
	int m_maxAffectedTroops;
	sf::IntRect m_currObjPos;
	int m_endX;
	int m_startX;
	int m_width;
	int m_endY;
	int m_startY;
	sf::Vector2f m_animationDirection = { 2, 2 };
	bool m_changeAnimationDirection;
	sf::Vector2f m_prevPos;
	sf::Clock m_clockTry;
	sf::Vector2f m_direction;
	bool m_oppositeDirection;
	bool m_isSpell;
	sf::Vector2f m_destLocation;
	int m_soundLevel;

private:
};