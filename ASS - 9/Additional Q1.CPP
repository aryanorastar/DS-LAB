#include <iostream>
#include <vector>
#include <list>
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
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected graph
    }

    // Find all connected components
    void findConnectedComponents() {
        vector<bool> visited(V, false);
        vector<vector<int>> components;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> component;
                DFSUtil(i, visited, component);
                components.push_back(component);
            }
        }

        cout << "Number of connected components: " << components.size() << endl;
        for (int i = 0; i < components.size(); i++) {
            cout << "Component " << i + 1 << ": ";
            for (int j = 0; j < components[i].size(); j++) {
                cout << components[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFSUtil(int u, vector<bool>& visited, vector<int>& component) {
        visited[u] = true;
        component.push_back(u);

        for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
            int v = *it;
            if (!visited[v]) {
                DFSUtil(v, visited, component);
            }
        }
    }

    // Check if graph is bipartite
    bool isBipartite() {
        vector<int> color(V, -1); // -1: uncolored, 0: color1, 1: color2

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!isBipartiteUtil(i, color)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartiteUtil(int start, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = *it;
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
        return true;
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

    cout << "\n";
    g.findConnectedComponents();

    cout << "\nGraph is " << (g.isBipartite() ? "bipartite" : "not bipartite") << endl;

    return 0;
}

