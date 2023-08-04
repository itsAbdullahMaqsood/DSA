#include <iostream>
using namespace std;

int main() {

	int arr[5] = { 55,3,65,24,17 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << "\t";
	}

	

	for (int i = 0; i < size - 1; i++)				//bubble sorting
	{
		int flag = false;					// the flag is used to break out of the loop if the array gets sorted in the middle
											// of the 'i' loop, for example, if it gets fully sorted on the first loop, why run
											// the loop till the end of "i<size-1" condition, why not break out on the second
											// iteration?, so flag is added to indicate if we should break out.
		for (int j = 0; j < size - (i + 1); j++)
		{
			if (arr[j] > arr[j + 1]) {
				flag = true;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		} 
		if (flag == false)
			break;
		
	}

	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << "\t";
	}


	return 0;
}
