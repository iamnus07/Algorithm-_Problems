#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int MAX = 100;

int n, e;
int adj[MAX][MAX];          // Original graph
int transpose[MAX][MAX];    // Transposed graph
bool visited[MAX];

// Step 1: Fill vertices in stack according to finishing time
void dfs1(int u, stack<int> &S) {
    visited[u] = true;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs1(v, S);
        }
    }
    S.push(u);  // All descendants are visited, push to stack
}

// Step 2: DFS on transpose graph
void dfs2(int u) {
    cout << u << " ";
    visited[u] = true;
    for (int v = 0; v < n; v++) {
        if (transpose[u][v] && !visited[v]) {
            dfs2(v);
        }
    }
}

void findSCCs() {
    stack<int> S;

    // Step 1: Do DFS and store finish times
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs1(i, S);
    }

    // Step 2: Transpose the graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            transpose[j][i] = adj[i][j];

    // Step 3: Do DFS according to finish times in stack
    memset(visited, false, sizeof(visited));
    cout << "\nStrongly Connected Components:\n";
    while (!S.empty()) {
        int u = S.top();
        S.pop();
        if (!visited[u]) {
            dfs2(u);
            cout << endl;
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    // Initialize graph
    memset(adj, 0, sizeof(adj));
    memset(transpose, 0, sizeof(transpose));

    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    findSCCs();

    return 0;
}

