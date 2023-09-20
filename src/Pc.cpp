#include "Pc.h"

Pc::Pc()
{}

// This function sets the PC's cards deck according to the cards currently available for the player:
void Pc::setDeck(std::vector<std::shared_ptr<Card>> collection, const int playerTrophies, const int availableCards, const int arena)
{
	m_arena = arena;
	m_deck.clear();

	if (availableCards <= PC_DECK_SIZE)
	{
		for (int i = 0; i < PC_DECK_SIZE; i++)
		{
			if (collection[i] != nullptr && collection[i]->getUnlockedInTrophies() <= playerTrophies)
			{
				if (((m_arena == 2 || m_arena == 3) && i % 2 != 0 && collection[i]->getLevel() < 5) ||
					(m_arena == 4 && collection[i]->getLevel() < 5))
				{
					auto newCard = collection[i]->clone(collection[i]->getLevel() + 1);
					m_deck.push_back(newCard);
				}
				else
				{
					auto newCard = collection[i]->clone(collection[i]->getLevel());
					m_deck.push_back(newCard);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < PC_COLLECTION_SIZE; i++)
			m_pickedCards[i] = false;

		int i = 0;
		while (i < PC_DECK_SIZE)
		{
			int randCard = std::rand() % collection.size();
			if (!m_pickedCards[randCard] && collection[randCard] != nullptr &&
				collection[randCard]->getUnlockedInTrophies() <= playerTrophies)
			{
				if (((m_arena == 2 || m_arena == 3) && i % 2 != 0 && collection[randCard]->getLevel() < 5) ||
					(m_arena == 4 && collection[randCard]->getLevel() < 5))
				{
					auto newCard = collection[randCard]->clone(collection[randCard]->getLevel() + 1);
					m_deck.push_back(newCard);
				}
				else
				{
					auto newCard = collection[randCard]->clone(collection[randCard]->getLevel());
					m_deck.push_back(newCard);
				}

				m_pickedCards[randCard] = true;
				i++;
			}
		}
	}
}

// This function sets the PC's current four cards available for it to use in battle (like how the player
// has four cards from his deck to choose from in the battle at any given time):
void Pc::setCurrDeckCards()
{
	m_currDeck.clear();

	for (int i = 0; i < PC_DECK_SIZE; i++)
		m_pickedCards[i] = false;

	int i = 0;

	while (i < PC_CURR_VISIBLE_DECK_SIZE)
	{
		int randCard = std::rand() % m_deck.size();
		if (!m_pickedCards[randCard])
		{
			auto newCard = m_deck[randCard]->clone(m_deck[randCard]->getLevel());
			m_currDeck.push_back(newCard);
			m_pickedCards[randCard] = true;
			i++;
		}
	}
}

// This function returns the entire PC's deck:
std::vector<std::shared_ptr<Card>> Pc::getDeck()
{
	return m_deck;
}

// This function returns the PC's currently available four cards to choose from when in battle:
std::vector<std::shared_ptr<Card>> Pc::getCurrDeck()
{
	return m_currDeck;
}

// This function adds a random card from the PC's deck to its currently available four cards to choose from
// in battle, after it used a card:
void Pc::addToCurrDeck(const int cardIndex)
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
			if (((m_arena == 2 || m_arena == 3) && randCard % 2 != 0 && m_deck[randCard]->getLevel() < 5) ||
				(m_arena == 4 && m_deck[randCard]->getLevel() < 5))
			{
				auto newCard = m_deck[randCard]->clone(m_deck[randCard]->getLevel() + 1);
				m_currDeck.erase(m_currDeck.begin() + cardIndex);
				m_currDeck.insert(m_currDeck.begin() + cardIndex, newCard);
			}
			else
			{
				auto newCard = m_deck[randCard]->clone(m_deck[randCard]->getLevel());
				m_currDeck.erase(m_currDeck.begin() + cardIndex);
				m_currDeck.insert(m_currDeck.begin() + cardIndex, newCard);
			}

			break;
		}
	}
}

