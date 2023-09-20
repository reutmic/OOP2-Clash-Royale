#include "Tower.h"

static auto registerIt = Factory<Unmovable>::instance().registerType(
    ObjectType::Tower,
    [](sf::Vector2f position, const int cardLevel, const int arena, const bool bigTower, const TURN_OWNER turnOwner, const int soundLevel) -> std::unique_ptr<Unmovable>
    {
        return std::make_unique<Tower>(position, cardLevel, arena, bigTower, turnOwner);
    }
);


Tower::Tower(sf::Vector2f position, const int cardLevel, const int arena, const bool bigTower, const TURN_OWNER turnOwner)
{
    m_hitByFireball = false;
    m_hitByArrows = false;

    m_position = position;
    m_owner = turnOwner;

    if (bigTower)   // checks if the tower is the main fortress
    {
        m_bigTower = true;
        if (turnOwner == PC)
            m_objBorder.setSize(sf::Vector2f(75, 75));
        else
            m_objBorder.setSize(sf::Vector2f(75, 90));

        switch (arena)      // defines the fortress's lives according to the level of the player's arena
        {
        case 1:
            m_lives = BIG_TOWER_LIVES_1;
            break;
        case 2:
            m_lives = BIG_TOWER_LIVES_2;
            break;
        case 3:
            m_lives = BIG_TOWER_LIVES_3;
            break;
        case 4:
            m_lives = BIG_TOWER_LIVES_4;
            break;
        }
    }
    else
    {
        m_bigTower = false;
        m_objBorder.setSize(sf::Vector2f(60, 60));

        switch (arena)
        {
        case 1:
            m_lives = REG_TOWER_LIVES_1;
            break;
        case 2:
            m_lives = REG_TOWER_LIVES_2;
            break;
        case 3:
            m_lives = REG_TOWER_LIVES_3;
            break;
        case 4:
            m_lives = REG_TOWER_LIVES_4;
            break;
        }
    }

    m_objBorder.setFillColor(sf::Color::Transparent);
    m_objBorder.setPosition(position);
    m_center.x = m_objBorder.getPosition().x + (m_objBorder.getSize().x / 2);
    m_center.y = m_objBorder.getPosition().y + (m_objBorder.getSize().y / 2);

    m_lifeBar.setFillColor(sf::Color(54, 66, 71));
    m_lifeBar.setOutlineThickness(3);
    m_lifeBar.setOutlineColor(sf::Color(196, 169, 77));

    m_life_bar_crown.setTexture(Resources::instance().getCommonImg(Resources::LIFE_BAR_CROWN));

    m_life_bar_count.setFont(Resources::instance().getFont());
    m_life_bar_count.setFillColor(sf::Color(236, 205, 194));
    m_life_bar_count.setOutlineColor(sf::Color::Black);
    m_life_bar_count.setOutlineThickness(2);

    if (bigTower)
    {
        m_lifeBar.setSize(sf::Vector2f(92, 24));

        if (turnOwner == PC)
            m_lifeBar.setPosition(m_objBorder.getPosition().x - 7, m_objBorder.getPosition().y - m_lifeBar.getSize().y - 28);

        else
            m_lifeBar.setPosition(m_objBorder.getPosition().x - 7, m_objBorder.getPosition().y + m_objBorder.getSize().y + m_lifeBar.getSize().y - 25);

        m_life_bar_crown.setScale(0.3f, 0.3f);
        m_life_bar_crown.setPosition(m_lifeBar.getPosition().x, m_lifeBar.getPosition().y);

        m_life_bar_count.setCharacterSize(13);
        m_life_bar_count.setPosition(m_life_bar_crown.getPosition().x + 28, m_life_bar_crown.getPosition().y + 4);
    }
    else
    {
        m_lifeBar.setSize(sf::Vector2f(73, 15));

        if (turnOwner == PC)
            m_lifeBar.setPosition(m_objBorder.getPosition().x - 7, m_objBorder.getPosition().y - m_lifeBar.getSize().y - 6);
        else
            m_lifeBar.setPosition(m_objBorder.getPosition().x - 7, m_objBorder.getPosition().y + m_objBorder.getSize().y + m_lifeBar.getSize().y - 32);

        m_life_bar_crown.setScale(0.2f, 0.2f);
        m_life_bar_crown.setPosition(m_lifeBar.getPosition().x, m_lifeBar.getPosition().y);

        m_life_bar_count.setCharacterSize(9);
        m_life_bar_count.setPosition(m_life_bar_crown.getPosition().x + 24, m_life_bar_crown.getPosition().y + 3);
    }
}


void Tower::setLifeBar()
{
    m_life_bar_count.setString(std::to_string(m_lives));
}


