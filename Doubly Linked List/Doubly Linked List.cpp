#include <iostream>
#include <conio.h>
using namespace std;

class Node {
public:
	int key, data;
	Node* prev;
	Node* next;

	Node() {
		key = 0;
		data = 0;
		prev = NULL;
		next = NULL;
	}

	Node(int key, int data) {
		this->key = key;
		this->data = data;
		prev = NULL;
		next = NULL;
	}

};

Node* n1;

class DoublyLinkedList {
public:
	Node* head;
	Node* Temp = head;				//Temp and special_ptr are for traversing purposes only.
	Node* special_ptr = head;

	void startupTemp() {
		Temp = head;
		special_ptr = head;
	}

	Node* nodeExists(int key) {
		Node* ptr = head;
		Node* temp = NULL;
		while (ptr != NULL) {
			if (ptr->key == key) {
				temp = ptr;
			}
				ptr = ptr->next;
		}
		return temp;
	}
	
	void appendNode(Node* n) {
		if (head == NULL) {
			head = n;
			cout << "node appended"<<endl;
			n1 = new Node();

		}
		else if (nodeExists(n->key) == NULL) {
			Node* ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = n;
			n->prev = ptr;
			cout << "new node appended"<<endl;
			n1 = new Node();

		}
		else {
			cout << "node already exists in the list"<<endl;
		}
	}

	void prependNode(Node* n) {
		if (head == NULL) {
			head = n;
			cout << "Node prepended"<<endl;
			n1 = new Node();
		}
		else if(nodeExists(n->key) == NULL) {
			n->next = head;
			head->prev = n;
			head = NULL;
			head = n;
			cout << "Node prepended"<<endl;
			n1 = new Node();

		}
		else {
			cout << "node already exists in the list" << endl;
		}
	}


	void insertNode(int afterKey, Node* n) {
		
		if (head == NULL) {
			cout << "can't insert in empty list"<<endl;
		}
		else if (nodeExists(afterKey) == NULL) {
			cout << "invalid after key ";
		}
		else if (nodeExists(n->key) == NULL && nodeExists(afterKey)->next == NULL) {
			Node* ptr = nodeExists(afterKey);
			ptr->next = n;
			n->prev = ptr;
			cout << "node inserted at the end"<<endl;
			n1 = new Node();


		}
		else if(nodeExists(n->key) == NULL && nodeExists(afterKey)->next != NULL)
		{
			Node* temp;
			Node* ptr = nodeExists(afterKey);	

			n->next = ptr->next;
			ptr->next = n;
			n->prev = ptr;
			temp = n->next;
			temp->prev = n;
			cout << "node inserted in between"<<endl;
			n1 = new Node();

		}
		else {
			cout << "node already exists in the list"<<endl;
		}
	}

	void deleteNode(int key) {
		
		if (nodeExists(key)!=NULL)
		{
			if (nodeExists(key)->key == Temp->key) {
				if (Temp->next == NULL) {
					Temp = Temp->prev;
					special_ptr = Temp;
				}
				else {
					Temp = Temp->next;
					special_ptr = Temp;
				}
			}
			if (head->next == NULL) {
				delete head;
				head = NULL;
				cout << "Node Deleted" << endl;
			}
			else if (nodeExists(key)->key == head->key) {
				Node* ptr = head->next;
				head->next = NULL;
				delete head;
				head = ptr;
				head->prev = NULL;
			cout << "Node Deleted"<<endl;
			}
			else if(nodeExists(key)->next != NULL) {
				Node* ptr = nodeExists(key);

				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				ptr->next = NULL;
				ptr->prev = NULL;
				delete ptr;
				ptr = NULL;
			cout << "Node Deleted"<<endl;
			}
			else if (nodeExists(key)->next == NULL) {
				Node* ptr = nodeExists(key);
				ptr->prev->next = NULL;
				ptr->prev = NULL;
				delete ptr;
				ptr = NULL;
				
			}
		}
		else {
			cout << "Node doesn't exist in the list"<<endl;
		}
		
	}

	void updateNode(int key, int data) {
		Node* ptr = nodeExists(key);
		ptr->data = data;
		cout << "node value updated"<<endl;
	}

	void changeTemp(char input) {
		switch (input) {
		case 'f':                       
			if (special_ptr->next != NULL)
			{
				special_ptr = special_ptr->next;
				Temp = special_ptr;
				cout << "Temp forwarded"<<endl;
			}
			else {
				cout << "We're on the last node"<<endl;
			break;
		case 'r':
			if (special_ptr->prev != NULL) {
				special_ptr = special_ptr->prev;
				Temp = special_ptr;
				cout << "Temp reversed"<<endl;
			}
			else {
				cout << "We're on the first node"<<endl;
			}
			}
		}
	}

	void printList() {
		if (head != NULL )
		{
			Node* ptr = head;
			static int count = 0;
			count++;
			if (count == 1) {
				startupTemp();
			}
			cout << endl << endl;
			cout << "head = " << head->key << " : " << head->data;
			cout << endl;
			cout << "Temp = " << Temp->key << " : " << Temp->data;
			cout << endl;
			while (ptr != NULL) {
				cout << ptr->key << " : " << ptr->data << " <---> ";
				ptr = ptr->next;
			}
		}

	}

};

int main() {

	// append, prepend, insert, delete, update, traverse Temp

	

	DoublyLinkedList d;

	int key, value, selection;
	bool one = false;


	if (one == false)
	{
		one = true;
		n1 = new Node();
	}

	do {
		cout << "1.append node \n2.prepend node \n3.insert node \n4.delete node \n5.update node \n6.traverse \"Temp\" ";
		d.printList();
		cout << endl << endl;
		cout << "selection:";
		cin >> selection;
		switch (selection) {
		case 1:
			cout << "key: ";
			cin >> key;
			cout << "value: ";
			cin >> value;
			n1->key = key;
			n1->data = value;
			d.appendNode(n1);
			break;
		case 2:
			cout << "key: ";
			cin >> key;
			cout << "value: ";
			cin >> value;
			n1->key = key;
			n1->data = value;
			d.prependNode(n1);
			break;
		case 3:
			int after;
			cout << "key: ";
			cin >> key;
			cout << "value: ";
			cin >> value;
			n1->key = key;
			n1->data = value;
			cout << "insert after key:  ";
			cin >> after;
			d.insertNode(after, n1);
			break;
		case 4:
			cout << "key: ";
			cin >> key;
			d.deleteNode(key);
			break;
		case 5:
			cout << "key to update: ";
			cin >> key;
			cout << "new value: ";
			cin >> value;
			d.updateNode(key, value);
			break;
		case 6:
			cout << "input: ";			//enter f or r
			char input;
			input = _getch();
			d.changeTemp(input);
			break;
		case 0:
			delete n1;
		}
		_getch();
		system("cls");
	} while (selection != 0);

	cout << "program quit";

	return 0;
}