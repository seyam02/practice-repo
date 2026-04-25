#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 4; 
    vector<int> adj[5]; 

    // building graph
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    // BFS start
    vector<bool> visited(5, false);
    queue<int> q;

    int start = 1; // starting node

    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int x : adj[node]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return 0;
}