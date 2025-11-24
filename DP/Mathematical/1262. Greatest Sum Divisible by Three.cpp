
// Approach 1: Using recursio + memoization
class Solution {
private:
unordered_map<int,unordered_map<int,int>> dp;
int solve(int idx,vector<int>&nums,int prevRem){
    if(idx>=nums.size()){
       if(prevRem==0) return 0;

       return INT_MIN;
    }

    if(dp[idx].count(prevRem)) return dp[idx][prevRem];

    int newRem=(nums[idx]+prevRem)%3;
    int pick=(nums[idx]+solve(idx+1,nums,newRem));
    int notPick=solve(idx+1,nums,prevRem);

    return dp[idx][prevRem]=max(pick,notPick);
}
public:
    int maxSumDivThree(vector<int>& nums) {
        return max(0,solve(0,nums,0));
    }
};

// Approach 2: Using Greedy Approach (credit to CodeStorywithMik for this approach)

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        int totalSum=accumulate(begin(nums),end(nums),0);

        if(totalSum%3==0) return totalSum;

        vector<int> rem1;
        vector<int> rem2;

        for(int val:nums){
            if(val%3==1){
                rem1.push_back(val);
            }
            else if(val%3==2){
                rem2.push_back(val);
            }
        }

        sort(begin(rem1),end(rem1));
        sort(begin(rem2),end(rem2));

        int maxSum=0;
        if(totalSum%3==1){
            // we need to find min no that gives 1 as remainder
            // find two smallest hving indicidual rem as 2 but overall rem as 1
            if(rem1.size()>=1)maxSum=max(maxSum,totalSum-rem1[0]);
            if(rem2.size()>=2)maxSum=max(maxSum,totalSum-(rem2[0]+rem2[1]));
        }
        else if(totalSum%3==2){
            if(rem2.size()>=1)maxSum=max(maxSum,totalSum-rem2[0]);
            if(rem1.size()>=2)maxSum=max(maxSum,totalSum-(rem1[0]+rem1[1]));
        }

        return maxSum;
    }
};
