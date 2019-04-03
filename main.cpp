/*********************************************************************
** Program Filename: main.cpp
** Author: Jackson Perry
** Date: 2/10/19
** Description: main class
*********************************************************************/

//TODO fix food costs being 0 or high #

#include <iostream>
#include "animal.hpp"
#include "monkey.hpp"
#include "seaotter.hpp"
#include "sloth.hpp"
#include "zoo.hpp"
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	srand(time(NULL));
	Zoo z;
	while (z.getBank() >0) {
		z.passDay();
	}
	z.endGame();
	return 0;
}