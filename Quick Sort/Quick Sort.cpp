#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {
	int pIndex = start;				// pIndex is the "soon to be pivot" while, end is the "current pivot"
	
	for (int i = start; i <= end; i++)
	{
		if (arr[i] < arr[end]) {
			int temp = arr[pIndex];
			arr[pIndex] = arr[i];
			arr[i] = temp;
			pIndex++;
		}
	}

	int temp = arr[end];
	arr[end] = arr[pIndex];
	arr[pIndex] = temp;

	return pIndex;

}

void quickSort(int arr[], int start, int end) {
	if (start<end)
	{
		int p = partition(arr, start, end);
		quickSort(arr, start, (p - 1));
		quickSort(arr, (p + 1), end);
	}
}

int main() {

	int arr[] = { 5,6,4,3,8,7,1,2,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int start = 0;
	int end = size -1;

	quickSort(arr, start, end);

	for (int i = 0; i < size ; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}