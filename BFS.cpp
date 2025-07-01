#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int adj[MAX][MAX];    // adjacency matrix
int color[MAX];       // color array
int dist[MAX];        // distance from source
int parent[MAX];      // parent array

void BFS(int n, int source) {
    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
        dist[i] = -1;
        parent[i] = -1;
    }

    queue<int> Q;
    color[source] = GRAY;
    dist[source] = 0;
    Q.push(source);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && color[v] == WHITE) {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
        }

        color[u] = BLACK;
    }

    // Output the BFS tree and distances
    cout << "\nVertex\tDistance\tParent\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << dist[i] << "\t\t";
        if (parent[i] == -1)
            cout << "None" << endl;
        else
            cout << parent[i] << endl;
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    cout << "Enter edges (u v) for an undirected graph (0-indexed):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // Remove this line for directed graph
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    BFS(n, source);

    return 0;
}
