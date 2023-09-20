#include "Window.h"

Window::Window()
    : m_window(sf::VideoMode(windowWidth, windowHeight), "Clash Royale", sf::Style::Titlebar | sf::Style::Close),
    m_battleMode(false),
    m_controller(Controller(m_window, m_battleMode, m_player, m_soundLevel)),
    m_arenaBattle(ArenaBattle(m_window, m_battleMode, m_player))
{}


void Window::run()
{
    sf::Vector2f location = { -1, -1 };
    sf::Event event;

    while (m_window.isOpen())
    {
        while (m_window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased:
            {
                location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                if (m_battleMode)
                    m_arenaBattle.getMouseClick(location, m_window);
                else
                    m_controller.getMouseClick(location, m_window);
            }
            }
        }

        m_window.clear();

        if (m_battleMode)
        {
            m_arenaBattle.setDynamic(m_window, m_soundLevel);
        }
        else
        {
            m_controller.setDynamic(m_window);
            m_controller.drawFrame(m_window);
            m_controller.drawCurrPage(m_window);
        }

        m_window.display();
    }
}
