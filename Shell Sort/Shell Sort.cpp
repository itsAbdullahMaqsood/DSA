#include <iostream>
using namespace std;



int main() {

	int arr[8] = { 8,7,6,5,4,3,2,1 };
	int halfSize = 8;
	
	while(halfSize/2 > 0){
		halfSize /= 2;
		for (int i = halfSize; i < 8; i++)
		{
			if (arr[i] < arr[i - halfSize]) {
				int temp = arr[i];
				arr[i] = arr[i - halfSize];
				arr[i - halfSize] = temp;
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}