#include "Player.h"
#include "Knight.h"

Player::Player()
	:m_arena(1),
	m_trophies(0),
	m_coins(0),
	m_lives(6),
	m_name("Hello player!"),
	m_availableCards(DECK_STARTER_CARDS)
{}


int Player::getArena() const
{
	return m_arena;
}


int Player::getTrophies() const
{
	return m_trophies;
}


int Player::getCoins() const
{
	return m_coins;
}


int Player::getLives() const
{
	return m_lives;
}


std::string Player::getName() const
{
	return m_name;
}


void Player::setDeckBackgroundPosition(const sf::Vector2f position)
{
	m_deckBackgroundPosition = position;
}


void Player::setDeck(std::vector<std::shared_ptr<Card>> deck)
{
	m_collection = deck;

	m_deck.clear();

	for (int i = 0; i < DECK_SIZE; i++)
	{
		if (deck[i] != nullptr)
		{
			m_deck.push_back(deck[i]);
		}
	}
}

// This function sets the current four available cards for the player to use in battle:
void Player::setCurrDeckCards()
{
	m_currDeck.clear();

	for (int i = 0; i < DECK_SIZE; i++)
		m_pickedCards[i] = false;

	int i = 0;

	while (i < CURR_VISIBLE_DECK_SIZE)
	{
		int randCard = std::rand() % m_deck.size();
		if (!m_pickedCards[randCard])
		{
			auto newCard = m_deck[randCard]->clone(m_deck[randCard]->getLevel());

			newCard->setCardDynamic();
			newCard->setCardImgScale(0.35f, 0.35f);
			newCard->setCardImgPos((m_deckBackgroundPosition.x + 150) + (i * (m_deck[randCard]->getCardImg().getGlobalBounds().width - 20)), m_deckBackgroundPosition.y + 7);
			newCard->setElixirDetails();
			m_currDeck.push_back(newCard);
			m_pickedCards[randCard] = true;
			i++;
		}
	}
}


std::vector<std::shared_ptr<Card>> Player::getDeck()
{
	return m_deck;
}


std::vector<std::shared_ptr<Card>> Player::getCurrDeck()
{
	return m_currDeck;
}


std::vector<std::shared_ptr<Card>> Player::getCollection()
{
	return m_collection;
}

// This function adds a random card from the player's deck to their currently available four cards to choose from
// in battle, after a card has ben used:
void Player::addToCurrDeck(const int cardIndex)
{
	bool equalId;

	while (true)
	{
		equalId = false;

		int randCard = std::rand() % m_deck.size();

		for (auto& card : m_currDeck)
		{
			if (m_deck[randCard] && card->getId() == m_deck[randCard]->getId())
			{
				equalId = true;
				break;
			}
		}

		if (!equalId && m_deck[randCard])
		{
			auto newCard = m_deck[randCard]->clone(m_deck[randCard]->getLevel());
			newCard->setCardDynamic();
			newCard->setCardImgScale(0.35f, 0.35f);
			newCard->setCardImgPos(m_currDeck[cardIndex]->getCardImg().getPosition().x, m_currDeck[cardIndex]->getCardImg().getPosition().y);
			newCard->setElixirDetails();

			m_currDeck.erase(m_currDeck.begin() + cardIndex);
			m_currDeck.insert(m_currDeck.begin() + cardIndex, newCard);

			break;
		}
	}
}


int Player::getAvailableCards() const
{
	return m_availableCards;
}

// This function updates a card details after it has been upgraded:
bool Player::upgradeCardHandler(const int cardIndex)
{
	if (m_coins >= m_deck[cardIndex]->getCurrUpgradeCost())
	{
		m_coins -= m_deck[cardIndex]->getCurrUpgradeCost();
		m_deck[cardIndex]->upgradeLevel();

		return true;
	}

	return false;
}

// This function increases the player's arena when they win a battle:
void Player::setArena()
{
	m_arena++;
}


void Player::setTrophies(const int trophies)
{
	m_trophies += trophies;
}


void Player::setCoins(const int coins)
{
	m_coins += coins;
}


void Player::decLives()
{
	m_lives--;
}


void Player::setAvailableCards()
{
	m_availableCards++;
}


void Player::clearAvailableCards()
{
	m_availableCards = 0;
}