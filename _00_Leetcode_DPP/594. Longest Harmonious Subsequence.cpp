

// BRUTE FORCE: O(N^2) +O(NLOGN)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int maxLen=INT_MIN;
        for(int i=n-1;i>=0;i--){
            int len=0;

            for(int j=i-1;j>=0;j--){
                if((nums[i]-nums[j])==1){
                    len=max(len,i-j+1);
                }
                else if((nums[i]-nums[j])>1) break;
            }
            maxLen=max(len,maxLen);
        }

        return maxLen;
    }
};
