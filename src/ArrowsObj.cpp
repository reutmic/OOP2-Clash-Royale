#include "ArrowsObj.h"
#include "Factory.h"
#include "SpellObj.h"



static auto registerIt = Factory<SpellObj>::instance().registerType(
    ObjectType::Arrows,
    [](sf::Vector2f position, const int cardLevel, const int arena, const bool bigTower, const TURN_OWNER turnOwner, const int soundLevel) -> std::unique_ptr<SpellObj>
    {
        return std::make_unique<ArrowsObj>(position, cardLevel, arena, turnOwner, soundLevel);
    }
);



ArrowsObj::ArrowsObj(sf::Vector2f position, const int cardLevel, const int arena, const TURN_OWNER turnOwner, const int soundLevel)
{
    m_soundLevel = soundLevel;
    m_hitSound.setBuffer(Resources::instance().getSound(Resources::ARROWS_HIT));
    m_hitSound.setVolume(20.f * (m_soundLevel));

    m_impact = true;
    m_owner = turnOwner;

    // reut3
    m_hitAction = false;
    //

    m_position = position;

    m_destLocation.x = position.x;
    m_destLocation.y = position.y;

    // m_currObjPos = sf::IntRect(0, 0, 604, 413);
   //  m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::ARROWS_SP), m_currObjPos);
    m_currObjSprite.setScale(0.2f, 0.2f);

    // reut5
    if (turnOwner == PLAYER)
    {
        m_currObjSprite.setPosition(310, 560);
        m_prevPos.x = 310;
        m_prevPos.y = 580;
    }
    else
    {
        m_currObjSprite.setPosition(310, 100);
        m_prevPos.x = 310;
        m_prevPos.y = 100;
    }
    //

// reut2
    if (position.x > m_currObjSprite.getPosition().x)
    {
        //       m_destLocation.x = position.x + (m_currObjSprite.getGlobalBounds().width / 2);

    }
    else
    {
        //      m_destLocation.x = position.x - (m_currObjSprite.getGlobalBounds().width / 2);

    }

    //  if (position.y > m_currObjSprite.getPosition().y)
    //  {
    //      m_destLocation.y = position.y + (m_currObjSprite.getGlobalBounds().height / 2);

   //   }
    //  else
    //  {
    //      m_destLocation.y = position.y - (m_currObjSprite.getGlobalBounds().height / 2);

    //  }
          //

    // reut5
   // m_prevPos.x = 310;
    //m_prevPos.y = 580;
    //

    m_clockTry.restart();

    setProperties(cardLevel);

    // reut2
    m_isSpell = true;

    setSpellTargetArea(position);
    //
}


void ArrowsObj::setProperties(const int cardLevel)
{
    switch (cardLevel)
    {
    case 1:
        m_atk = ARROWS_ATK_1;
        m_spd = ARROWS_SPD_1;
        break;
    case 2:
        m_atk = ARROWS_ATK_2;
        m_spd = ARROWS_SPD_2;
        break;
    case 3:
        m_atk = ARROWS_ATK_3;
        m_spd = ARROWS_SPD_3;
        break;
    case 4:
        m_atk = ARROWS_ATK_4;
        m_spd = ARROWS_SPD_4;
        break;
    case 5:
        m_atk = ARROWS_ATK_5;
        m_spd = ARROWS_SPD_5;
        break;
    default:
        break;
    }

    m_lives = ARROWS_LIVES;
}


void ArrowsObj::mapDirectionToAnimation(const sf::Time deltaTime, const sf::Vector2f animationDirection, const sf::Vector2f direction)
{
    //if ((m_currObjSprite.getGlobalBounds().contains(m_destLocation)) && m_impact)
    if ((m_currObjSprite.getGlobalBounds().intersects(m_spellTargetArea.getGlobalBounds()) && m_impact))
    {
        m_direction.x = 0;
        m_direction.y = 0;
        m_animationDirection.x = 0;
        m_animationDirection.y = 0;

        m_currObjPos = sf::IntRect(ARROWS_SMOKE_START_X, ARROWS_SMOKE_START_Y, ARROWS_SMOKE_WIDTH, ARROWS_SMOKE_HEIGHT);
        m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::SMOKE_SP), m_currObjPos);
        m_currObjSprite.setScale(0.1f, 0.1f);
        //  m_currObjSprite.setPosition(m_prevPos);   // reut2
          //m_currObjSprite.setPosition(m_spellTargetArea.getPosition().x - 50 , m_spellTargetArea.getPosition().y - 50);
        m_currObjSprite.setPosition(m_destLocation.x - 70, m_destLocation.y - 60);
        //m_currObjSprite.setPosition(300 , 300);
        //

        m_startX = ARROWS_SMOKE_START_X;
        m_endX = ARROWS_SMOKE_END_X;
        m_width = ARROWS_SMOKE_WIDTH;

        m_impact = false;

        // reut3
       // m_hitAction = true;
        //
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

        if (x == 0 && y == -1)
        {
            m_currObjPos = sf::IntRect(ARROWS_FLY_UP_START_X, ARROWS_FLY_UP_START_Y, ARROWS_FLY_UP_WIDTH, ARROWS_FLY_UP_HEIGHT);
            m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::ARROWS_SP), m_currObjPos);
            m_currObjSprite.setPosition(m_prevPos);
        }
        else if (x == 0.5 && y == -0.5)
        {
            m_currObjPos = sf::IntRect(ARROWS_FLY_UP_RIGHT_START_X, ARROWS_FLY_UP_RIGHT_START_Y, ARROWS_FLY_UP_RIGHT_WIDTH, ARROWS_FLY_UP_RIGHT_HEIGHT);
            m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::ARROWS_SP), m_currObjPos);
            m_currObjSprite.setPosition(m_prevPos.x, m_prevPos.y);
        }
        else if (x == 1 && y == 0)
        {
            m_currObjPos = sf::IntRect(ARROWS_FLY_RIGHT_START_X, ARROWS_FLY_RIGHT_START_Y, ARROWS_FLY_RIGHT_WIDTH, ARROWS_FLY_RIGHT_HEIGHT);
            m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::ARROWS_SP), m_currObjPos);
            m_currObjSprite.setPosition(m_prevPos);
        }
        else if (x == 0.5 && y == 0.5)
        {
            m_currObjPos = sf::IntRect(ARROWS_FLY_DOWN_RIGHT_START_X, ARROWS_FLY_DOWN_RIGHT_START_Y, ARROWS_FLY_DOWN_RIGHT_WIDTH, ARROWS_FLY_DOWN_RIGHT_HEIGHT);
            m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::ARROWS_SP), m_currObjPos);
            m_currObjSprite.setPosition(m_prevPos);
        }
        else if (x == 0 && y == 1)
        {
            m_currObjPos = sf::IntRect(ARROWS_FLY_DOWN_START_X, ARROWS_FLY_DOWN_START_Y, ARROWS_FLY_DOWN_WIDTH, ARROWS_FLY_DOWN_HEIGHT);
            m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::ARROWS_SP), m_currObjPos);
            m_currObjSprite.setPosition(m_prevPos);
        }
        else if (x == -0.5 && y == 0.5)
        {
            m_currObjPos = sf::IntRect(ARROWS_FLY_DOWN_LEFT_START_X, ARROWS_FLY_DOWN_LEFT_START_Y, ARROWS_FLY_DOWN_LEFT_WIDTH, ARROWS_FLY_DOWN_LEFT_HEIGHT);
            m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::ARROWS_SP), m_currObjPos);
            m_currObjSprite.setPosition(m_prevPos);
        }
        else if (x == -1 && y == 0)
        {
            m_currObjPos = sf::IntRect(ARROWS_FLY_LEFT_START_X, ARROWS_FLY_LEFT_START_Y, ARROWS_FLY_LEFT_WIDTH, ARROWS_FLY_LEFT_HEIGHT);
            m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::ARROWS_SP), m_currObjPos);
            m_currObjSprite.setPosition(m_prevPos);
        }
        else if (x == -0.5 && y == -0.5)
        {
            m_currObjPos = sf::IntRect(ARROWS_FLY_UP_LEFT_START_X, ARROWS_FLY_UP_LEFT_START_Y, ARROWS_FLY_UP_LEFT_WIDTH, ARROWS_FLY_UP_LEFT_HEIGHT);
            m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::ARROWS_SP), m_currObjPos);
            m_currObjSprite.setPosition(m_prevPos);
        }

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


void ArrowsObj::movement(const sf::Time deltaTime, sf::Vector2f direction)
{
    m_spellTargetArea.setFillColor(sf::Color::Transparent);

    if (m_clockTry.getElapsedTime().asSeconds() > 0.2f)
    {
        if ((m_currObjPos.left >= ARROWS_SMOKE_END_X) && !m_impact)
        {
            m_spriteSheetCounter = 0;
            m_lives = -1;
        }

        else
        {
            if (!m_impact) 
            {
                m_spriteSheetCounter++;

                if (m_spriteSheetCounter == 3)
                {
                    m_hitAction = true;
                    m_spriteSheetCounter -= ARROWS_SMOKE_AMOUNT;
                }

                if (m_spriteSheetCounter > 3)
                {
                    m_hitAction = false;
                }
            }
            //
            m_currObjPos.left += m_width;
            m_currObjSprite.setTextureRect(m_currObjPos);
        }
        m_clockTry.restart();
    }

    if (m_impact)
    {
        m_currObjSprite.setScale(0.5f, 0.5f);
    }
    else
    {
        m_currObjSprite.setScale(0.7f, 0.7f);

    }
    m_currObjSprite.move(direction * m_spd * deltaTime.asSeconds());
}





