#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class View
{
public:
    View() = default;
    virtual ~View() = default;
    virtual void getMouseClick(const sf::Vector2f location, sf::RenderWindow& window) = 0;
    virtual void setDynamic(sf::RenderWindow& window) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};
