


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
