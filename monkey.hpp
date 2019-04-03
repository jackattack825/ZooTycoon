/*********************************************************************
** Program Filename: monkey.hpp
** Author: Jackson Perry
** Date: 2/10/19
** Description: monkey class
*********************************************************************/

#ifndef monkey
#define monkey

#include "animal.hpp"

class Monkey : public Animal {

public:
	Monkey();
	string getName();
};

#endif