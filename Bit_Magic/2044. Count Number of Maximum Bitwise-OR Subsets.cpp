// Leetcode potd: 28 july 2025
// Time : O(n*2^N) + O(N)
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxOr=0;
        for(int val:nums){
            maxOr|=val;
        }

        int count=0;

        for(int mask=0;mask<(1<<n);mask++){
            int curOr=0;

            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    curOr|=nums[i];
                }
            }

            if(curOr==maxOr) count++;
        }

        return count;
    }
};
