#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
Node(int val)
{
	data=val;
	next=NULL;
}
};
class link
{
public:
	Node* head;
	link()
	{
		head=NULL;
	}
	void push(int val)
	{
		Node *newnode=new Node(val);
	    if(head==NULL)
		{
			head=newnode;
			return;
		}
		Node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	void pop()
	{
		Node *t1,*t2;
		if(head==NULL)
		{
			cout<<"empty list";
			return;
		}
		else
		{
			t1=NULL;
			t2=head;
			while(t2->next!=NULL)
			{
				t1=t2;
				t2=t2->next;
			}
			delete t2;
			if(t1!=NULL)
				t1->next=NULL;
		}
	}
	void display()
	{
		Node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
	}
};
void main()
{
	link l;
	int ch;
	int ele;
	cout<<"stack operations using linked list"<<endl;
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.display"<<endl;
	cout<<"4.exit"<<endl;
	do
	{
	cout<<"enter your choice:";
	cin>>ch;
	switch(ch)
	{
	case 1:
		{
			cout<<"enter the element to insert:";
			cin>>ele;
			l.push(ele);
		}
		break;
	case 2:
		{
			cout<<"element is removed"<<endl;
			l.pop();

		}
		break;
	case 3:
		{
			l.display();
		}
		break;
	default:
		{
			cout<<"Invalid choice"<<endl;
			break;
			}
	}
	}
	while(ch!=4);
}

