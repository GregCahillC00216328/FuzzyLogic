#include <SFML/Graphics.hpp>
#include "AIAttacker.h"
#include "AIDefender.h"
#include "RuleMatrix.h"
#include <vector>
#include <iostream>
#include <time.h>
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	void setPositions();
private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();
	rulesMatrix m_rules;
	AIAttack attackers;
	AIDefend defenders;
	void generateResponse();
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	sf::RectangleShape lines[2];

	sf::Text m_textAr[11];

};



