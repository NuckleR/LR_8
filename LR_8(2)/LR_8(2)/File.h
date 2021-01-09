#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Exception.h"
#include "Casino.h"
using namespace std;


enum Key {
	none = 0,
	txt,
	bin
};

class File
{
public:
	fstream file;
	string path;
	Key key; //none txt bin
	int size;
public:
	File() :path("Space"), key(none), size(0) {}
	File(string path, Key key) {
		this->path = path;
		this->key = key;
		this->size = 0;
	}
	~File() { file.close(); }
	void open(string mode) {
		switch (key) {
		case txt: {
			if (mode == "r") {
				file.open(path, ios_base::in);
			}
			else if (mode == "add") {
				file.open(path, ios_base::app);
			}
			else if (mode == "w") {
				file.open(path, ios_base::out);
			}
			else if (mode == "wr") {
				file.open(path, ios_base::in | ios_base::out);
			}
		}
				break;
		case bin: {
			if (mode == "r") {
				file.open(path, ios_base::binary | ios_base::in);
			}
			else if (mode == "add") {
				file.open(path, ios_base::binary | ios_base::app);
			}
			else if (mode == "w") {
				file.open(path, ios_base::binary | ios_base::out);
			}
			else if (mode == "wr") {
				file.open(path, ios_base::binary | ios_base::in | ios_base::out);
			}
		}
				break;
		}
		try {
			if (!file.is_open()){
				throw 1;
			}
		}
		catch (int i){
			Exception ex(i);
			ex.Print();
			exit(-1);
			return;
		}
	}
	void close() {
		file.close();
	}
	void begin() {
		file.seekg(0, ios_base::beg);
	}
	void set_size(int s) {
		size = s;
	}
	int get_size() {
		return	size;
	}
	void bubble_sort_name()
	{
		string temp;
		string j1, j2;
		int pos;
		this->open("wr");
		try {
			if (!file.is_open()){
				throw 1;
			}
		}
		catch (int i){
			Exception ex(i);
			ex.Print();
			return;
		}
		for (int i = 0; i < this->size - 1; i++) {
			for (int j = 0; j < this->size - i - 1; j++) {
				this->file.seekg(0, ios_base::beg);
				for (int k = 0; k < j; k++) {
					std::getline(this->file, j1);
				}
				std::getline(this->file, j1, ' ');
				std::getline(this->file, j2);
				std::getline(this->file, j2, ' ');
				if (j1 > j2) {
					this->file.seekg(0, ios_base::beg);
					pos = this->file.tellg();
					for (int k = 0; k <= j; k++) {
						std::getline(this->file, j1);
						pos = this->file.tellg();
					}
					temp = j1;
					std::getline(this->file, j2);
					this->file.seekg(0, ios_base::beg);
					for (int k = 0; k < j; k++) {
						std::getline(this->file, j1);
					}
					pos = this->file.tellg();
					this->file.seekg(pos, ios_base::beg);
					this->file << j2 << '\n';
					this->file << temp << '\n';
				}
			}
		}
		this->close();
	}
	void bubble_sort_money()
	{
		string temp;
		string j1, j2;
		int i1, i2;
		int pos;
		this->open("wr");
		try {
			if (!file.is_open()){
				throw 1;
			}
		}
		catch (int i){
			Exception ex(i);
			ex.Print();
			return;
		}
		for (int i = 0; i < this->size - 1; i++) {
			for (int j = 0; j < this->size - i - 1; j++) {
				this->file.seekg(0, ios_base::beg);
				for (int k = 0; k < j; k++) {
					getline(this->file, j1);
				}
				getline(this->file, j1, ' ');
				getline(this->file, j1, ' ');
				getline(this->file, j2);
				getline(this->file, j2, ' ');
				getline(this->file, j2, ' ');
				i1 = stoi(j1);
				i2 = stoi(j2);
				if (i1 > i2) {
					this->file.seekg(0, ios_base::beg);
					pos = this->file.tellg();
					for (int k = 0; k <= j; k++) {
						getline(this->file, j1);
						pos = this->file.tellg();
					}
					temp = j1;
					getline(this->file, j2);
					this->file.seekg(0, ios_base::beg);
					for (int k = 0; k < j; k++) {
						getline(this->file, j1);
					}
					pos = this->file.tellg();
					this->file.seekg(pos, ios_base::beg);
					this->file << j2 << '\n';
					this->file << temp << '\n';
				}
			}
		}
		this->close();
	}

	void bubble_sort_profit()
	{
		string temp;
		string j1, j2;
		int i1, i2;
		int pos;
		this->open("wr");
		try {
			if (!file.is_open()){
				throw 1;
			}
		}
		catch (int i){
			Exception ex(i);
			ex.Print();
			return;
		}
		for (int i = 0; i < this->size - 1; i++) {
			for (int j = 0; j < this->size - i - 1; j++) {
				this->file.seekg(0, ios_base::beg);
				for (int k = 0; k < j; k++) {
					getline(this->file, j1);
				}
				getline(this->file, j1, ' ');
				getline(this->file, j1, ' ');
				getline(this->file, j1, ' ');
				getline(this->file, j2);
				getline(this->file, j2, ' ');
				getline(this->file, j2, ' ');
				getline(this->file, j2, ' ');
				i1 = stoi(j1);
				i2 = stoi(j2);
				if (i1 > i2) {
					this->file.seekg(0, ios_base::beg);
					pos = this->file.tellg();
					for (int k = 0; k <= j; k++) {
						getline(this->file, j1);
						pos = this->file.tellg();
					}
					temp = j1;
					getline(this->file, j2);
					this->file.seekg(0, ios_base::beg);
					for (int k = 0; k < j; k++) {
						getline(this->file, j1);
					}
					pos = this->file.tellg();
					this->file.seekg(pos, ios_base::beg);
					this->file << j2 << '\n';
					this->file << temp << '\n';
				}
			}
		}
		this->close();
	}

	void bubble_sort_players()
	{
		string temp;
		string j1, j2;
		int i1, i2;
		int pos;
		this->open("wr");
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
		for (int i = 0; i < this->size - 1; i++) {
			for (int j = 0; j < this->size - i - 1; j++) {
				this->file.seekg(0, ios_base::beg);
				for (int k = 0; k < j; k++) {
					getline(this->file, j1);
				}
				getline(this->file, j1, ' ');
				getline(this->file, j1, ' ');
				getline(this->file, j1, ' ');
				getline(this->file, j1, ' ');
				getline(this->file, j2);
				getline(this->file, j2, ' ');
				getline(this->file, j2, ' ');
				getline(this->file, j2, ' ');
				getline(this->file, j2, ' ');
				i1 = stoi(j1);
				i2 = stoi(j2);
				if (i1 > i2) {
					this->file.seekg(0, ios_base::beg);
					pos = this->file.tellg();
					for (int k = 0; k <= j; k++) {
						getline(this->file, j1);
						pos = this->file.tellg();
					}
					temp = j1;
					getline(this->file, j2);
					this->file.seekg(0, ios_base::beg);
					for (int k = 0; k < j; k++) {
						getline(this->file, j1);
					}
					pos = this->file.tellg();
					this->file.seekg(pos, ios_base::beg);
					this->file << j2 << '\n';
					this->file << temp << '\n';
				}
			}
		}
		this->close();
	}


	void del(int line);

	int edit(int line);

	Casino return_art() {
		string str;
		int i1;
		Casino art;

		std::getline(this->file, str, ' ');
		art.set_name(str);
		std::getline(this->file, str, ' ');
		i1 = stoi(str);
		art.set_money(i1);
		std::getline(this->file, str, ' ');
		i1 = stoi(str);
		art.set_profit(i1);
		std::getline(this->file, str, ' ');
		i1 = stoi(str);
		art.set_players(i1);
		return art;
	}
	friend File& operator<<(File& file, Casino& art);
	friend File& operator<<(File& file, const char* s);
	friend ostream& operator<<(ostream& out, File& file);

	void ff() {

		size_t len;
		string name;
		int money = 0;
		int profit = 0;
		int players = 0;
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
	}
};