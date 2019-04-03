/*********************************************************************
** Program Filename: zoo.cpp
** Author: Jackson Perry
** Date: 2/10/19
** Description: contains defintions for functions from zoo.hpp
*********************************************************************/

#include <iostream>
#include "animal.hpp"
#include "monkey.hpp"
#include "seaotter.hpp"
#include "sloth.hpp"
#include "zoo.hpp"
#include <vector>
#include <cstdlib>
#include <typeinfo>

using namespace std;

/*********************************************************************
** Function: Zoo
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Zoo::Zoo() {
	this->bank = 100000;
	cout << "\n\nWelcome to Zoo Tycoon. You will start with $100,000 and manage a zoo. Each day you will be able to buy 2 animals, and must feed the existing ones.\n You also will get revenue from each animal and there is a special event some days.\n" << endl;
}

/*********************************************************************
** Function: passDay
** Description: pass by a day in the game
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Zoo::passDay() {
	cout << "start of new day bank is: " << this->bank << endl;
	incAllAges();
	promptBuyAnimals();
	payFeeding();
	specialEvent();
	getRevenue();
}

/*********************************************************************
** Function: incAllAges
** Description: increase aga of all animals
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Zoo::incAllAges() {
	for (int i = 0; i < this->sloths.size(); i++) {
		this->sloths.at(i).ageDay();
	}
	for (int i = 0; i < this->seaotters.size(); i++) {
		this->seaotters.at(i).ageDay();
	}
	for (int i = 0; i < this->monkeys.size(); i++) {
		this->monkeys.at(i).ageDay();
	}
}

/*********************************************************************
** Function: specialEvent
** Description: random special event
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Zoo::specialEvent() {
	int num = rand() % 4;
	int num2 = 0; //used for type of animal
	int price = 0;
	bool b;
	int babies = 0;
	int add = 0;
	switch (num) {
	case 0:
		cout << "A random animal is getting sick" << endl;
		num2 = rand() % 3;
		switch (num2) {
		case 0:
			if (sloths.size() == 0) {
				cout << "You got lucky and didnt have any sloths yet" << endl;
				return;
			}
			num = rand() % sloths.size();
			price = sloths.at(num).getCost() / 2;
			if (sloths.at(num).getAge() < 30)
				price *= 2;
			cout << "a sloth has gotten sick, you must pay " << price << endl;
			if (bank > price) {
				cout << "you can afford to fix animal, so you have done so" << endl;
				bank -= price;
			}
			else {
				cout << "You dont have the money to heal the animal, it died" << endl;
				sloths.erase(sloths.begin() + num);
			}
			break;
		case 1:
			if (seaotters.size() == 0) {
				cout << "You got lucky and didnt have any seaotters yet" << endl;
				return;
			}
			num = rand() % seaotters.size();
			price = seaotters.at(num).getCost() / 2;
			if (seaotters.at(num).getAge() < 30)
				price *= 2;
			cout << "a seaotter has gotten sick, you must pay " << price << endl;
			if (bank > price) {
				cout << "you can afford to fix animal, so you have done so" << endl;
				bank -= price;
			}
			else {
				cout << "You dont have the money to heal the animal, it died" << endl;
				seaotters.erase(seaotters.begin() + num);
			}
			break;
		case 2:
			if (monkeys.size() == 0) {
				cout << "You got lucky and didnt have any monkeys yet" << endl;
				return;
			}
			num = rand() % monkeys.size();
			price = monkeys.at(num).getCost() / 2;
			if (monkeys.at(num).getAge() < 30)
				price *= 2;
			cout << "a monkey has gotten sick, you must pay " << price << endl;
			if (bank > price) {
				cout << "you can afford to fix animal, so you have done so" << endl;
				bank -= price;
			}
			else {
				cout << "You dont have the money to heal the animal, it died" << endl;
				monkeys.erase(monkeys.begin() + num);
			}
			break;
		}
		
		break;
	case 1:
		cout << "An adult animal is getting pregnant" << endl;
		do {
			num = rand() % 3;
				switch (num) {
				case 0:
					if (sloths.size() == 0) {
						cout << "You got unlucky and didnt have any sloths yet to have babies with" << endl;
						return;
					}
					num2 = rand() % sloths.size();
					b = sloths.at(num2).isAdult();
					babies = sloths.at(num2).getBabies();
					break;
				case 1:
					if (seaotters.size() == 0) {
						cout << "You got unlucky and didnt have any seaotters yet to have babies with" << endl;
						return;
					}
					num2 = rand() % seaotters.size();
					b = seaotters.at(num2).isAdult();
					babies = seaotters.at(num2).getBabies();
					break;
				case 2:
					if (monkeys.size() == 0) {
						cout << "You got unlucky and didnt have any monkeys yet to have babies with" << endl;
						return;
					}
					num2 = rand() % monkeys.size();
					b = monkeys.at(num2).isAdult();
					babies = monkeys.at(num2).getBabies();
					break;

			}
			if (b) {
				for (int i = 0; i < b; i++) {
					if (num==0) {
						Sloth s;
						sloths.push_back(s);
						cout << "you had a baby sloth" << endl;
					}
					else if (num== 1) {
						SeaOtter sea;
						seaotters.push_back(sea);
						cout << "you had a baby seaotter" << endl;
					}
					else if (num== 2) {
						Monkey mon;
						monkeys.push_back(mon);
						cout << "you had a baby monkey" << endl;
					}
				}
			}
		} while (!b);
		break;
	case 2:
		cout << "A boom in zoo attendance has occurred" << endl;
		for (int i = 0; i < monkeys.size(); i++) {
			add = rand() % 251 + 250;
			cout << "A monkey has generated " << add << "$ for you" << endl;
			bank += add;
		}
		break;
	case 3:
		cout << "No special event has occured today" << endl;
		break;
	}
}

/*********************************************************************
** Function: getRevenue
** Description: add revenue to bank
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Zoo::getRevenue() {
	int rev;
	for (int i = 0; i < this->sloths.size(); i++) {
		rev= this->sloths.at(i).getRevenue();
		cout << "Earned " << rev << " from sloths" << endl;
		bank += rev;
	}
	for (int i = 0; i < this->seaotters.size(); i++) {
		rev = this->seaotters.at(i).getRevenue();
		cout << "Earned " << rev << " from seaotters" << endl;
		bank += rev;
	}
	for (int i = 0; i < this->monkeys.size(); i++) {
		rev = this->monkeys.at(i).getRevenue();
		cout << "Earned " << rev << " from monkeys" << endl;
		bank += rev;
	}
}

/*********************************************************************
** Function: promptBuyAnimals
** Description: prompt user for buying animals
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Zoo::promptBuyAnimals(){
	cout << "You can buys 2 animals but they must be of different species" << endl;
	int i = 0, ans=0, price=0;
	int res;
	Monkey mo;
	SeaOtter sea;
	Sloth sl;
	do{
		cout << "Buy animals? Type 1 to continue." << endl;
		cin >> ans;
		if (!ans) {
			cout << "exiting prompt fr buying animals" << endl;
			break;
		}

		cout << "type (1)seaotter, (2)monkey, or (3)sloth to choose an animal to attempt to buy" << endl;
		cin >> res;
		switch (res) {
		case 1:
			
			price = sea.getCost();
			if (bank > price) {
				cout << "You bought a seaotter" << endl;
				bank -= price;
				sea.setAge(1095);
				seaotters.push_back(sea);
			}
			else
				cout << "You don't have the required " << price << " to buy a seaotter" << endl;
			break;
		case 2:
			
			price = mo.getCost();
			if (bank > price) {
				cout << "You bought a monkey" << endl;
				bank -= price;
				mo.setAge(1095);
				monkeys.push_back(mo);
			}
			else
				cout << "You don't have the required " << price << " to buy a monkey" << endl;
			break;
		case 3:
			
			price = sl.getCost();
			if (bank > price) {
				cout << "You bought a sloth" << endl;
				bank -= price;
				sl.setAge(1095);
				sloths.push_back(sl);
			}
			else
				cout << "You don't have the required " << price << " to buy a sloth" << endl;
			break;
		}
		i++;
	} while (i != 2);
}

/*********************************************************************
** Function: payFeeding
** Description: pay feeding for all animals
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Zoo::payFeeding() {
	int price = 0;
	for (int i = 0; i < this->monkeys.size(); i++) {
		price = monkeys.at(i).getFoodC();
		cout << "paying " << price << " for monkey's food" << endl;
		this->bank -= price;
	}
	for (int i = 0; i < this->sloths.size(); i++) {
		price = sloths.at(i).getFoodC();
		cout << "paying " << price << " for sloths's food" << endl;
		this->bank -= price;
	}
	for (int i = 0; i < this->seaotters.size(); i++) {
		price = seaotters.at(i).getFoodC();
		cout << "paying " << price << " for seaotters's food" << endl;
		this->bank -= price;
	}
}

/*********************************************************************
** Function: endGame
** Description: endGame details
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Zoo::endGame() {
	cout << "You have finally lost and the game is over, thanks for playing" << endl;
}

/*********************************************************************
** Function: getBank
** Description: retruns value of bank
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Zoo::getBank() {
	return this->bank;
}