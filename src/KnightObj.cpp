#include "KnightObj.h"
#include "Factory.h"
#include "TroopObj.h"

static auto registerIt = Factory<TroopObj>::instance().registerType(
    ObjectType::Knight,
    [](sf::Vector2f position, const int cardLevel, const int arena, const bool bigTower, const TURN_OWNER turnOwner, const int soundLevel) -> std::unique_ptr<TroopObj>
    {
        return std::make_unique<KnightObj>(position, cardLevel, arena, turnOwner, soundLevel);
    }
);


// This function builds a Knight game object:
KnightObj::KnightObj(sf::Vector2f position, const int cardLevel, const int arena, const TURN_OWNER turnOwner, const int soundLevel)
{
    m_soundLevel = soundLevel;
    m_hitSound.setBuffer(Resources::instance().getSound(Resources::KNIGHT_WALK));
    m_deploySound.setBuffer(Resources::instance().getSound(Resources::KNIGHT_DEPLOY_SOUND));
    m_hitSound.setVolume(20.f * (m_soundLevel));
    m_deploySound.setVolume(20.f * (m_soundLevel));
    m_deploySound.play();

    m_hitByFireball = false;
    m_hitByArrows = false;
    m_frozen = false;
    m_owner = turnOwner;
    m_position = position;

    m_currObjPos = sf::IntRect(KNIGHT_WALK_UP_START_X, KNIGHT_WALK_UP_START_Y, KNIGHT_WALK_UP_WIDTH, KNIGHT_WALK_UP_HEIGHT);
    m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::KNIGHT_SP), m_currObjPos);
    m_currObjSprite.setScale(0.5f, 0.5f);
    m_currObjSprite.setPosition(position.x - (m_currObjSprite.getGlobalBounds().width / 2), position.y - (m_currObjSprite.getGlobalBounds().height / 2));
    m_prevPos.x = position.x - (m_currObjSprite.getGlobalBounds().width / 2);
    m_prevPos.y = position.y - (m_currObjSprite.getGlobalBounds().height / 2);
    m_currObjSprite.setOrigin(sf::Vector2f(m_currObjSprite.getTexture()->getSize() / 2u));

    m_clockTry.restart();
    setProperties(cardLevel);
    setLifeBarRects();

    m_isSpell = false;
}


// This function sets the object's attributes:
void KnightObj::setProperties(const int cardLevel)
{
    switch (cardLevel)
    {
    case 1:
        m_atk = KNIGHT_ATK_1;
        m_spd = KNIGHT_SPD_1;
        m_lives = KNIGHT_LIVES_1;
        break;
    case 2:
        m_atk = KNIGHT_ATK_2;
        m_spd = KNIGHT_SPD_2;
        m_lives = KNIGHT_LIVES_2;
        break;
    case 3:
        m_atk = KNIGHT_ATK_3;
        m_spd = KNIGHT_SPD_3;
        m_lives = KNIGHT_LIVES_3;
        break;
    case 4:
        m_atk = KNIGHT_ATK_4;
        m_spd = KNIGHT_SPD_4;
        m_lives = KNIGHT_LIVES_4;
        break;
    case 5:
        m_atk = KNIGHT_ATK_5;
        m_spd = KNIGHT_SPD_5;
        m_lives = KNIGHT_LIVES_5;
        break;
    default:
        break;
    }

    m_originalLives = m_lives;
}


// This function checks which animation direction fits best for the current movement:
void KnightObj::mapDirectionToAnimation(const sf::Time deltaTime, const sf::Vector2f animationDirection, const sf::Vector2f direction)
{
    float x = animationDirection.x, y = animationDirection.y;

    if (m_changeAnimationDirection || m_hitMode)
    {
        if (x == 0 && y == -1)
        {
            if (m_hitMode && !m_startedHit)
            {
                m_startX = KNIGHT_HIT_UP_START_X;
                m_endX = KNIGHT_HIT_UP_END_X;
                m_width = KNIGHT_HIT_UP_WIDTH;
                m_currObjPos = sf::IntRect(KNIGHT_HIT_UP_START_X, KNIGHT_HIT_UP_START_Y, KNIGHT_HIT_UP_WIDTH, KNIGHT_HIT_UP_HEIGHT);
                m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::KNIGHT_SP), m_currObjPos);
                m_currObjSprite.setScale(0.5f, 0.5f);
                m_currObjSprite.setPosition(m_prevPos);
                m_startedHit = true;
            }
            else if (!m_hitMode)
            {
                m_startX = KNIGHT_WALK_UP_START_X;
                m_endX = KNIGHT_WALK_UP_END_X;
                m_width = KNIGHT_WALK_UP_WIDTH;
                m_currObjPos = sf::IntRect(KNIGHT_WALK_UP_START_X, KNIGHT_WALK_UP_START_Y, KNIGHT_WALK_UP_WIDTH, KNIGHT_WALK_UP_HEIGHT);
                m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::KNIGHT_SP), m_currObjPos);
                m_currObjSprite.setScale(0.5f, 0.5f);
                m_currObjSprite.setPosition(m_prevPos);
            }
        }
        else if ((x == 0.5 && y == -0.5) || (x == -0.5 && y == -0.5))
        {
            if (m_hitMode && !m_startedHit)
            {
                m_startX = KNIGHT_HIT_UP_RIGHT_START_X;
                m_endX = KNIGHT_HIT_UP_RIGHT_END_X;
                m_width = KNIGHT_HIT_UP_RIGHT_WIDTH;
                m_currObjPos = sf::IntRect(KNIGHT_HIT_UP_RIGHT_START_X, KNIGHT_HIT_UP_RIGHT_START_Y, KNIGHT_HIT_UP_RIGHT_WIDTH, KNIGHT_HIT_UP_RIGHT_HEIGHT);
                m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::KNIGHT_SP), m_currObjPos);
                m_currObjSprite.setScale(0.5f, 0.5f);
                m_currObjSprite.setPosition(m_prevPos);
                m_startedHit = true;
                oppositeDirectionHandler(x, y, -0.5, -0.5);
            }
            else if (!m_hitMode)
            {
                m_startX = KNIGHT_WALK_UP_RIGHT_START_X;
                m_endX = KNIGHT_WALK_UP_RIGHT_END_X;
                m_width = KNIGHT_WALK_UP_RIGHT_WIDTH;
                m_currObjPos = sf::IntRect(KNIGHT_WALK_UP_RIGHT_START_X, KNIGHT_WALK_UP_RIGHT_START_Y, KNIGHT_WALK_UP_RIGHT_WIDTH, KNIGHT_WALK_UP_RIGHT_HEIGHT);
                m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::KNIGHT_SP), m_currObjPos);
                m_currObjSprite.setScale(0.5f, 0.5f);
                m_currObjSprite.setPosition(m_prevPos);
                oppositeDirectionHandler(x, y, -0.5, -0.5);
            }
        }
        else if ((x == 1 && y == 0) || (x == -1 && y == 0))
        {
            if (m_hitMode && !m_startedHit)
            {
                m_startX = KNIGHT_HIT_RIGHT_START_X;
                m_endX = KNIGHT_HIT_RIGHT_END_X;
                m_width = KNIGHT_HIT_RIGHT_WIDTH;
                m_currObjPos = sf::IntRect(KNIGHT_HIT_RIGHT_START_X, KNIGHT_HIT_RIGHT_START_Y, KNIGHT_HIT_RIGHT_WIDTH, KNIGHT_HIT_RIGHT_HEIGHT);
                m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::KNIGHT_SP), m_currObjPos);
                m_currObjSprite.setScale(0.5f, 0.5f);
                m_currObjSprite.setPosition(m_prevPos);
                m_startedHit = true;
                oppositeDirectionHandler(x, y, -1, 0);
            }

            else if (!m_hitMode)
            {
                m_startX = KNIGHT_WALK_RIGHT_START_X;
                m_endX = KNIGHT_WALK_RIGHT_END_X;
                m_width = KNIGHT_WALK_RIGHT_WIDTH;
                m_currObjPos = sf::IntRect(KNIGHT_WALK_RIGHT_START_X, KNIGHT_WALK_RIGHT_START_Y, KNIGHT_WALK_RIGHT_WIDTH, KNIGHT_WALK_RIGHT_HEIGHT);
                m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::KNIGHT_SP), m_currObjPos);
                m_currObjSprite.setScale(0.5f, 0.5f);
                m_currObjSprite.setPosition(m_prevPos);
                oppositeDirectionHandler(x, y, -1, 0);
            }
        }
        else if ((x == 0.5 && y == 0.5) || (x == -0.5 && y == 0.5))
        {
            if (m_hitMode && !m_startedHit)
            {
                m_startX = KNIGHT_HIT_DOWN_RIGHT_START_X;
                m_endX = KNIGHT_HIT_DOWN_RIGHT_END_X;
                m_width = KNIGHT_HIT_DOWN_RIGHT_WIDTH;
                m_currObjPos = sf::IntRect(KNIGHT_HIT_DOWN_RIGHT_START_X, KNIGHT_HIT_DOWN_RIGHT_START_Y, KNIGHT_HIT_DOWN_RIGHT_WIDTH, KNIGHT_HIT_DOWN_RIGHT_HEIGHT);
                m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::KNIGHT_SP), m_currObjPos);
                m_currObjSprite.setScale(0.5f, 0.5f);
                m_currObjSprite.setPosition(m_prevPos);
                m_startedHit = true;
                oppositeDirectionHandler(x, y, -0.5, 0.5);
            }

            else if (!m_hitMode)
            {
                m_startX = KNIGHT_WALK_DOWN_RIGHT_START_X;
                m_endX = KNIGHT_WALK_DOWN_RIGHT_END_X;
                m_width = KNIGHT_WALK_DOWN_RIGHT_WIDTH;
                m_currObjPos = sf::IntRect(KNIGHT_WALK_DOWN_RIGHT_START_X, KNIGHT_WALK_DOWN_RIGHT_START_Y, KNIGHT_WALK_DOWN_RIGHT_WIDTH, KNIGHT_WALK_DOWN_RIGHT_HEIGHT);
                m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::KNIGHT_SP), m_currObjPos);
                m_currObjSprite.setScale(0.5f, 0.5f);
                m_currObjSprite.setPosition(m_prevPos);
                oppositeDirectionHandler(x, y, -0.5, 0.5);
            }

        }
        else if (x == 0 && y == 1)
        {
            if (m_hitMode && !m_startedHit)
            {
                m_startX = KNIGHT_HIT_DOWN_START_X;
                m_endX = KNIGHT_HIT_DOWN_END_X;
                m_width = KNIGHT_HIT_DOWN_WIDTH;
                m_currObjPos = sf::IntRect(KNIGHT_HIT_DOWN_START_X, KNIGHT_HIT_DOWN_START_Y, KNIGHT_HIT_DOWN_WIDTH, KNIGHT_HIT_DOWN_HEIGHT);
                m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::KNIGHT_SP), m_currObjPos);
                m_currObjSprite.setScale(0.5f, 0.5f);
                m_currObjSprite.setPosition(m_prevPos);
                m_startedHit = true;
            }

            else if (!m_hitMode)
            {
                m_startX = KNIGHT_WALK_DOWN_START_X;
                m_endX = KNIGHT_WALK_DOWN_END_X;
                m_width = KNIGHT_WALK_DOWN_WIDTH;
                m_currObjPos = sf::IntRect(KNIGHT_WALK_DOWN_START_X, KNIGHT_WALK_DOWN_START_Y, KNIGHT_WALK_DOWN_WIDTH, KNIGHT_WALK_DOWN_HEIGHT);
                m_currObjSprite = sf::Sprite(Resources::instance().getSpriteSheet(Resources::KNIGHT_SP), m_currObjPos);
                m_currObjSprite.setScale(0.5f, 0.5f);
                m_currObjSprite.setPosition(m_prevPos);
            }

        }
        m_changeAnimationDirection = false;
    }

    movement(deltaTime, direction);
    m_prevPos = m_currObjSprite.getPosition();
}


void KnightObj::movement(const sf::Time deltaTime, sf::Vector2f direction)
{
    if (!m_frozen)
    {
        if (m_clockTry.getElapsedTime().asSeconds() > 0.1f)
        {
            if (m_currObjPos.left >= m_endX)
            {
                if (m_hitMode)
                    m_spriteSheetCounter = 0;
                m_currObjPos.left = m_startX;
                m_hitMode = false;
                m_startedHit = false;
                m_changeAnimationDirection = true;
            }

            else
            {
                if (m_hitMode)
                {
                    m_spriteSheetCounter++;

                    if (m_spriteSheetCounter == 4)  // signifies that the animation reached an impact picture according to the game object's sprite sheet
                    {
                        m_hitSound.play();
                        m_hitAction = true;
                        m_spriteSheetCounter -= KNIGHT_HIT_AMOUNT;
                    }
                }
                m_currObjPos.left += m_width;
            }

            m_currObjSprite.setTextureRect(m_currObjPos);
            m_clockTry.restart();
        }

        if (!m_hitMode)
            m_currObjSprite.move(direction * m_spd * deltaTime.asSeconds());
    }
}
