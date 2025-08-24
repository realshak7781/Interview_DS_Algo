// Time complexity: O(2*N)(first one to include in the current window and second N to exclude from the current window)
// space complexity : O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // its a basic sliding window problem:
        // where you have to maintain the count of zeroes inside your current window as 1

        int zeroCount=0;
        int i=0;
        int maxLen=0;

        for(int j=0;j<nums.size();j++){
            if(nums[j]==0){
                zeroCount++;
            }

            while(zeroCount>1){
                if(nums[i]==0){
                    zeroCount--;
                }
                i++;
            }

            maxLen=max(maxLen,j-i);
        }
        return maxLen;
    }
};
