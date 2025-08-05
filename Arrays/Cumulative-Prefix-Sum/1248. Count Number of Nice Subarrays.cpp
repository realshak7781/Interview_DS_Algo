class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int goal=k;

        for(int i=0;i<n;i++){
            nums[i]=nums[i]%2;
        }
        unordered_map<int, int> mp;

        int curSum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            curSum += nums[i];
            if (curSum >= goal) {

                if (curSum == goal)
                    count++;
                int pasVal = curSum - goal;

                count += mp[pasVal];
            }

            mp[curSum]++;
        }

        return count;
    }
};
