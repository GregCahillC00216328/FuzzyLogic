#include "RuleMatrix.h"
#include <iostream>
rulesMatrix::rulesMatrix()
{

}

rulesMatrix::~rulesMatrix()
{

}

void rulesMatrix::beginFuzzification(int t_numOfAttackers, int t_range)
{
	tiny = FuzzyTriangle(t_numOfAttackers, -10, 0, 10);
	small = FuzzyTrapezoid(t_numOfAttackers, 2.5, 10, 15, 20);
	moderate = FuzzyTrapezoid(t_numOfAttackers, 15, 20, 25, 30);
	Large = FuzzyGrade(t_numOfAttackers, 25, 30);

	close = FuzzyTriangle(t_range, -30, 0, 30);
	medium = FuzzyTrapezoid(t_range, 10, 30, 50, 70);
	far = FuzzyGrade(t_range, 50, 70);

	low = FuzzyOR(FuzzyAND(medium, tiny), FuzzyAND(medium, small));
	med = FuzzyAND(close, tiny);
	high = FuzzyAND(close, FuzzyNot(med));

	deploy = (low * 5 + med * 15 + high * 30) / (low + med + high);
	std::cout << deploy << std::endl;
}

double rulesMatrix::FuzzyGrade(double value, double x0, double x1)
{
	double result = 0;
	double x = value;

	if (x <= x0)
		result = 0;
	else if (x > x1)
		result = 1;
	else
		result = ((x - x0) / (x1 - x0));
	return result;
}

double rulesMatrix::FuzzyTrapezoid(double value, double x0, double x1, double x2, double x3)
{
	
	double result = 0;
	double x = value;

	if ((x <= x0) || (x >= x3))
		result = 0;
	else if ((x >= x1) && (x <= x2))
		result = 1;
	else if ((x > x0) && (x < x1))
		result = ((x - x0) / (x1 - x0));
	else
		result = ((x3 - x) / (x3 - x2));
	return result;
	

}

double rulesMatrix::FuzzyTriangle(double value, double x0, double x1, double x2)
{
	double result = 0;
	double x = value;

	if ((x <= x0) || (x >= x2))
		result = 0;
	else if (x == x1)
		result = 1;
	else if ((x > x0) && (x < x1))
		result = ((x - x0) / (x1 - x0));
	else
		result = ((x2 - x) / (x2 - x1));

	return result;
}
