class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mx=*max_element(begin(nums),end(nums));
        long long min=*min_element(begin(nums),end(nums));

        long long diff=mx-min;
        long long res=k*diff;

        return res;
    }
};
