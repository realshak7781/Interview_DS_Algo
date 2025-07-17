class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // mod k : 0,1,2,3,......k-1
        int n=nums.size();
        // using LS bottomu up approach:
        vector<vector<int>> dp(k,vector<int>(n,1));
        // row 0: sum%k -->0
        // row 1 : sum%k--> 1

        int maxSubLength=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int modVal=(nums[i]+nums[j])%k;
                dp[modVal][i]=max(dp[modVal][i],dp[modVal][j]+1);
                maxSubLength=max(maxSubLength,dp[modVal][i]);
            }
        }

        return maxSubLength;
    }
};
