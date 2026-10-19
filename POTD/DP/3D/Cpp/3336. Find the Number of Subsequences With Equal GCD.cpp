// TIME : O(N*MAX(NUMS)*MAX(NUMS)) 
// SPACE : O(N*MAX(NUMS)*MAX(NUMS))  + O(N){RECURSION STACK SPACE}

class Solution {
private:
const int mod=1e9+7;
int gcd(int a,int b){
    if(b==0) return a;

    return gcd(b,a%b);
}
int dp[201][201][201];
int solve(int idx,int gcd1,int gcd2,int n,vector<int>&nums){
    if(idx>=n){
        if(gcd1==0 && gcd2==0) return 0;
        return (gcd1==gcd2) ? 1 : 0;
    }

    if(dp[idx][gcd1][gcd2]!=-1) return dp[idx][gcd1][gcd2];

    // pick
    //    seq1
    int pickSeq1=solve(idx+1,gcd(gcd1,nums[idx]),gcd2,n,nums)%mod;
    //    seq2
    int pickSeq2=solve(idx+1,gcd1,gcd(gcd2,nums[idx]),n,nums)%mod;

    int notPick=solve(idx+1,gcd1,gcd2,n,nums)%mod;

    int res=((pickSeq1+pickSeq2)%mod + notPick)%mod;

    return dp[idx][gcd1][gcd2]=res;
}
public:
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int maxGCD=*max_element(nums.begin(), nums.end());

        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,nums);
    }
};
