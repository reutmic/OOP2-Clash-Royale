#include "PlayerTerritory.h"

static auto registerIt = Factory<Unmovable>::instance().registerType(
    ObjectType::PlayerTerritory,
    [](sf::Vector2f position, const int cardLevel, const int arena, const bool bigTower, const TURN_OWNER turnOwner, const int soundLevel) -> std::unique_ptr<Unmovable>
    {
        return std::make_unique<PlayerTerritory>(position);
    }
);

PlayerTerritory::PlayerTerritory()
{
}