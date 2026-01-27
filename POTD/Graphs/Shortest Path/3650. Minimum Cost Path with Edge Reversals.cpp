// TIME : O(ELOGV)
// SPACE : O(V+E)

using p=pair<int,int>;
class Solution {
private:
unordered_map<int,vector<p>> adjList;

int dijkstras(int n){
    priority_queue<p,vector<p>,greater<p>>pq;
    pq.push({0,0});

    unordered_set<int> vis;
    vector<int> dist(n,INT_MAX);
    dist[0]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        if(vis.count(u)) continue;

        vis.insert(u);

        for(auto [v,w]:adjList[u]){
            if(dist[u]!=INT_MAX && (dist[u]+w)<dist[v]){
                dist[v]=dist[u]+w;

                pq.push({dist[v],v});
            }
        }
    }

    return dist[n-1];
}
public:
    int minCost(int n, vector<vector<int>>& edges) {
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,2*wt});
        }

        // need to find the min Dist;
        int res=dijkstras(n);

        return res==INT_MAX ? -1 : res;
    }
};
