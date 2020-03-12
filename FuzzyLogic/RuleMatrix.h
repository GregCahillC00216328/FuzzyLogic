#pragma once
#include <SFML/Graphics.hpp>

class rulesMatrix
{
public:
	rulesMatrix();
	~rulesMatrix();
	void setWinSize(sf::Vector2f t_winSize) { m_winSize = t_winSize; };
	void beginFuzzification(int t_numOfAttackers, int t_range);
	double FuzzyGrade(double value, double x0, double x1);
	double FuzzyTrapezoid(double value, double x0, double x1, double x2, double x3);
	double FuzzyTriangle(double value, double x0, double x1, double x2);
	double FuzzyAND(double A, double B) { return Min(A, B); };
	double FuzzyOR(double A, double B) { return Max(A, B); };
	double FuzzyNot(double A) { return 1.0 - A; };
	float getTiny() { return tiny; }; float getSmall() { return small; };
	float getModerate() { return moderate; }; float getLarge() { return Large; };
	float getClose() { return close; }; float getMedium() { return medium; }; float getFar() { return far; };
	float getLow() { return low; }; float getMed() { return med; }; float getHigh() { return high; };
	float getDeploy() { return deploy; };
	//void sortTroops(int numOfUnits);
private:
	int attackerCount;
	sf::Vector2f m_winSize;
	float tiny = 0, small = 0, moderate = 0, Large = 0;
	float close = 0, medium = 0, far = 0;
	float low = 0, med = 0, high = 0;
	double Min(double A, double B) { if (A < B) { return A; } else { return B; }; }
	double Max(double A, double B) { if (A > B) { return A; } else { return B; } };
	float deploy ;
};




