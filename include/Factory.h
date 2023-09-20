#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include "Object.h"

// ----- This is a Factory class for creating the game objects ----- //

enum class ObjectType
{
    Knight = 1,
    Archers = 2,
    Minions = 3,
    Arrows = 4,
    Fireball = 5,
    Giant = 6,
    Valkyrie = 7,
    DartGoblin = 8,
    Freeze = 9,
    Pekka = 10,
    Tower = 11,
    PcTerritory = 12,
    PlayerTerritory = 13,
    Bullet = 14
};

template <typename T>
class Factory
{
public:
    static Factory& instance()
    {
        static auto instance = Factory();
        return instance;
    }

    using FuncType = std::unique_ptr<T>(*)(sf::Vector2f position, const int cardLevel, const int arena, const bool bigTower, const TURN_OWNER turnOwner, const int soundLevel);

    bool registerType(ObjectType t, FuncType f)
    {
        m_map.emplace(t, f);
        return true;
    }

    std::unique_ptr<T> create(ObjectType t, sf::Vector2f position, const int cardLevel, const int arena, const bool bigTower, const TURN_OWNER turnOwner, const int soundLevel) const
    {
        if (!m_map.contains(t))
        {
            return nullptr;
        }
        return m_map.at(t)(position, cardLevel, arena, bigTower, turnOwner, soundLevel);
    }

private:
    Factory() = default;
    Factory(const Factory&) = delete;
    void operator=(const Factory&) = delete;

    std::unordered_map<ObjectType, FuncType> m_map;
};
