
#include "Game.h"
#include <iostream>
#include <string>



Game::Game() :
	m_window{ sf::VideoMode{ 1920U, 1080U, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	srand(time(NULL));
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	setPositions();
}


Game::~Game()
{
}



void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::setPositions()
{
	
		attackers.setPos(sf::Vector2f(rand() % m_window.getSize().x, rand() % m_window.getSize().y));
		attackers.setUpRect(sf::Vector2f(100, 100), sf::Color::Blue);
		attackers.setNumAttackers(rand() % 30);
		attackers.setRangeVal(rand() % 30);
		m_welcomeMessage.setPosition(sf::Vector2f(attackers.getPos().x+25,attackers.getPos().y+25));
		m_welcomeMessage.setString(std::to_string(attackers.getNumOfAttackers()));
		m_rules.beginFuzzification(attackers.getNumOfAttackers(), attackers.getRangeVal());

		m_textAr[0].setString("Tiny : " + std::to_string(m_rules.getTiny()));
		m_textAr[1].setString("Small : " + std::to_string(m_rules.getSmall()));
		m_textAr[2].setString("Moderate : " + std::to_string(m_rules.getModerate()));
		m_textAr[3].setString("Large : " + std::to_string(m_rules.getLarge()));
		m_textAr[4].setString("Close : " + std::to_string(m_rules.getClose()));
		m_textAr[5].setString("Medium : " + std::to_string(m_rules.getMedium()));
		m_textAr[6].setString("Far : " + std::to_string(m_rules.getFar()));
		m_textAr[7].setString("Low : " + std::to_string(m_rules.getLow()));
		m_textAr[8].setString("Med : " + std::to_string(m_rules.getMed()));
		m_textAr[9].setString("Deploy Str : " + std::to_string(m_rules.getDeploy()));
		m_textAr[10].setString("Deploy Str : " + std::to_string(m_rules.getDeploy()));
		

}

void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
		
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		setPositions();
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear();
	
	//m_window.draw(m_logoSprite);
	for (int i = 0; i < 10; i++)
	{
		m_window.draw(m_textAr[i]);
	}
	m_window.draw(attackers.getRect());
	
	m_window.draw(m_welcomeMessage);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("SFML Game");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(36U);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);
	for (int i = 0; i < 10; i++)
	{
		m_textAr[i].setFont(m_ArialBlackfont);
		m_textAr[i].setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
		m_textAr[i].setPosition(40.0f, 40.0f*i);
		m_textAr[i].setCharacterSize(36U);
		m_textAr[i].setOutlineColor(sf::Color::Red);
		m_textAr[i].setFillColor(sf::Color::Black);
		m_textAr[i].setOutlineThickness(3.0f);
	}

	m_rules.setWinSize(sf::Vector2f(m_window.getSize()));

	
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\SFML-LOGO.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(300.0f, 180.0f);

	lines[0].setSize(sf::Vector2f(1920, 5));
	lines[0].setFillColor(sf::Color::White);
	int tempPos = 1080 / 3;
	lines[0].setPosition(sf::Vector2f(0, tempPos));
	lines[1].setSize(sf::Vector2f(1920, 5));
	lines[1].setFillColor(sf::Color::White);
	lines[1].setPosition(sf::Vector2f(0, tempPos*2));
}

void Game::generateResponse()
{

}
