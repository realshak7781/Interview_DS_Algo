// Approach 3 : Using Binary Search to find the maxEnd ,while being fixated on the minimum on one Side
using ll=long long;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 0;

        sort(begin(nums),end(nums));
        int minRes=1e9;
        for(int i=0;i<n;i++){
            ll mulVal=1LL*k*nums[i]; 
            int low=i+1;
            int high=n-1;
            int idx=-1;

            while(low<=high){
                int mid=low+(high-low)/2;

                if(nums[mid]<=mulVal){
                    idx=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }

            if(idx!=-1){
                int elemToDelete=n-(idx-i+1);
                minRes=min(minRes,elemToDelete);
            }
            else if(idx==-1){
                // only keep the current element and delete everything
                minRes=min(minRes,n-1);
            }
        }

        return minRes;
    }
};


// approach 2: Using brute force approach :
using ll=long long;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();

        sort(begin(nums),end(nums));
        int minRes=n;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ll mulVal=1LL*nums[i]*k;
                if(nums[j]<=mulVal){
                    int elemToDelete=n-(j-i+1);
                    minRes=min(minRes,elemToDelete);
                }
            }
        }

        return minRes;
    }
};

// Approach 1 : Using DP
// Time : O(n*n)
// space : O(n*n)
using ll=long long;
class Solution {
private:
unordered_map<int,unordered_map<int,int>> dp;
int findWays(int start,int end,vector<int>&nums,int k,int n){
    if(start>=end){
        return 0;
    }

    int minSteps=1e9;
    ll mulVal=1LL*k*nums[start];
    bool isBalanced=nums[end]<=mulVal;
    if(isBalanced) return 0;

    if(dp[start].count(end)) return dp[start][end];

    // three options
    // move start
    minSteps=min(minSteps,1+findWays(start+1,end,nums,k,n));
    // move end
    minSteps=min(minSteps,1+findWays(start,end-1,nums,k,n));
    // move both
    minSteps=min(minSteps,2+findWays(start+1,end-1,nums,k,n));

    return dp[start][end]=minSteps;
}
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));

        return findWays(0,n-1,nums,k,n);
    }
};
