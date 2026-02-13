


// approach 1 : Using brute force 
// time : O(n^2)
// space : O(n)
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();

        vector<int> cumSum(n,0);
        unordered_map<int,int> mp;

        int maxLen=0;

        for(int r=0;r<n;r++){
            int val=(nums[r]&1) ? -1 : 1;

            int prev=-1;
            if(mp.count(nums[r])){
                prev=mp[nums[r]];
            }

            if(prev!=-1){
                // found the element previously
                for(int l=0;l<=prev;l++){
                    cumSum[l]-=val;
                }
            }

            // now add the val to cumSum
            for(int l=0;l<=r;l++){
                cumSum[l]+=val;

                if(cumSum[l]==0){
                    maxLen=max(maxLen,r-l+1);
                }
            }

            mp[nums[r]]=r;
        }

        return maxLen;
    }
};
