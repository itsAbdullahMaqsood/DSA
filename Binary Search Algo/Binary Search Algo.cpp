#include <iostream>
using namespace std;

void BinarySearch(int arr[]) {
	//int size = sizeof(arr)/sizeof(arr[0]);		//can't do this here because the arr of this function is a pointer that
													//is pointing to an array of the main function, and using the sizeof() 
													//operator here would not give us the right size, like it does in the 
													//main function.
	int left = 0, right = 19, input, mid;
	bool found = false;

	cout << "enter the number you want to find";
	cin >> input;
	cout << endl;

	while (left <= right) {
		mid = (left + right) / 2;

		if (input == arr[mid]) {
			found = true;
			break;
		}

		else if (input < arr[mid])
			right = mid - 1;

		else if (input > arr[mid])
			left = mid + 1;

	}

	if (found == false) {
		cout << "number not found in the array" << endl;
	}
	else {
		cout << "index is: " << mid;
	}
	
}

int main() {

	int arr[20];			//this array must be sorted for the binary search algorithm to work
	for (int i = 0; i < 20; i++)
	{
		arr[i] = i;					//20 numbers in ascending order 
	}
	while (true) {
		cout << endl;
		BinarySearch(arr);
	}
	return 0;
}