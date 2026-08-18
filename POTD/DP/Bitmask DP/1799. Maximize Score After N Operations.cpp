

// TIME : O(N^3 * 4^N)
// SPACE : O(OPS) + O(N*4^N)
class Solution {
private:
int gcd(int a,int b){
    if(b==0) return a;

    return gcd(b,a%b);
}

unordered_map<int,unordered_map<int,int>> dp;

int solve(int ops,int mask,int n,vector<int>&nums){
    if(ops>=n){
        return 0;
    }

    if(dp[ops].count(mask)) return dp[ops][mask];
    int maxScore=0;
    
    for(int i=0;i<nums.size();i++){
        if(mask & (1<<i)) continue;
        for(int j=i+1;j<nums.size();j++){
            if(mask & (1<<j))continue;

            int cur_score=(ops+1)*gcd(nums[i],nums[j]);

            int next_mask=mask | (1<<i);
            next_mask=next_mask | (1<<j);

            maxScore=max(maxScore,cur_score+
                                 solve(ops+1,next_mask,n,nums)
            );
        }
    }

    return dp[ops][mask]=maxScore;
}
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size()/2;
        return solve(0,0,n,nums);
    }
};
