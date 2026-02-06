using ll=long long;
class Solution {
private :
unordered_map<int,unordered_map<int,ll>> dp;
const ll negInf=-1e16;
ll solve(int idx,int trend,vector<int>&nums,int n){
    if(idx==n){
        if(trend==3){
            return 0;
        }
        else{
            return negInf;
        }
    }

    if(dp[idx].count(trend)) return dp[idx][trend];

    ll maxSum=negInf;
    if(trend==0){
        maxSum=max(maxSum,solve(idx+1,0,nums,n));
    }

    if(trend==3){
        maxSum=nums[idx];
    }
    if(idx+1<n){
        int cur=nums[idx];
        int next=nums[idx+1];

        if(trend==0 && next>cur){
            maxSum=max(maxSum,nums[idx]+solve(idx+1,1,nums,n));
        }
        else if(trend==1){
            if(next>cur){
                maxSum=max(maxSum,nums[idx]+solve(idx+1,1,nums,n));
            }
            else if(next<cur){
                maxSum=max(maxSum,nums[idx]+solve(idx+1,2,nums,n));
            }
        }
        else if(trend==2){
            if(next<cur){
                maxSum=max(maxSum,nums[idx]+solve(idx+1,2,nums,n));
            }
            else if(next>cur){
                maxSum=max(maxSum,nums[idx]+solve(idx+1,3,nums,n));
            }
        }
        else if(trend==3){
           if(next>cur){
            // continuing trend
             maxSum=max(maxSum,nums[idx]+solve(idx+1,3,nums,n));
           }
        }
    }

    return dp[idx][trend]=maxSum;
}
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        return solve(0,0,nums,n);
    }
};
