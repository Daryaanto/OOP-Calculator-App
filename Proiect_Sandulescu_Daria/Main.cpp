#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cstring>

#include "Expresie.h"
#include "Functions.h"
#include "Operator.h"



using namespace std;





int main() {

	int r = 0, test = 0, kg1,kg2;
	string expresieGrad1,c;
	Expresie e1;
	int* rez = nullptr;

	Operator op;

	//cin >> e1;
	e1.setLungimeExpresie(9);
	e1.setExpresie("300/3-3*7");

	cout << e1 << endl;

	string expresie = Functions::convertire(e1.getExpresie());

	kg1 = kg2 = 0;

	int firstNum = stoi(expresie, 0, 10);
	r = firstNum;

	expresieGrad1 = to_string(r);



	int ln = expresieGrad1.length();

	if (expresie[ln] == '*' || expresie[ln] == '/') {
		c = expresieGrad1;
		expresieGrad1.clear();

	}

	for (int i = ln; i < expresie.length(); i++) {


		if (isdigit(expresie[i]) && c == "") {
			c += expresie[i];
					}
		else
		{
			test = Functions::numTot(i + 1, expresie + " ");
			switch (expresie[i])
			{
			case '+':
				kg2 = 0;
				if (kg1 != 0) {
					expresieGrad1 = expresieGrad1 + c;
				}
				expresieGrad1 = expresieGrad1 + expresie[i];

				c.clear();
				kg1 = 1;
				break;

			case '-':
				kg2 = 0;
				if (kg1 != 0) {
					expresieGrad1 = expresieGrad1 + c;
				}
				expresieGrad1 = expresieGrad1 + expresie[i];

				c.clear();
				kg1 = 1;
				break;

			case '*':
				kg1 = 0;

				r = op.inmultire(stoi(c), test);

				c.clear();
				expresieGrad1 = expresieGrad1 + to_string(r);
				kg2 = 1;
				break;

			case '/':

				kg1 = 0;

				r = op.impartire(stoi(c), test);
				c.clear();
				expresieGrad1 = expresieGrad1 + to_string(r);

				kg2 = 1;
				break;
			default:
				break;
			}
			e1.realocaRezultate(rez, r);
		}


	}
	cout << "---------" << endl;
	cout << "Expresia de grad 1 este = " << expresieGrad1 << endl;
	cout << "---------" << endl;

	//se prelucreaza expr de g1
	r = 0;
	c.clear();

	for (int i = 0; i < expresieGrad1.length(); i++)
	{
		if (isdigit(expresieGrad1[i]))
		{
			c += expresieGrad1[i];
		}
		else
		{
			break;
		}
	}

	r = stoi(c);
	c.clear();
	expresieGrad1 = expresieGrad1.erase(0, to_string(r).length());
	for (int i = 0; i < expresieGrad1.length(); i++) {


		if (!isdigit(expresieGrad1[i])) {

			test = Functions::numTot(i + 1, expresieGrad1);



			switch (expresieGrad1[i])
			{
			case '+':
				r = op.adunare(r, test);
				c.clear();

				break;

			case '-':
				r = op.scadere(r, test);
				c.clear();

				break;

			default:
				break;
			}

		}

	}

	

		cout << "Rezultat final = " << r << endl;

	cout << "---------" << endl;

	for (int i = 0; i < e1.getLungimeRez(); i++)
	{
		cout << rez[i] << " ";
	}

}