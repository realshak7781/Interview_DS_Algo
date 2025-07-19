using p = pair<int, int>;
const int inf = INT_MAX;
class Solution {
private:
    unordered_map<int, vector<p>> adjList;

    void dijkstras(int src, vector<int>& dist, int n) {
        // O(elogv) time
        // space : o(v+E)
        dist[src] = 0;
        priority_queue<p, vector<p>, greater<p>> minHeap;

        minHeap.push({0, src});

        while (!minHeap.empty()) {
            auto [curDist, u] = minHeap.top();
            minHeap.pop();

            if (curDist > dist[u])
                continue;

            for (auto [v, wt] : adjList[u]) {
                if (dist[u] != inf && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    minHeap.push({dist[v], v});
                }
            }
        }
    }

public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        // create adjacency list;
        for (auto it : edges) {
            // O(e):time
            // space : O(v+e)
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        // find the shortest distance from src:0 to all nodes using dijkstras
        vector<int> srcDist(n, inf);
        dijkstras(0, srcDist, n);

        // find the shortest distance from destination : n-1 to all nodes;
        vector<int> endDist(n, inf);
        dijkstras(n - 1, endDist, n);

        int shortestDist = srcDist[n - 1];
        // story points:
        // 1--> an edge(v,v,w) is a part of  any shortest dist path if and only
        // if : srcDist[u]+w+endDist[v]=shortestPathDist OR
        // srcDist[v]+w+endDist[u]=shortestPathDist
        int totalEdges = edges.size();
        vector<bool> res(totalEdges, false);
        // O(e):space

        for (int i = 0; i < totalEdges; i++) {
            // O(e):time
            auto it = edges[i];
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (srcDist[u] != inf && endDist[v] != inf) {
                int dist1 = srcDist[u] + w + endDist[v];
                if (dist1 == shortestDist)
                    res[i] = true;
            }
            if (srcDist[v] != inf && endDist[u] != inf) {
                int dist2 = srcDist[v] + w + endDist[u];
                if (dist2 == shortestDist)
                    res[i] = true;
            }
        }

        return res;
    }
};
