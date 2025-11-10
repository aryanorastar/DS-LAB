#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<list<int>> adjList; // Adjacency List
    vector<vector<int>> adjMatrix; // Adjacency Matrix

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    // Add edge for undirected graph
    void addEdgeUndirected(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // Add edge for directed graph
    void addEdgeDirected(int u, int v) {
        adjList[u].push_back(v);
        adjMatrix[u][v] = 1;
    }

    // Display Adjacency List
    void displayAdjList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (auto it = adjList[i].begin(); it != adjList[i].end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    // Display Adjacency Matrix
    void displayAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        cout << "  ";
        for (int i = 0; i < V; i++) {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " ";
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Get degree of a vertex (for undirected graph)
    int getDegree(int vertex) {
        return adjList[vertex].size();
    }

    // Check if edge exists
    bool hasEdge(int u, int v) {
        return adjMatrix[u][v] == 1;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);
    int choice;
    cout << "1. Undirected Graph\n2. Directed Graph\nEnter choice: ";
    cin >> choice;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        if (choice == 1) {
            g.addEdgeUndirected(u, v);
        } else {
            g.addEdgeDirected(u, v);
        }
    }

    cout << "\n";
    g.displayAdjList();
    cout << "\n";
    g.displayAdjMatrix();

    // Example operations
    cout << "\nDegree of vertex 0: " << g.getDegree(0) << endl;
    cout << "Edge (0,1) exists: " << (g.hasEdge(0, 1) ? "Yes" : "No") << endl;

    return 0;
}

