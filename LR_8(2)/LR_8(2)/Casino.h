#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Casino {
private:
	string name;
	int money;
	int profit;
	int players;
public:
	Casino() {
		this->name = " ";
		this->money = 10000;
		this->profit = 1000;
		this->players = 10;
	}
	Casino(string name, int amount, int price, int rest) {
		this->name = name;
		this->money = amount;
		this->profit = price;
		this->players = rest;
	}
	friend ostream& operator<<(ostream& out, const Casino& art);
	friend istream& operator>>(istream& in, Casino& art);
	friend bool operator==(const Casino num1, const Casino num2);

	string get_name();
	int get_money();
	int get_profit();
	int get_players();

	void set_name(string);
	void set_money(int);
	void set_profit(int);
	void set_players(int);
};