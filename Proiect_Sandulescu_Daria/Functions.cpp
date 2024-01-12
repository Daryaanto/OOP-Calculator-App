#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cstring>

#include "Functions.h"

using namespace std;


Functions::Functions():idFunctie(1) {
		numeFunctie = "Multifunctie";
	}
Functions::Functions(string nume) :idFunctie(2) {
		numeFunctie = nume;
	}
Functions::Functions(const Functions& f) :idFunctie(f.idFunctie) {
		numeFunctie = "Multifunctie";
	}

	bool Functions::operator>(const Functions& f) {
		return this->idFunctie > f.idFunctie;
	}

	string Functions::getNume() {
		return numeFunctie;
	}

	int Functions::getId() {
		return idFunctie;
	}

	void Functions::setNume(int s) {
		numeFunctie = s;
	}


	  string Functions::convertire(char* c) {
		string s(c);

		return s;

	}
	 int Functions::numTot(int index, string expr) {
		string c;
		int num, numFin = 0;
		for (int j = index; j < expr.length(); j++)
		{
			if (isdigit(expr[j]))
			{
				c = expr[j];
				num = stoi(c);
				numFin = numFin * 10 + stoi(c);

			}
			else
			{
				break;
			}

		}
		return numFin;
	}
	

istream& operator>>(istream& in, Functions& f) {
 in >> f.numeFunctie;
	return in;
}

ostream& operator<<(ostream& out, Functions& f) {
	cout << "Functia se numeste " << f.numeFunctie << endl;
	return out;
}
char Functions::expChr = 'c';






