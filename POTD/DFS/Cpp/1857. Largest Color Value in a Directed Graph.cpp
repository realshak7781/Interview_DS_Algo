// TIME : O(v+E)
// SPACE : O(V+E)

class Solution {
private:

unordered_map<int,unordered_map<int,int>> dp;
bool findCycle(int node,unordered_map<int,vector<int>>&adj,vector<int>&state){
    state[node]=1;

    for(int neigh:adj[node]){
        if(state[neigh]==1) return true;

        if(state[neigh]==2) continue;

        if(findCycle(neigh,adj,state)) return true;
    }

    state[node]=2;

    return false;
}

int solve(int node,int chIdx,unordered_map<int,vector<int>> &adj,string &colours){


    if(dp[node].count(chIdx)) return dp[node][chIdx];
    int curIdx=colours[node]-'a';

    int curCost=0;

    for(int neigh:adj[node]){
        curCost=max(curCost,solve(neigh,chIdx,adj,colours));
    }

    if(curIdx==chIdx){
        curCost+=1;
    }

    return dp[node][chIdx]=curCost;
}
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // should be DAG
        int n=colors.length();
        unordered_map<int,vector<int>> adj;

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
        }

        vector<int> state(n,0);
        for(int i=0;i<n;i++){
            if(state[i]==0){
                if(findCycle(i,adj,state)) return -1;
            }
        }


        // now find the longest length of same colour
        int maxLen=1;
        for(char ch='a';ch<='z';ch++){
            int chIdx=ch-'a';

            for(int node=0;node<n;node++){
                maxLen=max(
                    maxLen,
                    solve(node,chIdx,adj,colors)
                );
            }
        }

        return maxLen;
    }
};
