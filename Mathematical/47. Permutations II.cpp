class Solution {
private:
vector<vector<int>> res;
void solve(int idx,vector<int>& nums,int n){
    if(idx>=n){
        res.push_back(nums);
        return;
    }

    unordered_set<int> seen;
    for(int start=idx;start<n;start++){

        if(seen.count(nums[start])) continue;
        seen.insert(nums[start]);

        swap(nums[start],nums[idx]);
        solve(idx+1,nums,n);
        swap(nums[start],nums[idx]);
    }
}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        solve(0,nums,n);

        return res;
    }
};
