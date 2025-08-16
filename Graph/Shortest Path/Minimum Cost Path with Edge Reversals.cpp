using p=pair<int,int>;
const int inf=INT_MAX;
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<p>> adjList;

        for(auto&it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            adjList[u].push_back({v,w});
            adjList[v].push_back({u,2*w});
        }
        
        unordered_set<int> vis;
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});

        vector<int> dist(n,inf);
        dist[0]=0;
        while(!pq.empty()){
            int uCost=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            
            if(vis.count(u)) continue;
            vis.insert(u);

            if(u==n-1) return uCost;

            for(auto it:adjList[u]){
                int ng=it.first;
                int nCost=it.second;
                if(uCost+nCost<dist[ng]){
                    dist[ng]=uCost+nCost;
                    pq.push({dist[ng],ng});
                }
            }
        }


        return -1;
    }
};
