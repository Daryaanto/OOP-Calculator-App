#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cstring>

#include "Expresie.h"

using namespace std;

void Expresie::setRezultate(int* v) {
	if (rezultate != nullptr) {
		delete[]rezultate;
	}
	rezultate = new int[lungimeRez];
	if (lungimeRez != 0) {
		for (int i = 0; i < lungimeRez; i++)
		{
			rezultate[i] = v[i];
		}
	}
}
void Expresie::realocaRezultate(int* vec, int n) {
	int* v;


	v = new int[lungimeRez];
	for (int i = 0; i < lungimeRez; i++) {
		v[i] = vec[i];
	}
	delete[]vec;
	vec = new int[lungimeRez + 1];

	for (int i = 0; i < lungimeRez; i++) {
		vec[i] = v[i];
	}
	vec[lungimeRez + 1] = n;
	delete[]v;
}

	int Expresie::getLungimeExpresie() {
		return lungimeExpresie;
	}
	int Expresie::getLungimeRez() {
		return lungimeRez;
	}

	char* Expresie::getExpresie() {
		return expresie;
	}

	

	void Expresie::setLungimeRez(int x) {
		if (x > 0)
		{
			lungimeRez = x;
		}
	}

	void Expresie::setLungimeExpresie(int x) {
		if (x > 0)
		{
			lungimeExpresie = x;
		}
	}

	void Expresie::setExpresie(const char* c) {
		if (expresie != nullptr) {
			delete[]expresie;
		}
		if (c != nullptr)
		{

			expresie = new char[lungimeExpresie + 1];
			strcpy(expresie, c);
		}
	}

	void Expresie::realocareLg(int x) {
		if (expresie != nullptr && x != lungimeExpresie && x > 0)
			delete[]expresie;
		lungimeExpresie = x;
		expresie = new char[lungimeExpresie + 1];
	}
	void Expresie::schimbExpresia(char* c) {
		if (expresie != nullptr) {
			delete[]expresie;
		}
		expresie = new char[strlen(c) + 1];
		strcpy(expresie, c);

	}

	Expresie::Expresie() {
		lungimeExpresie = 3;
		expresie = new char[lungimeExpresie + 1];
		strcpy(expresie, "1+2");
		lungimeRez = 0;
		rezultate = nullptr;
	}

	Expresie::Expresie(int lungime) {
		if (lungime > 2)
			this->lungimeExpresie = lungime;
		expresie = new char[this->lungimeExpresie + 1];
		lungimeExpresie = 0;
		rezultate = nullptr;

	}
	Expresie::Expresie(int lungime, char* c) {
		if (lungime > 2)
			this->lungimeExpresie = lungime;
		expresie = new char[this->lungimeExpresie + 1];
		if (c != nullptr) {
			strcpy(expresie, c);
		}
		lungimeExpresie = 0;
		rezultate = nullptr;
	}

	Expresie::Expresie(const Expresie& e) {
		if (e.expresie != nullptr)
			this->expresie = e.expresie;
		else
			this->expresie = nullptr;

		if (e.lungimeExpresie > 0)
			this->lungimeExpresie = e.lungimeExpresie;
		else
			this->lungimeExpresie = 1;
		this->lungimeRez = e.lungimeRez;
		if (this->lungimeRez > 0) {
			this->rezultate = new int[lungimeRez];
			for (int i = 0; i < this->lungimeRez; i++) {
				this->rezultate[i] = e.rezultate[i];

			}
		}
		else {
			this->rezultate = nullptr;
		}

	}
	Expresie& Expresie::operator=(const Expresie& e) {
		if (this != &e) {
			if (expresie != nullptr) {
				delete[]expresie;
			}

			if (e.expresie != nullptr)
				this->expresie = e.expresie;
			else
				this->expresie = nullptr;

			if (e.lungimeExpresie > 0)
				this->lungimeExpresie = e.lungimeExpresie;
			else
				this->lungimeExpresie = 1;
		}
		return *this;
	}

	int Expresie::operator+(int x) {
		lungimeExpresie = lungimeExpresie + x;
		return lungimeExpresie;
	}

	bool Expresie::operator!() {
		return lungimeExpresie != 0;
	}

	
	Expresie::~Expresie() {
		if (expresie != nullptr) {
			delete[]expresie;
		}
		if (rezultate != nullptr) {
			delete[]rezultate;
		}
	}


Expresie operator+(int x, Expresie& e) {
	return e + x;
}
istream& operator>>(istream& in, Expresie& e)
{
	string exp;
	if (e.expresie != nullptr)
		delete[]e.expresie;
	
	cout << "Introduceti expresia: ";
	in >> exp;
	e.expresie = new char[exp.length() + 1];
	e.lungimeExpresie = exp.length();
	strcpy(e.expresie, exp.data());
	return in;
}

ostream& operator<<(ostream& out, Expresie& e) {
	cout << "Expresia este: " << e.expresie;
	return out;
}
