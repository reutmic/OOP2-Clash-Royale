#pragma once
//#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Resources.h"
#include "View.h"
#include "CardsPage.h"
#include "BattlePage.h"
#include "InfoPage.h"

enum Page
{
    CARDS,
    BATTLE,
    INFO
};

class Controller
{
public:
    Controller(sf::RenderWindow& window, bool& battleMode, Player& player, int& soundLevel);
    void playSound();
    void buildNavBar(sf::RenderWindow& window);
    void buildCurrencies(sf::RenderWindow& window);
    void setDynamic(sf::RenderWindow& window);
    void drawFrame(sf::RenderWindow& window);
    void drawCurrPage(sf::RenderWindow& window);
    void resetBattleBtn();
    void resetCardsBtn();
    void resetInfoBtn();
    void getMouseClick(const sf::Vector2f location, sf::RenderWindow& window);

private:
    Player* m_player;
    bool m_cardsPageInitializied;
    bool m_initialized;
    sf::Texture m_background;
    sf::Sprite m_backgroundSprite1;
    sf::Sprite m_backgroundSprite2;
    std::vector<sf::Sprite> m_hearts;
    sf::RectangleShape m_currencies1;
    sf::RectangleShape m_currenciesLighter1;
    sf::RectangleShape m_currencies2;
    sf::RectangleShape m_currenciesLighter2;
    sf::Texture m_coin;
    sf::Sprite m_coinSprite;
    sf::Texture m_trophy;
    sf::Sprite m_trophySprite;
    sf::Text m_coinsNum;
    sf::Text m_trophiesNum;
    sf::RectangleShape m_navBar1;
    sf::RectangleShape m_navBar2;
    sf::RectangleShape m_navBar3;
    sf::RectangleShape m_navBarUpperLine;
    sf::RectangleShape m_navBarVerticalLine1;
    sf::RectangleShape m_navBarVerticalLine2;
    sf::Texture m_navBarBattle;
    sf::Sprite m_navBarBattleSprite;
    sf::Texture m_navBarCards;
    sf::Sprite m_navBarCardsSprite;
    sf::Texture m_navBarInfo;
    sf::Sprite m_navBarInfoSprite;
    sf::Font m_navBarFont;
    sf::Text m_navBarCardsText;
    sf::Text m_navBarBattleText;
    sf::Text m_navBarInfoText;
    Page m_currPage;
    std::vector<std::unique_ptr<View>> m_views;
    sf::Sound m_sound;

};
