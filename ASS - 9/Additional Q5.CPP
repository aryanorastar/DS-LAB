#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

class Graph {
private:
    int V;
    vector<list<pair<int, int>>> adjList; // pair<destination, weight>

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight)); // Directed graph
    }

    // Bellman-Ford Algorithm for shortest path (handles negative weights)
    void bellmanFord(int start) {
        vector<int> distance(V, INT_MAX);
        distance[start] = 0;

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (int u = 0; u < V; u++) {
                for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                    int v = it->first;
                    int weight = it->second;

                    if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                    }
                }
            }
        }

        // Check for negative weight cycles
        for (int u = 0; u < V; u++) {
            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = it->first;
                int weight = it->second;

                if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    cout << "Graph contains negative weight cycle!" << endl;
                    return;
                }
            }
        }

        cout << "Shortest distances from vertex " << start << " (Bellman-Ford):" << endl;
        for (int i = 0; i < V; i++) {
            if (distance[i] == INT_MAX) {
                cout << "Vertex " << i << ": INF" << endl;
            } else {
                cout << "Vertex " << i << ": " << distance[i] << endl;
            }
        }
    }

    // Floyd-Warshall Algorithm for all pairs shortest path
    void floydWarshall() {
        vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

        // Initialize distance matrix
        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }

        for (int u = 0; u < V; u++) {
            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = it->first;
                int weight = it->second;
                dist[u][v] = weight;
            }
        }

        // Floyd-Warshall algorithm
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        cout << "All pairs shortest paths (Floyd-Warshall):" << endl;
        cout << "   ";
        for (int i = 0; i < V; i++) {
            cout << i << "  ";
        }
        cout << endl;

        for (int i = 0; i < V; i++) {
            cout << i << "  ";
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INT_MAX) {
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << "  ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v weight) for directed graph:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    int start;
    cout << "\nEnter source vertex for Bellman-Ford: ";
    cin >> start;
    g.bellmanFord(start);

    cout << "\n";
    g.floydWarshall();

    return 0;
}

