using p = pair<int, int>;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, pair<int, int>>>> adjList;

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int st = it[2];
            int en = it[3];
            adjList[u].push_back({v, {st, en}});
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        set<int> vis;  

        pq.push({0, 0}); 

        while (!pq.empty()) {
            auto front = pq.top();
            int time = front.first;
            int node = front.second;
            pq.pop();

            if (node == (n - 1)) return time;  

            if (vis.count(node)) continue;  
            vis.insert(node);  

            
            for (auto& neigh : adjList[node]) {
                int ng = neigh.first;
                int st = neigh.second.first;
                int en = neigh.second.second;

                if (time >= st && time <= en) {
                    pq.push({time + 1, ng});
                }
                else if (time < st) {
                    pq.push({st + 1, ng});
                }
            }
        }

        return -1;  
    }
};
