class Solution {
private:
unordered_map<int,unordered_map<int,int>> dp;
int solve(int idx,vector<int>&nums,int prevRem){
    if(idx>=nums.size()){
       if(prevRem==0) return 0;

       return INT_MIN;
    }

    if(dp[idx].count(prevRem)) return dp[idx][prevRem];

    int newRem=(nums[idx]+prevRem)%3;
    int pick=(nums[idx]+solve(idx+1,nums,newRem));
    int notPick=solve(idx+1,nums,prevRem);

    return dp[idx][prevRem]=max(pick,notPick);
}
public:
    int maxSumDivThree(vector<int>& nums) {
        return max(0,solve(0,nums,0));
    }
};
