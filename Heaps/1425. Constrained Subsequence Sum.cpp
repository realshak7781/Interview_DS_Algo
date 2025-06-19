class Solution {
private:
    unordered_map<string, int> dp;
    int memo(int prevIdx, int idx, vector<int>& nums, int k) {
        if (idx >= nums.size()) {
            return 0;
        }
        string key = to_string(prevIdx) + "#" + "|" + to_string(idx);
        if (dp.count(key))
            return dp[key];
        // not pick
        int notPick = 0 + memo(prevIdx, idx + 1, nums, k);

        int pick = INT_MIN;
        if (prevIdx == -1 || (idx - prevIdx) <= k) {
            pick = nums[idx] + memo(idx, idx + 1, nums, k);
        }

        return dp[key] = max(pick, notPick);
    }

    int tab(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prevIdx = n; prevIdx >= -1; prevIdx--) {
                int notPick = dp[idx + 1][prevIdx + 1];

                int pick = INT_MIN;
                if (prevIdx == -1 || (idx - prevIdx) <= k) {
                    pick = nums[idx] + dp[idx + 1][idx + 1];
                }

                dp[idx][prevIdx + 1] = max(pick, notPick);
            }
        }

        return dp[0][0]; 
    }

int bottomUp(vector<int>&nums,int k){
    int n=nums.size();
    vector<int> vec(n);

    for(int i=0;i<n;i++){
        vec[i]=nums[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0 && (i-j)<=k;j--){
            vec[i]=max(vec[i],nums[i]+vec[j]);
        }
    }

    int res=*max_element(vec.begin(),vec.end());

    return res;
}

public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // int n = nums.size();
        // int maxi = *max_element(nums.begin(), nums.end());
        // all neg case
        // int val = tab(nums, k);

        // if (val == 0)
        //     return maxi;

        // else
        //     return val;


        return bottomUp(nums,k);
    }
};
