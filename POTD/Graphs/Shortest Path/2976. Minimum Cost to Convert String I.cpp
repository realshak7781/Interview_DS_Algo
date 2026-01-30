// USING THE FLOYD WARSHALL ALGORITHM:

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // construct the adjacency List;
        int totalSizeOfOperations=original.size();

        // Using the Floyd warshall algorithm : we need the min cost from any source to any target
        vector<vector<long long>> dist(26,vector<long long>(26,LLONG_MAX));
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j){
                    dist[i][j]=0;
                }
            }
        }

        for(int i=0;i<totalSizeOfOperations;i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            int wt=cost[i];
            dist[u][v]=min(dist[u][v], 1LL*wt);
        }

        

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        long long totalMinCost=0;
        for(int i=0;i<source.length();i++){
            int u=source[i]-'a';
            int v=target[i]-'a';

            long long curTransitionCost=dist[u][v];
            if(curTransitionCost==LLONG_MAX) return -1;
            totalMinCost+=curTransitionCost;
        }

        return totalMinCost;
    }
};

// USING MULTI SOURCE DIJKSTRAS ALGORITHM : 
// m : TOTAL ENTRIES IN ORIGINAL AND CHANGED
// TIME : O(N) + O(mlogm)
// SPACE : O(m)
using p=pair<int,long long>;
class Solution {
private:
unordered_map<int,vector<p>> adjList;

vector<long long> dijkstras(int source){
    vector<long long> dist(26,LLONG_MAX);
    priority_queue<p,vector<p>,greater<p>>pq;

    pq.push({0,source});
    dist[source]=0;
    unordered_set<int> seen;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        if(seen.count(u)) continue;

        seen.insert(u);

        for(auto [v,wt]:adjList[u]){
            if(dist[u]!=LLONG_MAX && (dist[u]+wt)<dist[v]){
                dist[v]=dist[u]+wt;
                pq.push({dist[v],v});
            }
        }
    }


    return dist;
}
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // construct the adjacency List;
        int totalSizeOfOperations=original.size();
        for(int i=0;i<totalSizeOfOperations;i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            int wt=cost[i];

            adjList[u].push_back({v,wt});
        }

        unordered_map<int,vector<long long>> distMap;
        for(int i=0;i<26;i++){
            distMap[i]=dijkstras(i);
        }

        long long totalMinCost=0;
        for(int i=0;i<source.length();i++){
            int u=source[i]-'a';
            int v=target[i]-'a';

            long long curTransitionCost=distMap[u][v];
            if(curTransitionCost==LLONG_MAX) return -1;
            totalMinCost+=curTransitionCost;
        }

        return totalMinCost;
    }
};
