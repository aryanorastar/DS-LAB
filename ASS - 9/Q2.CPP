#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
private:
    int V;
    vector<list<int>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // BFS traversal starting from a given source
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from " << start << ": ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = *it;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    // BFS to find shortest path (unweighted graph)
    void shortestPath(int start, int end) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        vector<int> distance(V, -1);
        queue<int> q;

        visited[start] = true;
        distance[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == end) {
                break;
            }

            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = *it;
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    distance[v] = distance[u] + 1;
                    q.push(v);
                }
            }
        }

        if (distance[end] == -1) {
            cout << "No path exists from " << start << " to " << end << endl;
        } else {
            cout << "Shortest distance from " << start << " to " << end << ": " << distance[end] << endl;
            cout << "Path: ";
            vector<int> path;
            int current = end;
            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i];
                if (i > 0) cout << " -> ";
            }
            cout << endl;
        }
    }

    // Check if graph is connected (for undirected graph)
    bool isConnected() {
        vector<bool> visited(V, false);
        queue<int> q;
        int count = 0;

        // Start BFS from vertex 0
        visited[0] = true;
        q.push(0);
        count++;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = *it;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    count++;
                }
            }
        }

        return count == V;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "\nEnter starting vertex for BFS: ";
    cin >> start;
    g.BFS(start);

    int end;
    cout << "\nEnter destination vertex for shortest path: ";
    cin >> end;
    g.shortestPath(start, end);

    cout << "\nGraph is " << (g.isConnected() ? "connected" : "disconnected") << endl;

    return 0;
}

