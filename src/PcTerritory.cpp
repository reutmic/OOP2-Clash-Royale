#include "PcTerritory.h"

static auto registerIt = Factory<Unmovable>::instance().registerType(
    ObjectType::PcTerritory,
    [](sf::Vector2f position, const int cardLevel, const int arena, const bool bigTower, const TURN_OWNER turnOwner, const int soundLevel) -> std::unique_ptr<Unmovable>
    {
        return std::make_unique<PcTerritory>(position);
    }
);

PcTerritory::PcTerritory()
{
}