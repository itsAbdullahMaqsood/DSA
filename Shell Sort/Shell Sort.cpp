#include <iostream>
using namespace std;



int main() {

	int arr[8] = { 8,7,6,5,4,3,2,1 };
	int halfSize = 8;
	//while(halfSize/2 > 0){
	//	halfSize /= 2;
	//	for (int i = 0; i < 8; i++)
	//	{
	//		int check = i - halfSize;		//this checks if the range is within the range of the array i.e 0-7;
	//		if ((check >= 0 && check < 8) && arr[i] < arr[i - halfSize]) {
	//			int temp = arr[i];
	//			arr[i] = arr[i - halfSize];
	//			arr[i - halfSize] = temp;
	//		}
	//	}
	//}
	
	while(halfSize/2 > 0){
		halfSize /= 2;
		for (int j = halfSize; j < 8; j++)
		{
			int temp = arr[j];
			int i = 0;

			for (int i = j; i > halfSize && arr[i- halfSize] > temp ; i-=halfSize)
			{
				arr[i] = arr[i - halfSize];
			}
			arr[i] = temp;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}