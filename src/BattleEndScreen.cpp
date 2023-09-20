#include "BattleEndScreen.h"

BattleEndScreen::BattleEndScreen(sf::RenderWindow& window)
	:m_blueCrown1Display(false),
	m_blueCrown2Display(false),
	m_blueCrown3Display(false),
	m_redCrown1Display(false),
	m_redCrown2Display(false),
	m_redCrown3Display(false)
{
	// sets the screen at the end of a battle:
	loadFromFiles();
	setPcAndPlayerState(window);
	setTrophiesAndCoins(window);
	setFinishedAllArenas(window);
	setGameOver(window);
	setOkBtn(window);
}

void BattleEndScreen::loadFromFiles()
{
	m_blueCrown1.setTexture(Resources::instance().getEndBattleScreenItem(Resources::BLUE_CROWN));
	m_blueCrown2.setTexture(Resources::instance().getEndBattleScreenItem(Resources::BLUE_CROWN));
	m_blueCrown3.setTexture(Resources::instance().getEndBattleScreenItem(Resources::BLUE_CROWN));

	m_redCrown1.setTexture(Resources::instance().getEndBattleScreenItem(Resources::RED_CROWN));
	m_redCrown2.setTexture(Resources::instance().getEndBattleScreenItem(Resources::RED_CROWN));
	m_redCrown3.setTexture(Resources::instance().getEndBattleScreenItem(Resources::RED_CROWN));

	m_trophiesIcon.setTexture(Resources::instance().getMenuFrameItem(Resources::TROPHIES));
	m_coinsIcon.setTexture(Resources::instance().getCommonImg(Resources::COIN));

	m_winner.setFont(Resources::instance().getFont());
	m_pcName.setFont(Resources::instance().getFont());
	m_playerName.setFont(Resources::instance().getFont());
	m_okBtn.setFont(Resources::instance().getFont());
	m_trophies.setFont(Resources::instance().getFont());
	m_coins.setFont(Resources::instance().getFont());
	m_vs.setFont(Resources::instance().getFont());
	m_finishedAllArenasText1.setFont(Resources::instance().getFont());
	m_finishedAllArenasText2.setFont(Resources::instance().getFont());
	m_gameOverText1.setFont(Resources::instance().getFont());
	m_gameOverText2.setFont(Resources::instance().getFont());
}


void BattleEndScreen::setPcAndPlayerState(sf::RenderWindow& window)
{
	m_background.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	m_background.setPosition(0, 0);
	m_background.setFillColor(sf::Color(0, 0, 0, 150));

	m_pcRibbon.setSize(sf::Vector2f(400, 80));
	m_pcRibbon.setFillColor(sf::Color(213, 18, 93));
	m_pcRibbon.setOutlineThickness(4);
	m_pcRibbon.setOutlineColor(sf::Color(81, 14, 35));
	m_pcRibbon.setPosition((window.getSize().x / 2) - (m_pcRibbon.getGlobalBounds().width / 2), 170);

	m_playerRibbon.setSize(sf::Vector2f(400, 80));
	m_playerRibbon.setFillColor(sf::Color(20, 119, 254));
	m_playerRibbon.setOutlineThickness(4);
	m_playerRibbon.setOutlineColor(sf::Color(21, 46, 86));
	m_playerRibbon.setPosition((window.getSize().x / 2) - (m_pcRibbon.getGlobalBounds().width / 2), 520);

	m_pcName.setString("CPU");
	m_pcName.setCharacterSize(22);
	m_pcName.setFillColor(sf::Color::White);
	m_pcName.setOutlineColor(sf::Color(22, 16, 69));
	m_pcName.setOutlineThickness(3);
	m_pcName.setPosition(m_pcRibbon.getPosition().x + (m_pcRibbon.getSize().x / 2) - (m_pcName.getGlobalBounds().width / 2), m_pcRibbon.getPosition().y + (m_pcRibbon.getSize().y / 2) - (m_pcName.getGlobalBounds().height / 2) + 10);

	m_playerName.setString("PLAYER");
	m_playerName.setCharacterSize(22);
	m_playerName.setFillColor(sf::Color::White);
	m_playerName.setOutlineColor(sf::Color(22, 16, 69));
	m_playerName.setOutlineThickness(3);
	m_playerName.setPosition(m_playerRibbon.getPosition().x + (m_playerRibbon.getSize().x / 2) - (m_playerName.getGlobalBounds().width / 2), m_playerRibbon.getPosition().y + (m_playerRibbon.getSize().y / 2) - (m_playerName.getGlobalBounds().height / 2) + 10);

	m_redCrown1.setScale(0.9f, 0.9f);
	m_redCrown1.setPosition(m_pcRibbon.getPosition().x + 10, m_pcRibbon.getPosition().y - m_redCrown1.getGlobalBounds().height + 10);
	m_redCrown2.setScale(0.9f, 0.9f);
	m_redCrown2.setPosition(m_pcRibbon.getPosition().x + (m_pcRibbon.getSize().x / 2) - (m_redCrown2.getGlobalBounds().width / 2), m_pcRibbon.getPosition().y - m_redCrown2.getGlobalBounds().height + 10);
	m_redCrown3.setScale(0.9f, 0.9f);
	m_redCrown3.setPosition(m_pcRibbon.getPosition().x + m_pcRibbon.getSize().x - m_redCrown3.getGlobalBounds().width - 10, m_pcRibbon.getPosition().y - m_redCrown3.getGlobalBounds().height + 10);

	m_blueCrown1.setScale(0.9f, 0.9f);
	m_blueCrown1.setPosition(m_playerRibbon.getPosition().x + 10, m_playerRibbon.getPosition().y - m_blueCrown1.getGlobalBounds().height + 10);
	m_blueCrown2.setScale(0.9f, 0.9f);
	m_blueCrown2.setPosition(m_playerRibbon.getPosition().x + (m_playerRibbon.getSize().x / 2) - (m_blueCrown2.getGlobalBounds().width / 2), m_playerRibbon.getPosition().y - m_blueCrown2.getGlobalBounds().height + 10);
	m_blueCrown3.setScale(0.9f, 0.9f);
	m_blueCrown3.setPosition(m_playerRibbon.getPosition().x + m_playerRibbon.getSize().x - m_blueCrown3.getGlobalBounds().width - 10, m_playerRibbon.getPosition().y - m_blueCrown3.getGlobalBounds().height + 10);

	m_vs.setString("VS");
	m_vs.setCharacterSize(36);
	m_vs.setFillColor(sf::Color(253, 255, 155));
	m_vs.setOutlineColor(sf::Color(0, 2, 3));
	m_vs.setOutlineThickness(3);
	m_vs.setPosition(m_pcRibbon.getPosition().x + (m_pcRibbon.getSize().x / 2) - (m_vs.getGlobalBounds().width / 2), 345);

	m_winner.setString("WINNER!");
	m_winner.setCharacterSize(36);
	m_winner.setFillColor(sf::Color::White);
	m_winner.setOutlineColor(sf::Color(4, 38, 118));
	m_winner.setOutlineThickness(3);
}


void BattleEndScreen::setTrophiesAndCoins(sf::RenderWindow& window)
{
	m_trophiesRect.setSize(sf::Vector2f(100, 30));
	m_trophiesRect.setFillColor(sf::Color(29, 35, 72));
	m_trophiesRect.setOutlineThickness(3);
	m_trophiesRect.setOutlineColor(sf::Color(0, 4, 15));
	m_trophiesRect.setPosition((window.getSize().x / 2) - (m_trophiesRect.getSize().x / 2), m_playerName.getPosition().y + 80);

	m_trophiesIcon.setScale(0.32f, 0.32f);
	m_trophiesIcon.setPosition(m_trophiesRect.getPosition().x - 17, m_trophiesRect.getPosition().y - 7);

	m_trophies.setCharacterSize(14);
	m_trophies.setFillColor(sf::Color::White);
	m_trophies.setOutlineColor(sf::Color::Black);
	m_trophies.setOutlineThickness(3);

	m_coinsRect.setSize(sf::Vector2f(100, 30));
	m_coinsRect.setFillColor(sf::Color(29, 35, 72));
	m_coinsRect.setOutlineThickness(3);
	m_coinsRect.setOutlineColor(sf::Color(0, 4, 15));
	m_coinsRect.setPosition((window.getSize().x / 2) - (m_trophiesRect.getSize().x / 2), m_trophiesRect.getPosition().y + 60);

	m_coinsIcon.setScale(0.5f, 0.5f);
	m_coinsIcon.setPosition(m_coinsRect.getPosition().x - 15, m_coinsRect.getPosition().y - 4);

	m_coins.setCharacterSize(14);
	m_coins.setFillColor(sf::Color::White);
	m_coins.setOutlineColor(sf::Color::Black);
	m_coins.setOutlineThickness(3);
}

// This function sets the ending game window when the player wins the last arena of the game:
void BattleEndScreen::setFinishedAllArenas(sf::RenderWindow& window)
{
	m_finishedAllArenasText1.setString("Well done! you have won in all arenas!");
	m_finishedAllArenasText1.setCharacterSize(20);
	m_finishedAllArenasText1.setFillColor(sf::Color::White);
	m_finishedAllArenasText1.setOutlineThickness(2);
	m_finishedAllArenasText1.setOutlineColor(sf::Color::Black);
	m_finishedAllArenasText1.setPosition((window.getSize().x / 2) - (m_finishedAllArenasText1.getGlobalBounds().width / 2), m_playerName.getPosition().y + 100);
	m_finishedAllArenasText2.setString("Press ok to exit the game");
	m_finishedAllArenasText2.setCharacterSize(20);
	m_finishedAllArenasText2.setFillColor(sf::Color::White);
	m_finishedAllArenasText2.setOutlineThickness(2);
	m_finishedAllArenasText2.setOutlineColor(sf::Color::Black);
	m_finishedAllArenasText2.setPosition(m_finishedAllArenasText1.getPosition().x + (m_finishedAllArenasText1.getGlobalBounds().width / 2) - (m_finishedAllArenasText2.getGlobalBounds().width / 2), m_finishedAllArenasText1.getPosition().y + 30);
}

// This function sets the 'game over' window when the player loses all his 'lives' (hearts) when loosing to the PC:
void BattleEndScreen::setGameOver(sf::RenderWindow& window)
{
	m_gameOverText1.setString("Game over :(");
	m_gameOverText1.setCharacterSize(20);
	m_gameOverText1.setFillColor(sf::Color::White);
	m_gameOverText1.setOutlineThickness(2);
	m_gameOverText1.setOutlineColor(sf::Color::Black);
	m_gameOverText1.setPosition((window.getSize().x / 2) - (m_gameOverText1.getGlobalBounds().width / 2), m_playerName.getPosition().y + 100);
	m_gameOverText2.setString("Press ok to exit the game");
	m_gameOverText2.setCharacterSize(20);
	m_gameOverText2.setFillColor(sf::Color::White);
	m_gameOverText2.setOutlineThickness(2);
	m_gameOverText2.setOutlineColor(sf::Color::Black);
	m_gameOverText2.setPosition(m_gameOverText1.getPosition().x + (m_gameOverText1.getGlobalBounds().width / 2) - (m_gameOverText2.getGlobalBounds().width / 2), m_gameOverText1.getPosition().y + 30);
}


void BattleEndScreen::setOkBtn(sf::RenderWindow& window)
{
	m_okBtnRect1.setSize(sf::Vector2f(window.getSize().x / 4.5, 70));
	m_okBtnRect1.setFillColor(sf::Color(12, 38, 88, 230));
	m_okBtnRect1.setPosition((window.getSize().x / 2) - (m_okBtnRect1.getSize().x / 2), m_coinsRect.getPosition().y + 90);

	m_okBtnRect2.setSize(sf::Vector2f(m_okBtnRect1.getSize().x - 6, m_okBtnRect1.getSize().y - 10));
	m_okBtnRect2.setFillColor(sf::Color(22, 77, 143, 230));
	m_okBtnRect2.setPosition(m_okBtnRect1.getPosition().x + 3, m_okBtnRect1.getPosition().y + 3);

	m_okBtnRect3.setSize(sf::Vector2f(m_okBtnRect2.getSize().x, m_okBtnRect2.getSize().y - 10));
	m_okBtnRect3.setFillColor(sf::Color(33, 133, 242, 230));
	m_okBtnRect3.setPosition(m_okBtnRect2.getPosition().x, m_okBtnRect2.getPosition().y);

	m_okBtnRect4.setSize(sf::Vector2f(m_okBtnRect3.getSize().x - 8, m_okBtnRect3.getSize().y - 15));
	m_okBtnRect4.setFillColor(sf::Color(77, 175, 255, 230));
	m_okBtnRect4.setPosition(m_okBtnRect3.getPosition().x + 4, m_okBtnRect3.getPosition().y + 8);

	m_okBtnRect5.setSize(sf::Vector2f(m_okBtnRect2.getSize().x, 5));
	m_okBtnRect5.setFillColor(sf::Color(103, 186, 254, 100));
	m_okBtnRect5.setPosition(m_okBtnRect2.getPosition().x, m_okBtnRect2.getPosition().y);

	m_okBtn.setFont(Resources::instance().getFont());
	m_okBtn.setString("OK");
	m_okBtn.setCharacterSize(20);
	m_okBtn.setFillColor(sf::Color::White);
	m_okBtn.setOutlineThickness(2);
	m_okBtn.setOutlineColor(sf::Color::Black);
	m_okBtn.setPosition(m_okBtnRect1.getPosition().x + (m_okBtnRect1.getSize().x / 2) - (m_okBtn.getGlobalBounds().width / 2), m_okBtnRect1.getPosition().y + (m_okBtnRect1.getSize().y / 2) - (m_okBtn.getGlobalBounds().height / 2) - 7);
}


bool BattleEndScreen::getMouseClick(const sf::Vector2f location)
{
	if (m_okBtnRect1.getGlobalBounds().contains(location))
	{
		return true;
	}

	return false;
}

// This function sets the winner's details on the battle ending screen when the battle is over:
void BattleEndScreen::setRealData(const int pcCrowns, const int playerCrowns, const int winner, const int trophies, const int coins, const int arena, const int lives)
{
	m_arena = arena;
	m_theWinner = winner;
	m_lives = lives;

	switch (pcCrowns)
	{
	case 1:
		m_redCrown1Display = true;
		break;
	case 2:
		m_redCrown1Display = true;
		m_redCrown2Display = true;
		break;
	case 3:
		m_redCrown1Display = true;
		m_redCrown2Display = true;
		m_redCrown3Display = true;
		break;
	}

	switch (playerCrowns)
	{
	case 1:
		m_blueCrown1Display = true;
		break;
	case 2:
		m_blueCrown1Display = true;
		m_blueCrown2Display = true;
		break;
	case 3:
		m_blueCrown1Display = true;
		m_blueCrown2Display = true;
		m_blueCrown3Display = true;
		break;
	}

	switch (winner)
	{
	case 0:
		m_winner.setPosition(m_pcRibbon.getPosition().x + (m_pcRibbon.getSize().x / 2) - (m_winner.getGlobalBounds().width / 2), m_pcRibbon.getPosition().y - (m_winner.getGlobalBounds().height / 2));
		break;

	case 1:
		m_winner.setPosition(m_playerRibbon.getPosition().x + (m_playerRibbon.getSize().x / 2) - (m_winner.getGlobalBounds().width / 2), m_playerRibbon.getPosition().y - (m_winner.getGlobalBounds().height / 2));
		break;
	}

	m_trophies.setString(std::to_string(trophies));
	m_trophies.setPosition(m_trophiesRect.getPosition().x + (m_trophiesRect.getSize().x / 2) - (m_trophies.getGlobalBounds().width / 2) + 5, m_trophiesRect.getPosition().y + (m_trophiesRect.getSize().y / 2) - (m_trophies.getGlobalBounds().height / 2) + 2);

	m_coins.setString(std::to_string(coins));
	m_coins.setPosition(m_coinsRect.getPosition().x + (m_coinsRect.getSize().x / 2) - (m_coins.getGlobalBounds().width / 2) + 5, m_coinsRect.getPosition().y + (m_coinsRect.getSize().y / 2) - (m_coins.getGlobalBounds().height / 2) + 2);
}


void BattleEndScreen::draw(sf::RenderWindow& window)
{
	window.draw(m_background);
	window.draw(m_pcRibbon);

	if (m_redCrown1Display)
		window.draw(m_redCrown1);
	if (m_redCrown2Display)
		window.draw(m_redCrown2);
	if (m_redCrown3Display)
		window.draw(m_redCrown3);

	window.draw(m_vs);
	window.draw(m_pcName);
	window.draw(m_playerRibbon);

	if (m_blueCrown1Display)
		window.draw(m_blueCrown1);
	if (m_blueCrown2Display)
		window.draw(m_blueCrown2);
	if (m_blueCrown3Display)
		window.draw(m_blueCrown3);

	window.draw(m_playerName);
	window.draw(m_winner);

	if (m_lives == 1 && m_theWinner == 0)
	{
		window.draw(m_gameOverText1);
		window.draw(m_gameOverText2);
	}
	else if (m_arena != ARENA_IMGS)
	{
		window.draw(m_trophiesRect);
		window.draw(m_trophiesIcon);
		window.draw(m_trophies);
		window.draw(m_coinsRect);
		window.draw(m_coinsIcon);
		window.draw(m_coins);
	}
	else if (m_arena == ARENA_IMGS && m_theWinner == 1)
	{
		window.draw(m_finishedAllArenasText1);
		window.draw(m_finishedAllArenasText2);
	}

	window.draw(m_okBtnRect1);
	window.draw(m_okBtnRect2);
	window.draw(m_okBtnRect3);
	window.draw(m_okBtnRect4);
	window.draw(m_okBtnRect5);
	window.draw(m_okBtn);
}