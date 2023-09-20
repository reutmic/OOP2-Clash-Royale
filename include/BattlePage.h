#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "View.h"

const int ARENAS = 4;
const int SOUNDS_RECTS = 5;

class BattlePage : public View
{
public:
    BattlePage(sf::RenderWindow& window, Player& player, bool& battleMode, sf::Sound& menuSound, bool& initialized, int& soundLevel);
    void buildPlayerBar(sf::RenderWindow& window);
    void buildArenaSection(sf::RenderWindow& window);
    void buildBattleBtn(sf::RenderWindow& window);
    void setDynamic(sf::RenderWindow& window) override;
    void getMouseClick(const sf::Vector2f location, sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
    void setSettingsSection();
    void drawSettingsSection(sf::RenderWindow& window);

private:
    Player* m_player;
    sf::RectangleShape m_userBig;
    sf::RectangleShape m_userSmall;
    sf::RectangleShape m_userSmallest;
    sf::Texture m_user;
    sf::Sprite m_userSprite;
    sf::RectangleShape m_usernameBackground;
    sf::Text m_username;
    sf::Texture m_usernameAccessory;
    sf::Sprite m_usernameAccessorySprite;
    sf::RectangleShape m_settingsBig;
    sf::RectangleShape m_settingsSmallest;
    sf::Texture m_settings;
    sf::Sprite m_settingsSprite;
    std::vector<sf::Texture> m_arenas;
    std::vector<sf::Sprite> m_arenasSprites;
    sf::Text m_arenaNum;
    sf::RectangleShape m_battleBtn1;
    sf::RectangleShape m_battleBtn2;
    sf::RectangleShape m_battleBtn3;
    sf::RectangleShape m_battleBtn4;
    sf::RectangleShape m_battleBtn5;
    sf::RectangleShape m_battleBtn6;
    sf::Text m_battle;
    bool* m_battlePageBattleMode;
    bool* m_soundInitialized;
    sf::Sound* m_menuSound;
    sf::RectangleShape m_settingsScreen;
    std::vector<sf::RectangleShape> m_volumeRects;
    sf::RectangleShape m_volumeBackground;
    sf::Text m_adjustSound;
    sf::Text m_doneBtn;
    sf::RectangleShape m_doneBtnBackground;
    sf::Sprite m_turnUp;
    sf::Sprite m_turnDown;
    std::vector<sf::Sprite> m_soundLevels;
    int* m_soundLevel;
    bool m_inSettings;
};
