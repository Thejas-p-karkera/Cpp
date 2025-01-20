#include <iostream>
#include <stack>

using namespace std;

const int MAX_NODES = 100; // Maximum number of nodes in the graph

// Function to perform DFS
void DFS(int startNode, int graph[MAX_NODES][MAX_NODES], int n)
{
    bool visited[MAX_NODES]; // Array to keep track of visited nodes

    // Initialize all nodes as not visited
    for (int i = 0; i < MAX_NODES; i++)
    {
        visited[i] = false;
    }

    stack<int> s; // Stack to manage DFS traversal
    s.push(startNode);       // Push the starting node onto the stack
    visited[startNode] = true; // Mark the starting node as visited

    cout << "DFS Traversal: ";
    while (!s.empty()) // Continue until the stack is empty
    {
        int current = s.top(); // Get the top node from the stack
        s.pop();               // Remove it from the stack
        cout << current << " "; // Print the current node

        // Visit all adjacent nodes of the current node
        for (int i = 1; i <= n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                s.push(i);       // Add the neighbor to the stack
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
        cout << "Enter the edges (source & destination): " << endl;
        cin >> src >> dst;
        graph[src][dst] = 1; // Add edge

        if (ch == 1)
        {
            graph[dst][src] = 1; // Add edge for undirected graph
        }
    }

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    DFS(startNode, graph, n);

    return 0;
}


// ------------------------------------------------------------------------------------------------

//   #include <iostream>
// using namespace std;

// const int MAX_NODES = 100; // Maximum number of nodes in the graph

// // Simple implementation of a stack using an array
// class Stack {
//     int items[MAX_NODES];
//     int top;

// public:
//     Stack() : top(-1) {} // Initialize top to -1

//     bool isEmpty() {
//         return top == -1; // Stack is empty when top == -1
//     }

//     void push(int element) {
//         if (top == MAX_NODES - 1) {
//             cout << "Stack Overflow" << endl;
//             return;
//         }
//         items[++top] = element; // Increment top and add element
//     }

//     int pop() {
//         if (isEmpty()) {
//             cout << "Stack Underflow" << endl;
//             return -1;
//         }
//         return items[top--]; // Return the top element and decrement top
//     }
// };

// // Function to perform DFS
// void DFS(int startNode, int graph[MAX_NODES][MAX_NODES], int n) {
//     bool visited[MAX_NODES]; // Array to keep track of visited nodes

//     // Initialize all nodes as not visited
//     for (int i = 0; i < MAX_NODES; i++) {
//         visited[i] = false;
//     }

//     Stack s; // Use custom stack
//     s.push(startNode); // Push the starting node onto the stack
//     visited[startNode] = true; // Mark the starting node as visited

//     cout << "DFS Traversal: ";
//     while (!s.isEmpty()) {
//         int current = s.pop(); // Pop the top node from the stack
//         cout << current << " "; // Print the current node

//         // Visit all adjacent nodes of the current node
//         for (int i = n; i >= 1; i--) { // Iterate in reverse to maintain order
//             if (graph[current][i] == 1 && !visited[i]) {
//                 s.push(i);       // Push the neighbor onto the stack
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
//     cout << "Enter the starting node for DFS: ";
//     cin >> startNode;

//     DFS(startNode, graph, n);

//     return 0;
// }
