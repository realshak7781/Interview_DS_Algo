/*
Final Time Complexity: O((m + n) * log W)
    - m: number of edges
    - n: number of nodes
    - W: maximum edge weight
Final Space Complexity: O(n)
*/

class disjointSet {
private:
    vector<int> parent; // O(n) space
    vector<int> rank;   // O(n) space

public:
    disjointSet(int n) {
        parent.resize(n); // O(n)
        rank.resize(n, 1); // O(n)

        for (int i = 0; i < n; i++) {
            parent[i] = i; // O(n)
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node; // O(1)
        return parent[node] = findUPar(parent[node]); // O(α(n)) amortized
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u); // O(α(n))
        int pv = findUPar(v); // O(α(n))

        if (pu == pv) return; // O(1)

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv; // O(1)
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu; // O(1)
        }
        else {
            parent[pv] = pu; // O(1)
            rank[pu] += 1;   // O(1)
        }
    }
};


class Solution {
private:
    int getComponentCount(int mid, vector<vector<int>>& edges, int n) {
        disjointSet ds(n); // O(n) time & space

        for (auto &it : edges) { // O(m)
            if (it[2] <= mid) {
                ds.unionByRank(it[0], it[1]); // O(α(n)) ≈ O(1) amortized
            }
        }

        unordered_set<int> compCount; // O(n) space in worst case

        for (int i = 0; i < n; i++) {
            compCount.insert(ds.findUPar(i)); // O(α(n)) ≈ O(1) amortized per call → O(n)
        }

        return compCount.size(); // O(1)
    }

public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int maxWeight = INT_MIN;
        for (auto &it : edges) { // O(m)
            maxWeight = max(maxWeight, it[2]); // O(1)
        }

        int left = 0, right = maxWeight; // O(1)
        int cost = 0; // O(1)

        // Binary Search: O(log W)
        while (left <= right) { // O(log W)
            int mid = left + (right - left) / 2; // O(1)

            // getComponentCount: O(m + n)
            if (getComponentCount(mid, edges, n) <= k) {
                cost = mid; // O(1)
                right = mid - 1; // O(1)
            }
            else {
                left = mid + 1; // O(1)
            }
        }

        return cost; // O(1)
    }
};
