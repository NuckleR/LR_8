#include "File.h"
#include "Casino.h"
#include "Exception.h"
#include <io.h>
#include <sys/types.h>
#include <stdio.h>



File& operator<<(File& file, const char* s)
{
	try {
		if (!file.file.is_open()){
			throw 1;
		}
	}
	catch (int i){
		Exception ex(i);
		ex.Print();
	}
	string str = s;
	file.file << str;
	return file;
}

fstream& operator<<(fstream& out, Casino& Cas) {
	try {
		if (!out.is_open()){
			throw 1;
		}
	}
	catch (int i){
		Exception ex(i);
		ex.Print();
	}

	int a = out.tellg();
	string art_name = Cas.get_name();
	size_t len1 = art_name.size() + 1;

	int money = Cas.get_money();
	int profit = Cas.get_profit();
	int players = Cas.get_players();

	out.write((char*)(&len1), sizeof(len1));
	out.write((char*)(art_name.c_str()), len1);
	out.write((char*)(&money), sizeof(money));
	out.write((char*)(&profit), sizeof(profit));
	out.write((char*)(&players), sizeof(players));

	return out;
}

File& operator<<(File& file, Casino& Cas)
{
	int pos = 0, a = 0, size = 0;
	try {
		if (!file.file.is_open()){
			throw 1;
		}
	}
	catch (int i){
		Exception ex(i);
		ex.Print();
	}
	if (file.key == txt) {
		file.file << Cas.get_name() << " " << Cas.get_money() << " " << Cas.get_profit() << " " << Cas.get_players() << " " <<endl;
	}
	else if (file.key == bin) {
		string name = Cas.get_name();
		size_t len1 = name.size() + 1;

		int money = Cas.get_money();
		int profit = Cas.get_profit();
		int players = Cas.get_players();


		file.file.write((char*)(&len1), sizeof(len1));
		file.file.write((char*)(name.c_str()), len1);
		file.file.write((char*)(&money), sizeof(money));
		file.file.write((char*)(&profit), sizeof(profit));
		file.file.write((char*)(&players), sizeof(players));
	}
	return file;
}



ostream& operator<<(ostream& out, File& file)
{
	int a = 0;
	try {
		if (!file.file.is_open()){
			throw 1;
		}
	}
	catch (int i){
		Exception ex(i);
		ex.Print();
	}
	if (file.key == txt) {
		string str;
		while (!file.file.eof()) {
			std::getline(file.file, str);
			a = file.file.tellg();
			cout << str << endl;
		}
	}
	else if (file.key == bin) {
		int i = 0;
		int size = 0, step = 0;
		while (i < file.size) {
			int money;
			int profit;
			int players;

			size_t len;

			file.file.read((char*)(&len), sizeof(len));
			char* name = new char[len];
			file.file.read((char*)(name), len);
			name[len - 1] = '\0';
			file.file.read((char*)(&money), sizeof(int));
			file.file.read((char*)(&profit), sizeof(int));
			file.file.read((char*)(&players), sizeof(int));

			cout << name << " " << money << " " << profit << " " << players << endl;

			delete[] name;
			i++;
		}
	}
	return out;
}


int File::edit(int line)
{
	this->open("wr");

	int a, b;
	Casino* tmpe = new Casino[get_size()];

	try {
		if (!file.is_open()){
			throw 1;
		}
	}
	catch (int i){
		Exception ex(i);
		ex.Print();
		return 3;
	}
	Casino tmp;
	if (this->key == txt) {
		string temp;
		for (int i = 0; i < get_size(); i++) {
			std::getline(this->file, temp, ' ');
			tmpe[i].set_name(temp);
			std::getline(this->file, temp, ' ');
			tmpe[i].set_money(stoi(temp));
			std::getline(this->file, temp, ' ');
			tmpe[i].set_profit(stoi(temp));
			std::getline(this->file, temp, '\n');
			tmpe[i].set_players(stoi(temp));
		}
	}
	else if (this->key == bin) {
		size_t len;
		for (int i = 0; i < get_size(); i++) {
			this->file.read((char*)(&len), sizeof(len));
			char* n = new char[len];
			string name;
			int money = 0;
			int profit = 0;
			int players = 0;

			this->file.read((char*)(n), len);
			name = n;
			name[len - 1] = '\0';
			this->file.read((char*)(&money), sizeof(int));
			this->file.read((char*)(&profit), sizeof(int));
			this->file.read((char*)(&players), sizeof(int));

			tmpe[i].set_name(name);
			tmpe[i].set_money(money);
			tmpe[i].set_profit(profit);
			tmpe[i].set_players(players);
		}
		a = file.tellg();
	}

	cout << "Выберите параметр для изменения в строке?\n1 - Название\n2 - Деньги\n3 - Прибыль\n4 - Игроки\n5 - Выход из редактирования - переход к удалению (редактированию бинарного файла)\n" << endl;
	int choice;

	do {
		cin >> choice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\n\nПовторите ввод: ";
			choice = -1;
		}
		else break;
	} while (choice < 0 || choice>5);
	if(choice!=5)cout << "Введите новые данные: ";
	switch (choice) {
	case 1: {
		string a;
		rewind(stdin);
		cin >> a;
		tmpe[line-1].set_name(a);
		break;
	}
	case 2: {
		int a;
		while (true) {
			cin >> a;
			
			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\n\nПовторите ввод: ";
			}
			else break;
		}
		tmpe[line-1].set_money(a);
		break;
	}
	case 3: {
		int a;
		while (true) {
			cin >> a;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\n\nПовторите ввод: ";
			}
			else break;
		}
		tmpe[line-1].set_profit(a);
		break;
	}
	case 4: {
		int a;
		while (true) {
			cin >> a;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\n\nПовторите ввод: ";
			}
			else break;
		}
		tmpe[line-1].set_players(a);
		break;
	}
	case 5: {
		break;
	}
	} if (choice == 5) {
		this->file.close();
		return 0;
	}
		  a = this->file.tellg();
		  this->file.seekg(0, ios_base::end);
		  b = this->file.tellg();
		  this->file.seekg(0, ios_base::beg);
		  if (this->key == txt) {
			  this->file.close();
			  this->file.open(path, ios_base::in | ios_base::out | ios_base::trunc);
			  this->file.clear();
			  for (int i = 0; i < get_size(); i++) {
				  *this << tmpe[i];
			  }
		  }
		  else if (this->key == bin) {
			  this->file.close();
			  this->file.open(path, ios_base::in | ios_base::out | ios_base::trunc);
			  this->file.clear();
			  for (int i = 0; i < get_size(); i++) {
				  *this << tmpe[i];
			  }
		  }

		  this->close();
		  return 1;
}



//------------------------------ Реализовать
void File::del(int line)
{
	this->open("wr");

	int a, b;
	string name;
	int money = 0;
	int profit = 0;
	int players = 0;

	try {
		if (!file.is_open()) {
			throw 1;
		}
	}
	catch (int i) {
		Exception ex(i);
		ex.Print();
		return;
	}
	Casino tmp;
	string temp;
	Casino* tmpe = new Casino[get_size()];
	if (this->key == txt) {
		for (int i = 0; i < line - 1; i++) {
			std::getline(this->file, temp);
		}
		a = this->file.tellg();
		std::getline(this->file, temp);
		b = this->file.tellg();
		for (int i = line; i < get_size(); i++) {
			this->file.seekg(b, ios_base::beg);
			std::getline(this->file, temp);
			this->file.seekg(a, ios_base::beg);
			this->file << temp << "\n";
			a = this->file.tellg();
			this->file.seekg(a, ios_base::beg);
			std::getline(this->file, temp);
			b = this->file.tellg();
		}
		set_size(get_size() - 1);
		this->file.seekg(0, ios_base::beg);
		for (int i = 0; i < get_size(); i++) {
			std::getline(this->file, temp, ' ');
			tmpe[i].set_name(temp);
			std::getline(this->file, temp, ' ');
			tmpe[i].set_money(stoi(temp));
			std::getline(this->file, temp, ' ');
			tmpe[i].set_profit(stoi(temp));
			std::getline(this->file, temp, '\n');
			tmpe[i].set_players(stoi(temp));
		}
		this->file.close();
		this->file.open(path, ios_base::in | ios_base::out | ios_base::trunc);
		this->file.clear();
		int g = get_size();
		for (int i = 0; i < g; i++) {
			*this << tmpe[i];
		}
		this->file.close();
	}
	else if (this->key == bin) {
		size_t len;
		fstream temper;
		Casino *tmpe = new Casino [get_size()];
		char* r = new char[0];
		temper.open("temper.bin", ios_base::in | ios_base::out);
		for (int g = 0; g < line-1; g++) {
			this->file.read((char*)(&len), sizeof(len));
			char* n = new char[len];
			name = "";
			money = 0;
			profit = 0;
			players = 0;

			this->file.read((char*)(n), len);
			name = n;
			name[len - 1] = '\0';			
			this->file.read((char*)(&money), sizeof(int));
			this->file.read((char*)(&profit), sizeof(int));
			this->file.read((char*)(&players), sizeof(int));
			tmpe[g].set_name(name);
			tmpe[g].set_money(money);
			tmpe[g].set_profit(profit);
			tmpe[g].set_players(players);
		} ff();
		for (int i = line; i < get_size(); i++) {
			this->file.read((char*)(&len), sizeof(len));
			char* n = new char[len];
			name = "";
			money = 0;
			profit = 0;
			players = 0;

			this->file.read((char*)(n), len);
			name = n;
			name[len - 1] = '\0';
			this->file.read((char*)(&money), sizeof(int));
			this->file.read((char*)(&profit), sizeof(int));
			this->file.read((char*)(&players), sizeof(int));

			tmpe[i-1].set_name(name);
			tmpe[i-1].set_money(money);
			tmpe[i-1].set_profit(profit);
			tmpe[i - 1].set_players(players);
		}
		this->file.close();
		this->file.open(path, ios_base::in | ios_base::out | ios_base::trunc);
		this->file.clear();
		set_size(get_size()-1);

		for (int i = 0; i < get_size(); i++) {
			*this << tmpe[i];
		}
		a = this->file.tellg();
		this->file.close();
	}


}


