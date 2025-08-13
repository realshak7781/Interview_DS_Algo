class Solution {
private:
int count=0;
      unordered_map<int,vector<
            pair<int,pair<int,int>>
            >
            > adjList;
    
void dfs(int node,vector<int>&vis,int n){
    if(vis[node]) return ;
    vis[node]=true;
    
    for(auto &it:adjList[node]){
        int v=it.first;
        if(vis[v]) continue;
        int start=it.second.first;
        int end=it.second.second;
        
        if(node==start && v==end){
            count++;
        }
        
        dfs(v,vis,n);
    }
}
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        count=0;
        
        for(auto &it:connections){
            int u=it[0];
            int v=it[1];
            
            adjList[u].push_back({v,{u,v}});
            adjList[v].push_back({u,{u,v}});
        }
        
        vector<int> vis(n,false);
        
        dfs(0,vis,n);
        
        return count;
        
    }
};
