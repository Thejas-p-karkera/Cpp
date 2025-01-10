#include <iostream>
#include <vector>
using namespace std;

// Function to print the adjacency list
void printAdjList(vector<vector<int>>& adjList, int n)
{
    cout << "The adjacency list is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int j : adjList[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of Nodes (Vertices): ";
    cin >> n;

    // Create an adjacency list
    vector<vector<int>> adjList(n);

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

        adjList[src].push_back(dst); // Add edge from src to dst
        if (graphType == 'U' || graphType == 'u') // For undirected graph
        {
            adjList[dst].push_back(src); // Add edge from dst to src
        }
    }

    printAdjList(adjList, n);

    return 0;
}
