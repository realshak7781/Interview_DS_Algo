class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int> mp;

        int curSum=0;
        int count=0;
        for(int i=0;i<n;i++){
            curSum+=nums[i];
            if(curSum>=goal){

                if(curSum==goal) count++;
                int pasVal=curSum-goal;

                count+=mp[pasVal];
            }

            mp[curSum]++;
        }

        return count;
    }
};
