class Solution {
private:
vector<vector<int>> res;

void solve(int idx,vector<int>&nums,int target,vector<int>&temp){
    if(target==0){
        res.push_back(temp);
        return;
    }
    
    if(idx>=nums.size()) return ;
    
//     pick or not pick strategy
    if(nums[idx]<=target){
        temp.push_back(nums[idx]);
        solve(idx,nums,target-nums[idx],temp);
        temp.pop_back();
    }
    
    solve(idx+1,nums,target,temp);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<int> temp;
        
        solve(0,candidates,target,temp);
        
        return res;
    }
};
