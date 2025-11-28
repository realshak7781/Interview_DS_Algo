// Approach 2:
// using maths and prefixSum :
using ll = long long;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        ll maxSum=LLONG_MIN;
        // we will use the formula and derive the solution from that :
        // len = j-i+1
        // (j+1)%k==(i%k)
        // subarraySum=pfSum[j]-pfsum[i-1]
        // to form a valid subarray ending at idx j start idex i must have the same rem as (j+1)%k
        // so prevIdx=i-1;
        // i=prevIdx+1
        // substituting:
        // (j+1)%k==(prevIdx+1)%k;


        vector<ll> mp(k,LLONG_MAX);
        ll curSum=0;
        mp[0]=0;
        for(int i=0;i<n;i++){
            curSum+=nums[i];

            int rem=(i+1)%k;

            if(mp[rem]!=LLONG_MAX){
                ll subSum=curSum-mp[rem];
                maxSum=max(maxSum,subSum);
            }

            mp[rem]=min(curSum,mp[rem]);
        }

        return maxSum;
    }
};


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


// Approach 3 : Using Kadane Algorithm
using ll=long long;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        ll maxSum=LLONG_MIN;

        vector<ll> pfSum(n);
        pfSum[0]=nums[0];
        for(int i=1;i<n;i++){
            pfSum[i]=nums[i]+pfSum[i-1];
        }

        for(int idx=0;idx<k;idx++){
            ll curSum=0;
            int i=idx;
            int j=i+k-1;

            while(i<n && j<n){
                ll subSum=pfSum[j]-(i>0 ? pfSum[i-1]:0);
                curSum=max(subSum,curSum+subSum);
                maxSum=max(maxSum,curSum);
                i+=k;
                j=i+k-1;
            }
        }

        return maxSum;
    }
};
