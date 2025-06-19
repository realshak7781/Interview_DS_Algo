
//BRUTE FORCE APPROACH : TLE

class Solution {
private:
unordered_map<string,int> dp;
int solve(int prevIdx,int idx,vector<int>&nums,int k){
    if(idx>=nums.size()){
        return 0;
    }
    string key=to_string(prevIdx)+"#"+"|"+to_string(idx);
    if(dp.count(key)) return dp[key];
    // not pick
    int notPick=0+solve(prevIdx,idx+1,nums,k);

    int pick=INT_MIN;
    if(prevIdx==-1 || (idx-prevIdx)<=k){
        pick=nums[idx]+solve(idx,idx+1,nums,k);
    }

    return dp[key]=max(pick,notPick);
}    
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        // all neg case
        int val=solve(-1,0,nums,k);

        if(val==0) return maxi; 

        else return val;
    }
};


