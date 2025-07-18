using p=pair<int,int>;
const int inf = INT_MAX;
class Solution {
private:
vector<vector<int>> edg;
void bellmenFord(int node,vector<vector<int>> &dist,int n){


    // relaxx every edge n-1 times;
    for(int i=1;i<n;i++){
        for(auto &it:edg){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            if(dist[node][u]!=inf && dist[node][u]+w<dist[node][v]){
                dist[node][v]=dist[node][u]+w;
            }
        }
    }
}
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n,vector<int>(n,inf));

        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            edg.push_back({u,v,wt});
            edg.push_back({v,u,wt});
        }

        for(int i=0;i<n;i++){
            bellmenFord(i,dist,n);
        }

        int city=-1;
        int minReachable=n;
        for(int i=0;i<n;i++){
            int src=i;
            int count=0;
            for(int j=0;j<n;j++){
                if(src!=j && dist[src][j]<=distanceThreshold){
                    count++;
                }
            }

            if(count<=minReachable){
                minReachable=count;
                city=src;
            }
        }

        return city;
    }
};
