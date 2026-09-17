// APPROACH 2 : USING BINARY LIFTING FOR LCA :
// TIME : O(Q*LOGN)
// SPACE : O(NlogN+Q)
class Solution {
private:
    const int MOD = 1e9 + 7;

    int findWays(int a, int b) {
        // finding a^b
        if (b == 0)
            return 1;

        long long half = findWays(a, b / 2) % MOD;
        long long res = (half * half) % MOD;
        if (b & 1) {
            res = (res * a) % MOD;
        }

        return res;
    }

    int findLCA(int cols, int u, int v, unordered_map<int, int>& depth,
                vector<vector<int>>& ancestor) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];
        for (int j = 0; j < cols; j++) {
            if ((diff >> j) & 1) {
                u = ancestor[u][j];
            }
        }

        if (u == v) {
            return u;
        }

        for(int j=cols-1;j>=0;j--){
            if(ancestor[u][j]!=ancestor[v][j]){
                u=ancestor[u][j];
                v=ancestor[v][j];
            }
        }

        return ancestor[u][0];
    }

    void dfs(int par, int d, int node, vector<vector<int>>& ancestor,
             unordered_map<int, int>& depth,
             unordered_map<int, vector<int>>& adj) {
        depth[node] = d;
        ancestor[node][0] = par;

        for (int neigh : adj[node]) {
            if (neigh == par)
                continue;

            dfs(node, d + 1, neigh, ancestor, depth, adj);
        }
    }
    void createAncestor(int n, int cols, unordered_map<int, vector<int>>& adj,
                        vector<vector<int>>& ancestor,
                        unordered_map<int, int>& depth) {

        // we need to populate for ancestor[node][0] for every node
        //  do a simple dfs

        dfs(-1, 0, 1, ancestor, depth, adj);
        for (int j = 1; j < cols; j++) {
            for (int node = 1; node <= n; node++) {

                if (ancestor[node][j - 1] != -1) {
                    ancestor[node][j] = ancestor[ancestor[node][j - 1]][j - 1];
                }
            }
        }
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        int n = edges.size() + 1;
        int cols = log2(n) + 1;

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // create the ancestor array and depth map
        unordered_map<int, int> depth;
        vector<vector<int>> ancestor(n + 1, vector<int>(cols + 1, -1));
        createAncestor(n, cols, adj, ancestor, depth);

        vector<int> res;
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                res.push_back(0);
                continue;
            }
            int lca = findLCA(cols, u, v, depth, ancestor);

            int edgeCnt =
                depth[u] + depth[v] - 2 * depth[lca];

            // no of ways = 2^(edgeCnt-1)
            long long ways = findWays(2, edgeCnt - 1) % MOD;

            res.push_back(ways);
        }

        return res;
    }
};


// APPTROAHC : USING BRUTE FORCE TO FIND LCA
// TIME : O(Q*N)
class Solution {
private:
    const int MOD = 1e9 + 7;

    int findWays(int a, int b) {
        // finding a^b
        if (b == 0)
            return 1;

        long long half = findWays(a, b / 2) % MOD;
        long long res = (half * half) % MOD;
        if (b & 1) {
            res = (res * a) % MOD;
        }

        return res;
    }

    int findLCA(int u, int v, unordered_map<int, int>& parent) {
        unordered_set<int> pSet;
        int curP = u;

        while (curP != -1) {
            pSet.insert(curP);
            curP = parent[curP];
        }

        curP=v;

        while(curP!=-1){
            if(pSet.count(curP)) return curP;
            curP=parent[curP];
        }

        return 1;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        unordered_set<int> vis;
        q.push(1);
        vis.insert(1);
        unordered_map<int, int> distFromOne;
        unordered_map<int, int> parent;
        parent[1] = -1;

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                distFromOne[node] = dist;
                for (int neigh : adj[node]) {
                    if (vis.count(neigh))
                        continue;

                    vis.insert(neigh);
                    q.push(neigh);
                    parent[neigh] = node;
                }
            }

            dist++;
        }

        vector<int> res;
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if(u==v){
                res.push_back(0);
                continue;
            }
            int lca = findLCA(u, v, parent);

            int edgeCnt =
                distFromOne[u] + distFromOne[v] - 2 * distFromOne[lca];

            // no of ways = 2^(edgeCnt-1)
            long long ways = findWays(2, edgeCnt - 1) % MOD;

            res.push_back(ways);
        }

        return res;
    }
};
