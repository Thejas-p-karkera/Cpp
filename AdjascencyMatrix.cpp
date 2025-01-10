#include<iostream>
using namespace std;

void printArray(int** arr, int n)
{
	cout<<"The matrix is: "<<endl;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	cout<<"Enter the number of Nodes(Vertices): ";
	cin>>n;

	int** arr = new int*[n];
	for(int i=0; i<n; i++)
	{
		arr[i] = new int[n];
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			arr[i][j] = 0;
		}
	}

	int m;
	cout<<"Enter the number of edges: ";
	cin>>m;

	int src, dst;

	cout<<"Directed or undirected?: "<<endl;
	cout<<"1. Directed"<<endl;
	cout<<"2. Undirected"<<endl;
	cout<<"Enter your choice: ";
	int ch;
	if(ch

	for(int i=0; i<m; i++)
	{
		cout<<"Enter the edges (source & destination): "<<endl;
		cin>>src>>dst;
		arr[src][dst] = 1;
		arr[dst][src] = 1;
	}
	
	//arr[src][dst] = 1;
	//arr[dst][src] = 1;

	printArray(arr, n);
}




//------_----------------------

#include <iostream>
using namespace std;

void printArray(int** arr, int n)
{
    cout << "The matrix is: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of Nodes (Vertices): ";
    cin >> n;

    // Dynamically allocate memory for the adjacency matrix
    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    char graphType;
    cout << "Enter 'D' for Directed graph or 'U' for Undirected graph: ";
    cin >> graphType;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    int src, dst;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the edges (source & destination): " << endl;
        cin >> src >> dst;

        arr[src][dst] = 1;
        if (graphType == 'U' || graphType == 'u') // For undirected graph
        {
            arr[dst][src] = 1;
        }
    }

    printArray(arr, n);

    // Free the dynamically allocated memory
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
