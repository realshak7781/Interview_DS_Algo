class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<long long, long long>> dp(n);
        // a vector of maps:
        //  each index having its own map:
        //  0 : {
                //   diff : count
        // }

        long long totalSeq=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff=(long long)((long long)nums[i]-(long long)nums[j]);

                dp[i][diff]+=dp[j][diff]+1;

                totalSeq+= dp[j][diff];
            }
        }

        return totalSeq;
    }
};
