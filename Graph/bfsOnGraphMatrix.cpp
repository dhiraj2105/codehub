#include <bits/stdc++.h>
using namespace std;

// Graph class to represent an undirected - unweighted graph
class Graph
{
private:
    int vertices;                  // no. of vertices
    vector<vector<int>> adjMatrix; // adjacency matrix

public:
    // constructor : initializes a V x V matrix with all 0
    Graph(int V)
    {
        vertices = V;
        adjMatrix.resize(V, vector<int>(V, 0)); // V x V matrix
    }
    // adds an undirected edge between vertex u and v
    void addEdge(int u, int v)
    {
        if (u >= 0 && v >= 0 && u < vertices && v < vertices)
        {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; // remove this line for directed graph
        }
        else
        {
            cout << "Invalid vertices" << endl;
        }
    }

    // display adjacency matrix
    void display()
    {

        cout << "\nAdjacency Matrix:\n   ";
        for (int i = 0; i < vertices; ++i)
            cout << i << " ";
        cout << "\n";

        for (int i = 0; i < vertices; ++i)
        {
            cout << i << ": ";
            for (int j = 0; j < vertices; ++j)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " edges (u v) : " << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.display();

    return 0;
}