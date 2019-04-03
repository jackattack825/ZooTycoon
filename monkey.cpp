/*********************************************************************
** Program Filename: monkey.cpp
** Author: Jackson Perry
** Date: 2/10/19
** Description: Contains definitions for functions in monkey.hpp
*********************************************************************/

#include "animal.hpp"
#include "monkey.hpp"

/*********************************************************************
** Function: Monkey
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Monkey::Monkey() {
	this->age = 0;
	this->cost = 15000;
	this->foodC = 50;
	this->babies = 1;
	this->revenue = 1500;
	this->foodMult = 4;
}