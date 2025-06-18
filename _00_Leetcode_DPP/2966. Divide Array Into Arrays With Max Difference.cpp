class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int totalGroups=n/3;

        int i=0;

        vector<vector<int>> res;
        while(i<n){
            int start=i;
            int end=i+2;

            if((nums[end]-nums[start])<=k){
                res.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            else{
                res.clear();
                break;
            }

            i+=3;
        }


        return res;
    }
};
