#include <iostream>
#include "sort.h"

int main()
{
	int a[] = { 3, 2, 5, 4, 1, 9, 7, 6, 8 };
	std::cout << "Array before sort: ";
	for (auto x : a)
	{
		std::cout << x << " ";
	}

	std::cout << "\n";
	SelectionSort(a, sizeof(a)/sizeof(int));

	std::cout << "Array after sort: ";
	for (auto x : a)
	{
		std::cout << x << " ";
	}
}