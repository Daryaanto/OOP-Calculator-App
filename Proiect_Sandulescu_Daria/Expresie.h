#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cstring>


using namespace std;


class Expresie {
	int lungimeExpresie;
	char* expresie;
	int lungimeRez = 0;
	int* rezultate;

public:

	int getLungimeExpresie();
	int getLungimeRez();

	char* getExpresie();
	void setRezultate(int* v);
	void realocaRezultate(int* vec, int n);
	void setLungimeExpresie(int x);
	void setLungimeRez(int x);


	void setExpresie(const char* c);

	void realocareLg(int x);
	void schimbExpresia(char* c);

	Expresie();

	Expresie(int lungime);
	Expresie(int lungime, char* c);

	Expresie(const Expresie& e);

	Expresie& operator=(const Expresie& e);

	int operator+(int x);

	bool operator!();

	friend istream& operator>>(istream& in, Expresie& e);
	friend ostream& operator<<(ostream& out, Expresie& e);

	~Expresie();

};

Expresie operator+(int x, Expresie& e);
istream& operator>>(istream& in, Expresie& e);

ostream& operator<<(ostream& out, Expresie& e);
