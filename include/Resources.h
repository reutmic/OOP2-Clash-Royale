#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>

const int COMMON_IMGS = 5;
const int MENU_FRAME = 6;
const int BATTLE_PAGE = 3;
const int INFO_PAGE = 2;
const int ARENA_IMGS = 4;
const int CARDS_PAGE = 3;
const int CARDS_IMAGES = 10;
const int BATTLE_BACKGROUNDS = 4;
const int SPRITE_SHEETS = 11;
const int SOUNDS = 28;
const int END_BATTLE_SCREEN = 2;
const int SOUND_LEVELS = 4;

class Resources
{
public:
	enum CommonImg {
		COIN,
		ELIXIR,
		LIFE_BAR_CROWN,
		DAMAGED_AREA,
		BULLET
	};

	enum MenuFrame {
		BACKGROUND,
		HEART,
		TROPHIES,
		COLLECTION,
		BATTLE,
		INSTRUCTIONS
	};

	enum BattlePage {
		USER,
		USER_ACCESSORY,
		SETTINGS
	};

	enum InfoPage {
		RIGHT_ARROW,
		LEFT_ARROW
	};

	enum ArenaImg {
		ARENA1,
		ARENA2,
		ARENA3,
		ARENA4
	};

	enum CardsPage
	{
		UPGRADE,
		ADD,
		REMOVE
	};

	enum Card {
		KNIGHT,
		ARCHERS,
		MINIONS,
		ARROWS,
		FIREBALL,
		GIANT,
		VALKYRIE,
		DART_GOBLIN,
		FREEZE,
		PEKKA
	};

	enum BattleBackground {
		ARENA1_BACKGROUND,
		ARENA2_BACKGROUND,
		ARENA3_BACKGROUND,
		ARENA4_BACKGROUND
	};

	enum SpriteSheet {
		KNIGHT_SP,
		ARCHERS_SP,
		MINIONS_SP,
		ARROWS_SP,
		SMOKE_SP,
		FIREBALL_SP,
		EXPLOSION_SP,
		GIANT_SP,
		VALKYRIE_SP,
		DART_GOBLIN_SP,
		PEKKA_SP
	};

	enum Sound {
		MENU,
		BATTLE1,
		BATTLE2,
		BATTLE3,
		UPGRADE_CARD,
		ARCHERS_WALK,
		ARCHERS_HIT,
		ARROWS_HIT,
		DART_GOBLIN_HIT,
		FIREBALL_DISPATCH,
		FIREBALL_HIT,
		FREEZE_SOUND,
		GIANT_HIT,
		KNIGHT_WALK,
		KNIGHT_HIT,
		MINIONS_WALK,
		MINIONS_HIT,
		PEKKA_HIT,
		VALKYRIE_HIT,
		ARCHERS_DEPLOY_SOUND,
		KNIGHT_DEPLOY_SOUND,
		GIANT_DEPLOY_SOUND,
		MINIONS_DEPLOY_SOUND,
		VALKYRIE_DEPLOY_SOUND,
		PEKKA_DEPLOY_SOUND,
		DART_GOBLIN_DEPLOY_SOUND,
		LOSE_BATTLE,
		WIN_BATTLE
	};

	enum EndBattleScreen {
		RED_CROWN,
		BLUE_CROWN
	};

	enum SoundLevels {
		MUTE,
		SOUND_LEVEL_1,
		SOUND_LEVEL_2,
		SOUND_LEVEL_3
	};

	static Resources& instance();

	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;

	void loadFromFile();

	sf::Texture& getCommonImg(const CommonImg i);
	sf::Texture& getMenuFrameItem(const MenuFrame i);
	sf::Texture& getBattlePageItem(const BattlePage i);
	sf::Texture& getArenaImg(const ArenaImg i);
	sf::Texture& getCardsPageItem(const CardsPage i);
	sf::Texture& getCard(const Card i);
	sf::Texture& getEndBattleScreenItem(const EndBattleScreen i);
	sf::Texture& getInfoPageItem(const InfoPage i);
	sf::Texture& getBattleBackground(const BattleBackground i);
	sf::Texture& getSpriteSheet(const SpriteSheet i);
	sf::Texture& getSoundLevelImg(const SoundLevels i);
	sf::Font& getFont();
	sf::SoundBuffer& getSound(Sound);

private:
	Resources();

	sf::Font m_font;

	sf::Texture m_commonImgsTextures[COMMON_IMGS];
	sf::Texture m_menuFrameTextures[MENU_FRAME];
	sf::Texture m_battlePageTextures[BATTLE_PAGE];
	sf::Texture m_arenaImgsTextures[ARENA_IMGS];
	sf::Texture m_cardsPageTextures[CARDS_PAGE];
	sf::Texture m_cardsTextures[CARDS_IMAGES];
	sf::Texture m_infoPageTextures[INFO_PAGE];
	sf::Texture m_battleBackgroundsTextures[BATTLE_BACKGROUNDS];
	sf::Texture m_spriteSheetsTextures[SPRITE_SHEETS];
	sf::Texture m_endBattleScreenTextures[END_BATTLE_SCREEN];
	sf::Texture m_soundLevelsTextures[SOUND_LEVELS];

	std::string m_commonImgsFiles[COMMON_IMGS] = { "coin.png", "elixirCost.png", "life_bar_crown.png", "damaged_area.png", "bullet.png" };
	std::string m_menuFrameFiles[MENU_FRAME] = { "mainBackground.png", "heart.png", "trophy.png","navBarCards.png","navBarBattle.png","navBarInfo.png" };
	std::string m_battlePageFiles[BATTLE_PAGE] = { "user.png", "usernameAccessory.png", "settings.png" };
	std::string m_arenaImgsFiles[ARENA_IMGS] = { "arena1.png", "arena2.png", "arena3.png", "arena4.png" };
	std::string m_cardsPageFiles[CARDS_PAGE] = { "upgradeCard.png", "addCard.png", "removeCard.png" };
	std::string m_cardsFiles[CARDS_IMAGES] = { "knight.png", "archers.png", "minions.png", "arrows.png", "fireball.png", "giant.png", "valkyrie.png", "dart-goblin.png", "freeze.png", "pekka.png" };
	std::string m_battleBackgroundsFiles[BATTLE_BACKGROUNDS] = { "arena1Background.png", "arena2Background.png", "arena3Background.png", "arena4Background.png" };
	std::string m_spriteSheetsFiles[SPRITE_SHEETS] = { "knight_spritesheet.png", "archers_spritesheet.png", "minions_spritesheet.png", "arrows_spritesheet.png", "smoke_spritesheet.png", "fireball_spritesheet.png", "explosion_spritesheet.png", "giant_spritesheet.png", "valkyrie_spritesheet.png", "dartGoblin_spritesheet.png", "pekka_spritesheet.png" };
	std::string m_endBattleScreenFiles[END_BATTLE_SCREEN] = { "red-crown.png", "blue-crown.png", };
	std::string m_infoPageFiles[INFO_PAGE] = { "right-arrow.png", "left-arrow.png", };
	std::string m_soundLevelsFiles[SOUND_LEVELS] = { "mute.png", "sound1.png", "sound2.png", "sound3.png" };

	sf::SoundBuffer m_sounds[SOUNDS];
	std::string m_soundFiles[SOUNDS] = { "Menu_sound.ogg", "Battle1_sound.ogg", "Battle2_sound.ogg", "Battle3_sound.ogg", "upgrade_card_sound.ogg",
										 "archers_walk_sound.ogg", "archers_hit_sound.ogg", "arrow_hit_sound.ogg", "dartgoblin_hit_sound.ogg", "fireball_sound.ogg", "fireball_hit_sound.ogg", "freeze_sound.ogg", "giant_hit_sound.ogg", "knight_walk_sound.ogg", "knight_hit_sound.ogg", "minions_walk_sound.ogg", "minions_hit_sound.ogg", "pekka_hit_sound.ogg", "valkyrie_hit_sound.ogg",
										 "archers_deploy_sound.ogg", "knight_deploy_sound.ogg", "giant_deploy_sound.ogg", "minions_deploy_sound.ogg", "valkyrie_deploy_sound.ogg", "pekka_deploy_sound.ogg", "dartgoblin_deploy_sound.ogg",
										 "lose_battle_sound.ogg", "win_battle_sound.ogg" };
};