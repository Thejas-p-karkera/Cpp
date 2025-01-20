#include <iostream>
#include <queue>

using namespace std;

const int MAX_NODES = 100; // Maximum number of nodes in the graph

// Function to perform BFS
void BFS(int startNode, int graph[MAX_NODES][MAX_NODES], int n)
{
    bool visited[MAX_NODES]; // Array to keep track of visited nodes

    // Initialize all nodes as not visited
    for (int i = 0; i < MAX_NODES; i++)
    {
        visited[i] = false;
    }

    queue<int> q; // Queue to manage BFS traversal
    q.push(startNode);
    visited[startNode] = true;

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int current = q.front(); // Get the front node in the queue
        q.pop();
        cout << current << " "; // Print the current node

        // Visit all adjacent nodes of the current node
        for (int i = 1; i <= n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                q.push(i);       // Add the neighbor to the queue
                visited[i] = true; // Mark it as visited
            }
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

// ---------------------------------------------------------------------------------------------------------

// 	#include <iostream>

// using namespace std;

// const int MAX_NODES = 100; // Maximum number of nodes in the graph

// // Simple implementation of a queue using an array
// class Queue {
//     int items[MAX_NODES];
//     int front, rear;

// public:
//     Queue() : front(0), rear(0) {} // Initialize front and rear to 0

//     bool isEmpty() {
//         return front == rear; // Queue is empty when front == rear
//     }

//     void enqueue(int element) {
//         if (rear == MAX_NODES) {
//             cout << "Queue Overflow" << endl;
//             return;
//         }
//         items[rear++] = element; // Add element and move rear forward
//     }

//     int dequeue() {
//         if (isEmpty()) {
//             cout << "Queue Underflow" << endl;
//             return -1;
//         }
//         return items[front++]; // Return the front element and move front forward
//     }
// };

// // Function to perform BFS
// void BFS(int startNode, int graph[MAX_NODES][MAX_NODES], int n) {
//     bool visited[MAX_NODES]; // Array to keep track of visited nodes

//     // Initialize all nodes as not visited
//     for (int i = 0; i < MAX_NODES; i++) {
//         visited[i] = false;
//     }

//     Queue q; // Use custom queue
//     q.enqueue(startNode);
//     visited[startNode] = true;

//     cout << "BFS Traversal: ";
//     while (!q.isEmpty()) {
//         int current = q.dequeue(); // Get the front node in the queue
//         cout << current << " ";    // Print the current node

//         // Visit all adjacent nodes of the current node
//         for (int i = 1; i <= n; i++) {
//             if (graph[current][i] == 1 && !visited[i]) {
//                 q.enqueue(i);      // Add the neighbor to the queue
//                 visited[i] = true; // Mark it as visited
//             }
//         }
//     }
//     cout << endl;
// }

// int main() {
//     int n;
//     cout << "Enter the number of nodes: ";
//     cin >> n;

//     int src, dst;
//     int ch;
//     cout << "Enter '0' for Directed graph or '1' for Undirected graph: ";
//     cin >> ch;

//     int m;
//     cout << "Enter the number of edges: ";
//     cin >> m;

//     int graph[MAX_NODES][MAX_NODES] = {0}; // Adjacency matrix for the graph

//     for (int i = 0; i < m; i++) {
//         cout << "Enter the edges (source & destination): " << endl;
//         cin >> src >> dst;
//         graph[src][dst] = 1; // Add edge

//         if (ch == 1) {
//             graph[dst][src] = 1; // Add edge for undirected graph
//         }
//     }

//     int startNode;
//     cout << "Enter the starting node for BFS: ";
//     cin >> startNode;

//     BFS(startNode, graph, n);

//     return 0;
// }
