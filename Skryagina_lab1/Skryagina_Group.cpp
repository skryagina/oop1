#include "Skryagina_Group.h"
#include "Utilities.h"

void Group_Dessert::addDessert()
{
	Dessert* dessert0 = new Dessert;
	cin >> *dessert0;
	ptrsDessert.push_back(dessert0);
}

void Group_Dessert::deleteDessert()
{
	for (auto& elem : ptrsDessert)
		delete elem;
	ptrsDessert.clear();
}

ostream& operator<<(ostream& grout, const Group_Dessert& group)
{
	grout << "Имеющиеся блюда:" << endl;
	if (group.ptrsDessert.size() == 0)
		grout << "Блюд нет.";
	else
	{
		for (const auto& elem : group.ptrsDessert) {
			grout << *elem << endl;
		}
	}
	grout << endl;
	return grout;
}

void Group_Dessert::readDessert(ifstream& fin)
{
	if (!fin.is_open())
		cout << "\nТакого файла не существует.";
	else
	{
		deleteDessert();
		int n = 0;
		fin >> n;
		for (int i = 0; i < n; i++) {
			Dessert* dessert0 = new Dessert;
			fin >> *dessert0;
			ptrsDessert.push_back(dessert0);
		}
		cout << "\nДанные успешно загружены!" << endl;
	}
}

void Group_Dessert::saveDessert(ofstream& fout)
{
	if (ptrsDessert.size() == 0)
		cout << "\nСписок блюд пуст." << endl;
	else
	{
		fout << ptrsDessert.size() << endl;
		for (auto elem : ptrsDessert) {
			fout << *elem;
		}
		cout << "\nДанные успешно сохранены!" << endl;
	}
}


