
// Leetcode POTD : 22 july 2025
// Time : Each element is visited twice : while adding to curSum and while removing from Cur sum : O(2*N)
// space is : O(n) for map
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // simple sliding window problem using a hashtable
        int n=nums.size();
        unordered_map<int,int> idxMap;

        int maxScore=0;
        int curScore=0;
        int i=0,j=0;
        while(j<n){
            if(idxMap.count(nums[j])){
                // idx of previous duplicate element;
                int prevIdx=idxMap[nums[j]];
                maxScore=max(curScore,maxScore);

                while(i<=prevIdx){
                    curScore-=nums[i++];
                }
            }
            curScore+=nums[j];
            
            idxMap[nums[j]]=j;
            j++;
        }

        maxScore=max(maxScore,curScore);

        return maxScore;
    }
};

