#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "View.h"
#include "Card.h"
#include "Knight.h"
#include "Archers.h"
#include "Minions.h"
#include "Arrows.h"
#include "Fireball.h"
#include "Giant.h"
#include "Pekka.h"
#include "Freeze.h"
#include "Valkyrie.h"
#include "DartGoblin.h"

const int DECK_CARDS = 8;
const int COLLECTION_CARDS = 10;

class CardsPage : public View
{
public:
    CardsPage(sf::RenderWindow& window, Player& player, bool& initializied);
    void buildDeck(sf::RenderWindow& window);
    void buildCollection(sf::RenderWindow& window);
    void setDynamic(sf::RenderWindow& window) override;
    double getElixirAvg() const;
    void getMouseClick(const sf::Vector2f location, sf::RenderWindow& window) override;
    void removeCardHandler(const int clickedIndex);
    void addCardHandler(const int clickedIndex);
    void draw(sf::RenderWindow& window) override;

private:
    Player* m_player;
    sf::RectangleShape m_deckBackground;
    sf::RectangleShape m_deckTextBackground;
    sf::Text m_deck;
    sf::Text m_avgElixirCostText;
    sf::Text m_avgElixirCost;
    sf::Sprite m_elixirCostSprite;
    std::vector<sf::RectangleShape> m_cardsTemplate;
    std::vector<sf::RectangleShape> m_noColorCards;
    std::vector<std::shared_ptr<Card>> m_cardsCollection;
    sf::RectangleShape m_collectionTextBackground;
    sf::Text m_collection;
    sf::Text m_foundCards;
    sf::Text m_availableCards;
    int m_deckCardsCount;
    sf::Sound m_upgradeCardSound;
    bool* m_initialized;
};
