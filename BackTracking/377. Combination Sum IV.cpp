class Solution {
private:
unordered_map<int,int> dp[201];
int totalWays(int idx,vector<int>& nums, int target){

    if(target==0){
        return 1;
    }

    if(dp[idx].count(target)) return dp[idx][target];

    int ways=0;
    for(int i=idx;i<nums.size();i++){
        if(nums[i]>target) continue;

        ways+=(totalWays(0,nums,target-nums[i]));
    }

    return dp[idx][target]=ways;
}    
public:
    int combinationSum4(vector<int>& nums, int target) {
        return totalWays(0,nums,target);
    }
};
