#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Dessert
{
protected:
	static int maxId;
	int Id;
	string dessertName = "None";
	int dessertPrice = 0;
	double dessertWeight = 0.0;
	bool dessertAvailability = 1;

	int GetId();

public:
	friend istream& operator>> (istream& in, Dessert& newDessert);
	friend ostream& operator<< (ostream& out, const Dessert& newDessert);
	friend ifstream& operator>> (ifstream& fin, Dessert& newDessert);
	friend ofstream& operator<< (ofstream& fout, const Dessert& newDessert);
};

