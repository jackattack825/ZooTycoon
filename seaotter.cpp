/*********************************************************************
** Program Filename: seaotter.cpp
** Author: Jackson Perry
** Date: 2/10/19
** Description: Contains definitions for functions in seaotter.hpp
*********************************************************************/

#include "animal.hpp"
#include "seaotter.hpp"
#include <string>

/*********************************************************************
** Function: SeaOtter
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
SeaOtter::SeaOtter() {
	this->age = 0;
	this->cost = 5000;
	this->foodC = 50;
	this->babies = 2;
	this->revenue = 250;
	this->foodMult = 2;
}