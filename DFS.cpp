#include <iostream>
#include <stack>
using namespace std;

const int MAX = 100;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int adj[MAX][MAX];
int color[MAX];
int parent[MAX];

void DFS(int n, int source) {
    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
        parent[i] = -1;
    }

    stack<int> S;
    S.push(source);
    color[source] = GRAY;

    while (!S.empty()) {
        int u = S.top();
        S.pop();

        if (color[u] == BLACK)
            continue;

        cout << "Visited: " << u << endl;
        color[u] = BLACK;

        for (int v = n - 1; v >= 0; v--) { // reverse order for consistent output
            if (adj[u][v] == 1 && color[v] == WHITE) {
                S.push(v);
                color[v] = GRAY;
                parent[v] = u;
            }
        }
    }

    // Optional: Print DFS Tree (Parent array)
    cout << "\nVertex\tParent\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t";
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
        adj[v][u] = 1; // Remove this line if the graph is directed
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    DFS(n, source);

    return 0;
}

