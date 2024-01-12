#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cstring>

#include "Operator.h"

using namespace std;



	Operator::Operator() {
		tipOperator = "Multifunctional";
		int grad = 10;
	}


	Operator::Operator(string op) {
		tipOperator = op;
	}
	Operator::Operator(const Operator& o) {
		this->tipOperator = o.tipOperator;
		this->grad = o.grad;
	}

	Operator Operator::operator++(int x) {
		Operator copy = *this;
		this->grad++;
		return copy;
	}

	bool Operator::operator==(const Operator& o) {
		return this->grad == o.grad;
	}

	int Operator::adunare(int a, int b) {
		return a + b;
	}

	int Operator::scadere(int a, int b) {
		return a - b;
	}
	int Operator::inmultire(int a, int b) {
		return a * b;
	}
	int Operator::impartire(int a, int b) {
		if (b == 0) {
			cout << "Nu se poate imparti la 0" << endl;
			return -1;
		}

		else
			return a / b;
	}

	int Operator::getGrad() {
		return grad;
	}
	string Operator::getTip() {
		return tipOperator;
	}

	void Operator::setGrad(int x) {
		if (x > 0 && x < 4) {
			grad = x;
		}
	}
	void Operator::setTip(string s) {
		tipOperator = s;
	}

	
istream& operator>>(istream& in, Operator& o) {
	cout << "Gradul operatorului: ";
	in >> o.grad;
	cout << endl;
	cout << "Tipul operatorului (+, -, *, /): ";
	in >> o.tipOperator;
	return in;
}

ostream& operator<<(ostream& out, Operator& o) {
	cout << "Operatorul " << o.tipOperator << " are gradul " << o.grad << endl;
	return out;

}