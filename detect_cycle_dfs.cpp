#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> adj[N];
bool visited[N];

// DFS function
bool dfs(int node, int parent) {
    visited[node] = true;
  
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent) {
            // visited and not parent → cycle found
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m; // n = nodes, m = edges

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    bool hasCycle = false;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}
