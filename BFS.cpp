#include <iostream>

using namespace std;

const int MAX_NODES = 100; // Maximum number of nodes in the graph

class Queue 
{
    public:
        int arr[MAX_NODES];
		int front, rear;

    
        Queue() 
        {
            front = 0;
            rear = -1;
        }

		/*bool isFull()
		{
			return rear == MAX_NODES-1;
		}*/

		bool empty()
		{
			return front > rear;
		}

    void enqueue(int val)
    {
        rear++;
		arr[rear] = val;
    }

    int dequeue() 
    {
     int removed = arr[front]; 
	 front++;
	 return removed;
    }
};


// Function to perform BFS
void BFS(int startNode, int graph[MAX_NODES][MAX_NODES], int n)
{
    bool visited[MAX_NODES]; // Array to keep track of visited nodes

    // Initialize all nodes as not visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

	Queue q;
    q.enqueue(startNode);
    visited[startNode] = true;

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int current = q.dequeue(); // Get the front node in the queue
        
        cout << current << " "; // Print the current node

        // Visit all adjacent nodes of the current node
        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                q.enqueue(i);       // Add the neighbor to the queue
                visited[i] = true; // Mark it as visited
            }
        }
    }

	cout<<"\nUnvisited Nodes :";
	for(int i=0; i<n; i++)
	{
		if(!visited[i])
		{
			cout<<i <<" ";
		}
	}

    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

	int src, dst;

	int ch;
    cout << "Enter '0' for Directed graph or '1' for Undirected graph: ";
    cin >> ch;

	int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    int graph[MAX_NODES][MAX_NODES] = {0}; // Adjacency matrix for the graph

    for (int i = 0; i < m; i++)
    {
        cout<<"Enter the edges (source & destination): "<<endl;
        cin >> src >> dst;
        graph[src][dst] = 1; // Add edge

		if(ch == 1)
		{
			graph[dst][src] = 1; // Add edge for undirected graph
		}
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    BFS(startNode, graph, n);

    return 0;
}
