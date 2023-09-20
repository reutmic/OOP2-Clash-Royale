#include "InfoPage.h"

InfoPage::InfoPage(sf::RenderWindow& window)
	:m_textCounter(1)
{
	m_rightArrow.setTexture(Resources::instance().getInfoPageItem(Resources::RIGHT_ARROW));
	m_rightArrow.setPosition((window.getSize().x / 2) - (m_rightArrow.getGlobalBounds().width / 2) + 60, window.getSize().y - 150);
	m_rightArrow.setScale(0.8f, 0.8f);

	m_leftArrow.setTexture(Resources::instance().getInfoPageItem(Resources::LEFT_ARROW));
	m_leftArrow.setPosition((window.getSize().x / 2) - (m_leftArrow.getGlobalBounds().width / 2) - 60, window.getSize().y - 150);
	m_leftArrow.setScale(0.8f, 0.8f);

	m_headLine.setFont(Resources::instance().getFont());
	m_headLine.setCharacterSize(20);
	m_headLine.setFillColor(sf::Color::White);
	m_headLine.setOutlineColor(sf::Color::Black);
	m_headLine.setOutlineThickness(3);
	m_headLine.setString("Game instructions: ");
	m_headLine.setPosition((window.getSize().x / 2) - (m_headLine.getGlobalBounds().width/2), 70);

	m_subHeadLine1.setFont(Resources::instance().getFont());
	m_subHeadLine1.setCharacterSize(16);
	m_subHeadLine1.setFillColor(sf::Color(248, 183, 56));
	m_subHeadLine1.setOutlineColor(sf::Color::Black);
	m_subHeadLine1.setOutlineThickness(3);
	m_subHeadLine1.setString("Cards, trophies and coins: ");
	m_subHeadLine1.setPosition(30, m_headLine.getPosition().y + 60);

	m_subHeadLine2.setFont(Resources::instance().getFont());
	m_subHeadLine2.setCharacterSize(16);
	m_subHeadLine2.setFillColor(sf::Color(248, 183, 56));
	m_subHeadLine2.setOutlineColor(sf::Color::Black);
	m_subHeadLine2.setOutlineThickness(3);
	m_subHeadLine2.setString("The battles: ");

	for (int i = 0; i < INFO_TEXTS; i++)
	{
		sf::Text text;

		text.setFont(Resources::instance().getFont());
		text.setCharacterSize(14);
		text.setFillColor(sf::Color::White);
		text.setOutlineColor(sf::Color::Black);
		text.setOutlineThickness(2);
		text.setLineSpacing(1.3f);

		m_infoTexts.push_back(text);
	}

	m_infoTexts[0].setString(/*"The purpose of this game is tooooooooooooooooooooooo\n"*/
							   "Your goal in this game is to destroy your enemy towers.\n\n"
							   "For this purpose you have a collection of cards. each card\n"
							   "represents a game object.\n"
							   "The cards are divided into two sections:\n"
							   "1. Troop cards        2. Spell cards\n"
							   "Troop objects are the ground and air warriors, and the\n"
							   "spell objects are special effects, such as fireball.\n"
							   "The cards have properties such as meazure of attack,\n"
							   "amount of lives and speed.\n\n"
							   "As a starter pack you get 6 cards. Winning battles gives\n"
							   "you trophies, and the more trophies you have, the more\n"
							   "cards that will get unlocked for you.\n\n"
							   "In the collection page you can view your collection and edit\n"
							   "your deck. deck is the only 8 cards from your collection\n"
							   "that you will be able to use in the battles.\n");
	m_infoTexts[0].setPosition(30, m_subHeadLine1.getPosition().y + 60);

	m_infoTexts[1].setString("Another thing you can do in the collection page is to\n"
						     "upgarde your cards. As the card level increases, its\n"
						     "properties get improved and will increase your chances to\n"
						     "win the game. In order to upgrade a card you need pay\n"
						     "with your coins that you get in each battle winning or not\n"
						     "losing (draw).\n"
							 "Each card also has a property called 'elixir', but we will get\n"
	                         "to that later.\n");
	m_infoTexts[1].setPosition(30, m_headLine.getPosition().y + 60);
	m_subHeadLine2.setPosition(30, m_infoTexts[1].getPosition().y + m_infoTexts[1].getGlobalBounds().height + 10);

	m_infoTexts[2].setString("In this game, each level is called an 'arena'. There are 4\n"
		                     "arenas, and in order to move to the next arena, you have\n"
		                     "to win a battle (or not loose).\n\n"
		                     "You have 6 lives, and in each battle lose, you lose one life.\n\n"
		                     "As you start a battle, you will see 4 cards from your deck.\n"
		                     "Each time you pick a card and use it in the battle, a new\n"
		                     "card from your deck will replace the card you picked in\n"
		                     "the 4 cards display.\n"
		                     );
	m_infoTexts[2].setPosition(30, m_subHeadLine2.getPosition().y + 60);

	m_infoTexts[3].setString("Under the 4 cards display you will see the elixir bar.\n"
							 "As I mentioned, each card has its property of elixir cost,\n"
							 "and when you pick a card and use it in the battle, the\n"
							 "amount of its elixir cost will get decreased from the elixir\n"
							 "bar. When there are less than 10 elixirs in the elixir bar,\n"
							 "a new elixir will be added to the bar every second.\n\n"
							 "Every time you use a spell card, a blue circle will be placed\n"
		                     "in that position, and if your enemy used a spell card\n"
		                     "against you, a red circle will be placed in that position.\n\n"
		                     "Each battle has a timer of 3 minutes.\n"
		                     "Each player has 3 towers, 2 regular sized and one big.\n"
							 "tower\n\n"
		                     "The battle ends if:\n"
		                     "1. One of the big towers got distroyed\n"
		                     "2. All three towers of a player got distroyed\n"
		                     "3. The battle time is up\n"
		                     "Then the achievements in the battle are measured, and\n"
		                     "the winner gets announced.\n"
							 );
	m_infoTexts[3].setPosition(30, m_headLine.getPosition().y + 60);

}


void InfoPage::getMouseClick(const sf::Vector2f location, sf::RenderWindow& window)
{
	if (m_rightArrow.getGlobalBounds().contains(location) && m_textCounter < 3)
	{
		m_textCounter++;
	}
	else if (m_leftArrow.getGlobalBounds().contains(location) && m_textCounter > 1)
	{
		m_textCounter--;
	}
}		


void InfoPage::setDynamic(sf::RenderWindow& window)
{

	draw(window);
}


void InfoPage::draw(sf::RenderWindow& window)
{
	window.draw(m_headLine);

	switch (m_textCounter)
	{
	case 1:
		window.draw(m_subHeadLine1);
		window.draw(m_infoTexts[0]);
		break;
	case 2:
		window.draw(m_infoTexts[1]);
		window.draw(m_subHeadLine2);
		window.draw(m_infoTexts[2]);
		break;
	case 3:
		window.draw(m_infoTexts[3]);
		break;
	}
	if (m_textCounter < INFO_TEXTS-1)
		window.draw(m_rightArrow);

	window.draw(m_leftArrow);
}