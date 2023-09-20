#include "FreezeObj.h"
#include "Factory.h"
#include "SpellObj.h"

static auto registerIt = Factory<SpellObj>::instance().registerType(
    ObjectType::Freeze,
    [](sf::Vector2f position, const int cardLevel, const int arena, const bool bigTower, const TURN_OWNER turnOwner, const int soundLevel) -> std::unique_ptr<SpellObj>
    {
        return std::make_unique<FreezeObj>(position, cardLevel, arena, turnOwner, soundLevel);
    }
);


// This function builds a Freeze game object:
FreezeObj::FreezeObj(sf::Vector2f position, const int cardLevel, const int arena, const TURN_OWNER turnOwner, const int soundLevel)
{
    m_soundLevel = soundLevel;
    m_hitSound.setBuffer(Resources::instance().getSound(Resources::FREEZE_SOUND));
    m_hitSound.setVolume(20.f * (m_soundLevel));
    m_hitSound.play();

    m_owner = turnOwner;
    m_hitAction = true;
    m_finishedFreezingAction = false;
    m_freezeTroopsAmount = 0;
    m_position = position;
    m_destLocation.x = position.x;
    m_destLocation.y = position.y;

    m_clockTry.restart();
    setProperties(cardLevel);
    m_isSpell = true;
    setSpellTargetArea(position);
}


// This function sets the object's attributes:
void FreezeObj::setProperties(const int cardLevel)
{
    switch (cardLevel)
    {
    case 1:
        m_duration = FREEZE_DURATION_1;
        m_maxAffectedTroops = FREEZE_MAX_AFFECTED_1;
        break;
    case 2:
        m_duration = FREEZE_DURATION_2;
        m_maxAffectedTroops = FREEZE_MAX_AFFECTED_2;
        break;
    case 3:
        m_duration = FREEZE_DURATION_3;
        m_maxAffectedTroops = FREEZE_MAX_AFFECTED_3;
        break;
    case 4:
        m_duration = FREEZE_DURATION_4;
        m_maxAffectedTroops = FREEZE_MAX_AFFECTED_4;
        break;
    case 5:
        m_duration = FREEZE_DURATION_5;
        m_maxAffectedTroops = FREEZE_MAX_AFFECTED_5;
        break;
    default:
        break;
    }

    m_lives = FREEZE_LIVES;
}


void FreezeObj::mapDirectionToAnimation(const sf::Time deltaTime, const sf::Vector2f animationDirection, const sf::Vector2f direction)
{
    if (m_owner == PLAYER)
    {
        m_spellTargetArea.setOutlineColor(sf::Color(112, 212, 176, 255));
    }
    else
    {
        m_spellTargetArea.setOutlineColor(sf::Color::Red);
    }

    movement(deltaTime, direction);
}


void FreezeObj::movement(const sf::Time deltaTime, sf::Vector2f direction)
{
    if (m_clockTry.getElapsedTime().asSeconds() > m_duration)
    {
        m_finishedFreezingAction = true;
    }
}


bool FreezeObj::getFinishedFreezingAction() const
{
    return m_finishedFreezingAction;
}
