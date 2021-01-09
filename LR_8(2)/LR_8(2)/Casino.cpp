#include "Casino.h"
#include "Exception.h"

ostream& operator<<(ostream& out, const Casino& Cas)
{
	try {
		if (Cas.name == " "){
			throw 2;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	out << Cas.name << " " << Cas.money << " " << Cas.profit << " " << Cas.players << endl;
	return out;
}

istream& operator>>(istream& in, Casino& Cas)
{
	in >> Cas.name;
	in >> Cas.money;
	in >> Cas.profit;
	in >> Cas.players;
	return in;
}

bool operator==(Casino num1, Casino num2) {
	if (num1.get_name() == num2.get_name() && num1.get_money() == num2.get_money() && num1.get_profit() == num2.get_profit() &&
		num1.get_players() == num2.get_players()) {
		return true;
	}
	else {
		return false;
	}
}


string Casino::get_name() {
	return this->name;
}
int Casino::get_money() {
	return this->money;
}
int Casino::get_profit() {
	return this->profit;
}
int Casino::get_players() {
	return this->players;
}

void Casino::set_name(string temp) {
	this->name = temp;
}
void Casino::set_money(int temp) {
	this->money = temp;
}
void Casino::set_profit(int temp) {
	this->profit = temp;
}
void Casino::set_players(int temp) {
	this->players = temp;
}