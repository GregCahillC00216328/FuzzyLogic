#pragma once
#include <SFML/Graphics.hpp>
class AIDefend
{
public:
	AIDefend();
	~AIDefend();
	sf::Vector2f getPos() { return m_pos; };
	sf::Vector2f getSize() { return m_size; };
	sf::RectangleShape getViewRect() { return m_defender; };

	void setPos(sf::Vector2f t_vec) { m_pos = t_vec; m_defender.setPosition(m_pos); };
	void setViewRect(sf::Vector2f t_size, sf::Vector2f t_pos) { m_viewRect.setPosition(t_pos); m_viewRect.setPosition(t_size); };
private:
	sf::RectangleShape m_defender;
	sf::RectangleShape m_viewRect;
	sf::Vector2f m_pos;
	sf::Vector2f m_size;
};

