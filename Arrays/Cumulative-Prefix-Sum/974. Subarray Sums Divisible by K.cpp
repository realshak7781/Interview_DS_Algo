// brute force : O(n^2)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // divisible by k means modulo k==0
        int m = k;

        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];

                if (sum % m == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
