#include <iostream>
using namespace std;

void insertionSort(int arr[]) {			// O(n^2)
	for (int i = 0; i < 5; i++)
	{
		int min = arr[i];
		for (int j = i+1; j <=i; j++)
		{	
			if (min > arr[j]) {
				int temp = min;
				min = arr[j];
				arr[j] = temp;
			}
		}
		int m = i;
		for (int k = i-1; k >=0; k--) {
			if (arr[k] > arr[m])
			{
				int temp2 = arr[m];
				arr[m] = arr[k];
				arr[k] = temp2;
				m--;
			}
		}
	}
}

void insertionSort2(int arr[]) {		//O(n^2)
	for (int i = 1; i < 5; i++)
	{	
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
			arr[j+1] = key;

	}
}


int main() {

	int arr[5] = { 5,8,3,2,0 };

	insertionSort2(arr);

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << "\t";
	}

	return 0;
}