class Solution {
private:
unordered_map<int,unordered_map<int,int>>dp;
int solve(int idx,int mask,vector<int>&nums1,vector<int>&nums2,int n){
    if(idx>=n){
        return 0;
    }


    if(dp[idx].count(mask)){
        return dp[idx][mask];
    }
    int minSum=INT_MAX;

    for(int i=0;i<n;i++){
        if(mask & (1<<i)) continue;

        int xorSum=nums1[idx] ^ nums2[i];

        minSum=min(minSum,
               xorSum + solve(idx+1,mask | (1<<i),nums1,nums2,n)
        );
    }

    return dp[idx][mask]=minSum;
}
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        return solve(0,0,nums1,nums2,n);
    }
};
