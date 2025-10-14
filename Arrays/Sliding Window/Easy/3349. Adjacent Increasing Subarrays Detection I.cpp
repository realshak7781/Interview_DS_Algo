
// APPROACH 1:
// Brute Force : O(n^2) : ACCEPTED
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        for(int i=0;i<=(n-2*k);i++){
            int j=i+1;

            while((j-i)<k){
                // for first subarray
                if(nums[j]<=nums[j-1]) break;
                j++;
            }

            if((j-i)<k) continue;

            // second subarray
            // j holds the index of the starting of the next subarray
            int m=j+1;
            while((m-j)<k){
                if(nums[m]<=nums[m-1]) break;
                m++;
            }

            if(m-j < k) continue;

            return true;
        }

        return false;
    }
};
