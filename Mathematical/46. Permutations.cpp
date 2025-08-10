// Using recursion+backtracking:
class Solution {
private:
vector<vector<int>> res;
void solve(int idx,vector<int>& nums,int n){
    if(idx>=n){
        res.push_back(nums);
        return;
    }

    for(int start=idx;start<n;start++){
        swap(nums[start],nums[idx]);

        solve(idx+1,nums,n);

        swap(nums[start],nums[idx]);
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        solve(0,nums,n);

        return res;
    }
};

// Using STL:
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(),nums.end());
        do{
            res.push_back(nums);
        }
        while(next_permutation(begin(nums),end(nums)));

        return res;
    }
};
