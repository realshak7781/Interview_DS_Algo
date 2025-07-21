class disjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    disjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findUPar(parent[u]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<vector<int>> sortedEdges = edgeList;
        // sorting based on edge weights
        sort(sortedEdges.begin(), sortedEdges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        vector<vector<int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            auto q = queries[i];
            q.push_back(i);
            sortedQueries.push_back(q);
        }

        sort(sortedQueries.begin(), sortedQueries.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        disjointSet ds(n);
        int j = 0;
        vector<bool> res(queries.size(), false);

        for (auto& q : sortedQueries) {
            // / Time: O((E + Q) * α(N)), nearly linear due to DSU with path compression
            int u = q[0];
            int v = q[1];
            int limit = q[2];
            int resIdx = q[3];

            while (j < sortedEdges.size() && sortedEdges[j][2] < limit) {
                ds.unionByRank(sortedEdges[j][0], sortedEdges[j][1]);
                j++;
            }

            if (ds.findUPar(u) == ds.findUPar(v)) {
                res[resIdx] = true;
            }
        }

        return res;
    }
};
