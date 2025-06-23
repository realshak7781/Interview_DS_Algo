using ll=long long;
class Solution {
private:
vector<vector<ll>> dp; 
ll solve(int parity,int idx,vector<int>&nums,int n){

    if(idx>=n){
        return 0;
    }

    if(dp[idx][parity]!=-1) return dp[idx][parity];

    ll notPick=0+solve(parity,idx+1,nums,n);
    // parity-->0:even and parity--> 1: odd
    ll pick=0;
    if(parity==0){
        pick=solve(1-parity,idx+1,nums,n)+nums[idx];
    }
    else{
        pick=solve(1-parity,idx+1,nums,n)-nums[idx];
    }

    return  dp[idx][parity]=max(pick,notPick);
}    
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        dp=vector<vector<ll>>(n+1,vector<ll>(2,-1));
        return solve(0,0,nums,n);
    }
};
