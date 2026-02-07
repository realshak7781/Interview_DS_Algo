// using bottom up dp:
using ll = long long;
class Solution {
private:
    const ll negInf = -1e16;
    ll solve(vector<int>& nums) {
        int  n=nums.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(5, negInf));

        dp[n][3] = 0;

        // state definition : dp[idx][trend] : maximum sum of any trionic subarray starting at idx eith trend t 
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int trend=3;trend>=0;trend--) {
                ll maxSum = negInf;
                if (trend == 0) {
                    maxSum = max(maxSum, dp[idx+1][0]);
                }

                if (trend == 3) {
                    maxSum = nums[idx];
                }
                if (idx + 1 < n) {
                    int cur = nums[idx];
                    int next = nums[idx + 1];

                    if (trend == 0 && next > cur) {
                        maxSum =
                            max(maxSum, nums[idx] + dp[idx+1][1]);
                    } else if (trend == 1) {
                        if (next > cur) {
                            maxSum = max(
                                maxSum, nums[idx] + dp[idx+1][1]);
                        } else if (next < cur) {
                            maxSum = max(
                                maxSum, nums[idx] + dp[idx+1][2]);
                        }
                    } else if (trend == 2) {
                        if (next < cur) {
                            maxSum = max(
                                maxSum, nums[idx] + dp[idx+1][2]);
                        } else if (next > cur) {
                            maxSum = max(
                                maxSum, nums[idx] + dp[idx+1][3]);
                        }
                    } else if (trend == 3) {
                        if (next > cur) {
                            // continuing trend
                            maxSum = max(
                                maxSum, nums[idx] + dp[idx+1][3]);
                        }
                    }
                }

               dp[idx][trend] = maxSum;
            }
        }

        return dp[0][0];
    }

public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        return solve(nums);
    }
};


// Using Recursion + Memoization
using ll=long long;
class Solution {
private :
unordered_map<int,unordered_map<int,ll>> dp;
const ll negInf=-1e16;
ll solve(int idx,int trend,vector<int>&nums,int n){
    if(idx==n){
        if(trend==3){
            return 0;
        }
        else{
            return negInf;
        }
    }

    if(dp[idx].count(trend)) return dp[idx][trend];

    ll maxSum=negInf;
    if(trend==0){
        maxSum=max(maxSum,solve(idx+1,0,nums,n));
    }

    if(trend==3){
        maxSum=nums[idx];
    }
    if(idx+1<n){
        int cur=nums[idx];
        int next=nums[idx+1];

        if(trend==0 && next>cur){
            maxSum=max(maxSum,nums[idx]+solve(idx+1,1,nums,n));
        }
        else if(trend==1){
            if(next>cur){
                maxSum=max(maxSum,nums[idx]+solve(idx+1,1,nums,n));
            }
            else if(next<cur){
                maxSum=max(maxSum,nums[idx]+solve(idx+1,2,nums,n));
            }
        }
        else if(trend==2){
            if(next<cur){
                maxSum=max(maxSum,nums[idx]+solve(idx+1,2,nums,n));
            }
            else if(next>cur){
                maxSum=max(maxSum,nums[idx]+solve(idx+1,3,nums,n));
            }
        }
        else if(trend==3){
           if(next>cur){
            // continuing trend
             maxSum=max(maxSum,nums[idx]+solve(idx+1,3,nums,n));
           }
        }
    }

    return dp[idx][trend]=maxSum;
}
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        return solve(0,0,nums,n);
    }
};
