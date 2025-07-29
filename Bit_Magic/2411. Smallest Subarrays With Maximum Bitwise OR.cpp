
// O(n) approach : Last set bit seen technique used 
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n, 1);
        vector<int> recentSetBit(32, -1);

        for (int i = n - 1; i >= 0; i--) {
            int curVal = nums[i];

            int maxPos = -1;
            for (int pos = 0; pos < 32; pos++) {
                if (curVal & (1 << pos)) {
                    recentSetBit[pos] =i;
                }
                maxPos = max(maxPos, recentSetBit[pos]);
            }
            
            if(maxPos!=-1)res[i]=maxPos-i+1;
        }


        return res;
    }
};


// Brute force :
// O(n^2)
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();

        vector<int> res(n,1);

        int maxOr=nums[n-1];

        for(int i=n-2;i>=0;i--){
           maxOr|=nums[i];

           int curOr=nums[i];
           int j=i+1;

           while(j<n && curOr!=maxOr){
            curOr|=nums[j];
            j++;
           }

           if(curOr==maxOr){
            res[i]=j-i;
           }
        }

        return res;
    }
};
