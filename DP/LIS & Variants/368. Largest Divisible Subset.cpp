



// RECURSION & MEMOIZATION
class Solution {
private:
vector<vector<vector<int>>> dp;
vector<int> solve(int prevIdx,int idx,vector<int>&nums,int n){
    if(idx>=n){
        return {};
    }

   if (!dp[prevIdx + 1][idx].empty())  return dp[prevIdx + 1][idx];
           
    vector<int> notPick=solve(prevIdx,idx+1,nums,n);

    vector<int> pick;
    if(prevIdx==-1 || (nums[idx]%nums[prevIdx]==0)){
        // pick
        pick=solve(idx,idx+1,nums,n);
        pick.push_back(nums[idx]);
    }


   return dp[prevIdx+1][idx]=pick.size()>notPick.size()? pick:notPick;
}    
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n, vector<int>()));

        vector<int> result=solve(-1,0,nums,n);

        reverse(result.begin(),result.end());

        return result;
    }
};
