#include <iostream>
#include <conio.h>
using namespace std;

class Node {			//blueprint for a node
public:
	int key;
	int data;
	Node* next;

	Node() {			//default constructor
		key = 0;
		data = 0;
		next = NULL;
	}

	Node(int k, int d) {		//parameterized constructor
		key = k;
		data = d;
		next = NULL;
	}

};

class SinglyLinkedList {
public:
	Node* head;

	SinglyLinkedList() {
		head = NULL;
	}
	SinglyLinkedList(Node* n) {
		head = n;
	} 

	Node* nodeExists(int k) {			// check if a node exists using key value
		Node* temp = NULL;
		Node* ptr = head;
		while (ptr != NULL) {			//this is how you traverse through a linked list
			if (ptr->key == k) {
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	}

	
	void appendNode(Node* n) {		//appends a node to the end of the list.
		if (head == NULL) {				//we checked for the existence of head first.
			head = n;
			cout << "node appended"<<endl;
		}
		else
		{
			Node* ptr = head;
			if (nodeExists(n->key) == NULL)
			{
				while (ptr->next != NULL) {
					ptr = ptr->next; 
				}
				ptr->next = n;
				cout << "new node appended"<<endl;
			}
			else {
				cout << "node already exists in the list"<<endl;
			}
		}
		
	}

	void prependNode(Node* n) {		//prepends a node to the start of the list
		if (head == NULL){			//if head is null, it will start pointing at the given node
			head = n;
		}
		else {
			
			if (nodeExists(n->key) == NULL)	//if the passed new object's key is not already in the
			{								//list, the new object will point to the object that the
				n->next = head;				//head is pointing at, and then the head will point to 
				head = NULL;				//the new object. 
				head = n;					//in this way a new node/object is added into the list.
				cout << "Node prepended"<<endl;
			}
			else {
				cout << "node already exists in the list"<<endl;
			}
		}
	}

	void insertNode(int key, Node* n) {		//insert node after a unique key.
		Node* ptr = nodeExists(key);
		if (nodeExists(n->key) == NULL) {
			if (ptr != NULL) {
					n->next = ptr->next;
					ptr->next = NULL;
					ptr->next = n;
					cout << "Node inserted"<<endl;

			}
			else {
				cout << "node with key: " << key << "doesnot exist"<<endl;
			}
		}
		else
		{
			cout << "node already exists"<<endl;
		}
	}

	void deleteNode(int key) {		//delete a node using key.
		Node* ptr = nodeExists(key);
		Node* temp = head;
		if (head == NULL) {
			cout << "Singly linked list is empty"<<endl;
		}
		else if (head->key == key) {
			head = head->next;
			temp->next = NULL;
			cout << "the deleted key was next to head, head changed now"<<endl;
		}
		else
		{
			while (temp->key != (key - 1)) {
				temp = temp->next;
			}
			temp->next = ptr->next;
			ptr->next = NULL;
			cout << "node deleted"<<endl;
		}
		
	}

	void updateNode(int key, int data) {		//update a node using key.
		Node* ptr = nodeExists(key);
		if (ptr != NULL) {
			ptr->data = data;
			cout << "updated"<<endl;
		}
		else {
			cout << "node doesnot exist"<<endl;
		}
	}

	void printList() {			//print the linked list.
		Node* ptr = head;
		cout << endl;
		while (ptr != NULL){
			cout << ptr->key << " : " << ptr->data << "  --> ";
			ptr = ptr->next;
		}
	}
};

int main() {

	SinglyLinkedList s;
	
	int key, value, selection;
	
	do {

		Node* n1 = new Node();
		cout << "1.append node \n2.prepend node \n3.insert node \n4.delete node \n5.update node \n6.display node";
		cout << endl;
		if (s.head != NULL) {
			cout <<"\t\t\thead : " << s.head->key << " : " << s.head->data;
		}
		cout << endl;
		s.printList();
		cout << "\n\nselection: ";
		cin >> selection;
		switch (selection) {
		case 1:
			cout << "key: ";
			cin >> key;
			cout << "value: ";
			cin >> value;
			n1->key = key;
			n1->data = value;
			s.appendNode(n1);
			break;
		case 2:
			cout << "key: ";
			cin >> key;
			cout << "value: ";
			cin >> value;
			n1->key = key;
			n1->data = value;			
			s.prependNode(n1);
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
			s.insertNode(after,n1);
			break;
		case 4:
			cout << "key: ";
			cin >> key;
			s.deleteNode(key);
			break;
		case 5:
			cout << "key to update: ";
			cin >> key;
			cout << "new value: ";
			cin >> value;
			s.updateNode(key, value);
			break;
		case 6:
			s.printList();
			break;
		case 0:
			delete n1;
		}
		_getch();
		system("cls");
	} while (selection != 0);

	cout << "program ended.";

	return 0;
}