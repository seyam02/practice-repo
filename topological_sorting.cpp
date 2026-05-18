#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> adj[N];
bool visited[N];
stack<int> st;

// DFS function
void dfs(int node) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }

    // push after visiting all neighbors
    st.push(node);
}

int main() {

    int n, e;
    cin >> n >> e;

    // input edges
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    // run DFS for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // print topological order
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}