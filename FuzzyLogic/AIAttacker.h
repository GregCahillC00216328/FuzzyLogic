#pragma once
#include "SFML/Graphics.hpp"

class AIAttack
{
public:
	AIAttack();
	~AIAttack();

	sf::Vector2f getPos() { return m_pos; };
	sf::Vector2f getSize() { return m_size; };
	sf::RectangleShape getRect() { return m_attacker; };
	void setPos(sf::Vector2f t_vec) {
		sf::Vector2f temp = t_vec;
		if (temp.x < 0)
		{
			temp.x += 51;
		}if (temp.x > 1820)
		{
			temp.x -= 50;
		}
		if (temp.y < 0)
		{
			temp.y += 50;
		}
		if (temp.y > 980)
		{
			temp.y -= 50;
		}
		m_pos = temp; m_attacker.setPosition(m_pos);
	};
	void setUpRect(sf::Vector2f t_size, sf::Color t_col) { m_attacker.setFillColor(t_col); m_attacker.setSize(t_size); };
	void setNumAttackers(int t_num) { numOfAttackers = t_num; };
	void setRangeVal(int t_num) { rangeVal = t_num; };
	int getNumOfAttackers(){return numOfAttackers;};
	int getRangeVal() { return rangeVal; };

private:
	sf::RectangleShape m_attacker;
	sf::Vector2f m_pos;
	sf::Vector2f m_size;
	int numOfAttackers;
	int rangeVal;

};

