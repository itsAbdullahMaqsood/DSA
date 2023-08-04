#include <iostream>			//Time Complexity = O(n)
using namespace std;

void countSort(int arr[],int start, int end) {
	
	int countArray[12]{};		//the actual numbers you can sort should not be greater than 9 because the size of countArray is 0-9
								//in order to store a greater number 'n' , the size of the countArray should be 'n+1'.
	
	int range = 12;				//and ofcourse, change this range variable to 'n+1' aswell.

	for (int i = 0; i <= end; i++)		//to increment the repetetive number's count.
	{
		countArray[arr[i]]++;
	}

	for (int i = 0; i < (range - 1); i++)		//for adding the 1st block to the 2nd, the 2nd to the 3rd and so forth. To make a cumulative countArray.
	{
		countArray[i + 1] += countArray[i];
	}

	int pos = 0;		//for sorting the values.
	for (int i = 0; i <= end+1; i++)
	{
		while (pos < countArray[i]) {
			arr[pos] = i;
			pos++;
		}
	}

}

int main() {

	int arr[] = { 5,6,4,4,9,3,7,5,5,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int start = 0;
	int end = size - 1;

	countSort(arr, start, end);			//This is a non-comparative sorting algorithm.

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	

	return 0;
}