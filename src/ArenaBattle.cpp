#include "ArenaBattle.h"

ArenaBattle::ArenaBattle(sf::RenderWindow& window, bool& battleMode, Player& player)
	:m_elixirCount(ELIXIR_COUNT),
	m_player(&player),
	m_clickedIndex(-1),
	m_currCard(nullptr),
	m_clickedCard(false),
	m_initialized(false),
	m_battleEnded(false),
	m_battleEndedScreen(window),
	m_enteredEndBattle(false),
	m_pcCreatedBullets(false),
	m_playerCreatedBullets(false),
	m_destroyedRegTowersByPc(0),
	m_destroyedRegTowersByPlayer(0),
	m_bigTowerDistroyedByPc(false),
	m_bigTowerDistroyedByPlayer(false),
	m_winner(1),
	m_trophiesToAdd(0),
	m_coinsToAdd(0),
	m_pcElixirCount(ELIXIR_COUNT),
	m_pcPlacedCard(false),
	m_playerTroopCount(0),
	m_priority1(-1),
	m_priority2(-1),
	m_priority3(-1),
	m_priority4(-1),
	m_priority5(-1),
	m_pcManagedToPlaceObj(false),
	m_numOfSeconds(BATTLE_TIME)
{
	if (m_player->getArena() == 1 || m_player->getArena() == 4)
		m_sound.setBuffer(Resources::instance().getSound(Resources::BATTLE1));
	else if (m_player->getArena() == 2)
		m_sound.setBuffer(Resources::instance().getSound(Resources::BATTLE2));
	else if (m_player->getArena() == 3)
		m_sound.setBuffer(Resources::instance().getSound(Resources::BATTLE3));

	m_loseSound.setBuffer(Resources::instance().getSound(Resources::LOSE_BATTLE));
	m_winSound.setBuffer(Resources::instance().getSound(Resources::WIN_BATTLE));

	m_pcDamagedArea1.setTexture(Resources::instance().getCommonImg(Resources::DAMAGED_AREA));
	m_pcDamagedArea2.setTexture(Resources::instance().getCommonImg(Resources::DAMAGED_AREA));
	m_pcDamagedArea3.setTexture(Resources::instance().getCommonImg(Resources::DAMAGED_AREA));
	m_playerDamagedArea1.setTexture(Resources::instance().getCommonImg(Resources::DAMAGED_AREA));
	m_playerDamagedArea2.setTexture(Resources::instance().getCommonImg(Resources::DAMAGED_AREA));
	m_playerDamagedArea3.setTexture(Resources::instance().getCommonImg(Resources::DAMAGED_AREA));

	m_pcElixirTimer.restart();
	m_movementClock.restart();
	m_elixirTimer.restart();
	m_pcBattleTimer.restart();
	m_pcWaitTimer.restart();
	m_battleTimer.restart();

	buildBattleBackground(window);
	buildTimer();
	buildDeck(window);

	m_battleMode = &battleMode;
}


void ArenaBattle::playSound()
{
	m_sound.setLoop(true);
	m_sound.play();
}


void ArenaBattle::buildBattleBackground(sf::RenderWindow& window)
{
	sf::Sprite sprite1;
	sprite1.setTexture(Resources::instance().getBattleBackground(Resources::ARENA1_BACKGROUND));
	m_arenasBackgroundsSprites.push_back(sprite1);

	sf::Sprite sprite2;
	sprite2.setTexture(Resources::instance().getBattleBackground(Resources::ARENA2_BACKGROUND));
	m_arenasBackgroundsSprites.push_back(sprite2);

	sf::Sprite sprite3;
	sprite3.setTexture(Resources::instance().getBattleBackground(Resources::ARENA3_BACKGROUND));
	m_arenasBackgroundsSprites.push_back(sprite3);

	sf::Sprite sprite4;
	sprite4.setTexture(Resources::instance().getBattleBackground(Resources::ARENA4_BACKGROUND));
	m_arenasBackgroundsSprites.push_back(sprite4);

	for (int i = 0; i < ARENAS_BACKGROUNDS; i++)
	{
		m_arenasBackgroundsSprites[i].setScale(0.73f, 0.73f);
		m_arenasBackgroundsSprites[i].setPosition(-595, -150);
	}
}


void ArenaBattle::buildDeck(sf::RenderWindow& window)
{
	m_deckBackground.setSize(sf::Vector2f(window.getSize().x - 45, 135));
	m_deckBackground.setFillColor(sf::Color(139, 96, 64, 255));
	m_deckBackground.setOutlineColor(sf::Color(77, 57, 38, 255));
	m_deckBackground.setOutlineThickness(2);
	m_deckBackground.setPosition((window.getSize().x / 2) - (m_deckBackground.getSize().x / 2), window.getSize().y - m_deckBackground.getSize().y);
	m_player->setDeckBackgroundPosition(m_deckBackground.getPosition());

	m_elixirCountContainer.setSize(sf::Vector2f(m_deckBackground.getSize().x - 100, 15));
	m_elixirCountContainer.setFillColor(sf::Color(0, 0, 0, 100));
	m_elixirCountContainer.setOutlineColor(sf::Color(58, 49, 42));
	m_elixirCountContainer.setOutlineThickness(2);
	m_elixirCountContainer.setPosition(m_deckBackground.getPosition().x + (m_deckBackground.getSize().x / 2) - (m_elixirCountContainer.getSize().x / 2) + 8, m_deckBackground.getPosition().y + m_deckBackground.getSize().y - m_elixirCountContainer.getSize().y - 10);

	m_elixirSprite.setTexture(Resources::instance().getCommonImg(Resources::ELIXIR));

	double elixirUnitWidth = m_elixirCountContainer.getSize().x / 10;
	double elixirUnitHeight = m_elixirCountContainer.getSize().y;

	int posX = m_elixirCountContainer.getPosition().x;

	// building the elixir bar
	for (int i = 0; i < ELIXIR_COUNT; i++)
	{
		sf::RectangleShape elixirUnit;

		elixirUnit.setSize(sf::Vector2f(elixirUnitWidth, elixirUnitHeight));
		elixirUnit.setFillColor(sf::Color(206, 33, 209));
		elixirUnit.setOutlineColor(sf::Color(75, 42, 77));
		elixirUnit.setOutlineThickness(2);
		elixirUnit.setPosition(posX, m_elixirCountContainer.getPosition().y);

		posX += elixirUnit.getSize().x;

		m_elixirCountRects.push_back(elixirUnit);
	}

	m_elixirCountText.setFont(Resources::instance().getFont());
	m_elixirCountText.setCharacterSize(16);
	m_elixirCountText.setFillColor(sf::Color::White);
	m_elixirCountText.setOutlineColor(sf::Color::Black);
	m_elixirCountText.setOutlineThickness(1);
}


void ArenaBattle::buildTowers(sf::RenderWindow& window)
{
	std::vector<sf::Vector2f> locations = {
		// pc
		{165, 150},
		{455, 150},
		{305, 65},
		// player
		{165, 550},
		{455, 550},
		{300, 615}
	};

	for (int i = 0; i < TOWERS_AMOUNT; i++)
	{
		auto type = static_cast<ObjectType>(TOWER_TYPE);

		// pc towers
		if (i < 3)
		{
			if (i == 2)
				addUnmovableObjToFactory(PC, type, locations[i], true);
			else
				addUnmovableObjToFactory(PC, type, locations[i], false);

		}
		// players towers
		else
		{
			if (i == 5)
				addUnmovableObjToFactory(PLAYER, type, locations[i], true);
			else
				addUnmovableObjToFactory(PLAYER, type, locations[i], false);
		}
	}

	m_pcDamagedArea1.setScale(0.43f, 0.65f);
	m_pcDamagedArea2.setScale(0.43f, 0.65f);
	m_pcDamagedArea3.setScale(0.43f, 0.65f);

	m_playerDamagedArea1.setScale(0.43f, 0.65f);
	m_playerDamagedArea2.setScale(0.43f, 0.65f);
	m_playerDamagedArea3.setScale(0.43f, 0.65f);

	m_pcDamagedArea1.setPosition(locations[0].x - 80, locations[0].y - 95);
	m_pcDamagedArea2.setPosition(locations[1].x - 80, locations[1].y - 95);
	m_pcDamagedArea3.setPosition(locations[2].x - 80, locations[2].y - 95);

	m_playerDamagedArea1.setPosition(locations[3].x - 80, locations[3].y - 95);
	m_playerDamagedArea2.setPosition(locations[4].x - 80, locations[4].y - 95);
	m_playerDamagedArea3.setPosition(locations[5].x - 80, locations[5].y - 95);
}


// this functions returns the object position with the shortest distance from a given object 
sf::Vector2f ArenaBattle::getShortestObjPos(const TURN_OWNER turnOwner, const sf::Vector2f currObjPos, const bool checkUnmovable)
{
	sf::Vector2f shortestPos;
	float shortestDistance;

	switch (turnOwner)
	{
	case PLAYER:

		shortestDistance = getDistance(currObjPos, m_pcUnmovable[1]->getCenter());
		shortestPos.x = m_pcUnmovable[1]->getCenter().x;
		shortestPos.y = m_pcUnmovable[1]->getCenter().y;

		if (checkUnmovable)
		{
			for (int i = 1; i < m_pcUnmovable.size(); i++)
			{
				float distance = getDistance(currObjPos, m_pcUnmovable[i]->getCenter());
				if (distance < shortestDistance)
				{
					shortestDistance = distance;
					shortestPos.x = m_pcUnmovable[i]->getCenter().x;
					shortestPos.y = m_pcUnmovable[i]->getCenter().y;
				}
			}
		}

		for (auto& obj : m_pcMovable)
		{
			if (obj->getLives() < 10000)
			{
				float distance = getDistance(currObjPos, obj->getCenter());
				if (distance < shortestDistance)
				{
					shortestDistance = distance;
					shortestPos.x = obj->getCenter().x;
					shortestPos.y = obj->getCenter().y;
				}
			}
		}

		break;

	case PC:
		shortestDistance = getDistance(currObjPos, m_playerUnmovable[1]->getCenter());
		shortestPos.x = m_playerUnmovable[1]->getCenter().x;
		shortestPos.y = m_playerUnmovable[1]->getCenter().y;

		if (checkUnmovable)
		{
			for (int i = 1; i < m_playerUnmovable.size(); i++)
			{
				float distance = getDistance(currObjPos, m_playerUnmovable[i]->getCenter());
				if (distance < shortestDistance)
				{
					shortestDistance = distance;
					shortestPos.x = m_playerUnmovable[i]->getCenter().x;
					shortestPos.y = m_playerUnmovable[i]->getCenter().y;
				}
			}
		}

		for (auto& obj : m_playerMovable)
		{
			if (obj->getLives() < 10000)
			{
				float distance = getDistance(currObjPos, obj->getCenter());
				if (distance < shortestDistance)
				{
					shortestDistance = distance;
					shortestPos.x = obj->getCenter().x;
					shortestPos.y = obj->getCenter().y;
				}
			}
		}

		break;
	}

	return shortestPos;
}


// this function returns the shortest direction between a given object to a given target object
sf::Vector2f ArenaBattle::getShortestDirection(const sf::Vector2f currObjPos, const sf::Vector2f targetObjPos)
{
	sf::Vector2f direction = targetObjPos - currObjPos;
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0.0f)
	{
		direction /= length;
	}

	return direction;
}


float ArenaBattle::getDistance(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	float dx = v2.x - v1.x;
	float dy = v2.y - v1.y;
	return std::sqrt(dx * dx + dy * dy);
}


// this function calculates the animation direction based on a given direction
sf::Vector2f ArenaBattle::getAnimationDirection(const sf::Vector2f direction)
{
	sf::Vector2f currDirection = { 0, -1 };
	sf::Vector2f closestDirection = { 0, -1 };
	float minDifference = std::abs(direction.x - currDirection.x) + std::abs(direction.y - currDirection.y);
	float currDifference;

	for (int i = 0; i < 4; i++)
	{
		// regular:
		currDifference = std::abs(direction.x - currDirection.x) + std::abs(direction.y - currDirection.y);
		if (currDifference < minDifference)
		{
			minDifference = currDifference;
			closestDirection.x = currDirection.x;
			closestDirection.y = currDirection.y;
		}

		// opposite:
		currDifference = std::abs(direction.x - (currDirection.x * (-1))) + std::abs(direction.y - (currDirection.y * (-1)));
		if (currDifference < minDifference)
		{
			minDifference = currDifference;
			closestDirection.x = currDirection.x * (-1);
			closestDirection.y = currDirection.y * (-1);
		}

		if (i == 2)
			currDirection.x -= 0.5;
		else
			currDirection.x += 0.5;

		currDirection.y += 0.5;
	}

	return closestDirection;
}


// this function checks which objects can be removed and remove them
void ArenaBattle::removeObjs()
{
	// **************************** pc ****************************

	// remove unmovable
	m_indexesToRemove.clear();

	for (int i = 1; i < m_pcUnmovable.size(); i++)
	{
		// object with lives <= 0 needs to get removed
		if (m_pcUnmovable[i]->getLives() <= 0)
		{
			if (m_pcUnmovable[i]->getIsBigTower())
			{
				m_bigTowerDistroyedByPlayer = true; // saving for the end battle screen
				m_battleEnded = true;
			}
			else
			{
				m_destroyedRegTowersByPlayer++; // saving for the end battle screen
			}

			m_indexesToRemove.push_back(i);

			// the damaged area images
			if (m_pcUnmovable[i]->getPos().x == 165)
				m_pcDamagedAreaDisplay[0] = true;
			else if (m_pcUnmovable[i]->getPos().x == 455)
				m_pcDamagedAreaDisplay[1] = true;
			else if (m_pcUnmovable[i]->getPos().x == 305)
				m_pcDamagedAreaDisplay[2] = true;
		}
	}

	// finaly erasing the objects
	for (int i = m_indexesToRemove.size() - 1; i >= 0; i--)
		m_pcUnmovable.erase(m_pcUnmovable.begin() + m_indexesToRemove[i]);

	// remove movable
	m_indexesToRemove.clear();

	for (int i = 0; i < m_pcMovable.size(); i++)
	{
		if (m_pcMovable[i]->getLives() <= 0)
		{
			m_indexesToRemove.push_back(i);
		}

		if (m_pcUnmovable[0]->getCollidedWithTerritory() && m_pcMovable[i]->getLives() == 10000 && !m_pcMovable[i]->getIsSpell())
		{
			if (removeBullet(PLAYER))
			{
				m_indexesToRemove.push_back(i);
				m_pcCreatedBullets = false;
			}
		}
	}

	for (int i = m_indexesToRemove.size() - 1; i >= 0; i--)
		m_pcMovable.erase(m_pcMovable.begin() + m_indexesToRemove[i]);

	// **************************** player ****************************

	// remove unmovable
	m_indexesToRemove.clear();

	for (int i = 1; i < m_playerUnmovable.size(); i++)
		if (m_playerUnmovable[i]->getLives() <= 0)
		{
			if (m_playerUnmovable[i]->getIsBigTower())
			{
				m_bigTowerDistroyedByPc = true;
				m_battleEnded = true;
			}
			else
				m_destroyedRegTowersByPc++;

			m_indexesToRemove.push_back(i);

			if (m_playerUnmovable[i]->getPos().x == 165)
				m_playerDamagedAreaDisplay[0] = true;
			else if (m_playerUnmovable[i]->getPos().x == 455)
				m_playerDamagedAreaDisplay[1] = true;
			else if (m_playerUnmovable[i]->getPos().x == 305)
				m_playerDamagedAreaDisplay[2] = true;
		}

	for (int i = m_indexesToRemove.size() - 1; i >= 0; i--)
		m_playerUnmovable.erase(m_playerUnmovable.begin() + m_indexesToRemove[i]);

	// remove movable
	m_indexesToRemove.clear();

	for (int i = 0; i < m_playerMovable.size(); i++)
	{
		if (m_playerMovable[i]->getLives() <= 0)
		{
			m_indexesToRemove.push_back(i);
			if (m_playerMovable[i]->getLives() != 10000 && !m_playerMovable[i]->getIsSpell())
				m_playerTroopCount--;
		}

		if (m_playerUnmovable[0]->getCollidedWithTerritory() && m_playerMovable[i]->getLives() == 10000 && !m_playerMovable[i]->getIsSpell())
		{
			if (removeBullet(PC))
			{
				m_indexesToRemove.push_back(i);
				m_playerCreatedBullets = false;
			}
		}
	}

	for (int i = m_indexesToRemove.size() - 1; i >= 0; i--)
		m_playerMovable.erase(m_playerMovable.begin() + m_indexesToRemove[i]);
}


// this functions checks if the turn owner territory does not contain any enemy objects
// (to determine if the tower bullets can be stopped)
bool ArenaBattle::removeBullet(const TURN_OWNER owner) const
{
	int count = 0;
	int size;
	owner == PLAYER ? size = m_playerMovable.size() : size = m_pcMovable.size();
	for (int j = 0; j < size; j++)
		if ((owner == PLAYER && !m_playerMovable[j]->getPcTerritoryCollision()) ||
			(owner == PC && !m_pcMovable[j]->getPlayerTerritoryCollision()))
			count++;

	if (count == size)
	{
		return true;
	}

	return false;
}


// this function gets executed only once each time we reach arena battle screen.
// it initializes all vectors, variables, etc at the beginning of each battle
void ArenaBattle::battleInitializations(sf::RenderWindow& window)
{
	// sounds
	m_sound.setVolume(20.f * (m_soundLevel));
	m_loseSound.setVolume(20.f * (m_soundLevel));
	m_winSound.setVolume(20.f * (m_soundLevel));

	// player deck 
	m_player->setCurrDeckCards();

	// pc timers
	m_pcBattleTimer.restart();
	m_pcWaitTimer.restart();

	// pc deck
	m_pc.setDeck(m_player->getCollection(), m_player->getTrophies(), m_player->getAvailableCards(), m_player->getArena());
	m_pc.setCurrDeckCards();

	// pc elixir
	m_pcElixirCount = ELIXIR_COUNT;

	// pc chosen card
	m_pcPlacedCard = false;

	// trophies and coins
	m_trophiesToAdd = 0;
	m_coinsToAdd = 0;

	// curr card
	m_currCard = nullptr;

	// destroyed towers
	m_destroyedRegTowersByPc = 0;
	m_destroyedRegTowersByPlayer = 0;
	m_bigTowerDistroyedByPc = false;
	m_bigTowerDistroyedByPlayer = false;

	// sound
	playSound();
	m_enteredEndBattle = false;

	// vector clearing
	m_playerMovable.clear();
	m_pcMovable.clear();
	m_playerUnmovable.clear();
	m_pcUnmovable.clear();

	// area damage
	for (int i = 0; i < TOWERS_AMOUNT / 2; i++)
	{
		m_pcDamagedAreaDisplay[i] = false;
		m_playerDamagedAreaDisplay[i] = false;
	}

	// elixir
	m_elixirCount = ELIXIR_COUNT;
	for (int i = 0; i < m_elixirCount; i++)
		m_elixirCountRects[i].setFillColor(sf::Color(206, 33, 209));

	// territories
	auto type1 = static_cast<ObjectType>(PC_TERRITORY_TYPE);
	addUnmovableObjToFactory(PC, type1, { 0, 0 }, false);
	auto type2 = static_cast<ObjectType>(PLAYER_TERRITORY_TYPE);
	addUnmovableObjToFactory(PLAYER, type2, { 0, 0 }, false);

	m_pcUnmovable[0]->getRect().setPosition((window.getSize().x / 2) - (m_pcUnmovable[0]->getRect().getSize().x / 2) + 3, 87);
	m_playerUnmovable[0]->getRect().setPosition((window.getSize().x / 2) - (m_pcUnmovable[0]->getRect().getSize().x / 2) + 3, m_pcUnmovable[0]->getRect().getSize().y + m_pcUnmovable[0]->getRect().getPosition().y + 40);

	// towers
	buildTowers(window);

	// bullets
	m_pcCreatedBullets = false;
	m_playerCreatedBullets = false;

	// battle timer
	m_battleTimer.restart();
}


// this function runs all the time and responsible for updating the things
// that need to be updated or get checked all the time
void ArenaBattle::setDynamic(sf::RenderWindow& window, const int soundLevel)
{
	m_soundLevel = soundLevel;
	m_battleTimerText.setPosition(m_battleTimerBackground.getPosition().x + (m_battleTimerBackground.getSize().x / 2) - (m_battleTimerText.getGlobalBounds().width / 2), m_timeLeftText.getPosition().y + m_timeLeftText.getGlobalBounds().height + (m_timeLeftText.getGlobalBounds().height / 3));

	if (m_numOfSeconds == 0)
	{
		m_battleEnded = true;
		m_battleTimerText.setPosition(m_battleTimerBackground.getPosition().x + (m_battleTimerBackground.getSize().x / 2) - (m_battleTimerText.getGlobalBounds().width / 2), m_timeLeftText.getPosition().y + m_timeLeftText.getGlobalBounds().height + (m_timeLeftText.getGlobalBounds().height / 3));
	}

	if (!m_battleEnded)
	{
		if (m_battleTimer.getElapsedTime().asSeconds() > 1.0f)
			updateTimer();

		if (!m_initialized)
		{
			battleInitializations(window);
			m_initialized = true;
		}

		addElixir();
		m_elixirSprite.setScale(0.35f, 0.35f);
		m_elixirSprite.setPosition(m_elixirCountContainer.getPosition().x - 20, m_elixirCountContainer.getPosition().y - 15);
		m_elixirCountText.setPosition(m_elixirCountRects[0].getPosition().x + (m_elixirCountRects[0].getSize().x / 2) - (m_elixirCountText.getGlobalBounds().width / 2), m_elixirCountContainer.getPosition().y - (m_elixirCountText.getGlobalBounds().height / 2));
		m_elixirCountText.setString(std::to_string(m_elixirCount));

		m_deltaTime = m_movementClock.restart();
		pcAction();

		// constantly calculating the animation direction for each movable object of player and pc
		// ****************************************************************************************
		for (auto& obj : m_playerMovable)
		{
			if (typeid(*obj) != typeid(Bullet))
			{
				if (!obj->getIsSpell())
				{
					sf::Vector2f pos = getShortestObjPos(PLAYER, obj->getCenter(), true);
					sf::Vector2f direction = getShortestDirection(obj->getCenter(), pos);
					sf::Vector2f animationDirection = getAnimationDirection(direction);
					obj->changeAnimationDirection(animationDirection);
					obj->mapDirectionToAnimation(m_deltaTime, animationDirection, direction);
				}
				else
					obj->mapDirectionToAnimation(m_deltaTime, obj->getAnimationDirection(), obj->getDirection());

				obj->movement(m_deltaTime, obj->getDirection());
			}
			else
			{
				obj->movement(m_deltaTime, PLAYER_BULLET_DIR);
			}

			handleCollisions(*obj);
			obj->setLifeBar();
		}

		for (auto& obj : m_pcMovable)
		{
			if (typeid(*obj) != typeid(Bullet))
			{
				if (!obj->getIsSpell())
				{
					sf::Vector2f pos = getShortestObjPos(PC, obj->getCenter(), true);
					sf::Vector2f direction = getShortestDirection(obj->getCenter(), pos);
					sf::Vector2f animationDirection = getAnimationDirection(direction);
					obj->changeAnimationDirection(animationDirection);
					obj->mapDirectionToAnimation(m_deltaTime, animationDirection, direction);
				}
				else
					obj->mapDirectionToAnimation(m_deltaTime, obj->getAnimationDirection(), obj->getDirection());

				obj->movement(m_deltaTime, obj->getDirection());
			}

			else
				obj->movement(m_deltaTime, PC_BULLET_DIR);

			handleCollisions(*obj);
			obj->setLifeBar();
		}
		// ****************************************************************************************


		// if an object collided with a territory - start this territory towers bullets
		// ****************************************************************************************
		for (int i = 0; i < m_pcUnmovable.size(); i++)
		{
			if (i == 0)
			{
				if (!m_pcCreatedBullets && m_pcUnmovable[i]->getCollidedWithTerritory())
				{
					auto type = static_cast<ObjectType>(BULLET_TYPE);
					for (int j = 1; j <= TOWERS_AMOUNT / 2; j++)
					{
						if (j < m_pcUnmovable.size())
							addObjToFactory(PC, type, { m_pcUnmovable[j]->getCenter().x + 2, m_pcUnmovable[j]->getCenter().y + 10 }, 0);
					}

					m_pcCreatedBullets = true;
				}
			}
			else
				m_pcUnmovable[i]->setLifeBar(); // setting the life bar for the towers
		}

		for (int i = 0; i < m_playerUnmovable.size(); i++)
		{
			if (i == 0)
			{
				if (!m_playerCreatedBullets && m_playerUnmovable[i]->getCollidedWithTerritory())
				{
					auto type = static_cast<ObjectType>(BULLET_TYPE);
					for (int j = 1; j <= TOWERS_AMOUNT / 2; j++)
					{
						if (j < m_playerUnmovable.size())
							addObjToFactory(PLAYER, type, { m_playerUnmovable[j]->getCenter().x + 2, m_playerUnmovable[j]->getCenter().y + 10 }, 0);
					}

					m_playerCreatedBullets = true;
				}
			}
			else
				m_playerUnmovable[i]->setLifeBar(); // setting the life bar for the towers
		}
		// ****************************************************************************************

		removeObjs();
	}
	else // if the game ended
	{
		battleEndedHandler();
	}

	draw(window);
}



void ArenaBattle::pcAction()
{
	pcAddElixir();

	if (m_player->getArena() == 1 || m_player->getArena() == 2)
	{
		pcGenerateCard();
	}
	else
	{
		pcChooseSmartCard();
	}
}


// the easy algorithm of the pc that picks a random card, but place it in the 
// best found position
void ArenaBattle::pcGenerateCard()
{
	if (!m_pcPlacedCard)
	{
		m_pcChosenCard = std::rand() % m_pc.getCurrDeck().size();
		getPcOptimalPos();
		m_pcPlacedCard = true;
	}

	if (m_pcWaitTimer.getElapsedTime().asSeconds() > 6 && pcElixirCountManagment(m_pc.getDeck()[m_pcChosenCard]->getElixirCost()))
	{
		m_pcPlacedCard = false;
		pcAlgorithm({ -1, -1 });
		m_pc.addToCurrDeck(m_pcChosenCard);
		m_pcWaitTimer.restart();
	}
}


// the hard algorithm of the pc that picks cards based on priorities
// and place them in the best found place
void ArenaBattle::pcChooseSmartCard()
{
	if (m_pcWaitTimer.getElapsedTime().asSeconds() > 3)
	{
		// if the pc waited a while or the player started playing - pick a card
		if ((m_pcBattleTimer.getElapsedTime().asSeconds() > 3) ||
			(m_playerMovable.size() > 0 && m_playerMovable[m_playerMovable.size() - 1]->getIsSpell()) ||
			(m_playerTroopCount >= 1))
		{
			m_pcManagedToPlaceObj = false;

			// mapping the pc current deck to 5 priorities
			for (int i = 0; i < m_pc.getCurrDeck().size(); i++)
			{
				if (m_pc.getCurrDeck()[i]->getPriority() == PRIORITY_1)
					m_priority1 = i;
				else if (m_pc.getCurrDeck()[i]->getPriority() == PRIORITY_2)
					m_priority2 = i;
				else if (m_pc.getCurrDeck()[i]->getPriority() == PRIORITY_3)
					m_priority3 = i;
				else if (m_pc.getCurrDeck()[i]->getPriority() == PRIORITY_4)
					m_priority4 = i;
				else if (m_pc.getCurrDeck()[i]->getPriority() == PRIORITY_5)
					m_priority5 = i;
			}

			// *************************** the priorities: ***************************
			
			// spell imapct >= a tower's lives
			if (m_priority4 != -1 && !m_pcManagedToPlaceObj)
			{
				int hit;
				switch (m_pc.getCurrDeck()[m_priority4]->getLevel())
				{
				case 1:
					hit = FIREBALL_ATK_1;
					break;
				case 2:
					hit = FIREBALL_ATK_2;
					break;
				case 3:
					hit = FIREBALL_ATK_3;
					break;
				case 4:
					hit = FIREBALL_ATK_4;
					break;
				}
				for (int i = 1; i < m_playerUnmovable.size(); i++)
				{
					if (hit >= m_playerUnmovable[i]->getLives())
					{
						pcPlaceCard(m_priority4, m_playerUnmovable[i]->getCenter());
						m_pcManagedToPlaceObj = true;
						break;
					}
				}
				m_priority4 = -1;
			}

			// freeze & 3 troops in same radius
			if (m_priority5 != -1 && !m_pcManagedToPlaceObj)
			{
				sf::CircleShape circle;
				circle.setRadius(50);
				int count = 0;

				for (int i = 0; i < m_playerMovable.size(); i++)
				{
					count = 0;
					sf::Vector2f destLocation;

					destLocation.x = m_playerMovable[i]->getCenter().x;
					destLocation.y = m_playerMovable[i]->getCenter().y;
					circle.setPosition(destLocation.x - circle.getRadius(), destLocation.y - circle.getRadius());

					for (int j = 0; j < m_playerMovable.size(); j++)
					{
						if (m_playerMovable[j]->getLives() != 10000 && circle.getGlobalBounds().contains(m_playerMovable[j]->getCenter()))
						{
							count++;
						}
					}

					if (count == 3)
					{
						pcPlaceCard(m_priority5, m_playerMovable[i]->getCenter());
						m_pcManagedToPlaceObj = true;
						break;
					}

					if (m_pcManagedToPlaceObj)
						break;
				}
				m_priority5 = -1;
			}

			// defense card & minion collided with pc territory
			if (m_priority3 != -1 && !m_pcManagedToPlaceObj)
			{
				for (auto& obj : m_playerMovable)
				{
					if (obj->getPcTerritoryCollision() && typeid(*obj) == typeid(MinionsObj))
					{
						pcPlaceCard(m_priority3, { -1, -1 });
						m_pcManagedToPlaceObj = true;
						break;
					}
				}

				m_priority3 = -1;
			}

			// minion 
			if (m_priority1 != -1 && !m_pcManagedToPlaceObj)
			{
				pcPlaceCard(m_priority1, { -1, -1 });
				m_pcManagedToPlaceObj = true;
				m_priority1 = -1;
			}

			// attack card 
			if (m_priority2 != -1 && !m_pcManagedToPlaceObj)
			{
				pcPlaceCard(m_priority2, { -1, -1 });
				m_pcManagedToPlaceObj = true;
				m_priority2 = -1;
			}

			// defense card 
			if (m_priority3 != -1 && !m_pcManagedToPlaceObj)
			{
				pcPlaceCard(m_priority3, { -1, -1 });
				m_pcManagedToPlaceObj = true;
				m_priority3 = -1;
			}

			// spell card 
			if (m_priority4 != -1 && !m_pcManagedToPlaceObj)
			{
				pcPlaceCard(m_priority4, { -1, -1 });
				m_pcManagedToPlaceObj = true;
				m_priority4 = -1;
			}
		}
		m_pcWaitTimer.restart();
	}
}


// this function manages the placement of the pc cards
void ArenaBattle::pcPlaceCard(const int priority, const sf::Vector2f targetPos)
{
	if (!m_pcPlacedCard)
	{
		m_pcChosenCard = priority;
		getPcOptimalPos();
		m_pcPlacedCard = true;
	}
	if (pcElixirCountManagment(m_pc.getDeck()[m_pcChosenCard]->getElixirCost()))
	{
		m_pcPlacedCard = false;
		pcAlgorithm(targetPos);
		m_pc.addToCurrDeck(m_pcChosenCard);
	}
}


// this function creates a new object of the pc
void ArenaBattle::pcAlgorithm(const sf::Vector2f targetPos)
{
	sf::Vector2f optimalPos, dest;

	// if no targetPos was sent, take the current optimal pos that is being constantly calculated (m_currPcOptimalPos)
	if (targetPos.x == -1 && targetPos.y == -1)
	{
		optimalPos.x = m_currPcOptimalPos.x;
		optimalPos.y = m_currPcOptimalPos.y;
	}
	else
	{
		optimalPos.x = targetPos.x;
		optimalPos.y = targetPos.y;
	}

	auto type = static_cast<ObjectType>(m_pc.getCurrDeck()[m_pcChosenCard]->getId());
	addObjToFactory(PC, type, optimalPos, m_pc.getCurrDeck()[m_pcChosenCard]->getLevel());

	// saving the position of the last added object
	m_lastObjCenterPos.x = m_pcMovable[m_pcMovable.size() - 1]->getCenter().x;
	m_lastObjCenterPos.y = m_pcMovable[m_pcMovable.size() - 1]->getCenter().y;

	// handling the spell added object
	if (m_pcMovable[m_pcMovable.size() - 1]->getIsSpell())
	{
		if (targetPos.x == -1 && targetPos.y == -1)
		{
			dest = getShortestObjPos(PC, m_pcMovable[m_pcMovable.size() - 1]->getCenter(), true);
		}
		else
		{
			dest.x = targetPos.x;
			dest.y = targetPos.y;
		}
		m_pcMovable[m_pcMovable.size() - 1]->setPcSpellDest(dest);
		sf::Vector2f direction = getShortestDirection(m_pcMovable[m_pcMovable.size() - 1]->getCenter(), dest);
		sf::Vector2f animationDirection = getAnimationDirection(direction);
		m_pcMovable[m_pcMovable.size() - 1]->mapDirectionToAnimation(m_deltaTime, animationDirection, direction);
	}
}


// this function calculates the most optimal position for the pc to place a card at
sf::Vector2f ArenaBattle::getPcOptimalPos()
{
	sf::Vector2f shortestPos, currPos, pos, destTowerPos;
	float currDistance, shortestDistance;
	int minLives = 10000, currLives;

	shortestPos.x = getShortestObjPos(PC, m_pcUnmovable[1]->getCenter(), false).x;
	shortestPos.y = getShortestObjPos(PC, m_pcUnmovable[1]->getCenter(), false).y;
	shortestDistance = 1000;

	// getting the pos of the closest player object to one of the pc towers
	for (int i = 1; i < m_pcUnmovable.size(); i++)
	{
		currPos = getShortestObjPos(PC, m_pcUnmovable[i]->getCenter(), false);
		currDistance = getDistance(currPos, m_pcUnmovable[i]->getCenter());
		if (currDistance < shortestDistance)
		{
			shortestDistance = currDistance;
			shortestPos.x = currPos.x;
			shortestPos.y = currPos.y;
		}
	}

	// if this object pos is in the pc territory
	if (shortestPos.y <= 387)
	{
		pos.x = shortestPos.x - 20;
		pos.y = shortestPos.y;
	}
	// if not - check for the player tower with the least lives
	else
	{
		for (int i = 1; i < m_playerUnmovable.size(); i++)
		{
			currLives = m_playerUnmovable[i]->getLives();
			if (currLives < minLives)
			{
				minLives = currLives;
				destTowerPos = m_playerUnmovable[i]->getCenter();
			}
		}

		pos.x = destTowerPos.x;
		pos.y = destTowerPos.y - 290;
	}

	// saving the optimal position as a member
	m_currPcOptimalPos.x = pos.x;
	m_currPcOptimalPos.y = pos.y;

	return pos;
}


// this function reduces the elixir count if there are enough elixirs
// and restarts the timer so a new elixir will be added every second
bool ArenaBattle::pcElixirCountManagment(const int elixirCost)
{
	if (elixirCost <= m_pcElixirCount)
	{
		m_pcElixirTimer.restart();
		m_pcElixirCount -= elixirCost;
		return true;
	}

	return false;
}


// this function added elixir to the pc elixirs
void ArenaBattle::pcAddElixir()
{
	if (m_pcElixirTimer.getElapsedTime().asSeconds() > 1.0f)
	{
		if (m_pcElixirCount < 10)
		{
			m_pcElixirCount += 1;
		}
		m_pcElixirTimer.restart();
	}
}


// this function manages the end battle operations, such as calculating the
// winner, trophies and coins
void ArenaBattle::battleEndedHandler()
{
	// music handling
	m_sound.stop();
	if (!m_enteredEndBattle)
	{
		// trophies and coins handling
		m_trophiesToAdd = 0;
		m_coinsToAdd = 0;

		// pc: big tower:1, regular towers:2
		if (m_bigTowerDistroyedByPc && m_destroyedRegTowersByPc == 2)
		{
			m_destroyedRegTowersByPc++;
			m_winner = 0;
		}
		// pc: big tower:1, regular towers:1
		else if (m_bigTowerDistroyedByPc && m_destroyedRegTowersByPc == 1)
		{
			m_destroyedRegTowersByPc++;
			m_winner = 0;
		}
		// pc: big tower:1, regular towers:0
		else if (m_bigTowerDistroyedByPc && m_destroyedRegTowersByPc == 0)
		{
			m_destroyedRegTowersByPc++;
			m_winner = 0;
		}
		// pc: big tower:0, regular towers: more than player
		else if (!m_bigTowerDistroyedByPc && m_destroyedRegTowersByPc > m_destroyedRegTowersByPlayer)
		{
			m_winner = 0;
		}

		// player: big:1, reg:2
		else if (m_bigTowerDistroyedByPlayer && m_destroyedRegTowersByPlayer == 2)
		{
			m_destroyedRegTowersByPlayer++;
			m_winner = 1;
			m_trophiesToAdd = 32;
			m_coinsToAdd = 190;
		}
		// player: big:1, reg:1
		else if (m_bigTowerDistroyedByPlayer && m_destroyedRegTowersByPlayer == 1)
		{
			m_destroyedRegTowersByPlayer++;
			m_winner = 1;
			m_trophiesToAdd = 30;
			m_coinsToAdd = 170;
		}
		// player: big:1, reg:0
		else if (m_bigTowerDistroyedByPlayer && m_destroyedRegTowersByPlayer == 0)
		{
			m_destroyedRegTowersByPlayer++;
			m_winner = 1;
			m_trophiesToAdd = 28;
			m_coinsToAdd = 150;
		}
		// player: big:0, reg: more than pc
		else if (!m_bigTowerDistroyedByPlayer && m_destroyedRegTowersByPlayer > m_destroyedRegTowersByPc)
		{
			m_winner = 1;
			m_trophiesToAdd = 26;
			m_coinsToAdd = 140;
		}
		// equality
		else
		{
			m_winner = 1;
			m_trophiesToAdd = 24;
			m_coinsToAdd = 130;
		}

		if (m_winner == 0)
			m_loseSound.play();
		else
			m_winSound.play();

		m_player->setTrophies(m_trophiesToAdd);
		m_player->setCoins(m_coinsToAdd);

		m_battleEndedScreen.setRealData(m_destroyedRegTowersByPc, m_destroyedRegTowersByPlayer, m_winner, m_trophiesToAdd, m_coinsToAdd, m_player->getArena(), m_player->getLives());
		m_enteredEndBattle = true;
	}

	m_initialized = false;
	m_numOfSeconds = BATTLE_TIME;
}


void ArenaBattle::getMouseClick(const sf::Vector2f location, sf::RenderWindow& window)
{
	if (!m_battleEnded)
	{
		// checking if a card was clicked
		for (int i = 0; i < m_player->getCurrDeck().size(); i++)
		{
			if (m_player->getCurrDeck()[i]->getCardImg().getGlobalBounds().contains(location))
			{
				if (m_clickedIndex >= 0 && m_clickedCard)
					m_player->getCurrDeck()[m_clickedIndex]->cancelClickedCard();

				m_clickedCard = true;
				m_currCard = m_player->getCurrDeck()[i];
				m_currCard->setClickedCard();
				m_clickedIndex = i;

				if (m_currCard->getTerritoryLimited())
					m_pcUnmovable[0]->getRect().setFillColor(sf::Color(255, 0, 0, 100));
				else
					m_pcUnmovable[0]->getRect().setFillColor(sf::Color::Transparent);
			}
		}

		// checking if the player territory was clicked after picking a card - for troops
		if (m_playerUnmovable[0]->getRect().getGlobalBounds().contains(location) && m_currCard && m_currCard->getTerritoryLimited())
		{
			elixirCountManagment();
			m_player->getCurrDeck()[m_clickedIndex]->cancelClickedCard();
			if (!m_clickedCard)
			{
				auto type = static_cast<ObjectType>(m_player->getCurrDeck()[m_clickedIndex]->getId());
				addObjToFactory(PLAYER, type, location, m_player->getCurrDeck()[m_clickedIndex]->getLevel());

				m_pcUnmovable[0]->getRect().setFillColor(sf::Color::Transparent);
				m_player->addToCurrDeck(m_clickedIndex);
				m_playerTroopCount++;
				m_pcBattleTimer.restart();
			}
		}

		// checking if the player or pc territory was clicked after picking a card - for troops & spells
		else if ((m_playerUnmovable[0]->getRect().getGlobalBounds().contains(location) || m_pcUnmovable[0]->getRect().getGlobalBounds().contains(location)) && m_currCard && (!m_currCard->getTerritoryLimited()))
		{
			elixirCountManagment();
			m_player->getCurrDeck()[m_clickedIndex]->cancelClickedCard();
			if (!m_clickedCard)
			{
				auto type = static_cast<ObjectType>(m_player->getCurrDeck()[m_clickedIndex]->getId());
				addObjToFactory(PLAYER, type, location, m_player->getCurrDeck()[m_clickedIndex]->getLevel());

				sf::Vector2f direction = getShortestDirection(m_playerMovable[m_playerMovable.size() - 1]->getCenter(), location);
				sf::Vector2f animationDirection = getAnimationDirection(direction);
				m_playerMovable[m_playerMovable.size() - 1]->mapDirectionToAnimation(m_deltaTime, animationDirection, direction);

				m_player->addToCurrDeck(m_clickedIndex);
				m_pcBattleTimer.restart();
			}
		}
	}
	// end battle page clicks handling
	else
	{
		if (m_battleEndedScreen.getMouseClick(location))
		{
			// the player won all arenas
			if ((m_player->getArena() == ARENA_IMGS && m_winner == 1) ||
				(m_player->getLives() == 1 && m_winner == 0))
				exit(EXIT_SUCCESS);
			// the player won
			else if (m_player->getArena() < ARENA_IMGS && m_winner == 1)
				m_player->setArena();
			// the player lost
			else if (m_winner == 0)
				m_player->decLives();

			m_battleEnded = false;
			*m_battleMode = false; // this will bring us back to main page
		}
	}
}



void ArenaBattle::addObjToFactory(const TURN_OWNER turnOwner, auto type, const sf::Vector2f location, const int cardLevel)
{
	auto movable = Factory<Movable>::instance().create(type, location, cardLevel, m_player->getArena(), false, turnOwner, m_soundLevel);
	if (movable)
	{
		turnOwner == PLAYER ? m_playerMovable.push_back(std::move(movable)) :
			m_pcMovable.push_back(std::move(movable));
		return;
	}

	auto troopObj = Factory<TroopObj>::instance().create(type, location, cardLevel, m_player->getArena(), false, turnOwner, m_soundLevel);
	if (troopObj)
	{
		turnOwner == PLAYER ? m_playerMovable.push_back(std::move(troopObj)) :
			m_pcMovable.push_back(std::move(troopObj));
		return;
	}

	auto spellObj = Factory<SpellObj>::instance().create(type, location, cardLevel, m_player->getArena(), false, turnOwner, m_soundLevel);
	if (spellObj)
	{
		turnOwner == PLAYER ? m_playerMovable.push_back(std::move(spellObj)) :
			m_pcMovable.push_back(std::move(spellObj));
		return;
	}


	throw std::runtime_error(std::string("No factory handles " + std::to_string(static_cast<int>(type))));
}


void ArenaBattle::addUnmovableObjToFactory(const TURN_OWNER turnOwner, auto type, const sf::Vector2f location, const bool bigTower)
{
	auto unmovable = Factory<Unmovable>::instance().create(type, location, 0, m_player->getArena(), bigTower, turnOwner, m_soundLevel);
	if (unmovable)
	{
		turnOwner == PLAYER ? m_playerUnmovable.push_back(std::move(unmovable)) :
			m_pcUnmovable.push_back(std::move(unmovable));
		return;
	}
	throw std::runtime_error(std::string("No factory handles " + std::to_string(static_cast<int>(type))));
}


// this function managed the elixirs of the player
void ArenaBattle::elixirCountManagment()
{
	if (m_currCard->getElixirCost() <= m_elixirCount)
	{
		m_elixirTimer.restart();
		m_clickedCard = false;

		for (int i = m_elixirCount - 1; i >= m_elixirCount - m_currCard->getElixirCost(); i--)
			m_elixirCountRects[i].setFillColor(sf::Color::Transparent);

		m_elixirCount -= m_currCard->getElixirCost();
		m_currCard = nullptr;
	}
}



void ArenaBattle::addElixir()
{
	if (m_elixirTimer.getElapsedTime().asSeconds() > 1.0f)
	{
		if (m_elixirCount < 10)
		{
			m_elixirCountRects[m_elixirCount].setFillColor(sf::Color(206, 33, 209));
			m_elixirCount += 1;
		}
		m_elixirTimer.restart();
	}
}


void ArenaBattle::handleCollisions(Object& gameObject)
{
	for (auto& movable : m_pcMovable)
	{
		if (movable != nullptr && gameObject.checkCollision(*movable))
		{
			Object& objectRef = dynamic_cast<Object&>(*movable);
			processCollision(gameObject, objectRef);
		}
	}

	for (auto& unmovable : m_pcUnmovable)
	{
		if (unmovable != nullptr && gameObject.checkCollision(*unmovable))
		{
			Object& objectRef = dynamic_cast<Object&>(*unmovable);
			processCollision(gameObject, objectRef);
		}
	}

	for (auto& movable : m_playerMovable)
	{
		if (movable != nullptr && gameObject.checkCollision(*movable))
		{
			Object& objectRef = dynamic_cast<Object&>(*movable);
			processCollision(gameObject, objectRef);
		}
	}

	for (auto& unmovable : m_playerUnmovable)
	{
		if (unmovable != nullptr && gameObject.checkCollision(*unmovable))
		{
			Object& objectRef = dynamic_cast<Object&>(*unmovable);
			processCollision(gameObject, objectRef);
		}
	}
}


void ArenaBattle::buildTimer()
{
	m_battleTimerBackground.setSize(sf::Vector2f(130, 75));
	m_battleTimerBackground.setFillColor(sf::Color(75, 53, 43, 255));
	m_battleTimerBackground.setOutlineThickness(4);
	m_battleTimerBackground.setOutlineColor(sf::Color::Black);
	m_battleTimerBackground.setPosition(530, 4);

	m_timeLeftText.setFont(Resources::instance().getFont());
	m_timeLeftText.setCharacterSize(17);
	m_timeLeftText.setFillColor(sf::Color(243, 226, 166, 255));
	m_timeLeftText.setOutlineThickness(2);
	m_timeLeftText.setOutlineColor(sf::Color(11, 13, 14, 255));
	m_timeLeftText.setString("Time left:");
	m_timeLeftText.setPosition(m_battleTimerBackground.getPosition().x + (m_battleTimerBackground.getSize().x / 2) - (m_timeLeftText.getGlobalBounds().width / 2), m_battleTimerBackground.getPosition().y + (m_timeLeftText.getGlobalBounds().height / 2));

	m_battleTimerText.setFont(Resources::instance().getFont());
	m_battleTimerText.setCharacterSize(25);
	m_battleTimerText.setFillColor(sf::Color::White);
	m_battleTimerText.setOutlineThickness(2);
	m_battleTimerText.setOutlineColor(sf::Color(11, 13, 14, 255));
	m_battleTimerText.setPosition(m_battleTimerBackground.getPosition().x + (m_battleTimerBackground.getSize().x / 2) - (m_battleTimerText.getGlobalBounds().width / 2), m_timeLeftText.getPosition().y + m_timeLeftText.getGlobalBounds().height + (m_timeLeftText.getGlobalBounds().height / 3));
}

void ArenaBattle::updateTimer()
{
	m_numOfSeconds--;

	std::string time;
	std::string s1;
	std::string s2;
	int minutes = m_numOfSeconds / 60;
	int seconds = m_numOfSeconds % 60;

	s1 = std::to_string(minutes) + ":";

	if (seconds < 10)
	{
		s2 = "0";
		s2 += std::to_string(seconds);
	}

	else
	{
		s2 = std::to_string(seconds);
	}

	time = s1 + s2;

	m_battleTimerText.setString(time);
	m_battleTimer.restart();
}


void ArenaBattle::draw(sf::RenderWindow& window)
{
	window.draw(m_arenasBackgroundsSprites[m_player->getArena() - 1]);
	window.draw(m_deckBackground);
	window.draw(m_elixirCountContainer);

	for (auto elixirUnit : m_elixirCountRects)
	{
		window.draw(elixirUnit);
	}
	window.draw(m_elixirCountText);
	window.draw(m_elixirSprite);

	for (auto& card : m_player->getCurrDeck())
	{
		window.draw(card->getCardOutline());
		window.draw(card->getCardImg());
		window.draw(card->getElixirCostSprite());
		window.draw(card->getElixirCostText());
		window.draw(card->getElixirCostText());
	}

	window.draw(m_pcUnmovable[0]->getRect());
	window.draw(m_playerUnmovable[0]->getRect());

	if (m_pcDamagedAreaDisplay[0])
		window.draw(m_pcDamagedArea1);
	if (m_pcDamagedAreaDisplay[1])
		window.draw(m_pcDamagedArea2);
	if (m_pcDamagedAreaDisplay[2])
		window.draw(m_pcDamagedArea3);

	if (m_playerDamagedAreaDisplay[0])
		window.draw(m_playerDamagedArea1);
	if (m_playerDamagedAreaDisplay[1])
		window.draw(m_playerDamagedArea2);
	if (m_playerDamagedAreaDisplay[2])
		window.draw(m_playerDamagedArea3);

	for (auto& obj : m_playerMovable)
	{
		if (obj->getIsSpell())
			window.draw(obj->getSpellTargetArea());
	}

	for (auto& obj : m_pcMovable)
	{
		if (obj->getIsSpell())
			window.draw(obj->getSpellTargetArea());
	}

	for (auto& obj : m_playerMovable)
	{
		window.draw(obj->getCurrObjSprite());
		window.draw(obj->getBulletSprite());


		window.draw(obj->getLifeBarBackground());
		window.draw(obj->getLifeBar());
	}

	for (auto& obj : m_pcMovable)
	{
		window.draw(obj->getCurrObjSprite());
		window.draw(obj->getBulletSprite());
		window.draw(obj->getLifeBarBackground());
		window.draw(obj->getLifeBar());
	}

	for (int i = 1; i < m_pcUnmovable.size(); i++)
	{
		window.draw(m_pcUnmovable[i]->getObjBorder());
		window.draw(m_pcUnmovable[i]->getLifeBar());
		window.draw(m_pcUnmovable[i]->getLifeBarCrown());
		window.draw(m_pcUnmovable[i]->getLifeBarCount());
	}

	for (int i = 1; i < m_playerUnmovable.size(); i++)
	{
		window.draw(m_playerUnmovable[i]->getObjBorder());
		window.draw(m_playerUnmovable[i]->getLifeBar());
		window.draw(m_playerUnmovable[i]->getLifeBarCrown());
		window.draw(m_playerUnmovable[i]->getLifeBarCount());
	}

	if (m_battleEnded)
		m_battleEndedScreen.draw(window);

	window.draw(m_battleTimerBackground);
	window.draw(m_timeLeftText);
	window.draw(m_battleTimerText);
}



