

// brute force : O(n^3) 
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[k]>nums[i] && nums[k]<nums[j]) return true;
                }
            }
        }

        return false;
    }
};
