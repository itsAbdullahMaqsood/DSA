#include <iostream>
using namespace std;

int findMax(int arr[], int end) {
	int max = arr[0];
	for (int i = 0; i <= end; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

void countSort(int arr[], int start, int end, int div) {
	
	int countArray[10]{};

	int outputArray[8]{};

	for (int i = 0; i <= end; i++)
	{
		countArray[(arr[i] / div) % 10]++;
	}

	for (int i = 0; i < (10-1); i++)
	{
		countArray[i + 1] += countArray[i];
	}

	for (int i = 0; i <= end; i++)
	{
		outputArray[countArray[(arr[i] % div) % 10] - 1] = arr[i];
	}

	for (int i = 0; i <= end; i++)
	{
		arr[i] = outputArray[i];
		cout << arr[i] << " ";
	}

}

void radixSort(int arr[], int start, int end) {
	int m = findMax(arr, end);

	for (int div = 1; m/div >= 0; div*=10)
	{
		countSort(arr, start, end, div);
	}

	

}

int main() {

	int arr[] = { 170,45,24,75,90,802,24,2,66 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int start = 0;
	int end = size - 1;

	//radixSort(arr, start, end);			//This is a non-comparative sorting algorithm.
	
	//--------------------------------------------------------------------------------------------
	int m = findMax(arr, end);

	for (int div = 1; m / div > 0; div *= 10)
	{
		int countArray[10]{};

		for (int i = 0; i < 10; i++)
		{
			countArray[i] = 0;
		}

		int outputArray[9]{};

		for (int i = 0; i <= end; i++)
		{
			(countArray[(arr[i] / div) % 10])++;
		}

		for (int i = 0; i < (10 - 1); i++)
		{
			countArray[i + 1] += countArray[i];
		}
		
		for (int i = end; i >= 0; i--)			//dry run this from end to 0 for practice
		{
			outputArray[--countArray[(arr[i] / div) % 10]] = arr[i];
		}

		for (int i = 0; i <= end; i++)
		{
			arr[i] = outputArray[i];
		}
	}

	


	//--------------------------------------------------------------------------------------------

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	

	return 0;
}