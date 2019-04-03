
/*********************************************************************
** Program Filename: animal.hpp
** Author: Jackson Perry
** Date: 2/10/19
** Description: animal class
*********************************************************************/

#ifndef animal
#define animal

#include <string>

using namespace std;

class Animal {

public:
	int age, cost, babies, foodC, revenue; //foodMult is each animals foodmultiplier
	float foodMult;
	void ageDay();

	int getAge();
	int getCost();
	int getBabies();
	float getFoodC();
	int getRevenue();
	bool isAdult();

	void setAge(int a);
};

#endif