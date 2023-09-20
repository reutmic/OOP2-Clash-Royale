#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteSheetsConsts.h"
#include "Resources.h"
#include "ObjsProperitesConsts.h"


enum TURN_OWNER {
    PLAYER,
    PC
};

class Object
{
public:
    Object(sf::Vector2f position) : m_position(position),
        m_spriteSheetCounter(0), m_hitMode(false), m_startedHit(false), m_hitAction(false),
        m_check1(false), m_check2(false), m_collidedWithTerritory(false), m_pcTerritoryCollision(false),
        m_playerTerritoryCollision(false)
    {}
    virtual ~Object() = default;
    virtual sf::Vector2f getCenter() const = 0;
    bool checkCollision(Object& other);
    int getLives() const;
    int getAtk() const;
    void decLives(const int atk);
    int getSpriteSheetCounter() const;
    bool getHitAction() const;
    void setHitAction(const bool hitAction);
    void setHitByFireball(const bool hitByFireball);
    void setHitByArrows(const bool hitByArrows);
    sf::RectangleShape& getLifeBar();
    sf::Sprite& getLifeBarCrown();
    sf::Text& getLifeBarCount();
    virtual void setLifeBar() = 0;
    sf::Vector2f getPos() const;
    TURN_OWNER getOwner() const;
    sf::RectangleShape& getRect();
    void setCollidedWithTerritory(const bool collided);
    void setPcTerritoryCollision(const bool collision);
    void setPlayerTerritoryCollision(const bool collision);
    bool getCollidedWithTerritory() const;
    bool getPcTerritoryCollision() const;
    bool getPlayerTerritoryCollision() const;
    sf::RectangleShape& getLifeBarBackground();
    void setFrozenState(bool isFrozen);
    int getFrozenAmount() const;
    void addToFrozenAmount();
    bool getHitByFireball();
    bool getHitByArrows();

protected:
    TURN_OWNER m_owner;
    int m_lives;
    int m_atk;
    sf::Sprite m_currObjSprite;
    sf::Sprite m_bulletSprite;
    sf::RectangleShape m_objBorder;
    sf::Vector2f m_position;
    sf::Vector2f m_center;
    int m_spriteSheetCounter;
    bool m_hitMode;
    bool m_startedHit;
    bool m_hitAction;
    sf::RectangleShape m_lifeBar;
    sf::Sprite m_life_bar_crown;
    sf::Text m_life_bar_count;
    sf::RectangleShape m_territoryRect;
    bool m_check1;
    bool m_check2;
    bool m_collidedWithTerritory;
    bool m_pcTerritoryCollision;
    bool m_playerTerritoryCollision;
    sf::RectangleShape m_lifeBarBackground;
    int m_originalLives;
    float m_originalLifeBarWidth;
    bool m_frozen;
    sf::CircleShape m_spellTargetArea;
    int m_freezeTroopsAmount;
    bool m_hitByFireball;
    bool m_hitByArrows;
    sf::Sound m_hitSound;
    sf::Sound m_deploySound;

private:
};
