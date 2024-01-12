#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Functions {
static char expChr;
	const int idFunctie;
	string numeFunctie;

public:

	Functions();

	Functions(string nume);

	Functions(const Functions& f) ;

	bool operator>(const Functions& f);

	string getNume();

	int getId();

	void setNume(int s);


	static string convertire(char* c);
	static int numTot(int index, string expr);
	friend istream& operator>>(istream& in, Functions& f);
	friend ostream& operator<<(ostream& out, Functions& f);
};

istream& operator>>(istream& in, Functions& f);

ostream& operator<<(ostream& out, Functions& f);







