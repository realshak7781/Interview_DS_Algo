// since it is a basic dfs : time : O(n+e) where e=connections.size();
//  and space: 3*O(n) + O(n+e) for adjList+ O(v+e)recursion stack

class Solution {
private:
vector<vector<int>> bridges;
vector<bool> vis;
unordered_map<int,vector<int>> adjList;
vector<int> t_in;
vector<int> low;
int timer;

private:
void dfs(int parent,int node){
    vis[node]=true;
    t_in[node]=low[node]=timer;
    timer++;

    for(auto &neigh:adjList[node]){
        if(neigh==parent) continue;

        if(!vis[neigh]){
            dfs(node,neigh);
            low[node] = min(low[neigh], low[node]);

            if(t_in[node]<low[neigh]){
                bridges.push_back({node,neigh});
            }
        }
        else{
            low[node]=min(low[node],low[neigh]);
        }
    }
}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // its a  basic implementation of tarjans algorithm
        vis.resize(n,false);
        t_in.resize(n,0);
        low.resize(n,0);
        timer=1;

        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        dfs(-1,0);

        return bridges;
    }
};
