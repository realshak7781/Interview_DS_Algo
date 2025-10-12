class Solution {
public:
    int minOperations(vector<int>& nums) {
        // just check whether all elements are equal or no

        sort(begin(nums),end(nums));

        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]) return 1;
        }

        return 0;
    }
};
