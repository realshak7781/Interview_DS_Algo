using ll=long long;
class Solution {
private:
unordered_map<int,vector<int>> adjList;
const int mod=1e9+7;

void dfs(int node,int depth,int &maxDepth){

    maxDepth=max(maxDepth,depth);
    for(auto it:adjList[node]){
        dfs(it,depth+1,maxDepth);
    }
}

ll findPow(ll a,ll b){
    if(b==0) return 1;

    ll half=findPow(a,b/2);

    ll result=(half*half)%mod;

    if(b&1){
        result=(result*a)%mod;
    }

    return result;
}
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int maxDepth=0;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            adjList[u].push_back(v);
        }

        dfs(1,0,maxDepth);


        ll res=findPow(2,maxDepth-1)%mod;

        return (int)res;
    }
};
