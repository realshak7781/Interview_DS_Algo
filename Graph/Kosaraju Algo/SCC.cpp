
class Solution {
    private:
    stack<int> topo;
     unordered_map<int,vector<int>> adjList;
  private:
  void topoDfs(int node,vector<bool>&vis){
    //   this dfs will be used both for topo order and kosaraju step
      vis[node]=true;
      
      for(auto neigh:adjList[node]){
          if(!vis[neigh]){
             topoDfs(neigh,vis);
          }
      }
      topo.push(node);
  }
  
  void dfs(int node,vector<bool>&vis,unordered_map<int,vector<int>> &adjList){
      vis[node]=true;
      
      for(auto neigh:adjList[node]){
          if(!vis[neigh]){
              dfs(neigh,vis,adjList);
          }
      }
  }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int n=adj.size();
        // n =totalNodes;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                adjList[i].push_back(it);
            }
        }
        // original graph is created
        // now create the topo sort using stack and visited array:
        vector<bool> vis(n,false);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoDfs(i,vis);
            }
        }
        // topo stack is created;
        
        // create a graph with reverse edges
        // the same adjList reused again saves memory
        unordered_map<int,vector<int>> revList;
           for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                revList[it].push_back(i);
            }
        }
        
        // same vis used again
        
        vis=vector<bool>(n,false);
        
        int compCount=0;
        
        while(!topo.empty()){
            int node=topo.top();
            topo.pop();
            
            if(vis[node]) continue;
            dfs(node,vis,revList);
            compCount++;
        }
        
        return compCount;
    }
};
