#include <iostream>
using namespace std;

const int MAX_NODES = 100; // Maximum number of nodes in the graph

// Stack class implementation
class Stack {
public:
    int arr[MAX_NODES];
    int top;

    Stack() {
        top = -1; // Initialize stack as empty
    }

    bool empty() {
        return top == -1;
    }

    void push(int val) {
        if (top == MAX_NODES - 1) {
            cout << "Stack is full!" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    int pop() {
        if (empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int removed = arr[top];
        top--;
        return removed;
    }

    int peek() {
        if (empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
};

// Function to perform DFS
void DFS(int startNode, int graph[MAX_NODES][MAX_NODES], int n) {
    bool visited[MAX_NODES] = {false}; // Array to keep track of visited nodes

    Stack s;
    s.push(startNode); // Push the starting node onto the stack

    cout << "DFS Traversal: ";
    while (!s.empty()) {
        int current = s.pop(); // Pop the top node from the stack

        // If the node is not visited, visit it
        if (!visited[current]) {
            cout << current << " "; // Print the current node
            visited[current] = true;
        }

        // Push all unvisited neighbors of the current node onto the stack
        for (int i = n - 1; i >= 0; i--) { // Iterate in reverse to ensure correct order
            if (graph[current][i] == 1 && !visited[i]) {
                s.push(i);
            }
        }
    }

    // Check for unvisited nodes
    cout << "\nUnvisited Nodes: ";
    bool hasUnvisited = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << i << " ";
            hasUnvisited = true;
        }
    }
    if (!hasUnvisited) {
        cout << "None";
    }
    cout << endl;
}

int main() {
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

    for (int i = 0; i < m; i++) {
        cout << "Enter the edges (source & destination): ";
        cin >> src >> dst;
        graph[src][dst] = 1; // Add edge

        if (ch == 1) {
            graph[dst][src] = 1; // Add edge for undirected graph
        }
    }

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    DFS(startNode, graph, n);

    return 0;
}
