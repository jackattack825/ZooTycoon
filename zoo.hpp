/*********************************************************************
** Program Filename: zoo.hpp
** Author: Jackson Perry
** Date: 2/10/19
** Description: zoo class
*********************************************************************/

#include "animal.hpp"
#include "monkey.hpp"
#include "seaotter.hpp"
#include "sloth.hpp"
#include <vector>

using namespace std;

class Zoo {

private:
	vector<Sloth> sloths;
	vector<SeaOtter> seaotters;
	vector<Monkey> monkeys;
	int bank;
public:
	Zoo();
	void passDay();
	void endGame();
	void incAllAges();
	void promptBuyAnimals();
	void payFeeding();
	void specialEvent();
	void getRevenue();
	int getBank();
};