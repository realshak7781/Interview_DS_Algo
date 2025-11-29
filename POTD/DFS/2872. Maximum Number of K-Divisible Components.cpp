class Solution {
private:
unordered_map<int,vector<int>> adjList;
int totalComps=0;
long long dfs(int node,int parent,vector<int>&values,int k){

    long long curVal=values[node];
    for(auto neigh:adjList[node]){
        if(neigh!=parent){
            curVal+=dfs(neigh,node,values,k);
        }
    }

    if(curVal%k==0){
        totalComps++;
        return 0;
    }

    return curVal;
}
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        dfs(0,-1,values,k);

        return totalComps;
    }
};
