class Solution {
private:
const int mod=1e9+7;
// unordered_map<int,int> dp;
// int solve(int idx,vector<int>&nums,int k){
//     if(idx>=nums.size()) return  1;

//     if(dp.count(idx)) return dp[idx];
//     int ways=0;
//     int maxi=INT_MIN;
//     int mini=INT_MAX;

//     for(int p=idx;p<nums.size();p++){
//         mini=min(mini,nums[p]);
//         maxi=max(maxi,nums[p]);

//         if((maxi-mini)<=k){
//             ways=(ways+solve(p+1,nums,k)%mod)%mod;
//         }
//         else{
//             break;
//         }
//     }
//     return dp[idx]=ways;
// }
public:
    int countPartitions(vector<int>& nums, int k) {  
       int n=nums.size();
       vector<int> dp(n+1,0);
       vector<int> pfSum(n+1,0);

       deque<int> maxDq,minDq;
       pfSum[0]=1;
       dp[0]=1;

       int i=0;
       int j=0;
       while(j<n){

        while(!maxDq.empty() && nums[j]>nums[maxDq.back()]) maxDq.pop_back();

        maxDq.push_back(j);

        while(!minDq.empty() && nums[j]<nums[minDq.back()]) minDq.pop_back();

        minDq.push_back(j);

        // check for a valid window
         while(i<=j && (nums[maxDq.front()]-nums[minDq.front()])>k){
            i++;

            if(!maxDq.empty() && maxDq.front()<i) maxDq.pop_front();
            if(!minDq.empty() && minDq.front()<i) minDq.pop_front();

         }

         dp[j+1]=(pfSum[j]-(i>0 ? pfSum[i-1] : 0) + mod)%mod;
         pfSum[j+1]=(pfSum[j]+dp[j+1])%mod;
         j++;
       }

       return dp[n];
    }
};
