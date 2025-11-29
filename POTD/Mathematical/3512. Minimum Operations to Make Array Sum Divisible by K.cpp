class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalSum=accumulate(begin(nums),end(nums),0);

        int ops=totalSum%k;

        return ops;
    }
};
