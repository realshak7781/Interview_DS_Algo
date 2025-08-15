// Space Complexity: O(V + E)

// Time Complexity: O(log W * (V + E) log V)

using p = pair<int, int>;
using ll=long long;
const ll inf=LLONG_MAX;
class Solution {
private:
    unordered_map<int, vector<p>> adjList;

    ll dijkstras(int node, int weight, int n, vector<bool>& online, long long k) {
       priority_queue<p,vector<p>,greater<p>> pq;

       pq.push({0,0});
       unordered_set<int> vis;
       vector<ll> dist(n,inf);
       dist[0]=0;

       while(!pq.empty()){
          int u=pq.top().second;
          ll uCost=pq.top().first;
          pq.pop();

          if(vis.count(u)) continue;
          vis.insert(u);

          if(u==n-1){
            return dist[u];
          }


          for(auto &it:adjList[u]){
            int v=it.first;
            int edgeCost=it.second;

            if(online[v] && edgeCost>=weight){
                // can we relax?
                ll newCost=uCost+edgeCost;
                if(newCost<dist[v]){
                    dist[v]=newCost;
                    pq.push({newCost,v});
                }
            }
          }

       }

       return dist[n-1];
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int low = INT_MAX;
        int high = INT_MIN;
        int n = online.size();  

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            low = min(low, cost);
            high = max(high, cost);

            adjList[u].push_back({v, cost});
        }

        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            
            if (dijkstras(0, mid, n, online, k)<=k) {
                res = mid;
                low = mid + 1;  
            } else {
                high = mid - 1;  
            }
        }

        return res;
    }
};
