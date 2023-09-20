#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Resources.h"

const int LEVELS_NUM = 5;
const int STARTER_POS = 772;
const int CLICKED_POS = 765;
const int LEVELS = 5;
const int PRIORITY1 = 1;
const int PRIORITY2 = 2;
const int PRIORITY3 = 3;
const int PRIORITY4 = 4;
const int PRIORITY5 = 5;

class Card
{
public:
	Card();
	Card(int cardLevel);
	virtual std::shared_ptr<Card> clone(int cardLevel) = 0;
	virtual ~Card() = default;
	void setElixirCostData();
	void setCardDynamic();
	void setUpgradeBar();
	void setLevelDisplay();
	void setAddAndRemove();
	void setCardOutline();
	void cancelClickedCard();
	sf::Sprite& getCardImg();
	void setCardImgPos(const int x, const int y);
	void setCardImgScale(const float x, const float y);
	void setElixirDetails();
	void setClickedCard();
	double getElixirCost() const;
	int getUnlockedInTrophies() const;
	sf::Sprite& getElixirCostSprite();
	sf::Text& getElixirCostText();
	sf::RectangleShape& getUpgradeBar();
	sf::Sprite& getUpgradeIcon();
	sf::Text& getUpgradeCostText();
	sf::Sprite& getUpgradeCoin();
	sf::RectangleShape& getLevelBackground();
	sf::Text& getLevelText();
	sf::RectangleShape& getCardOutline();
	sf::Sprite& getAddCard();
	sf::Sprite& getRemoveCard();
	bool getTerritoryLimited() const;
	int getId() const;
	int getCurrUpgradeCost() const;
	int getLevel() const;
	void upgradeLevel();

	// This virtual function returns a card's priority for the PC algorithm: 
	virtual int getPriority() const = 0;

protected:
	int m_id;
	sf::Sprite m_cardImgSprite;
	sf::RectangleShape m_cardOutline;
	int m_elixirCost;
	int m_level = 1;
	sf::Vector2f m_cardImgScale = { 0.52f, 0.52f };
	int m_unlockedInTrophies;
	sf::Sprite m_elixirCostSprite;
	sf::Text m_elixirCostText;
	sf::RectangleShape m_upgradeCardBar;
	sf::Sprite m_upgradeIconSprite;
	std::vector<int> m_upgradesCosts;
	sf::Text m_upgradeCost;
	sf::Sprite m_upgradeCoinSprite;
	sf::RectangleShape m_levelBackground;
	sf::Text m_levelText;
	sf::Sprite m_addCardSprite;
	sf::Sprite m_removeCardSprite;
	bool m_territoryLimited;

private:
};