/*********************************************************************
** Program Filename: sloth.cpp
** Author: Jackson Perry
** Date: 2/10/19
** Description: Contains definitions for functions in sloth.hpp
*********************************************************************/

#include "animal.hpp"
#include "sloth.hpp"

/*********************************************************************
** Function: Sloth
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Sloth::Sloth() {
	this->age = 0;
	this->cost = 2000;
	this->foodC = 50;
	this->babies = 3;
	this->revenue = 100;
	this->foodMult = 1;
}