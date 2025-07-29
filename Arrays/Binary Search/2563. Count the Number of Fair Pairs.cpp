using ll=long long;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        ll count=0;
        for(int i=0;i<n;i++){
            // nj>=lower-nums[i]
            // nj<=upper-nums[i];

            auto low=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            auto up=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);

            ll cnt=distance(low,up);

            count+=cnt;
        }

        return count;
    }
};
