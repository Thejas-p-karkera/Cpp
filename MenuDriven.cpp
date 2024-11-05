#include<iostream>
using namespace std;

//Functon to display the array
void display(int arr[], int& size)
{
	if(size == 0)
	{
		cout<<"Array is empty.\n";
		return;
	}
	else
	{
		for(int i=0; i<size; i++)
		{
			cout<<arr[i]<<" ";
		}
	}
	cout<<endl;
}

//Functon to insert an element to the array
void insert(int arr[], int& size, int MAX_SIZE)
{
	int element;
	cout<<"Enter the element to insert: ";
	cin>>element;

	if(size>= MAX_SIZE)
	{
		cout<<"Array is full!\n";
		return;
	}
	else
	{
		arr[size] = element;
		size++;
	}
	cout<<"Element inserted sucessfully.\n";
}

void deleteElement(int arr[], int& size)
{
	int position;
	cout<<"Enter the position of the element to delete(0 to "<<size-1<<"): ";
	cin>>position;

	if(position < 0 || position > size-1)
	{
		cout<<"Invalid position!\n";
		return;
	}
	else
	{
		for(int i=position; i<size-1; i++)
		{
			arr[i] = arr[i+1];
		}
	}
	size--;
	cout<<"Element deleted Successfully.\n";
}

//Function to search for an element in the array
void search(int arr[], int& size)
{
	int element;
	cout<<"Enter the element to search: ";
	cin>>element;

	for(int i=0; i<size; i++)
	{
		if(arr[i] == element)
		{
			cout<<"Element found at position "<<i+1<<".\n";
			return;
		}
	}
	cout<<"Element not found.\n";
}

//Function to sort the array
void sort(int arr[], int& size)
{
	for(int i=0; i<size-1; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if(arr[j] < arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "Array sorted successfully.\n";
}

//function to reverse the array
void reverse(int arr[], int& size)
{
	int strt = 0;
	int end = size-1;

	while(strt < end)
	{
		swap(arr[strt],arr[end]);
		strt++;
		end--;
	}
	cout<<"Array reversed successfully.\n";
}

void merge(int arr2[], int& size, int MAX_SIZE)
{
	
}

int main()
{
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE];
	int arr2[MAX_SIZE];
	int size = 0;
	int choice;

	while(true)
	{
		cout<<"\nMENU\n";
		cout<<"1. Insert an element\n";
		cout<<"2. Delete an element\n";
		cout<<"3. Search for an element\n";
		cout<<"4. Sort the array\n";
		cout<<"5. Reverse the array\n";
		cout<<"6. Display the arry\n";
		cout<<"7. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				insert(arr, size, MAX_SIZE);
				break;

			case 2:
				deleteElement(arr, size);
				break;

			case 3:
				search(arr, size);
				break;

			case 4:
				sort(arr, size);
				break;

			case 5:
				reverse(arr, size);
				break;

			case 6:
				display(arr, size);
				break;

			case 7:
				return 0;

			default:
				cout<<"Invalid choice! Please enter a valid choice.";
				break;
				
		}
	}
}