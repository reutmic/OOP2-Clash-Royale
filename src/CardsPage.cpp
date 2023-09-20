#include "CardsPage.h"

CardsPage::CardsPage(sf::RenderWindow& window, Player& player, bool& initializied)
	:m_deckCardsCount(DECK_STARTER_CARDS), m_player(&player)
{
	m_initialized = &initializied;
	buildDeck(window);
	buildCollection(window);
	m_upgradeCardSound.setBuffer(Resources::instance().getSound(Resources::UPGRADE_CARD));
}

// This function builds the cards deck of the user in the Collection page:
void CardsPage::buildDeck(sf::RenderWindow& window)
{
	m_deckBackground.setSize(sf::Vector2f(550, 420));
	m_deckBackground.setFillColor(sf::Color(139, 96, 64, 255));
	m_deckBackground.setOutlineThickness(10);
	m_deckBackground.setOutlineColor(sf::Color(77, 57, 38, 255));
	m_deckBackground.setPosition((window.getSize().x / 2) - (m_deckBackground.getSize().x / 2), 80);

	m_deckTextBackground.setSize(sf::Vector2f(500, 40));
	m_deckTextBackground.setFillColor(sf::Color(73, 41, 23, 255));
	m_deckTextBackground.setPosition(m_deckBackground.getPosition().x + (m_deckBackground.getSize().x / 2) - (m_deckTextBackground.getSize().x / 2), m_deckBackground.getPosition().y + 10);

	m_deck.setFont(Resources::instance().getFont());
	m_deck.setString("Battle Deck");
	m_deck.setCharacterSize(20);
	m_deck.setFillColor(sf::Color::White);
	m_deck.setOutlineThickness(1);
	m_deck.setOutlineColor(sf::Color::Black);
	m_deck.setPosition(m_deckTextBackground.getPosition().x + 10, m_deckTextBackground.getPosition().y + 8);

	m_avgElixirCostText.setFont(Resources::instance().getFont());
	m_avgElixirCostText.setString("Average Elixir Cost:");
	m_avgElixirCostText.setCharacterSize(13);
	m_avgElixirCostText.setFillColor(sf::Color(205, 154, 255, 255));
	m_avgElixirCostText.setOutlineThickness(1);
	m_avgElixirCostText.setOutlineColor(sf::Color::Black);
	m_avgElixirCostText.setPosition(m_deckTextBackground.getPosition().x + m_deckTextBackground.getSize().x - m_avgElixirCostText.getGlobalBounds().width - 78, m_deckTextBackground.getPosition().y + (m_deckTextBackground.getSize().y / 2) - (m_avgElixirCostText.getGlobalBounds().height / 2));

	m_avgElixirCost.setFont(Resources::instance().getFont());
	m_avgElixirCost.setCharacterSize(15);
	m_avgElixirCost.setFillColor(sf::Color(205, 154, 255, 255));
	m_avgElixirCost.setOutlineThickness(1);
	m_avgElixirCost.setOutlineColor(sf::Color::Black);
	m_avgElixirCost.setPosition(m_avgElixirCostText.getPosition().x + m_avgElixirCostText.getGlobalBounds().width + 5, m_avgElixirCostText.getPosition().y - 1);

	m_elixirCostSprite.setTexture(Resources::instance().getCommonImg(Resources::ELIXIR));
	m_elixirCostSprite.setScale(0.35f, 0.35f);

	int x = m_deckTextBackground.getPosition().x + 4;
	int y = m_deckTextBackground.getPosition().y + m_deckTextBackground.getSize().y + 20;

	for (int i = 0; i < DECK_CARDS; i++)
	{
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(100, 120));
		rect.setFillColor(sf::Color(94, 65, 44, 100));
		rect.setOutlineColor(sf::Color(76, 52, 31, 255));
		rect.setOutlineThickness(2);
		rect.setPosition(x, y);

		x += rect.getSize().x + 30;

		if (i == 3)
		{
			x = m_deckTextBackground.getPosition().x;
			y += m_cardsTemplate[0].getSize().y + 60;
		}

		m_cardsTemplate.push_back(rect);
	}

	// Pushing to the vector all the cards that exist in the collection, when the last 4 cards aren't 
	// availble for the user at the beginning of the game 
	m_cardsCollection.push_back(std::shared_ptr<Card>(new Knight(1)));
	m_cardsCollection.push_back(std::shared_ptr<Card>(new Archers(1)));
	m_cardsCollection.push_back(std::shared_ptr<Card>(new Minions(1)));
	m_cardsCollection.push_back(std::shared_ptr<Card>(new Arrows(1)));
	m_cardsCollection.push_back(std::shared_ptr<Card>(new Fireball(1)));
	m_cardsCollection.push_back(std::shared_ptr<Card>(new Giant(1)));
	m_cardsCollection.push_back(nullptr);
	m_cardsCollection.push_back(nullptr);
	m_cardsCollection.push_back(std::shared_ptr<Card>(new Valkyrie(1)));
	m_cardsCollection.push_back(std::shared_ptr<Card>(new DartGoblin(1)));
	m_cardsCollection.push_back(std::shared_ptr<Card>(new Freeze(1)));
	m_cardsCollection.push_back(std::shared_ptr<Card>(new Pekka(1)));


	for (int i = 0; i < m_cardsCollection.size(); i++)
	{
		if (m_cardsCollection[i] != nullptr && i < DECK_CARDS)
		{
			m_cardsCollection[i]->setCardImgPos(m_cardsTemplate[i].getPosition().x - 4, m_cardsTemplate[i].getPosition().y - 4);
		}
		else if (i >= DECK_CARDS)
		{
			auto currCard = m_cardsCollection[i - DECK_SIZE]->getCardImg();
			m_cardsCollection[i]->setCardImgPos(currCard.getPosition().x, currCard.getPosition().y + m_deckBackground.getSize().y + m_collectionTextBackground.getSize().y + 30);
		}
	}

	m_player->setDeck(m_cardsCollection);


	auto collectionCard = m_cardsCollection[DECK_STARTER_CARDS + 2]->getCardImg();

	int x2 = collectionCard.getPosition().x;
	int y2 = collectionCard.getPosition().y;

	for (int i = 0; i < COLLECTION_CARDS - DECK_STARTER_CARDS; i++)
	{
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(collectionCard.getGlobalBounds().width, collectionCard.getGlobalBounds().height));
		rect.setFillColor(sf::Color(0, 0, 0, 120));
		rect.setPosition(x2, y2);

		x2 += rect.getSize().x + 20;

		m_noColorCards.push_back(rect);
	}
}

// This function builds a specific title in the Collection page:
void CardsPage::buildCollection(sf::RenderWindow& window)
{
	m_collectionTextBackground.setSize(sf::Vector2f(500, 40));
	m_collectionTextBackground.setFillColor(sf::Color(73, 41, 23, 255));

	m_collection.setFont(Resources::instance().getFont());
	m_collection.setString("Card Collection");
	m_collection.setCharacterSize(20);
	m_collection.setFillColor(sf::Color::White);
	m_collection.setOutlineThickness(1);
	m_collection.setOutlineColor(sf::Color::Black);

	m_foundCards.setFont(Resources::instance().getFont());
	m_foundCards.setString("Found:");
	m_foundCards.setCharacterSize(13);
	m_foundCards.setFillColor(sf::Color(244, 168, 176, 255));
	m_foundCards.setOutlineThickness(1);
	m_foundCards.setOutlineColor(sf::Color::Black);

	m_availableCards.setFont(Resources::instance().getFont());
	m_availableCards.setCharacterSize(13);
	m_availableCards.setFillColor(sf::Color::White);
	m_availableCards.setOutlineThickness(1);
	m_availableCards.setOutlineColor(sf::Color::Black);
}

void CardsPage::getMouseClick(const sf::Vector2f location, sf::RenderWindow& window)
{
	for (int i = 0; i < m_cardsCollection.size() - 1; i++)
	{
		if (m_cardsCollection[i] != nullptr)
		{
			if (m_cardsCollection[i]->getRemoveCard().getGlobalBounds().contains(location))
			{
				removeCardHandler(i);
				m_player->setDeck(m_cardsCollection);
			}
			else if (i < DECK_CARDS && (m_cardsCollection[i]->getUpgradeBar().getGlobalBounds().contains(location) ||
				m_cardsCollection[i]->getUpgradeIcon().getGlobalBounds().contains(location)))
			{
				if (m_player->upgradeCardHandler(i))
					m_upgradeCardSound.play();
			}
		}
	}

	for (int i = 0; i < m_cardsCollection.size(); i++)
	{
		if (m_cardsCollection[i] != nullptr && m_cardsCollection[i]->getAddCard().getGlobalBounds().contains(location))
		{
			addCardHandler(i);
			m_player->setDeck(m_cardsCollection);
		}
	}
}

// This function removes a card from the player's deck in the Collection page:
void CardsPage::removeCardHandler(const int clickedIndex)
{
	m_deckCardsCount--;
	m_cardsCollection.push_back(m_cardsCollection[clickedIndex]);

	auto previousCard = m_cardsCollection[m_cardsCollection.size() - 2]->getCardImg();
	m_cardsCollection[m_cardsCollection.size() - 1]->setCardImgPos(previousCard.getPosition().x + previousCard.getGlobalBounds().width + 20, previousCard.getPosition().y);

	m_cardsCollection.erase(m_cardsCollection.begin() + clickedIndex);

	if (DECK_CARDS - m_deckCardsCount >= 1)
		m_cardsCollection.insert(m_cardsCollection.begin() + m_deckCardsCount, nullptr);

	for (int i = 0; i < m_cardsCollection.size(); i++)
	{
		if (m_cardsCollection[i] != nullptr && i < DECK_CARDS)
		{
			m_cardsCollection[i]->setCardImgPos(m_cardsTemplate[i].getPosition().x - 4, m_cardsTemplate[i].getPosition().y - 4);
		}
	}
}

// This function adds a card to the player's deck in the Collection page:
void CardsPage::addCardHandler(const int clickedIndex)
{
	auto cardToAdd = m_cardsCollection[clickedIndex];
	m_cardsCollection.erase(m_cardsCollection.begin() + clickedIndex);
	m_cardsCollection.insert(m_cardsCollection.begin() + m_deckCardsCount, cardToAdd);

	auto previousCard = m_cardsCollection[m_deckCardsCount - 1]->getCardImg();
	m_cardsCollection[m_deckCardsCount]->setCardImgPos(previousCard.getPosition().x + previousCard.getGlobalBounds().width + 20, previousCard.getPosition().y);

	m_deckCardsCount++;

	for (int i = DECK_CARDS; i < m_cardsCollection.size(); i++)
	{
		if (m_cardsCollection[i] == nullptr)
			m_cardsCollection.erase(m_cardsCollection.begin() + i);
	}

	for (int i = DECK_CARDS; i < m_cardsCollection.size(); i++)
	{
		if (m_cardsCollection[i] != nullptr)
			m_cardsCollection[i]->setCardImgPos(m_noColorCards[i - DECK_CARDS].getPosition().x - 4, m_noColorCards[i - DECK_CARDS].getPosition().y - 4);
	}
}

// This function is responsible for updating the details in the Collection page:
void CardsPage::setDynamic(sf::RenderWindow& window)
{
	if (!*m_initialized)
	{
		m_player->clearAvailableCards();
		for (auto& card : m_cardsCollection)
			if (card && m_player->getTrophies() >= card->getUnlockedInTrophies())
				m_player->setAvailableCards();

		*m_initialized = true;
	}


	double elixirAvg = getElixirAvg();
	int mulBy10 = int(elixirAvg * 10);
	int reminder = mulBy10 % 10;
	std::string avg = std::to_string(int(elixirAvg)) + "." + std::to_string(reminder);

	m_avgElixirCost.setString(avg);
	m_elixirCostSprite.setPosition(m_avgElixirCost.getPosition().x + m_avgElixirCost.getGlobalBounds().width + 7, m_deckTextBackground.getPosition().y);

	for (int i = 0; i < m_cardsCollection.size(); i++)
	{
		if (m_cardsCollection[i] != nullptr)
			m_cardsCollection[i]->setCardDynamic();
	}

	m_collectionTextBackground.setPosition(m_deckBackground.getPosition().x + (m_deckBackground.getSize().x / 2) - (m_deckTextBackground.getSize().x / 2), m_deckBackground.getPosition().y + m_deckBackground.getSize().y + 30);
	m_collection.setPosition(m_deckTextBackground.getPosition().x + 10, m_collectionTextBackground.getPosition().y + 8);

	std::string availableCards = std::to_string(m_player->getAvailableCards()) + "/" + std::to_string(COLLECTION_CARDS);

	m_availableCards.setString(availableCards);
	m_availableCards.setPosition(m_collectionTextBackground.getPosition().x + m_collectionTextBackground.getSize().x - m_foundCards.getGlobalBounds().width - 2, m_collectionTextBackground.getPosition().y + (m_collectionTextBackground.getSize().y / 2) - (m_foundCards.getGlobalBounds().height / 2));
	m_foundCards.setPosition(m_availableCards.getPosition().x - m_foundCards.getGlobalBounds().width - 5, m_availableCards.getPosition().y);

	draw(window);
}

double CardsPage::getElixirAvg() const
{
	double sum = 0;
	int count = 0;

	for (int i = 0; i < DECK_CARDS; i++)
	{
		if (m_cardsCollection[i] != nullptr)
		{
			count++;
			sum += m_cardsCollection[i]->getElixirCost();
		}
	}

	return (sum / count);
}

void CardsPage::draw(sf::RenderWindow& window)
{
	window.draw(m_deckBackground);
	window.draw(m_deckTextBackground);
	window.draw(m_deck);
	window.draw(m_avgElixirCostText);
	window.draw(m_avgElixirCost);
	window.draw(m_elixirCostSprite);

	for (auto cardContainer : m_cardsTemplate)
		window.draw(cardContainer);

	for (int i = 0; i < m_cardsCollection.size(); i++)
	{
		if (m_cardsCollection[i] != nullptr)
		{
			window.draw(m_cardsCollection[i]->getCardImg());

			if (m_player->getTrophies() >= m_cardsCollection[i]->getUnlockedInTrophies())
			{
				window.draw(m_cardsCollection[i]->getElixirCostSprite());
				window.draw(m_cardsCollection[i]->getElixirCostText());
				window.draw(m_cardsCollection[i]->getLevelBackground());
				window.draw(m_cardsCollection[i]->getLevelText());

				if (i >= DECK_CARDS && m_cardsCollection.size() > COLLECTION_CARDS)
				{
					m_cardsCollection[i]->getRemoveCard().setPosition(-100, -100);
					window.draw(m_cardsCollection[i]->getAddCard());
				}
			}

			// in deck
			if (i < DECK_CARDS)
			{
				if (m_cardsCollection[i]->getLevel() == LEVELS)
				{
					m_cardsCollection[i]->getUpgradeBar().setPosition(-100, -100);
					m_cardsCollection[i]->getUpgradeCoin().setPosition(-100, -100);
				}
				else
				{
					window.draw(m_cardsCollection[i]->getUpgradeBar());
					window.draw(m_cardsCollection[i]->getUpgradeIcon());
					window.draw(m_cardsCollection[i]->getUpgradeCostText());
					window.draw(m_cardsCollection[i]->getUpgradeCoin());
				}

				if (m_deckCardsCount > DECK_STARTER_CARDS)
				{
					m_cardsCollection[i]->getAddCard().setPosition(-100, -100);
					window.draw(m_cardsCollection[i]->getRemoveCard());
				}
			}

			// in collection - card is unable
			if (i >= DECK_CARDS && m_player->getTrophies() < m_cardsCollection[i]->getUnlockedInTrophies())
				window.draw(m_noColorCards[i - DECK_CARDS]);

		}
	}

	window.draw(m_collectionTextBackground);
	window.draw(m_collection);
	window.draw(m_foundCards);
	window.draw(m_availableCards);
}