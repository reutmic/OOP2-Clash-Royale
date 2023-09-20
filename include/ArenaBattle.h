#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <typeinfo>
#include <cmath>
#include <string>
#include "CollisionHandling.h"
#include "Player.h"
#include "Movable.h"
#include "Unmovable.h"
#include "TroopObj.h"
#include "SpellObj.h"
#include "Factory.h"
#include "ArchersObj.h"
#include "ValkyrieObj.h"
#include "BattleEndScreen.h"
#include "PcTerritory.h"
#include "PlayerTerritory.h"
#include "Bullet.h"
#include "Pc.h"
#include "Resources.h"


const int ARENAS_BACKGROUNDS = 4;
const int ELIXIR_COUNT = 10;
const int TOWER_TYPE = 11;
const int PC_TERRITORY_TYPE = 12;
const int PLAYER_TERRITORY_TYPE = 13;
const int BULLET_TYPE = 14;
const int TOWERS_AMOUNT = 6;
const sf::Vector2f PC_BULLET_DIR = {0, 1};
const sf::Vector2f PLAYER_BULLET_DIR = {0, -1};
const int PRIORITY_1 = 1; 
const int PRIORITY_2 = 2;
const int PRIORITY_3 = 3;
const int PRIORITY_4 = 4;
const int PRIORITY_5 = 5;
const int BATTLE_TIME = 180;

class ArenaBattle
{
public:
	ArenaBattle(sf::RenderWindow& window, bool& battleMode, Player& player);
	void battleInitializations(sf::RenderWindow& window);
	void playSound();
	void buildBattleBackground(sf::RenderWindow& window);
	void buildDeck(sf::RenderWindow& window);
	void buildTowers(sf::RenderWindow& window);
	void getMouseClick(const sf::Vector2f location, sf::RenderWindow& window);
	void addObjToFactory(const TURN_OWNER turnOwner, auto type, const sf::Vector2f location, const int cardLevel);
	void addUnmovableObjToFactory(const TURN_OWNER turnOwner, auto type, const sf::Vector2f location, const bool bigTower);
	float getDistance(const sf::Vector2f& v1, const sf::Vector2f& v2);
	sf::Vector2f getAnimationDirection(const sf::Vector2f direction);
	void elixirCountManagment();
	void addElixir();
	sf::Vector2f getShortestObjPos(const TURN_OWNER turnOwner, const sf::Vector2f currObjPos, const bool checkUnmovable);
	sf::Vector2f getShortestDirection(const sf::Vector2f currObjPos, const sf::Vector2f targetObjPos);
	void handleCollisions(Object& gameObject);
	void removeObjs();
	bool removeBullet(const TURN_OWNER owner) const;
	void battleEndedHandler();
	void pcAction();
	void pcGenerateCard();
	void pcChooseSmartCard();
	void pcPlaceCard(const int priority, const sf::Vector2f targetPos);
	void pcAlgorithm(const sf::Vector2f target);
	bool pcElixirCountManagment(const int elixirCost);
	void pcAddElixir();
	sf::Vector2f getPcOptimalPos();
	void buildTimer();
	void updateTimer();
	void setDynamic(sf::RenderWindow& window, const int soundLevel);
	void draw(sf::RenderWindow& window);

private:
	Player* m_player;
	Pc m_pc;
	bool* m_battleMode;
	std::vector<sf::Texture> m_arenasBackgrounds;
	std::vector<sf::Sprite> m_arenasBackgroundsSprites;
	sf::RectangleShape m_deckBackground;
	sf::RectangleShape m_elixirCountContainer;
	sf::Texture m_elixir;
	sf::Sprite m_elixirSprite;
	std::vector<sf::RectangleShape> m_elixirCountRects;
	sf::Font m_font;
	sf::Text m_elixirCountText;
	int m_elixirCount;
	int m_clickedIndex;
	std::shared_ptr<Card> m_currCard;
	sf::Clock m_movementClock;
	sf::Clock m_elixirTimer;
	sf::Time m_deltaTime;
	bool m_clickedCard;
	bool m_initialized;
	std::vector<std::unique_ptr<Movable>> m_playerMovable;
	std::vector<std::unique_ptr<Unmovable>> m_playerUnmovable;
	std::vector<std::unique_ptr<Movable>> m_pcMovable;
	std::vector<std::unique_ptr<Unmovable>> m_pcUnmovable;
	std::vector<int> m_indexesToRemove;
	sf::Sound m_sound;
	bool m_battleEnded;
	BattleEndScreen m_battleEndedScreen;
	bool m_enteredEndBattle;
	sf::Sound m_loseSound;
	sf::Sound m_winSound;
	bool m_pcDamagedAreaDisplay[TOWERS_AMOUNT/2];
	bool m_playerDamagedAreaDisplay[TOWERS_AMOUNT/2];
	sf::Sprite m_pcDamagedArea1;
	sf::Sprite m_pcDamagedArea2;
	sf::Sprite m_pcDamagedArea3;
	sf::Sprite m_playerDamagedArea1;
	sf::Sprite m_playerDamagedArea2;
	sf::Sprite m_playerDamagedArea3;
	bool m_pcCreatedBullets;
	bool m_playerCreatedBullets;
	int m_destroyedRegTowersByPc;
	bool m_bigTowerDistroyedByPc;
	int m_destroyedRegTowersByPlayer;
	bool m_bigTowerDistroyedByPlayer;
	int m_winner;
	int m_trophiesToAdd;
	int m_coinsToAdd;
	sf::Clock m_pcElixirTimer;
	int m_pcElixirCount;
	int m_pcChosenCard;
	bool m_pcPlacedCard;
	sf::Clock m_pcWaitTimer;
	sf::Clock m_pcBattleTimer;
	int m_playerTroopCount;
	int m_priority1;
	int m_priority2;
	int m_priority3;
	int m_priority4;
	int m_priority5;
	sf::Vector2f m_lastObjCenterPos;
	bool m_pcManagedToPlaceObj;
	sf::RectangleShape m_battleTimerBackground;
	sf::Text m_timeLeftText;
	sf::Text m_battleTimerText;
	sf::Clock m_battleTimer;
	int m_numOfSeconds;
	sf::Vector2f m_currPcOptimalPos;
	int m_soundLevel;
};