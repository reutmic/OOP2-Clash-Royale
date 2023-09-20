#include "BattlePage.h"
#include "Resources.h"

BattlePage::BattlePage(sf::RenderWindow& window, Player& player, bool& battleMode, sf::Sound& menuSound, bool& initialized, int& soundLevel)
	: m_inSettings(false)
{
	m_player = &player;
	m_soundInitialized = &initialized;
	m_menuSound = &menuSound;
	m_soundLevel = &soundLevel;
	*m_soundLevel = 5;

	buildPlayerBar(window);
	buildArenaSection(window);
	buildBattleBtn(window);

	m_battlePageBattleMode = &battleMode;

	setSettingsSection();
}

void BattlePage::buildPlayerBar(sf::RenderWindow& window)
{
	m_userBig.setSize(sf::Vector2f(60, 60));
	m_userBig.setFillColor(sf::Color(28, 56, 81, 150));
	m_userBig.setOutlineThickness(2);
	m_userBig.setOutlineColor(sf::Color(97, 161, 198, 150));
	m_userBig.setPosition(125, 100);

	m_userSprite.setTexture(Resources::instance().getBattlePageItem(Resources::USER));

	m_userSmall.setSize(sf::Vector2f(40, 40));
	m_userSmall.setFillColor(sf::Color(15, 32, 45, 200));
	m_userSmall.setPosition(m_userBig.getPosition().x + 10, m_userBig.getPosition().y + 10);
	m_userSprite.setPosition(m_userSmall.getPosition().x + 4, m_userSmall.getPosition().y + 4);

	m_userSmallest.setSize(sf::Vector2f(m_userBig.getSize().x - 8, (m_userBig.getSize().y / 2) - 8));
	m_userSmallest.setFillColor(sf::Color(78, 108, 131, 150));
	m_userSmallest.setPosition(m_userBig.getPosition().x + 4, m_userBig.getPosition().y + 4);

	m_usernameBackground.setSize(sf::Vector2f((m_userBig.getSize().x) * 5, 64));
	m_usernameBackground.setFillColor(sf::Color(14, 72, 115, 180));
	m_usernameBackground.setPosition(m_userBig.getPosition().x + m_userBig.getSize().x + 10, 98);

	m_username.setFont(Resources::instance().getFont());
	m_username.setCharacterSize(16);
	m_username.setFillColor(sf::Color::White);
	m_username.setOutlineThickness(2);
	m_username.setOutlineColor(sf::Color(11, 13, 14, 255));
	m_username.setPosition(m_usernameBackground.getPosition().x + 10, m_usernameBackground.getPosition().y + 22);

	m_settingsBig.setSize(sf::Vector2f(60, 60));
	m_settingsBig.setFillColor(sf::Color(28, 56, 81, 150));
	m_settingsBig.setOutlineThickness(2);
	m_settingsBig.setOutlineColor(sf::Color(97, 161, 198, 150));
	m_settingsBig.setPosition(m_usernameBackground.getPosition().x + m_usernameBackground.getSize().x + 10, 100);

	m_settingsSmallest.setSize(sf::Vector2f(m_settingsBig.getSize().x - 8, (m_settingsBig.getSize().y / 2) - 8));
	m_settingsSmallest.setFillColor(sf::Color(78, 108, 131, 150));
	m_settingsSmallest.setPosition(m_settingsBig.getPosition().x + 4, m_settingsBig.getPosition().y + 4);

	m_settingsSprite.setTexture(Resources::instance().getBattlePageItem(Resources::SETTINGS));
	m_settingsSprite.setScale(0.4f, 0.4f);
	m_settingsSprite.setPosition(m_settingsBig.getPosition().x + 9, m_settingsBig.getPosition().y + 8);

	m_usernameAccessorySprite.setTexture(Resources::instance().getBattlePageItem(Resources::USER_ACCESSORY));
	m_usernameAccessorySprite.setScale(0.2f, 0.2f);
	m_usernameAccessorySprite.setPosition(m_settingsBig.getPosition().x - 67, m_settingsBig.getPosition().y + 6);
}

void BattlePage::buildArenaSection(sf::RenderWindow& window)
{
	sf::Sprite sprite1;
	sprite1.setTexture(Resources::instance().getArenaImg(Resources::ARENA1));
	//sprite1.setScale(0.7f, 0.7f);
	//sprite1.setPosition((window.getSize().x / 2) - (sprite1.getGlobalBounds().width / 2), m_usernameBackground.getPosition().y + 150);
	m_arenasSprites.push_back(sprite1);

	sf::Sprite sprite2;
	sprite2.setTexture(Resources::instance().getArenaImg(Resources::ARENA2));
	//sprite1.setScale(0.4f, 0.4f);
	//sprite1.setPosition((window.getSize().x / 2) - (sprite1.getGlobalBounds().width / 2), m_usernameBackground.getPosition().y + 150);
	m_arenasSprites.push_back(sprite2);

	sf::Sprite sprite3;
	sprite3.setTexture(Resources::instance().getArenaImg(Resources::ARENA3));
	m_arenasSprites.push_back(sprite3);

	sf::Sprite sprite4;
	sprite4.setTexture(Resources::instance().getArenaImg(Resources::ARENA4));
	m_arenasSprites.push_back(sprite4);

	for (int i = 0; i < ARENAS; i++)
	{
		m_arenasSprites[i].setScale(0.7f, 0.7f);
		//m_arenasSprites[i].setPosition((window.getSize().x / 2) - (m_arenasSprites[i].getGlobalBounds().width / 2), m_usernameBackground.getPosition().y + 150);
	}

	m_arenasSprites[0].setPosition((window.getSize().x / 2) - (m_arenasSprites[0].getGlobalBounds().width / 2), m_usernameBackground.getPosition().y + 150);	// arena 1
	m_arenasSprites[1].setPosition((window.getSize().x / 2) - (m_arenasSprites[0].getGlobalBounds().width / 2), m_usernameBackground.getPosition().y + 135);	// arena 2
	m_arenasSprites[2].setPosition((window.getSize().x / 2) - (m_arenasSprites[0].getGlobalBounds().width / 2), m_usernameBackground.getPosition().y + 115);	// arena 3
	m_arenasSprites[3].setPosition((window.getSize().x / 2) - (m_arenasSprites[0].getGlobalBounds().width / 2), m_usernameBackground.getPosition().y + 120);	// arena 4


	m_arenaNum.setFont(Resources::instance().getFont());
	m_arenaNum.setCharacterSize(22);
	m_arenaNum.setFillColor(sf::Color(190, 191, 195));
}

void BattlePage::buildBattleBtn(sf::RenderWindow& window)
{
	m_battleBtn1.setSize(sf::Vector2f(window.getSize().x / 3.2, 100));
	m_battleBtn1.setFillColor(sf::Color(32, 32, 32, 230));
	m_battleBtn1.setPosition(m_arenasSprites[0].getPosition().x + 65, m_arenasSprites[0].getPosition().y + m_arenasSprites[0].getGlobalBounds().height + 60);

	m_battleBtn2.setSize(sf::Vector2f(m_battleBtn1.getSize().x - 6, m_battleBtn1.getSize().y - 10));
	m_battleBtn2.setFillColor(sf::Color(175, 105, 4, 230));
	m_battleBtn2.setPosition(m_battleBtn1.getPosition().x + 3, m_battleBtn1.getPosition().y + 3);

	m_battleBtn3.setSize(sf::Vector2f(m_battleBtn2.getSize().x, m_battleBtn2.getSize().y - 10));
	m_battleBtn3.setFillColor(sf::Color(255, 155, 7, 230));
	m_battleBtn3.setPosition(m_battleBtn2.getPosition().x, m_battleBtn2.getPosition().y);

	m_battleBtn4.setSize(sf::Vector2f(m_battleBtn3.getSize().x - 8, m_battleBtn3.getSize().y - 15));
	m_battleBtn4.setFillColor(sf::Color(255, 188, 43, 230));
	m_battleBtn4.setPosition(m_battleBtn3.getPosition().x + 4, m_battleBtn3.getPosition().y + 8);

	m_battleBtn5.setSize(sf::Vector2f(m_battleBtn2.getSize().x, 5));
	m_battleBtn5.setFillColor(sf::Color(244, 232, 137, 100));
	m_battleBtn5.setPosition(m_battleBtn2.getPosition().x, m_battleBtn2.getPosition().y);

	m_battleBtn6.setSize(sf::Vector2f(m_battleBtn4.getSize().x, m_battleBtn4.getSize().y / 2));
	m_battleBtn6.setFillColor(sf::Color(255, 208, 83, 200));
	m_battleBtn6.setPosition(m_battleBtn4.getPosition().x, m_battleBtn4.getPosition().y);

	m_battle.setFont(Resources::instance().getFont());
	m_battle.setString("Battle");
	m_battle.setCharacterSize(22);
	m_battle.setFillColor(sf::Color(255, 255, 204, 240));
	m_battle.setOutlineThickness(2);
	m_battle.setOutlineColor(sf::Color(52, 0, 52, 240));
	m_battle.setPosition(m_battleBtn1.getPosition().x + (m_battleBtn1.getSize().x / 2) - (m_battle.getGlobalBounds().width / 2), m_battleBtn1.getPosition().y + (m_battleBtn1.getSize().y / 2) - (m_battle.getGlobalBounds().height / 2) - 7);
}

void BattlePage::getMouseClick(const sf::Vector2f location, sf::RenderWindow& window)
{
	if (m_battleBtn1.getGlobalBounds().contains(location) && !m_inSettings)
	{
		m_menuSound->stop();
		*m_battlePageBattleMode = true;
		*m_soundInitialized = false;
	}

	else if (m_settingsBig.getGlobalBounds().contains(location))
	{
		m_inSettings = true;
	}

	else if (m_doneBtnBackground.getGlobalBounds().contains(location))
	{
		m_inSettings = false;
	}

	else if (m_turnDown.getGlobalBounds().contains(location))
	{
		if (*m_soundLevel > 0)
		{
			(*m_soundLevel)--;
			m_volumeRects[*m_soundLevel].setFillColor(sf::Color::Transparent);

			m_menuSound->setVolume(20.f * (*m_soundLevel));
		}
	}

	else if (m_turnUp.getGlobalBounds().contains(location))
	{
		if (*m_soundLevel < 5)
		{
			(*m_soundLevel)++;
			m_volumeRects[*m_soundLevel - 1].setFillColor(sf::Color(211, 237, 249));

			m_menuSound->setVolume(20.f * (*m_soundLevel));
		}
	}
}

void BattlePage::setDynamic(sf::RenderWindow& window)
{
	m_username.setString(m_player->getName());
	m_arenaNum.setString("Arena " + std::to_string(m_player->getArena()));
	//m_arenaNum.setString("Arena 4");
	//m_arenaNum.setPosition(m_arenasSprites[m_player->getArena() - 1].getPosition().x + (m_arenasSprites[m_player->getArena() - 1].getGlobalBounds().width / 2) - (m_arenaNum.getGlobalBounds().width / 2), m_arenasSprites[m_player->getArena() - 1].getPosition().y + 263);


	if (m_player->getArena() == 1)
	{
	//	m_arenaNum.setPosition(m_arenasSprites[m_player->getArena() - 1].getPosition().x + (m_arenasSprites[m_player->getArena() - 1].getGlobalBounds().width / 2) - (m_arenaNum.getGlobalBounds().width / 2), m_arenasSprites[m_player->getArena() - 1].getPosition().y + 263);
		m_arenaNum.setPosition(m_arenasSprites[m_player->getArena() - 1].getPosition().x + (m_arenasSprites[m_player->getArena() - 1].getGlobalBounds().width / 2) - (m_arenaNum.getGlobalBounds().width / 2), m_arenasSprites[m_player->getArena() - 1].getPosition().y + 263);
	}
	else if (m_player->getArena() == 2)
	{
		m_arenaNum.setPosition(m_arenasSprites[m_player->getArena() - 1].getPosition().x + (m_arenasSprites[m_player->getArena() - 1].getGlobalBounds().width / 2) - (m_arenaNum.getGlobalBounds().width / 2), m_arenasSprites[m_player->getArena() - 1].getPosition().y + 275);

	}
	else if (m_player->getArena() == 3)
	{
		m_arenaNum.setPosition(m_arenasSprites[m_player->getArena() - 1].getPosition().x + (m_arenasSprites[m_player->getArena() - 1].getGlobalBounds().width / 2) - (m_arenaNum.getGlobalBounds().width / 2), m_arenasSprites[m_player->getArena() - 1].getPosition().y + 318);

	}
	else if (m_player->getArena() == 4)
	{
		m_arenaNum.setPosition(m_arenasSprites[m_player->getArena() - 1].getPosition().x + (m_arenasSprites[m_player->getArena() - 1].getGlobalBounds().width / 2) - (m_arenaNum.getGlobalBounds().width / 2), m_arenasSprites[m_player->getArena() - 1].getPosition().y + 315);

	}

	draw(window);
}

void BattlePage::draw(sf::RenderWindow& window)
{
	window.draw(m_userBig);
	window.draw(m_userSmall);
	window.draw(m_userSmallest);
	window.draw(m_userSprite);
	window.draw(m_usernameBackground);
	window.draw(m_username);
	window.draw(m_usernameAccessorySprite);
	window.draw(m_settingsBig);
	window.draw(m_settingsSmallest);
	window.draw(m_settingsSprite);
	window.draw(m_arenasSprites[m_player->getArena()-1]);
	window.draw(m_arenaNum);
	window.draw(m_battleBtn1);
	window.draw(m_battleBtn2);
	window.draw(m_battleBtn3);
	window.draw(m_battleBtn4);
	window.draw(m_battleBtn5);
	window.draw(m_battleBtn6);
	window.draw(m_battle);


	if (m_inSettings)
	{
		drawSettingsSection(window);
	}
}


void BattlePage::setSettingsSection()
{
	m_settingsScreen.setSize(sf::Vector2f(380, 530));
	m_settingsScreen.setFillColor(sf::Color(108, 172, 236));
	m_settingsScreen.setOutlineColor(sf::Color(64, 86, 141, 255));
	m_settingsScreen.setOutlineThickness(2);
	m_settingsScreen.setPosition(m_userBig.getPosition().x + (m_settingsBig.getSize().x / 2), m_userBig.getPosition().y + (m_userBig.getSize().y / 2));

	m_adjustSound.setFont(Resources::instance().getFont());
	m_adjustSound.setCharacterSize(22);
	m_adjustSound.setFillColor(sf::Color::White);
	m_adjustSound.setOutlineThickness(2);
	m_adjustSound.setOutlineColor(sf::Color(11, 13, 14, 255));
	m_adjustSound.setString("Adjust Sound Volume:");
	m_adjustSound.setPosition(m_settingsScreen.getPosition().x + (m_settingsScreen.getSize().x / 2) - (m_adjustSound.getGlobalBounds().width / 2), m_settingsScreen.getPosition().y + 30);

	m_volumeBackground.setSize(sf::Vector2f(m_adjustSound.getGlobalBounds().width, 50));
	m_volumeBackground.setFillColor(sf::Color(152, 212, 242));
	m_volumeBackground.setOutlineColor(sf::Color(65, 116, 142));
	m_volumeBackground.setOutlineThickness(1);
	m_volumeBackground.setPosition(m_settingsScreen.getPosition().x + (m_settingsScreen.getSize().x / 2) - (m_volumeBackground.getSize().x / 2), m_adjustSound.getPosition().y + m_adjustSound.getGlobalBounds().height + (m_volumeBackground.getSize().y / 2));

	double soundUnitWidth = m_volumeBackground.getSize().x / SOUNDS_RECTS;
	double soundUnitHeight = m_volumeBackground.getSize().y;
	int posX = m_volumeBackground.getPosition().x;

	for (int i = 0; i < SOUNDS_RECTS; i++)
	{
		sf::RectangleShape soundUnit;

		soundUnit.setSize(sf::Vector2f(soundUnitWidth, soundUnitHeight));
		soundUnit.setFillColor(sf::Color(211, 237, 249));
		soundUnit.setOutlineColor(sf::Color(167, 218, 244));
		soundUnit.setOutlineThickness(3);
		soundUnit.setPosition(posX, m_volumeBackground.getPosition().y);

		posX += soundUnit.getSize().x;

		m_volumeRects.push_back(soundUnit);
	}

	m_turnUp.setTexture(Resources::instance().getCardsPageItem(Resources::ADD));
	m_turnUp.setScale(0.9f, 0.9f);
	m_turnUp.setPosition(m_volumeBackground.getPosition().x + m_volumeBackground.getSize().x - m_turnUp.getGlobalBounds().width, m_volumeBackground.getPosition().y + m_volumeBackground.getSize().y + ((m_turnUp.getGlobalBounds().height) / 2));

	m_turnDown.setTexture(Resources::instance().getCardsPageItem(Resources::REMOVE));
	m_turnDown.setScale(0.9f, 0.9f);
	m_turnDown.setPosition(m_volumeBackground.getPosition().x, m_volumeBackground.getPosition().y + m_volumeBackground.getSize().y + ((m_turnDown.getGlobalBounds().height) / 2));
	
	sf::Sprite mute(Resources::instance().getSoundLevelImg(Resources::MUTE));
	sf::Sprite sound1(Resources::instance().getSoundLevelImg(Resources::SOUND_LEVEL_1));
	sf::Sprite sound2(Resources::instance().getSoundLevelImg(Resources::SOUND_LEVEL_2));
	sf::Sprite sound3(Resources::instance().getSoundLevelImg(Resources::SOUND_LEVEL_3));
	m_soundLevels.push_back(mute);
	m_soundLevels.push_back(sound1);
	m_soundLevels.push_back(sound2);
	m_soundLevels.push_back(sound3);

	for (auto& sound : m_soundLevels)
	{
		sound.setScale(0.7f, 0.7f);
		sound.setPosition(m_volumeBackground.getPosition().x + (m_volumeBackground.getSize().x / 2) - (sound.getGlobalBounds().width / 2), m_turnDown.getPosition().y + m_turnDown.getGlobalBounds().height + 20);
	}

	m_doneBtnBackground.setSize(sf::Vector2f(150, 70));
	m_doneBtnBackground.setFillColor(sf::Color(108, 236, 193));
	m_doneBtnBackground.setOutlineColor(sf::Color(97, 212, 174));
	m_doneBtnBackground.setOutlineThickness(7);
	m_doneBtnBackground.setPosition(m_soundLevels[0].getPosition().x + (m_soundLevels[0].getGlobalBounds().width / 2) - (m_doneBtnBackground.getSize().x / 2), m_soundLevels[0].getPosition().y + (m_soundLevels[0].getGlobalBounds().height) + (4 * m_doneBtnBackground.getSize().y / 5));

	m_doneBtn.setFont(Resources::instance().getFont());
	m_doneBtn.setCharacterSize(30);
	m_doneBtn.setFillColor(sf::Color::White);
	m_doneBtn.setOutlineThickness(2);
	m_doneBtn.setOutlineColor(sf::Color(11, 13, 14, 255));
	m_doneBtn.setString("Done");
	m_doneBtn.setPosition(m_doneBtnBackground.getPosition().x + (m_doneBtnBackground.getSize().x / 2) - (m_doneBtn.getGlobalBounds().width / 2), m_doneBtnBackground.getPosition().y + (m_doneBtnBackground.getSize().y / 2) - (m_doneBtn.getGlobalBounds().height / 2));
}


void BattlePage::drawSettingsSection(sf::RenderWindow& window)
{
	window.draw(m_settingsScreen);
	window.draw(m_adjustSound);
	window.draw(m_volumeBackground);
	window.draw(m_turnDown);
	window.draw(m_turnUp);

	switch (*m_soundLevel)
	{
	case 0:
		window.draw(m_soundLevels[0]);
		break;
	case 1:
		window.draw(m_soundLevels[1]);
		break;
	case 2:
		window.draw(m_soundLevels[2]);
		break;
	case 3:
		window.draw(m_soundLevels[2]);
		break;
	case 4:
		window.draw(m_soundLevels[2]);
		break;
	case 5:
		window.draw(m_soundLevels[3]);
		break;
	}

	for (auto soundUnit : m_volumeRects)
	{
		window.draw(soundUnit);
	}

	window.draw(m_doneBtnBackground);
	window.draw(m_doneBtn);

}