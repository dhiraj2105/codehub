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
};

int main()
{
    return 0;
}