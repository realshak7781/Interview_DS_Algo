// APPROACH 2 : USING BINARY LIFTING FOR LCA :
// TIME : O(Q*LOGN)




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
