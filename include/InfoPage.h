#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "View.h"
#include "Resources.h"

const int INFO_TEXTS = 4;

class InfoPage : public View
{
public:
    InfoPage(sf::RenderWindow& window);
    void setDynamic(sf::RenderWindow& window) override;
    void getMouseClick(const sf::Vector2f location, sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::Text m_headLine;
    sf::Text m_subHeadLine1;
    sf::Text m_subHeadLine2;
    std::vector<sf::Text> m_infoTexts;
    sf::Text m_infoText1;
    sf::Text m_infoText2;
    sf::Text m_infoText3;
    sf::Text m_infoText4;
    sf::Sprite m_rightArrow;
    sf::Sprite m_leftArrow;

    int m_textCounter;
};
