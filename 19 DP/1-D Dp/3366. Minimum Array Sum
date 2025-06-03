class Solution {
private:
int n;
int dp[101][101][101];
int solve(int index,int k,int op1,int op2,vector<int>&nums){
    if(index>=n) return 0;

    if(dp[index][op1][op2]!=-1) return dp[index][op1][op2];
    int minVal=INT_MAX;
    // apply op1
    if(op1>0){
        int op1Val=(nums[index]+1)/2;
        minVal=min(minVal,op1Val+solve(index+1,k,op1-1,op2,nums));
    }
    // apply op2
    if(op2>0 && nums[index]>=k){
        int op2Val=nums[index]-k;
        minVal=min(minVal,op2Val+solve(index+1,k,op1,op2-1,nums));
    }
    // apply op1&op2
    if(op1>0 && op2>0){
        int apply1=(nums[index]+1)/2;
        if(apply1>=k){
            int apply2=apply1-k;
            minVal=min(minVal,apply2+solve(index+1,k,op1-1,op2-1,nums));
        }
    }
    // apply op2&op3
    if(op1>0 && op2>0){
        if(nums[index]>=k){
            int apply2=nums[index]-k;
            int apply1=(apply2+1)/2;
            minVal=min(minVal,apply1+solve(index+1,k,op1-1,op2-1,nums));
        }
    }
    // do nothing
    minVal=min(minVal,nums[index]+solve(index+1,k,op1,op2,nums));

    return dp[index][op1][op2]=minVal;
}    
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,k,op1,op2,nums);
    }
};
