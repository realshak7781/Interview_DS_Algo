// brute force : O(n^2) TLE : 102 / 112 testcases passed
class Solution {
private:
int kadane(int start,vector<int>&nums){
    int n=nums.size();
    int i=start;

    int curSum=0;
    int maxSum=INT_MIN;
    int count=0;
    while(count<n){
        curSum+=nums[i];
        maxSum=max(curSum,maxSum);

        if(curSum<0) curSum=0;
        i=(i+1)%n;
        count++;
    }

    return maxSum;
}  
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            // take the current index as starting point
            maxSum=max(maxSum,kadane(i,nums));
        }

        return maxSum;
    }
};
