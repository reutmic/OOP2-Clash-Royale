#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Card.h"

const int PC_DECK_SIZE = 8;
const int PC_COLLECTION_SIZE = 10;
const int PC_CURR_VISIBLE_DECK_SIZE = 4;

class Pc
{
public:
	Pc();

	void setDeck(std::vector<std::shared_ptr<Card>> collection, const int playerTrophies, const int availableCards, const int arena);
	void setCurrDeckCards();
	std::vector<std::shared_ptr<Card>> getDeck();
	std::vector<std::shared_ptr<Card>> getCurrDeck();
	void addToCurrDeck(const int cardIndex);

private:
	int m_arena;
	std::vector<std::shared_ptr<Card>> m_deck;
	std::vector<std::shared_ptr<Card>> m_currDeck;
	bool m_pickedCards[PC_COLLECTION_SIZE];
};