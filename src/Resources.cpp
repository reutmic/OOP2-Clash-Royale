#include "Resources.h"

Resources::Resources()
{
	loadFromFile();
}


Resources& Resources::instance()
{
	static Resources instance;
	return instance;
}


void Resources::loadFromFile()
{
	m_font.loadFromFile("Supercell-Magic Regular.ttf");

	for (int commonImg = COIN; commonImg <= BULLET; commonImg++)
	{
		m_commonImgsTextures[commonImg].loadFromFile(m_commonImgsFiles[commonImg]);
		m_commonImgsTextures[commonImg].setSmooth(true);
	}

	for (int menuFrameItem = BACKGROUND; menuFrameItem <= INSTRUCTIONS; menuFrameItem++)
	{
		m_menuFrameTextures[menuFrameItem].loadFromFile(m_menuFrameFiles[menuFrameItem]);
		m_menuFrameTextures[menuFrameItem].setSmooth(true);
	}

	for (int battlePageItem = USER; battlePageItem <= SETTINGS; battlePageItem++)
	{
		m_battlePageTextures[battlePageItem].loadFromFile(m_battlePageFiles[battlePageItem]);
		m_battlePageTextures[battlePageItem].setSmooth(true);
	}

	for (int arenaImg = ARENA1; arenaImg <= ARENA4; arenaImg++)
	{
		m_arenaImgsTextures[arenaImg].loadFromFile(m_arenaImgsFiles[arenaImg]);
		m_arenaImgsTextures[arenaImg].setSmooth(true);
	}

	for (int cardsPageItem = UPGRADE; cardsPageItem <= REMOVE; cardsPageItem++)
	{
		m_cardsPageTextures[cardsPageItem].loadFromFile(m_cardsPageFiles[cardsPageItem]);
		m_cardsPageTextures[cardsPageItem].setSmooth(true);
	}

	for (int card = KNIGHT; card <= PEKKA; card++)
	{
		m_cardsTextures[card].loadFromFile(m_cardsFiles[card]);
		m_cardsTextures[card].setSmooth(true);
	}

	for (int battleBackground = ARENA1_BACKGROUND; battleBackground <= ARENA4_BACKGROUND; battleBackground++)
	{
		m_battleBackgroundsTextures[battleBackground].loadFromFile(m_battleBackgroundsFiles[battleBackground]);
		m_battleBackgroundsTextures[battleBackground].setSmooth(true);
	}

	for (int spriteSheet = KNIGHT_SP; spriteSheet <= PEKKA_SP; spriteSheet++)
	{
		m_spriteSheetsTextures[spriteSheet].loadFromFile(m_spriteSheetsFiles[spriteSheet]);
		m_spriteSheetsTextures[spriteSheet].setSmooth(true);
	}

	for (int sound = MENU; sound <= WIN_BATTLE; sound++)
	{
		m_sounds[sound].loadFromFile(m_soundFiles[sound]);
	}

	for (int endBattleItem = RED_CROWN; endBattleItem <= BLUE_CROWN; endBattleItem++)
	{
		m_endBattleScreenTextures[endBattleItem].loadFromFile(m_endBattleScreenFiles[endBattleItem]);
	}

	for (int soundLevel = MUTE; soundLevel <= SOUND_LEVEL_3; soundLevel++)
	{
		m_soundLevelsTextures[soundLevel].loadFromFile(m_soundLevelsFiles[soundLevel]);
		m_soundLevelsTextures[soundLevel].setSmooth(true);
	}

	for (int infoPageItem = RIGHT_ARROW; infoPageItem <= LEFT_ARROW; infoPageItem++)
	{
		m_infoPageTextures[infoPageItem].loadFromFile(m_infoPageFiles[infoPageItem]);
		m_infoPageTextures[infoPageItem].setSmooth(true);
	}
}


sf::Texture& Resources::getCommonImg(const CommonImg i)
{
	return m_commonImgsTextures[i];
}


sf::Texture& Resources::getMenuFrameItem(const MenuFrame i)
{
	return m_menuFrameTextures[i];
}


sf::Texture& Resources::getBattlePageItem(const BattlePage i)
{
	return m_battlePageTextures[i];
}


sf::Texture& Resources::getArenaImg(const ArenaImg i)
{
	return m_arenaImgsTextures[i];
}


sf::Texture& Resources::getCardsPageItem(const CardsPage i)
{
	return m_cardsPageTextures[i];
}


sf::Texture& Resources::getCard(const Card i)
{
	return m_cardsTextures[i];
}


sf::Texture& Resources::getBattleBackground(const BattleBackground i)
{
	return m_battleBackgroundsTextures[i];
}


sf::Font& Resources::getFont()
{
	return m_font;
}


sf::Texture& Resources::getSpriteSheet(const SpriteSheet i)
{
	return m_spriteSheetsTextures[i];
}


sf::SoundBuffer& Resources::getSound(Sound sound)
{
	return m_sounds[sound];
}


sf::Texture& Resources::getEndBattleScreenItem(const EndBattleScreen i)
{
	return m_endBattleScreenTextures[i];
}

sf::Texture& Resources::getSoundLevelImg(const SoundLevels i)
{
	return m_soundLevelsTextures[i];
}

sf::Texture& Resources::getInfoPageItem(const InfoPage i)
{
	return m_infoPageTextures[i];
}