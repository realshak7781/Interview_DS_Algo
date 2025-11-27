

// Approach 1 : Using Sliding window and looping for Len
// time : O(n^2) --------------> BRUTE FORCE
using ll = long long;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        ll maxSum = LLONG_MIN;
        int len=k;

        while(len<=n){
            int i=0;
            int j=0;
            ll sum=0;
            while(j<n){
                int curLen=j-i+1;
                sum+=nums[j];
                if(curLen==len){
                  maxSum=max(maxSum,sum);
                  sum-=nums[i];
                  i++;  
                }
                j++;
            }

            len+=k;
        }

        return maxSum;
    }
};
