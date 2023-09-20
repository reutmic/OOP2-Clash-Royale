#include "Controller.h"
#include "Resources.h"

Controller::Controller(sf::RenderWindow& window, bool& battleMode, Player& player, int& soundLevel)
    :m_currPage(BATTLE), m_initialized(false), m_cardsPageInitializied(false)
{
    m_player = &player;

    m_backgroundSprite1.setTexture(Resources::instance().getMenuFrameItem(Resources::BACKGROUND));
    m_backgroundSprite1.setPosition(0, 0);
    m_backgroundSprite1.setScale(0.65f, 0.65f);

    m_backgroundSprite2.setTexture(Resources::instance().getMenuFrameItem(Resources::BACKGROUND));
    m_backgroundSprite2.setPosition(520, 0);
    m_backgroundSprite2.setScale(0.65f, 0.65f);

    buildCurrencies(window);
    buildNavBar(window);

    m_sound.setBuffer(Resources::instance().getSound(Resources::MENU));

    m_views.push_back(std::make_unique<CardsPage>(window, *m_player, m_cardsPageInitializied));
    m_views.push_back(std::make_unique<BattlePage>(window, *m_player, battleMode, m_sound, m_initialized, soundLevel));
    m_views.push_back(std::make_unique<InfoPage>(window));
}


void Controller::playSound()
{
    m_sound.setLoop(true);
    m_sound.play();
}


void Controller::buildNavBar(sf::RenderWindow& window)
{
    m_navBar1.setSize(sf::Vector2f((window.getSize().x) / 3, 85));
    m_navBar1.setFillColor(sf::Color(52, 64, 83, 255));
    m_navBar1.setPosition(0, 815);

    m_navBar2.setSize(sf::Vector2f((window.getSize().x) / 3, 85));
    m_navBar2.setFillColor(sf::Color(72, 84, 103, 255));
    m_navBar2.setPosition((window.getSize().x) / 3, 815);

    m_navBar3.setSize(sf::Vector2f((window.getSize().x) / 3, 85));
    m_navBar3.setFillColor(sf::Color(52, 64, 83, 255));
    m_navBar3.setPosition(((window.getSize().x) / 3) * 2, 815);

    m_navBarUpperLine.setSize(sf::Vector2f(window.getSize().x, 2));
    m_navBarUpperLine.setFillColor(sf::Color(88, 104, 124, 255));
    m_navBarUpperLine.setPosition(0, 815);

    m_navBarVerticalLine1.setSize(sf::Vector2f(2, m_navBar1.getSize().y));
    m_navBarVerticalLine1.setFillColor(sf::Color(95, 102, 111, 255));
    m_navBarVerticalLine1.setPosition(m_navBar1.getSize().x, 815 + m_navBarUpperLine.getSize().y + 1);

    m_navBarVerticalLine2.setSize(sf::Vector2f(2, m_navBar2.getSize().y));
    m_navBarVerticalLine2.setFillColor(sf::Color(95, 102, 111, 255));
    m_navBarVerticalLine2.setPosition(m_navBarVerticalLine1.getPosition().x + m_navBar2.getSize().x, 815 + m_navBarUpperLine.getSize().y + 1);

    m_navBarBattleSprite.setTexture(Resources::instance().getMenuFrameItem(Resources::BATTLE));
    m_navBarBattleSprite.setScale(0.35f, 0.35f);

    m_navBarCardsSprite.setTexture(Resources::instance().getMenuFrameItem(Resources::COLLECTION));
    m_navBarCardsSprite.setScale(0.33f, 0.33f);

    m_navBarInfoSprite.setTexture(Resources::instance().getMenuFrameItem(Resources::INSTRUCTIONS));
    m_navBarInfoSprite.setScale(0.32f, 0.32f);

    m_navBarCardsSprite.setPosition(85, m_navBar1.getPosition().y + 5);
    m_navBarBattleSprite.setPosition(m_navBar2.getSize().x + 85, m_navBar1.getPosition().y + 2);
    m_navBarInfoSprite.setPosition(m_navBar2.getSize().x + m_navBar3.getSize().x + 87, m_navBar3.getPosition().y + 5);

    m_navBarBattleText.setFont(Resources::instance().getFont());
    m_navBarBattleText.setString("Battle");
    m_navBarBattleText.setCharacterSize(14);
    m_navBarBattleText.setFillColor(sf::Color::White);
    m_navBarBattleText.setOutlineThickness(1);
    m_navBarBattleText.setOutlineColor(sf::Color(11, 13, 14, 255));
    m_navBarBattleText.setPosition(m_navBar2.getSize().x + 83, m_navBar2.getPosition().y + 65);

    m_navBarCardsText.setFont(Resources::instance().getFont());
    m_navBarCardsText.setString("Collection");
    m_navBarCardsText.setCharacterSize(14);
    m_navBarCardsText.setFillColor(sf::Color::White);
    m_navBarCardsText.setOutlineThickness(1);
    m_navBarCardsText.setOutlineColor(sf::Color(11, 13, 14, 255));
    m_navBarCardsText.setPosition(58, m_navBar1.getPosition().y + 65);

    m_navBarInfoText.setFont(Resources::instance().getFont());
    m_navBarInfoText.setString("Instructions");
    m_navBarInfoText.setCharacterSize(14);
    m_navBarInfoText.setFillColor(sf::Color::White);
    m_navBarInfoText.setOutlineThickness(1);
    m_navBarInfoText.setOutlineColor(sf::Color(11, 13, 14, 200));
    m_navBarInfoText.setPosition(m_navBar2.getSize().x + m_navBar3.getSize().x + 44, m_navBar3.getPosition().y + 65);
}

// This function build the coins and trophies section at the top-right corner of the menu:
void Controller::buildCurrencies(sf::RenderWindow& window)
{
    int posX = 20, posY = 14;

    for (int i = 0; i < m_player->getLives(); i++)
    {
        sf::Sprite heart;
        heart.setTexture(Resources::instance().getMenuFrameItem(Resources::HEART));
        heart.setScale(1.1f, 1.1f);
        heart.setPosition(posX, posY);

        m_hearts.push_back(heart);
        posX += 33;
    }

    m_currencies1.setSize(sf::Vector2f(100, 30));
    m_currencies1.setFillColor(sf::Color(3, 13, 22, 250));
    m_currencies1.setPosition(window.getSize().x - m_currencies1.getSize().x - 20, 10);

    m_currenciesLighter1.setSize(sf::Vector2f(100, 10));
    m_currenciesLighter1.setFillColor(sf::Color(60, 71, 78, 100));
    m_currenciesLighter1.setPosition(window.getSize().x - m_currencies1.getSize().x - 20, 12);

    m_coinSprite.setPosition(window.getSize().x - 43, 8);
    m_trophySprite.setPosition(window.getSize().x - m_currencies1.getSize().x - 63, 8);


    m_currencies2.setSize(sf::Vector2f(100, 30));
    m_currencies2.setFillColor(sf::Color(3, 13, 22, 250));
    m_currencies2.setPosition(window.getSize().x - (m_currencies2.getSize().x) * 2 - 40, 10);

    m_currenciesLighter2.setSize(sf::Vector2f(100, 10));
    m_currenciesLighter2.setFillColor(sf::Color(60, 71, 78, 100));
    m_currenciesLighter2.setPosition(window.getSize().x - (m_currencies2.getSize().x) * 2 - 40, 12);

    m_coinSprite.setTexture(Resources::instance().getCommonImg(Resources::COIN));
    m_coinSprite.setScale(0.47f, 0.47f);

    m_coinsNum.setFont(Resources::instance().getFont());
    m_coinsNum.setCharacterSize(14);
    m_coinsNum.setFillColor(sf::Color::White);
    m_coinsNum.setPosition(m_currencies1.getPosition().x + 10, m_currencies1.getPosition().y + 7);

    m_trophySprite.setTexture(Resources::instance().getMenuFrameItem(Resources::TROPHIES));
    m_trophySprite.setScale(0.27f, 0.27f);

    m_trophiesNum.setFont(Resources::instance().getFont());
    m_trophiesNum.setCharacterSize(14);
    m_trophiesNum.setFillColor(sf::Color::White);
    m_trophiesNum.setPosition(m_currencies2.getPosition().x + 10, m_currencies2.getPosition().y + 7);
}

// This function sets and updates the details that appear in every page of the menu:
void Controller::setDynamic(sf::RenderWindow& window)
{
    if (!m_initialized)
    {
        playSound();
        m_initialized = true;
    }
    m_coinsNum.setString(std::to_string(m_player->getCoins()));
    m_trophiesNum.setString(std::to_string(m_player->getTrophies()));

    drawFrame(window);
}

// This function draws the details that appear in every page of the menu:
void Controller::drawFrame(sf::RenderWindow& window)
{
    window.draw(m_backgroundSprite1);
    window.draw(m_backgroundSprite2);
    for (int i = 0; i < m_player->getLives(); i++)
        window.draw(m_hearts[i]);
    window.draw(m_currencies1);
    window.draw(m_currenciesLighter1);
    window.draw(m_coinSprite);
    window.draw(m_coinsNum);
    window.draw(m_currencies2);
    window.draw(m_currenciesLighter2);
    window.draw(m_trophySprite);
    window.draw(m_trophiesNum);
    window.draw(m_navBar1);
    window.draw(m_navBar2);
    window.draw(m_navBar3);
    window.draw(m_navBarUpperLine);
    window.draw(m_navBarVerticalLine1);
    window.draw(m_navBarVerticalLine2);
    window.draw(m_navBarCardsSprite);
    window.draw(m_navBarBattleSprite);
    window.draw(m_navBarInfoSprite);
    window.draw(m_navBarCardsText);
    window.draw(m_navBarBattleText);
    window.draw(m_navBarInfoText);
}

void Controller::drawCurrPage(sf::RenderWindow& window)
{
    m_views[m_currPage]->setDynamic(window);
}

// The following three functions resets the chosen page button in the menu navigation bar:
void Controller::resetCardsBtn()
{
    m_navBar1.setFillColor(sf::Color(52, 64, 83, 255));
    m_navBarCardsSprite.setPosition(85, m_navBar1.getPosition().y + 5);
}

void Controller::resetBattleBtn()
{
    m_navBar2.setFillColor(sf::Color(52, 64, 83, 255));
    m_navBarBattleSprite.setPosition(m_navBar2.getSize().x + 85, m_navBar1.getPosition().y + 5);
}

void Controller::resetInfoBtn()
{
    m_navBar3.setFillColor(sf::Color(52, 64, 83, 255));
    m_navBarInfoSprite.setPosition(m_navBar2.getSize().x + m_navBar3.getSize().x + 87, m_navBar3.getPosition().y + 5);
}


void Controller::getMouseClick(const sf::Vector2f location, sf::RenderWindow& window)
{
    if (m_navBar1.getGlobalBounds().contains(location))
    {
        m_cardsPageInitializied = false;
        m_currPage = CARDS;
        resetBattleBtn();
        resetInfoBtn();
        m_navBar1.setFillColor(sf::Color(72, 84, 103, 255));
        m_navBarCardsSprite.setPosition(m_navBarCardsSprite.getPosition().x, m_navBar1.getPosition().y + 2);
    }
    else if (m_navBar2.getGlobalBounds().contains(location))
    {
        m_currPage = BATTLE;
        resetCardsBtn();
        resetInfoBtn();
        m_navBar2.setFillColor(sf::Color(72, 84, 103, 255));
        m_navBarBattleSprite.setPosition(m_navBarBattleSprite.getPosition().x, m_navBar1.getPosition().y + 2);
    }
    else if (m_navBar3.getGlobalBounds().contains(location))
    {
        m_currPage = INFO;
        resetCardsBtn();
        resetBattleBtn();
        m_navBar3.setFillColor(sf::Color(72, 84, 103, 255));
        m_navBarInfoSprite.setPosition(m_navBarInfoSprite.getPosition().x, m_navBar1.getPosition().y + 2);
    }

    else
        m_views[m_currPage]->getMouseClick(location, window);
}