#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis) {
        
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {

            // If not visited
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis))
                    return true;
            }

            // If already visited and in current path
            else if (pathVis[it]) {
                return true;
            }
        }

        // Remove from current path
        pathVis[node] = 0;

        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis))
                    return true;
            }
        }

        return false;
    }
};

int main() {

    int V = 4;

    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // cycle

    Solution obj;

    if (obj.isCyclic(V, adj))
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}