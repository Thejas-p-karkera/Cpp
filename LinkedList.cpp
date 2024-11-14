#include<iostream>
using namespace std;

class Node
{
	public:
		int val;
		Node* next;

		Node(int data)
		{
			val = data;
			next = NULL;
		}
};

void insertAtHead(Node* &head, int val)
{
	Node* newNode = new Node(val);
	newNode->next = head;
	head = newNode;
}

void insertAtTail(Node*& head, int val)
{
	Node* newNode = new Node(val);

	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = newNode;
	//newNode->next = NULL;
}

void insertAtPosition(Node*& head, int val, int pos)
{
	if (pos == 0)
	{
		insertAtHead(head, val);
		return;
	}

	Node* newNode = new Node(val);
	Node* temp = head;
	int currentPos = 0;
	while (currentPos != pos - 1)
	{
		temp = temp->next;
		currentPos++;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void updateAtPosition(Node*& head, int val, int pos)
{
	Node* temp = head;
	int	currentPos = 0;
	while (currentPos != pos)
	{
		temp = temp->next;
		currentPos++;
	}

	//Temp will be pointing to posTh node
	temp->val = val;
}

void deleteAtHead(Node* &head)
{
	Node* temp = head;
	head= temp->next;
	free(temp);
}

void deleteAtTail(Node*& head)
{
	Node* secondLast = head;
	while (secondLast->next->next != NULL)
	{
		secondLast = secondLast->next;
	}

	Node* temp;
	temp = secondLast->next;
	secondLast->next = NULL;
	free(temp);
}

void deleteAtPosition(Node*& head, int pos)
{
	if (pos == 0)
	{
		deleteAtHead(head);
		return;
	}

	Node* prev = head;
	int currentPos = 0;
	while (currentPos != pos - 1)
	{
		prev = prev->next;
		pos++;
	}
	Node* temp = prev->next;
	prev->next = prev->next->next;
	free(temp);
}

void display(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->val << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

void main()
{
	Node* head = NULL;

	while (true)
	{
		int ch;
		int ele;
		int pos;

		cout << "1. Display." << endl;
		cout << "2. Insert at Front." << endl;
		cout << "3. Insert at Rear." << endl;
		cout << "4. Insert at a position." << endl;
		cout << "5. Update value at a position." << endl;
		cout << "6. Delete at Front." << endl;
		cout << "7. Delete at Rear." << endl;
		cout << "8. Delete at a position." << endl;
		cout << "9. Exit." << endl;
		cout << "Enter your choice: ";

		cin >> ch;

		switch (ch)
		{
			case 1:
				display(head);
				break;

			case 2:
				cout << "Enter the element you want to insert at front: ";
				cin >> ele;
				insertAtHead(head,ele);
				break;

			case 3:
				cout << "Enter the element you want to insert at rear: ";
				cin >> ele;
				insertAtTail(head,ele);
				break;

			case 4:
				cout << "Enter the element you want to insert at a perticular position: ";
				cin >> ele;
				cout << "Enter the position: ";
				cin >> pos;
				insertAtPosition(head,ele,pos);
				break;

			case 5:
				cout << "Enter the new element you want to update at a position: ";
				cin >> ele;
				cout << "Enter the position: ";
				cin >> pos;
				updateAtPosition(head,ele,pos);
				break;

			case 6:
				deleteAtHead(head);
				break;

			case 7:
				deleteAtTail(head);
				break;

			case 8:
				cout << "Enter the position where you want to delete: ";
				cin >> pos;
				deleteAtPosition(head,pos);
				break;

			case 9:
				return;

		}
	}
	//return 0;
}
	/*insertAtHead(head,2);
	display(head);
	insertAtHead(head,1);
	display(head);
	insertAtTail(head, 3);
	display(head);
	insertAtPosition(head, 4, 1);
	display(head);
	updateAtPosition(head, 2, 5);
	display(head);
	deleteAtHead(head);
	display(head);
	deleteAtTail(head);
	display(head);
	deleteAtPosition(head, 1);
	display(head);*/

	//Node* n = new Node(1);
	//cout << n->val << " " << n->next << endl;

