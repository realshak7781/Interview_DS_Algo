
// Leetcode POTD : 25 july 2025
class Solution {
public:
    int maxSum(vector<int>& nums) {
       int n=nums.size();
       int maxi=*max_element(begin(nums),end(nums));

       if(maxi<=0){
        // all neg case
        return maxi;
       }

       unordered_set<int> seen;
       int maxSum=0;
       for(int val:nums){
        if(val>=0 && !seen.count(val)){
            maxSum+=val;
            seen.insert(val);
        }
       }

       return maxSum;
    }
};
