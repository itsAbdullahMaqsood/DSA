#include <iostream>
using namespace std;

int main() {

	int arr[5] = { 5,4,3,2,1 };

	int min = arr[0];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}


	return 0;
}