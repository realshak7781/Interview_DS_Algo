
//Brute Force Approach O(n^2)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();

        int count=0;

        for(int i=0;i<=(n-3);i++){
            int diff=nums[i+1]-nums[i];

            for(int j=i+2;j<n;j++){
                int cur=nums[j];

                if((nums[j]-nums[j-1])!=diff){
                    break;
                }

                count++;
            }
        }

        return count;
    }
};
