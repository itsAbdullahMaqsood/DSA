#include <iostream>
using namespace std;

void linearSearch(int arr[], int size) {
	bool found = false;
	int input;
	cout << "enter the number would you like to find: ";
	cin >> input;
	for (int i = 0; i < size; i++)
	{	
		if (input == *(arr+i)) {
			cout << "found at index: " << i << endl;
			found = true;
			break;
		}
		
		
	}
	if (found == false) {
		cout << "element not found";
	}

}

int recursiveLinearSearch(int arr[], int size, int input) {
	static bool found = false;
	static int temp = 0;
	if (temp == size && found == false) {
		cout << "element not found";
		return 0;
	}
	else {

		if (input == arr[temp]) {
			return temp;
		}
		else{ 
			temp++;
			recursiveLinearSearch (arr, size, input);
		}
		
	}
}

int main() {

	int size;
	cout << "enter the size of the array: ";
	cin >> size;
	int* arr = new int [size] ;
	for (int i = 0; i < size; i++)
	{			
		cin >> *(arr+ i);
	}
	
	char choice;
	cout << "would you like to do this search with recursion? (y/n) ";
	cin >> choice;
	switch (choice) {
	case 'n':
		linearSearch(arr, size);

		break;
	case 'y':
		int input;
		cout << "enter the number would you like to find: ";
		cin >> input;

		cout << "found at index: " << recursiveLinearSearch(arr, size, input) << endl;

		break;
	}

	delete[] arr;

	return 0;
}