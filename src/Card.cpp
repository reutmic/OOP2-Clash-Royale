#include "Card.h"

Card::Card()
{
	setElixirCostData();
	setLevelDisplay();
	setUpgradeBar();
	setAddAndRemove();
}

Card::Card(const int cardLevel)
{
	m_level = cardLevel;
	setElixirCostData();
	setLevelDisplay();
	setUpgradeBar();
	setAddAndRemove();
}


void Card::setElixirCostData()
{
	m_elixirCostSprite.setTexture(Resources::instance().getCommonImg(Resources::ELIXIR));
	m_elixirCostSprite.setScale(0.32f, 0.32f);
	m_elixirCostText.setFont(Resources::instance().getFont());
	m_elixirCostText.setCharacterSize(15);
	m_elixirCostText.setFillColor(sf::Color::White);
	m_elixirCostText.setOutlineThickness(1);
	m_elixirCostText.setOutlineColor(sf::Color(101, 1, 124));
}


void Card::setUpgradeBar()
{
	m_upgradeCardBar.setFillColor(sf::Color(42, 152, 229, 255));
	m_upgradeCardBar.setOutlineThickness(2);
	m_upgradeCardBar.setOutlineColor(sf::Color(37, 25, 17, 255));

	m_upgradeIconSprite.setTexture(Resources::instance().getCardsPageItem(Resources::UPGRADE));
	m_upgradeIconSprite.setScale(0.45f, 0.45f);

	m_upgradeCost.setFont(Resources::instance().getFont());
	m_upgradeCost.setCharacterSize(12);
	m_upgradeCost.setFillColor(sf::Color(216, 253, 254, 255));
	m_upgradeCost.setOutlineThickness(1);
	m_upgradeCost.setOutlineColor(sf::Color::Black);

	m_upgradeCoinSprite.setTexture(Resources::instance().getCommonImg(Resources::COIN));
	m_upgradeCoinSprite.setScale(0.25f, 0.25f);
}

void Card::setLevelDisplay()
{
	m_levelBackground.setFillColor(sf::Color(0, 0, 0, 150));
	m_levelText.setFont(Resources::instance().getFont());
	m_levelText.setCharacterSize(12);
	m_levelText.setFillColor(sf::Color(152, 203, 253, 255));
	m_levelText.setOutlineColor(sf::Color::Black);
	m_levelText.setOutlineThickness(1);
}

// This function sets the '+' and '-' buttons for adding and removing a card from the player's deck:
void Card::setAddAndRemove()
{
	m_addCardSprite.setTexture(Resources::instance().getCardsPageItem(Resources::ADD));
	m_addCardSprite.setScale(0.53f, 0.53f);

	m_removeCardSprite.setTexture(Resources::instance().getCardsPageItem(Resources::REMOVE));
	m_removeCardSprite.setScale(0.53f, 0.53f);
}

// This function manages the positions and details appearances and changes in cards in the Collection page:
void Card::setCardDynamic()
{
	m_elixirCostText.setString(std::to_string(m_elixirCost));
	m_elixirCostSprite.setPosition(m_cardImgSprite.getPosition().x - 4, m_cardImgSprite.getPosition().y - 4);
	m_elixirCostText.setPosition(m_elixirCostSprite.getPosition().x + 8, m_elixirCostSprite.getPosition().y + 10);

	m_upgradeCardBar.setSize(sf::Vector2f(m_cardImgSprite.getGlobalBounds().width - 6, 20));
	m_upgradeCardBar.setPosition(m_cardImgSprite.getPosition().x + 3, m_cardImgSprite.getPosition().y + m_cardImgSprite.getGlobalBounds().height);

	m_upgradeIconSprite.setPosition(m_upgradeCardBar.getPosition().x - 10, m_upgradeCardBar.getPosition().y - 10);

	m_upgradeCost.setString(std::to_string(m_upgradesCosts[m_level - 1]));
	m_upgradeCost.setPosition(m_upgradeCardBar.getPosition().x + (m_upgradeCardBar.getSize().x / 2) - (m_upgradeCost.getGlobalBounds().width / 2), m_upgradeCardBar.getPosition().y + 3);

	m_upgradeCoinSprite.setPosition(m_upgradeCost.getPosition().x + m_upgradeCost.getGlobalBounds().width + 3, m_upgradeCost.getPosition().y - 2);

	m_levelBackground.setSize(sf::Vector2f(m_cardImgSprite.getGlobalBounds().width, 25));
	m_levelBackground.setPosition(m_cardImgSprite.getPosition().x, m_upgradeCardBar.getPosition().y - m_levelBackground.getSize().y - 2);

	std::string level = "Level " + std::to_string(m_level);
	m_levelText.setString(level);
	m_levelText.setPosition(m_levelBackground.getPosition().x + (m_levelBackground.getSize().x / 2) - (m_levelText.getGlobalBounds().width / 2), m_levelBackground.getPosition().y + (m_levelBackground.getSize().y / 2) - (m_levelText.getGlobalBounds().height / 2));

	m_addCardSprite.setPosition(m_elixirCostSprite.getPosition().x + m_cardImgSprite.getGlobalBounds().width - m_addCardSprite.getGlobalBounds().width + 12, m_elixirCostSprite.getPosition().y - 2);
	m_removeCardSprite.setPosition(m_elixirCostSprite.getPosition().x + m_cardImgSprite.getGlobalBounds().width - m_removeCardSprite.getGlobalBounds().width + 12, m_elixirCostSprite.getPosition().y - 2);
}


void Card::setCardOutline()
{
	m_cardOutline.setSize(sf::Vector2f(m_cardImgSprite.getGlobalBounds().width + 4, m_cardImgSprite.getGlobalBounds().height + 4));
	m_cardOutline.setPosition(m_cardImgSprite.getPosition().x - 2, m_cardImgSprite.getPosition().y - 2);
	m_cardOutline.setFillColor(sf::Color::White);
}

// This function is for emphasizing the card the user clicked on in the battle:
void Card::setClickedCard()
{
	setCardImgPos(m_cardImgSprite.getPosition().x, CLICKED_POS);
	setCardOutline();
	m_elixirCostSprite.setPosition(m_elixirCostSprite.getPosition().x, m_cardImgSprite.getPosition().y + m_cardImgSprite.getGlobalBounds().height - (0.75 * m_elixirCostSprite.getGlobalBounds().height));
	m_elixirCostText.setPosition(m_elixirCostText.getPosition().x, m_elixirCostSprite.getPosition().y + (m_elixirCostSprite.getGlobalBounds().height / 2) - (m_elixirCostText.getGlobalBounds().height / 2));
}

// This function cancels the card's emphasization when in battle:
void Card::cancelClickedCard()
{
	m_cardOutline.setFillColor(sf::Color::Transparent);
	setCardImgPos(m_cardImgSprite.getPosition().x, STARTER_POS);
	m_elixirCostSprite.setPosition(m_elixirCostSprite.getPosition().x, m_cardImgSprite.getPosition().y + m_cardImgSprite.getGlobalBounds().height - (0.75 * m_elixirCostSprite.getGlobalBounds().height));
	m_elixirCostText.setPosition(m_elixirCostText.getPosition().x, m_elixirCostSprite.getPosition().y + (m_elixirCostSprite.getGlobalBounds().height / 2) - (m_elixirCostText.getGlobalBounds().height / 2));
}


sf::Sprite& Card::getCardImg()
{
	return m_cardImgSprite;
}


void Card::setCardImgPos(const int x, const int y)
{
	m_cardImgSprite.setPosition(x, y);
}


void Card::setCardImgScale(const float x, const float y)
{
	m_cardImgSprite.setScale(x, y);
}


void Card::setElixirDetails()
{
	m_elixirCostSprite.setScale(0.25f, 0.25f);
	m_elixirCostSprite.setPosition(m_cardImgSprite.getPosition().x + (m_cardImgSprite.getGlobalBounds().width / 2) - (m_elixirCostSprite.getGlobalBounds().width / 2), m_cardImgSprite.getPosition().y + m_cardImgSprite.getGlobalBounds().height - (0.75 * m_elixirCostSprite.getGlobalBounds().height));
	m_elixirCostText.setPosition(m_elixirCostSprite.getPosition().x + (m_elixirCostSprite.getGlobalBounds().width / 2) - (m_elixirCostText.getGlobalBounds().width / 2), m_elixirCostSprite.getPosition().y + (m_elixirCostSprite.getGlobalBounds().height / 2) - (m_elixirCostText.getGlobalBounds().height / 2));
}


double Card::getElixirCost() const
{
	return m_elixirCost;
}

// This function returns the number of trophies needed in order for the player to use a card:
int Card::getUnlockedInTrophies() const
{
	return m_unlockedInTrophies;
}


sf::Sprite& Card::getElixirCostSprite()
{
	return m_elixirCostSprite;
}


sf::Text& Card::getElixirCostText()
{
	return m_elixirCostText;
}


sf::RectangleShape& Card::getUpgradeBar()
{
	return m_upgradeCardBar;
}


sf::Sprite& Card::getUpgradeIcon()
{
	return m_upgradeIconSprite;
}


sf::Text& Card::getUpgradeCostText()
{
	return m_upgradeCost;
}


sf::Sprite& Card::getUpgradeCoin()
{
	return m_upgradeCoinSprite;
}


sf::RectangleShape& Card::getLevelBackground()
{
	return m_levelBackground;
}


sf::Text& Card::getLevelText()
{
	return m_levelText;
}


sf::RectangleShape& Card::getCardOutline()
{
	return m_cardOutline;
}


sf::Sprite& Card::getAddCard()
{
	return m_addCardSprite;
}


sf::Sprite& Card::getRemoveCard()
{
	return m_removeCardSprite;
}


bool Card::getTerritoryLimited() const
{
	return m_territoryLimited;
}


int Card::getId() const
{
	return m_id;
}


int Card::getCurrUpgradeCost() const
{
	return m_upgradesCosts[m_level - 1];
}


int Card::getLevel() const
{
	return m_level;
}


void Card::upgradeLevel()
{
	m_level++;
}