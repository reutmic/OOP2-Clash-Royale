#include "Bullet.h"

static auto registerIt = Factory<Movable>::instance().registerType(
    ObjectType::Bullet,
    [](sf::Vector2f position, const int cardLevel, const int arena, const bool bigTower, const TURN_OWNER turnOwner, const int soundLevel) -> std::unique_ptr<Movable>
    {
        return std::make_unique<Bullet>(position, turnOwner, arena);
    }
);

Bullet::Bullet(sf::Vector2f position, const TURN_OWNER turnOwner, const int arena)
{
    m_owner = turnOwner;
    m_position = position;

    m_hitAction = true;

    m_bulletSprite.setTexture(Resources::instance().getCommonImg(Resources::BULLET));
    m_bulletSprite.setScale(0.15f, 0.15f);
    m_bulletSprite.setPosition(position.x - (m_bulletSprite.getGlobalBounds().width / 2), position.y - (m_bulletSprite.getGlobalBounds().height / 2));
    m_prevPos.x = position.x - (m_bulletSprite.getGlobalBounds().width / 2);
    m_prevPos.y = position.y - (m_bulletSprite.getGlobalBounds().height / 2);
    m_bulletSprite.setOrigin(sf::Vector2f(m_bulletSprite.getTexture()->getSize() / 2u));

    switch (turnOwner)
    {
    case PLAYER:
        m_endY = position.y - 100;
        break;

    case PC:
        m_endY = position.y + 100;
        break;
    }

    switch (arena)
    {
    case 1:
        m_atk = BULLET_ATK_1;
        break;
    case 2:
        m_atk = BULLET_ATK_2;
        break;
    case 3:
        m_atk = BULLET_ATK_3;
        break;
    case 4:
        m_atk = BULLET_ATK_4;
        break;
    }

    setProperties(0);
}

void Bullet::setProperties(const int cardLevel)
{
    m_spd = BULLET_SPD;
    m_lives = BULLET_LIVES;
}


void Bullet::movement(const sf::Time deltaTime, sf::Vector2f direction)
{
    if ((m_owner == PLAYER && m_bulletSprite.getPosition().y <= m_endY) ||
        (m_owner == PC && m_bulletSprite.getPosition().y >= m_endY))
    {
        m_hitAction = true;
        m_bulletSprite.setPosition(m_bulletSprite.getPosition().x, m_position.y);
    }
    else
    {
        m_bulletSprite.move(direction * m_spd * deltaTime.asSeconds());
    }
}
