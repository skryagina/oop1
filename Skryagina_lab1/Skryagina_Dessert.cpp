#include "Skryagina_Dessert.h"
#include "Utilities.h"

int Dessert::maxId = 0;

int Dessert::GetId()
{
    return Id;
}

istream& operator>>(istream& in, Dessert& newDessert)
{
    newDessert.Id = ++newDessert.maxId;
    cout << "ID: " << newDessert.Id;
    cout << "\nВведите наименование десерта: ";
    //in.ignore();
    getline(in, newDessert.dessertName);
    cout << "\nВведите цену десерта: ";
    newDessert.dessertPrice = GetCorrectData(50, 10000);
    cout << "\nВведите вес десерта: ";
    newDessert.dessertWeight = GetCorrectData(100.0, 3000.0);
    cout << "\nЕсли десерт в наличии, укажите 1; иначе - 0: ";
    newDessert.dessertAvailability = GetCorrectData(0, 1);
    return in;
}

ostream& operator<<(ostream& out, const Dessert& newDessert)
{
    if (newDessert.dessertName == "None")
    {
        out << "Десертов в наличии нет." << endl;
    }
    else
    {
        out << "ID: " << newDessert.Id << "\tНаименование: " << newDessert.dessertName <<
            "\tЦена: " << newDessert.dessertPrice << "\tВес: " << newDessert.dessertWeight;
    }

    return out;
}

ifstream& operator>>(ifstream& fin, Dessert& newDessert)
{
    fin >> newDessert.Id;
    newDessert.maxId = newDessert.Id;
    fin.ignore();
    getline(fin, newDessert.dessertName);
    fin >> newDessert.dessertPrice;
    fin >> newDessert.dessertWeight;
    fin >> newDessert.dessertAvailability;
    return fin;
}

ofstream& operator<<(ofstream& fout, const Dessert& newDessert)
{
    fout << newDessert.Id << "\n" << newDessert.dessertName << "\n" << newDessert.dessertPrice << "\n" <<
        newDessert.dessertWeight << "\n" << newDessert.dessertAvailability << endl;
    return fout;
}