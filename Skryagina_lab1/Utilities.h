#pragma once
#include <iostream>

using namespace std;

template <typename Type>
Type GetCorrectData(Type min, Type max)
{
	Type x;
	while ((std::cin >> x).fail() || std::cin.peek() != '\n' || x < min || x > max)
	{
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cout << "\n����������, ������� ���������� ������! ������ ������ ������ � ���������� [" << min << " - " << max << "]";
		std::cout << "\n��������� ����: ";
	}

	std::cin.ignore(100000, '\n');
	return x;
}