#include <iostream>
#include <vector>
using namespace std;

void printList(vector<vector<int>>& list, int n)
{
    cout << "The adjacency list is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < list[i].size(); j++)
        {
			cout << list[i][j]<<" ";
        }
        cout << endl;
    }
}

void main()
{
    int n;
    cout << "Enter the number of Nodes (Vertices): ";
    cin >> n;

    // Create an adjacency list
    vector<vector<int>> list(n);

    int ch;
    cout << "Enter '0' for Directed graph or '1' for Undirected graph: ";
    cin >> ch;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    int src, dst;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the edges (source & destination): " << endl;
        cin >> src >> dst;

        list[src].push_back(dst);

        if (ch == 1)
        {
            list[dst].push_back(src);
        }
    }

    printList(list, n);

}
