#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Skryagina_Dessert.h"

using namespace std;

class Group_Dessert
{
public:
	void addDessert();
	void readDessert(ifstream& fin);
	void saveDessert(ofstream& fout);
	void deleteDessert();

	friend ostream& operator<<(ostream& grout, const Group_Dessert& group);

	~Group_Dessert()
	{
	}

protected:
	vector<Dessert*> ptrsDessert;
};