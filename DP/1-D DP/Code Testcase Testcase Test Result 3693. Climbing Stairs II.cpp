class Solution {
private:
vector<int> dp;
int solve(int i,vector<int>&costs,int n){
    if(i>=n) return 0;

    if(dp[i]!=-1) return dp[i];
    int minCost=INT_MAX;
    for(int k=1;k<=3;k++){
        int j=i+k;
        if(j>n) break;
        int cost=costs[j-1]+pow(j-i,2);
        minCost=min(cost+solve(j,costs,n),minCost);
    }

    return dp[i] = minCost==INT_MAX ? 0 : minCost;
}
public:
    int climbStairs(int n, vector<int>& costs) {
        dp.resize(n+1,-1);
        return solve(0,costs,n);
    }
};
