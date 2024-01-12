#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cstring>

//#include "Operator.cpp"

using namespace std;

class Operator {
	string tipOperator;
	int grad;
public:

	Operator();


	Operator(string op);
	Operator(const Operator& o);

	Operator operator++(int x);

	bool operator==(const Operator& o);

	int adunare(int a, int b);

	int scadere(int a, int b);
	int inmultire(int a, int b);
	int impartire(int a, int b);

	int getGrad();
	string getTip();

	void setGrad(int x);
	void setTip(string s);

	friend istream& operator>>(istream& in, Operator& o);
	friend ostream& operator<<(ostream& out, Operator& o);

};

istream& operator>>(istream& in, Operator& o);

ostream& operator<<(ostream& out, Operator& o);
