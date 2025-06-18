class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0) return 0;
        int maxLen=1;
        int curLen=1;

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            else if((nums[i]-nums[i-1])==1) curLen++;

            else{
                maxLen=max(maxLen,curLen);
                curLen=1;
            }
        }

        return max(maxLen,curLen);
    }
};
