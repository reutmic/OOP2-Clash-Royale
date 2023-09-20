#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Card.h"

const int DECK_SIZE = 8;
const int CURR_VISIBLE_DECK_SIZE = 4;
const int DECK_STARTER_CARDS = 6;

class Player
{
public:
	Player();
	int getArena() const;
	int getTrophies() const;
	int getCoins() const;
	int getLives() const;
	std::string getName() const;
	void setDeck(std::vector<std::shared_ptr<Card>> deck);
	void setCurrDeckCards();
	void setArena();
	void setTrophies(const int trophies);
	void setCoins(const int coins);
	void decLives();
	std::vector<std::shared_ptr<Card>> getDeck();
	std::vector<std::shared_ptr<Card>> getCurrDeck();
	std::vector<std::shared_ptr<Card>> getCollection();
	void setDeckBackgroundPosition(const sf::Vector2f position);
	void addToCurrDeck(const int cardIndex);
	int getAvailableCards() const;
	bool upgradeCardHandler(const int cardIndex);
	void setAvailableCards();
	void clearAvailableCards();

private:
	int m_arena;
	int m_trophies;
	int m_coins;
	int m_lives;
	std::string m_name;
	std::vector<std::shared_ptr<Card>> m_collection;
	std::vector<std::shared_ptr<Card>> m_deck;
	std::vector<std::shared_ptr<Card>> m_currDeck;
	bool m_pickedCards[DECK_SIZE];
	sf::Vector2f m_deckBackgroundPosition;
	int m_availableCards;
};