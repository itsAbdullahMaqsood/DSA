#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
	
	int temp[9];
	int i = left;
	int j = mid+1 ;
	int currPos = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[currPos] = arr[i];
			i++; currPos++;
		}
		else {
			temp[currPos] = arr[j];
			j++; currPos++;
		}
	}
	while (i <= mid) {
		temp[currPos] = arr[i];
		i++; currPos++;
	}
	while (j <= right) {
		temp[currPos] = arr[j];
		j++; currPos++;
	}
	for (int n = left; n <=right; n++)
	{
		arr[n] = temp[n];
	}

}

void mergeSort(int arr[], int left, int right) {

	

	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}

}


int main() {
	
	int arr[9] = {9,8,7,6,5,4,3,2,1};

	int left = 0;
	int right = 8;


	mergeSort(arr, left, right);

	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}