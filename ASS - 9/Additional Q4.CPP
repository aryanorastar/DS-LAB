#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>

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
        adjList[u].push_back(v); // Directed graph
    }

    // Check if graph is strongly connected (for directed graph)
    bool isStronglyConnected() {
        // Check if all vertices are reachable from vertex 0
        vector<bool> visited(V, false);
        DFS(0, visited);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        // Reverse the graph
        Graph reversed = getTranspose();

        // Reset visited array
        fill(visited.begin(), visited.end(), false);
        reversed.DFS(0, visited);

        // Check if all vertices are reachable in reversed graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }

    void DFS(int u, vector<bool>& visited) {
        visited[u] = true;

        for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
            int v = *it;
            if (!visited[v]) {
                DFS(v, visited);
            }
        }
    }

    Graph getTranspose() {
        Graph g(V);
        for (int u = 0; u < V; u++) {
            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = *it;
                g.addEdge(v, u);
            }
        }
        return g;
    }

    // Find strongly connected components using Kosaraju's algorithm
    void findStronglyConnectedComponents() {
        stack<int> s;
        vector<bool> visited(V, false);

        // Fill vertices in stack according to their finishing times
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                fillOrder(i, visited, s);
            }
        }

        // Create reversed graph
        Graph reversed = getTranspose();

        // Reset visited array
        fill(visited.begin(), visited.end(), false);

        // Process all vertices in order defined by stack
        int componentNum = 0;
        while (!s.empty()) {
            int v = s.top();
            s.pop();

            if (!visited[v]) {
                componentNum++;
                cout << "Component " << componentNum << ": ";
                reversed.DFSUtil(v, visited);
                cout << endl;
            }
        }
    }

    void fillOrder(int u, vector<bool>& visited, stack<int>& s) {
        visited[u] = true;

        for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
            int v = *it;
            if (!visited[v]) {
                fillOrder(v, visited, s);
            }
        }

        s.push(u);
    }

    void DFSUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
            int v = *it;
            if (!visited[v]) {
                DFSUtil(v, visited);
            }
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

    cout << "Enter edges (u v) for directed graph:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nGraph is " << (g.isStronglyConnected() ? "strongly connected" : "not strongly connected") << endl;

    cout << "\nStrongly Connected Components:" << endl;
    g.findStronglyConnectedComponents();

    return 0;
}

