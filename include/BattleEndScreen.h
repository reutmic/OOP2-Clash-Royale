#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Resources.h"

class BattleEndScreen
{
public:
	BattleEndScreen(sf::RenderWindow& window);
	void loadFromFiles();
	void setPcAndPlayerState(sf::RenderWindow& window);
	void setTrophiesAndCoins(sf::RenderWindow& window);
	void setFinishedAllArenas(sf::RenderWindow& window);
	void setGameOver(sf::RenderWindow& window);
	void setOkBtn(sf::RenderWindow& window);
	bool getMouseClick(const sf::Vector2f location);
	void setRealData(const int pcCrowns, const int playerCrowns, const int winner, const int trophies, const int coins, const int arena, const int lives);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape m_background;
	sf::RectangleShape m_trophiesRect;
	sf::RectangleShape m_coinsRect;
	sf::RectangleShape m_pcRibbon;
	sf::RectangleShape m_playerRibbon;
	sf::Sprite m_blueCrown1;
	sf::Sprite m_blueCrown2;
	sf::Sprite m_blueCrown3;
	sf::Sprite m_redCrown1;
	sf::Sprite m_redCrown2;
	sf::Sprite m_redCrown3;
	bool m_blueCrown1Display;
	bool m_blueCrown2Display;
	bool m_blueCrown3Display;
	bool m_redCrown1Display;
	bool m_redCrown2Display;
	bool m_redCrown3Display;
	sf::Text m_winner;
	sf::Text m_pcName;
	sf::Text m_playerName;
	sf::Text m_okBtn;
	sf::Text m_trophies;
	sf::Text m_coins;
	sf::Text m_vs;
	sf::Sprite m_trophiesIcon;
	sf::Sprite m_coinsIcon;
	sf::RectangleShape m_okBtnRect1;
	sf::RectangleShape m_okBtnRect2;
	sf::RectangleShape m_okBtnRect3;
	sf::RectangleShape m_okBtnRect4;
	sf::RectangleShape m_okBtnRect5;
	sf::RectangleShape m_okBtnRect6;
	sf::Sound m_winSound;
	sf::Sound m_loseSound;
	int m_arena;
	int m_theWinner;
	int m_lives;
	sf::Text m_finishedAllArenasText1;
	sf::Text m_finishedAllArenasText2;
	sf::Text m_gameOverText1;
	sf::Text m_gameOverText2;
};