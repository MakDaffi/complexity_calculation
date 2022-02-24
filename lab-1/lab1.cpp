#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//ф-ция "шейкер"-сортировки
void myShakerSort(vector<int> &arr, const int size) {
	int leftMark = 1;
	int rightMark = size - 1;
	while (leftMark <= rightMark) {
		for (int i = rightMark; i >= leftMark; i--)
		if (arr[i - 1] > arr[i]) swap(arr[i], arr[i-1]);
		leftMark++;

		for (int i = leftMark; i <= rightMark; i++)
		if (arr[i - 1] > arr[i]) swap(arr[i], arr[i-1]);
		rightMark--;
	}
}

int main(void) {
	setlocale(LC_ALL, "rus");

	int size;
	cout << "Размер массива: ";
	cin >> size;
	vector<int> arr (size);
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	myShakerSort(arr, size); // сортировка

	cout << "Массив после сортировки:\n";
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}