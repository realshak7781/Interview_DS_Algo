class Solution {
private:
int n;
unordered_map<int,int> freq;
unordered_map<int,int> dp;
int solve(int idx,vector<int> &nums){
    if(idx>=n) return 0;

    if(dp.count(idx)) return dp[idx];

    int pick=freq[nums[idx]]*nums[idx];

    if(idx+1<n && nums[idx+1]==nums[idx]+1) pick+=solve(idx+2,nums);
    else if(idx+1<n && nums[idx+1]!=nums[idx]+1) pick+=solve(idx+1,nums);

    int notPick=0+solve(idx+1,nums);

    return dp[idx]=max(pick,notPick);
}
public:
    int deleteAndEarn(vector<int>& nums) {

        for(int val:nums) freq[val]++;

        vector<int> v;
        for(auto it:freq) v.push_back(it.first);
        sort(begin(v),end(v));

        n=v.size();

        return solve(0,v);
    }
};
