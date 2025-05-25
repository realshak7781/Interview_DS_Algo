#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define LL long long

vector<int> vis, degree, comp;

bool dfs(int parent, int node, unordered_map<int,vector<int>>& adj) {
    // Early return if degree != 2
    if(degree[node] != 2) return false;
    
    vis[node] = true;
    comp.push_back(node);
    
    for(auto& neigh : adj[node]) {
        if(!vis[neigh]) {
            if(dfs(node, neigh, adj)) return true;
        }
        else if(neigh != parent) {
            // Found a cycle and all nodes have degree 2
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    unordered_map<int,vector<int>> adj;
    vis.assign(n+1, false);
    degree.assign(n+1, 0);
    
    // Build graph and calculate degrees
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    
    int count = 0;
    for(int i = 1; i <= n; i++) {
        comp.clear();
        if(!vis[i]) {
            if(dfs(-1, i, adj)) {
                count++;
            }
        }
    }
    
    cout << count << endl;
}

int main() {
    FAST_IO;
    int t = 1;
    // cin >> t;  // Uncomment for multiple test cases
    while(t--) {
        solve();
    }
    return 0;
}