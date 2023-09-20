#include "FireballObj.h"
#include "Factory.h"
#include "SpellObj.h"



static auto registerIt = Factory<SpellObj>::instance().registerType(
    ObjectType::Fireball,
    [](sf::Vector2f position, const int cardLevel, const int arena, const bool bigTower, const TURN_OWNER turnOwner, const int soundLevel) -> std::unique_ptr<SpellObj>
    {
        return std::make_unique<FireballObj>(position, cardLevel, arena, turnOwner, soundLevel);
    }
);


// This function builds a Fireball game object:
FireballObj::FireballObj(sf::Vector2f position, const int cardLevel, const int arena, const TURN_OWNER turnOwner, const int soundLevel)
{
    m_soundLevel = soundLevel;
    m_deploySound.setBuffer(Resources::instance().getSound(Resources::FIREBALL_DISPATCH));
    m_hitSound.setBuffer(Resources::instance().getSound(Resources::FIREBALL_HIT));
    m_deploySound.setVolume(20.f * (m_soundLevel));
    m_hitSound.setVolume(20.f * (m_soundLevel));
    m_deploySound.play();

    m_impact = true;
    m_owner = turnOwner;
    m_hitAction = false;
    m_position = position;
    m_destLocation.x = position.x;
    m_destLocation.y = position.y;

    m_currObjPos = sf::IntRect(FIREBALL_FLY_START_X, FIREBALL_FLY_START_Y, FIREBALL_FLY_WIDTH, FIREBALL_FLY_HEIGHT);
    m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::FIREBALL_SP), m_currObjPos);
    m_currObjSprite.setScale(1.0f, 1.0f);

    if (turnOwner == PLAYER)
        m_currObjSprite.setPosition(310, 560);
    else
        m_currObjSprite.setPosition(310, 100);

    m_prevPos.x = 310;
    m_prevPos.y = 560;

    m_clockTry.restart();

    setProperties(cardLevel);
    m_isSpell = true;
    setSpellTargetArea(position);
}

// This function sets the object's attributes:
void FireballObj::setProperties(const int cardLevel)
{
    switch (cardLevel)
    {
    case 1:
        m_atk = FIREBALL_ATK_1;
        m_spd = FIREBALL_SPD_1;
        break;
    case 2:
        m_atk = FIREBALL_ATK_2;
        m_spd = FIREBALL_SPD_2;
        break;
    case 3:
        m_atk = FIREBALL_ATK_3;
        m_spd = FIREBALL_SPD_3;
        break;
    case 4:
        m_atk = FIREBALL_ATK_4;
        m_spd = FIREBALL_SPD_4;
        break;
    case 5:
        m_atk = FIREBALL_ATK_5;
        m_spd = FIREBALL_SPD_5;
        break;
    default:
        break;
    }

    m_lives = FIREBALL_LIVES;
}


void FireballObj::mapDirectionToAnimation(const sf::Time deltaTime, const sf::Vector2f animationDirection, const sf::Vector2f direction)
{
    if ((m_currObjSprite.getGlobalBounds().contains(m_destLocation)) && m_impact)   // checks if needs to be changed to an explosion animation
    {
        m_direction.x = 0;
        m_direction.y = 0;
        m_animationDirection.x = 0;
        m_animationDirection.y = 0;

        m_currObjPos = sf::IntRect(FIREBALL_EXPLOSION_START_X, FIREBALL_EXPLOSION_START_Y, FIREBALL_EXPLOSION_WIDTH, FIREBALL_EXPLOSION_HEIGHT);
        m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::EXPLOSION_SP), m_currObjPos);
        m_currObjSprite.setScale(0.1f, 0.1f);
        m_currObjSprite.setPosition(m_destLocation.x - 60, m_destLocation.y - 80);

        m_startX = FIREBALL_EXPLOSION_START_X;
        m_endX = FIREBALL_EXPLOSION_END_X;
        m_width = FIREBALL_EXPLOSION_WIDTH;

        m_impact = false;
    }

    if (m_impact)
    {
        float x = animationDirection.x, y = animationDirection.y;
        m_animationDirection.x = animationDirection.x;
        m_animationDirection.y = animationDirection.y;
        m_direction.x = direction.x;
        m_direction.y = direction.y;
        m_startX = FIREBALL_FLY_START_X;
        m_endX = FIREBALL_FLY_END_X;
        m_width = FIREBALL_FLY_WIDTH;
    }

    if (m_owner == PLAYER)
    {
        m_spellTargetArea.setOutlineColor(sf::Color(112, 212, 176, 255));
    }
    else
    {
        m_spellTargetArea.setOutlineColor(sf::Color::Red);
    }

    movement(deltaTime, direction);
    m_prevPos = m_currObjSprite.getPosition();
}


void FireballObj::movement(const sf::Time deltaTime, sf::Vector2f direction)
{
    m_spellTargetArea.setFillColor(sf::Color::Transparent);

    if (m_clockTry.getElapsedTime().asSeconds() > 0.2f)
    {
        if (m_currObjPos.left >= m_endX)
        {
            if (!m_impact)
                m_spriteSheetCounter = 0;

            m_currObjPos.left = m_startX;
        }

        else
        {
            if (!m_impact)
            {
                m_spriteSheetCounter++;

                if (m_spriteSheetCounter == 4)  // signifies that the animation reached an impact picture according to the game object's sprite sheet
                {
                    m_hitSound.play();
                    m_hitAction = true;
                    m_spriteSheetCounter -= FIREBALL_EXPLOSION_AMOUNT;
                }

                if (m_spriteSheetCounter > 4)
                {
                    m_hitAction = false;
                }

                if (m_currObjPos.left >= 936)
                {
                    m_lives = -1;
                }
            }
            m_currObjPos.left += m_width;
        }

        m_currObjSprite.setTextureRect(m_currObjPos);
        m_clockTry.restart();
    }

    if (m_impact)
    {
        m_currObjSprite.setScale(1.8f, 1.8f);
    }
    else
    {
        m_currObjSprite.setScale(1.0f, 1.0f);
    }
    m_currObjSprite.move(direction * m_spd * deltaTime.asSeconds());
}





