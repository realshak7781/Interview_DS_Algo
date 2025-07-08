using ll = long long;

class Solution {
private:
    ll target;
    unordered_map<int, vector<int>> adjList;
    vector<ll> sum;
    vector<ll> arr;
    int res = 0;

    void dfs1(int node, vector<int>& cost, int parent) {
        for (auto& neigh : adjList[node]) {
            if (neigh == parent)
                continue;
            sum[neigh] = cost[neigh] + sum[node];
            dfs1(neigh, cost, node);
        }
    }

    ll dfs2(int node, int parent) {
        bool isLeaf = true;
        ll mini = LLONG_MAX;

        for (auto& neigh : adjList[node]) {
            if (neigh == parent)
                continue;
            isLeaf = false;
            mini = min(mini, dfs2(neigh, node));
        }

        if (isLeaf) {
            arr[node] = target - sum[node];
        } else {
            arr[node] = mini;
        }

        return arr[node];
    }

    void dfs3(int node, int parent) {
        ll p = (parent == -1) ? 0 : arr[parent];

        if (arr[node] > p)
            res++;

        for (auto it : adjList[node]) {
            if (it == parent) continue;
            dfs3(it, node);
        }
    }

public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        target = LLONG_MIN;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        sum.resize(n);
        sum[0] = cost[0];
        dfs1(0, cost, -1);

        for (int u = 0; u < n; u++) {
            bool leaf = (u == 0 ? adjList[u].empty() : adjList[u].size() == 1);
            if (leaf)
                target = max(target, sum[u]);
        }

        arr.resize(n, 0);
        dfs2(0, -1);
        dfs3(0, -1);

        return res;
    }
};
