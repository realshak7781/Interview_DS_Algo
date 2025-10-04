class Solution {
private:
const int mod=1e9+7;
int dp[100001][3][3];
bool isSameParity(int idx,int prev,int lastPrev,vector<int>&nums){

   return (nums[idx]==prev && prev==lastPrev);
}
int solve(int idx,int prev,int lastPrev,vector<int>&nums){
    if(idx==nums.size()){
        if(prev==-1 && lastPrev==-1)return 0;
        return 1;
    }

    if(dp[idx][prev+1][lastPrev+1]!=-1) return dp[idx][prev+1][lastPrev+1];

    // pick 
    int pick=0;
    if(lastPrev==-1 || !isSameParity(idx,prev,lastPrev,nums)){
        pick=solve(idx+1,nums[idx],prev,nums)%mod;
    }
    // not pick
    int notPick=solve(idx+1,prev,lastPrev,nums)%mod;

    return dp[idx][prev+1][lastPrev+1]=(pick+notPick)%mod;
}

public:
    int countStableSubsequences(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            nums[i]=nums[i]%2;
        }

        memset(dp,-1,sizeof(dp));
        return solve(0,-1,-1,nums);
    }
};
