class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums),end(nums));
        int minMaxSum = 0;
        int left = 0, right = n - 1;

        while (left < right) {
            int curSum=nums[left]+nums[right];
            minMaxSum=max(curSum,minMaxSum);

            left++;
            right--;
        }

        return minMaxSum;
    }
};
