
/*********************************************************************
** Program Filename: animal.cpp
** Author: Jackson Perry
** Date: 2/10/19
** Description: Contains definitions for functions in animal.hpp
*********************************************************************/

#include "animal.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*********************************************************************
** Function: age
** Description: increases animals age
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Animal::ageDay() {
	this->age++;
}

/*********************************************************************
** Function: getAge
** Description: returns age
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Animal::getAge() {
	return this->age;
}

/*********************************************************************
** Function: getCost
** Description: returns cost
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Animal::getCost() {
	return this->cost;
}

/*********************************************************************
** Function: getBabies
** Description: returns babies
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Animal::getBabies() {
	return this->babies;
}

/*********************************************************************
** Function: getFoodC
** Description: returns food cost
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
float Animal::getFoodC() {
	float ran = rand() % 50 + 75;
	this->foodC *= (float)(ran / 100);
	return this->foodMult * this->foodC;
}

/*********************************************************************
** Function: getRevenue
** Description: returns revenue
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Animal::getRevenue() {
	if (this->getAge() < 30)
		return this->revenue * 2;
	return this->revenue;
}

/*********************************************************************
** Function: isAdult
** Description: returns if is adult
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
bool Animal::isAdult() {
	return this->age > 1095;
}

/*********************************************************************
** Function: setAge
** Description: setsAge
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Animal::setAge(int a) {
	this->age = a;
}
