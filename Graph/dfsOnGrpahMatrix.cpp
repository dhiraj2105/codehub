#include <bits/stdc++.h>
using namespace std;

// class to represent an undirected and unweighted graph
class Grpah
{

private:
    int vertices;                  // stores the number of vertices
    vector<vector<int>> adjMatrix; // 2D vector to store adjacency matrix

    // Utility function for recursive DFS traversal
    void dfsUtil(int node, vector<bool> &visited)
    {
        // Mark the current node as visited
        visited[node] = true;
        // Print the visited node
        cout << "Visited node : " << node << " ";

        // visit all adjacent vertices of current node
        for (int i = 0; i < vertices; i++)
        {
            // if there is an edge and the vertex is not visited
            if (adjMatrix[node][i] == 1 && !visited[i])
            {
                dfsUtil(i, visited);
            }
        }
    }

public:
    // Constructor to initialize the graph with V vertices
    Grpah(int V)
    {
        vertices = V;

        // resize the matrix to V x V with all values initialize
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    // Function to add an undirected edge between u and v
    void addEdge(int u, int v)
    {
        // check if valid vertix indices
        if (u >= 0 && v >= 0 && u < vertices && v < vertices)
        {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
        else
        {
            cout << "Invalid vertices" << endl;
        }
    }
    void display()
    {
        cout << "\n Adjacency Matrix : \n";

        for (int i = 0; i < vertices; i++)
        {
            cout << i << " ";
        }
        cout << endl;

        for (int i = 0; i < vertices; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < vertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(int start)
    {
        vector<bool> visited(vertices, false);

        cout << "\n DFS Traversal starting from node " << start << endl;

        dfsUtil(start, visited);
        cout << endl;
    }
};

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Grpah myGraph(V);

    int edges;
    cout << "Enter number of edges";
    cin >> edges;

    cout << "Enter " << edges << " edges (u v) : " << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        myGraph.addEdge(u, v);
    }

    myGraph.display();

    // DFS
    int startNode;
    cout << "Enter start node : ";
    cin >> startNode;

    myGraph.dfs(startNode);

    return 0;
}