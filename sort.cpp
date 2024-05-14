#include <iostream>
#include "sort.h"

void swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

void BubbleSort(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] > arr[j]) swap(arr[i], arr[j]);
		}
	}
}

void InsertionSort(int* arr, int n)
{
	for (int i = n; i >= 0; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
}

void SelectionSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_index]) min_index = j;
		}
		swap(arr[min_index], arr[i]);
	}
}
