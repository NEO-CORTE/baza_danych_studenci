#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;
class student
{
public:
	string nazwisko;
	int wiek;

	friend ostream& operator << (ostream& os, student& st_out) {
		os << "Nazwisko: " << st_out.nazwisko << " Wiek: " << st_out.wiek << endl;
		return os;
	}
	friend ofstream& operator << (ofstream& ofs, student& st_out) {
		ofs << st_out.nazwisko << endl << st_out.wiek << endl;
		return ofs;
	}
	friend istream& operator >> (istream& is, student& st_in) {
		cout << "Nazwisko: " << endl;
		is >> st_in.nazwisko;
		cout << " Wiek: " << endl;
		is >> st_in.wiek;
		cout << endl;
		return is;
	}
	friend ifstream& operator >> (ifstream& ifs, student& st_in) {
		ifs >> st_in.nazwisko >> st_in.wiek;
		return ifs;
	}
	void operator () (student& st) {
		cout << st;
	}
};

