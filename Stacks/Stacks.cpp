#include <iostream>
#include <conio.h>
using namespace std;

class Stack {
	int arr[5];
	int top = -1;

public:

	Stack() {
		for (int i = 0; i < 5; i++)
		{
			arr[i] = 0;
		}
	}

	bool isFull() {
		if (top == 4) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isEmpty() {
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	void push(int value ) {
		if (!isFull()) {
			top++;
			arr[top] = value;
		}
		else {
			cout << "stack overflow";
		}
	}
	
	int pop() {
		int temp = 0;
		if (!isEmpty()) {
			temp = arr[top];
			arr[top] = 0;
			top--;
			return temp;
		}
		else {
			cout << "stack underflow";
			return 0;
		}
	}

	int peek(int position) {
		if (position >= 1 || position <= 4) {
			return arr[position];
		}
		else {
			cout << "invalid";
			return 0;
		}
	}

	void change(int position, int value) {
		if (position >= 1 || position <= 4) {
			 arr[position] = value;
			 cout << "value changed";
		}
		else {
			cout << "invalid";
		}
	}

	int count() {
		return (top+1);
	}

	void display() {
		for (int i = 4; i >=0; i--)
		{
			cout << arr[i] << endl;
		}
		
	}
};


int main() {


	Stack s;
	int pos,val,selection;
	do {
		cout << "1.Push \n2.Pop \n3.isFull \n4.isEmpty \n5.peek \n6.change \n7.count \n8.display";
		cout << "\n\nselection: ";
		cin >> selection;
		cout << endl << endl << endl;
		switch (selection) {
		case 1:
			cout << "value: ";
			cin >> val;
			s.push(val);
			break;
		case 2:
			cout << " The popped value is : " << s.pop();
			break;
		case 3:
			cout << s.isFull();
			break;
		case 4:
			cout << s.isEmpty();
			break;
		case 5:
			cout << "position: ";
			cin >> pos;
			cout << s.peek(pos);
			break;
		case 6:
			cout << "position: ";
			cin >> pos;
			cout << "value";
			cin >> val;
			s.change(pos, val);
			break;
		case 7:
			cout << s.count();
			break;
		case 8:
			s.display();
			break;
		}
		cout << "\n...........press any key to erase........";
		_getch();
		system("cls");
	} while (true);

	return 0;
}