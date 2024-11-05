#include<iostream>
using namespace std;

class Node
{
	public: int data;
			Node* next;
			Node* head;

	Node(int val)
	{
		data = val;
		next = NULL;
		head = NULL;
	}
};

class Link
{
	void push(int val)
	{
		Node* newNode = new Node(val);
		if(head == NULL)
		{

		}
	}
};

void main()
{
	Link l;
	int ch;
	int ele;
	cout<<"stack operations using LinkedList"<<endl;
	cout<<"1. Push"<<endl;
	cout<<"2. Pop"<<endl;
	cout<<"3. Display"<<endl;
	cout<<"4. Exit"<<endl;

	while(true)
	{
		cout<<"Enter your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"Enter element to PUSH: ";
				cin>>ele;
				l.push(ele);

			case 2:
			
			case 3:

			case 4:
				return;

			default:
				cout<<"Invalid choice"<<endl;
				break;

		}
	}
	

}
