#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Controller.h"
#include "ArenaBattle.h"

const int windowWidth = 675;
const int windowHeight = 900;

class Window
{
public:
    Window();
    void run();

private:
    Player m_player;
    sf::RenderWindow m_window;
    Controller m_controller;
    ArenaBattle m_arenaBattle;
    bool m_battleMode;
    int m_soundLevel;
};
