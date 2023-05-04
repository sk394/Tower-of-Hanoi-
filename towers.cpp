#include <iostream>
#include "towers.h"


using namespace std;

Towers::Towers(int n)
{
	peg1 = new MyStack<int>(n);
	peg2 = new MyStack<int>(n);
	peg3 = new MyStack<int>(n);
	numDisk = n;
}

Towers::~Towers()
{
	delete peg1;
	delete peg2;
	delete peg3;
}

Towers::Towers(const Towers& t)
{
	peg1 = new MyStack<int>(*t.peg1);
	peg2 = new MyStack<int>(*t.peg2);
	peg3 = new MyStack<int>(*t.peg3);
	numDisk = t.numDisk;
}

Towers& Towers::operator=(const Towers& t)
{
	if (this != &t)
	{
		delete peg1;
		delete peg2;
		delete peg3;
		peg1 = new MyStack<int>(*t.peg1);
		peg2 = new MyStack<int>(*t.peg2);
		peg3 = new MyStack<int>(*t.peg3);
		numDisk = t.numDisk;
	}
	return *this;
}

void Towers::setDisks()
{
	for (int i = numDisk; i > 0; i--)
	{
		peg1->push(i);
	}
	plotPegs();
}

void Towers::move(int n, MyStack<int>* s, MyStack<int>* t, MyStack<int>* d)
{
	if (n == 1)
	{
		moveOne(s, d);
	}
	else
	{
		move(n - 1, s, d, t);
		moveOne(s, d);
		move(n - 1, t, s, d);
	}
}

void Towers::moveOne(MyStack<int>* s, MyStack<int>* d)
{
	int temp = s->top();
	s->pop();
	d->push(temp);
	plotPegs();
}


//display disks on the three pegs in the console window (stdout)
//DO NOT MODIFY THIS FUNCTION
void Towers::plotPegs()
{
	if (peg1 == NULL || peg2 == NULL || peg3 == NULL) return;

	int n1 = peg1->size();
	int n2 = peg2->size();
	int n3 = peg3->size();
	int numDisk = n1 + n2 + n3;

	MyStack<int> tmp1(*peg1);
	MyStack<int> tmp2(*peg2);
	MyStack<int> tmp3(*peg3);

	//plot
	for (int i = 0; i < numDisk; i++) {
		//peg1
		if (numDisk - n1 - i > 0) {
			for (int j = 0; j < numDisk; j++)
				cout << " ";
		}
		else {
			int m1 = tmp1.top();
			tmp1.pop();
			for (int j = 0; j < m1; j++)
				cout << "*";
			for (int j = m1; j < numDisk; j++)
				cout << " ";
		}
		cout << " | ";

		//peg2
		if (numDisk - n2 - i > 0) {
			for (int j = 0; j < numDisk; j++)
				cout << " ";
		}
		else {
			int m2 = tmp2.top();
			tmp2.pop();
			for (int j = 0; j < m2; j++)
				cout << "*";
			for (int j = m2; j < numDisk; j++)
				cout << " ";
		}
		cout << " | ";

		//peg3
		if (numDisk - n3 - i > 0) {
			for (int j = 0; j < numDisk; j++)
				cout << " ";
		}
		else {
			int m3 = tmp3.top();
			tmp3.pop();
			for (int j = 0; j < m3; j++)
				cout << "*";
			for (int j = m3; j < numDisk; j++)
				cout << " ";
		}
		cout << endl;
	}
	cout << "_________________________________________\n";
}
