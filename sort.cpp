﻿#include <iostream>
#include "sort.h"
#include <vector>

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


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void QuickSort1(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		QuickSort1(arr, low, pi - 1);
		QuickSort1(arr, pi + 1, high);
	}
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* Tạo các mảng tạm */
	std::vector<int> L, R;
	L.resize(n1);
	R.resize(n2);

	/* Copy dữ liệu sang các mảng tạm */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Gộp hai mảng tạm vừa rồi vào mảng arr*/
	i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
	j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
	k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy các phần tử còn lại của mảng L vào arr nếu có */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy các phần tử còn lại của mảng R vào arr nếu có */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
		int m = l + (r - l) / 2;

		// Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


void heapify(int arr[], int N, int i)
{
	// Khởi tạo largest là gốc
	int largest = i; // 'i' là chỉ số của gốc của cây con đang được heapify

	// left = 2*i + 1
	int l = 2 * i + 1; // 'l' là chỉ số của con trái

	// right = 2*i + 2
	int r = 2 * i + 2; // 'r' là chỉ số của con phải

	// Nếu con trái lớn hơn gốc
	if (l < N && arr[l] > arr[largest])
		largest = l; // Cập nhật largest nếu con trái lớn hơn gốc

	// Nếu con phải lớn hơn largest cho đến nay
	if (r < N && arr[r] > arr[largest])
		largest = r; // Cập nhật largest nếu con phải lớn hơn largest hiện tại

	// Nếu largest không phải là gốc
	if (largest != i) {
		swap(arr[i], arr[largest]); // Hoán đổi gốc với largest

		// Đệ quy heapify cây con bị ảnh hưởng
		heapify(arr, N, largest); // Đệ quy để heapify cây con ở vị trí largest
	}
}

void heapSort(int arr[], int N)
{
	// Xây dựng heap (sắp xếp lại mảng)
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	// Trích xuất từng phần tử từ heap
	for (int i = N - 1; i > 0; i--) {
		// Di chuyển gốc hiện tại đến cuối
		swap(arr[0], arr[i]);

		// Gọi heapify trên heap đã bị giảm kích thước
		heapify(arr, i, 0);
	}
}

