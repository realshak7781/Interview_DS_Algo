class Solution {
private:
void dfs(int node,int parent,unordered_map<int,vector<int>> &adjList,vector<int>&nums,vector<int>&subTreeXor,vector<int>&inTime,vector<int>&outTime,int &timer){

    subTreeXor[node]=nums[node];
    inTime[node]=timer;
    timer++;

    for(int &ngbr:adjList[node]){
        if(parent==ngbr) continue;
        dfs(ngbr,node,adjList,nums,subTreeXor,inTime,outTime,timer);
        subTreeXor[node]^=subTreeXor[ngbr];
    }

    outTime[node]=timer;
    timer++;
}

int getScore(int x1,int x2,int x3){
    int maxi=max({x1,x2,x3});
    int mini=min({x1,x2,x3});

    return (maxi-mini);
}

bool isAncestor(int u,int v,vector<int>&inTime,vector<int>&outTime){
    return inTime[u]<=inTime[v] && outTime[u]>=outTime[v];
}
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        //STORY POINTS;
        // compute totalXor
        // do a single dfs on the tree to compute xor values of each subtree(Postorder dfs) and store in subXor array: subXor[]
        //  Now select pair of nodes thorugh two for loops
        //  now xor1=subXor[node1]
        // xor2=subXor[node2];
        // xor3=totalXor^xor1^xor2;
        // score=0
        // res=min(score,max({xor1,xor2,xor3}-min(xor1,xor2,xor3)));
        // return res;
        int n=nums.size();
        unordered_map<int,vector<int>> adjList;

        int totalXor=0;
        for(int &val:nums)totalXor^=val;

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> subTreeXor(n,0);
        vector<int> inTime(n,0);
        vector<int> outTime(n,0);

        int timer=0;
        dfs(0,-1,adjList,nums,subTreeXor,inTime,outTime,timer);

        int score=INT_MAX;
        for(int u=1;u<n;u++){
            for(int v=u+1;v<n;v++){
                if(isAncestor(u,v,inTime,outTime)){
                    // ancestor descendant pairs;
                    // u is an ancestor of v
                    int xor1=subTreeXor[u]^subTreeXor[v];
                    int xor2=subTreeXor[v];
                    int xor3=totalXor^xor1^xor2;
                    score=min(score,getScore(xor1,xor2,xor3));
                }
                else if(isAncestor(v,u,inTime,outTime)){
                    // v is an ancestor of u
                    int xor1=subTreeXor[v]^subTreeXor[u];
                    int xor2=subTreeXor[u];
                    int xor3=totalXor^xor1^xor2;
                    score=min(score,getScore(xor1,xor2,xor3));
                }
                else{
                    // the nodes are not ancestor descendant pairs;
                    int xor1=subTreeXor[u];
                    int xor2=subTreeXor[v];
                    int xor3=totalXor^xor1^xor2;
                    score=min(score,getScore(xor1,xor2,xor3));
                }
            }
        }

        return score;
    }
};
