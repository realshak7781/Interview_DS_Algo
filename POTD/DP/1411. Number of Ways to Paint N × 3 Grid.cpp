class Solution {
private:
const int mod=1e9+7;
int dp[5001][4][4][4];
int solve(int idx,int prev1,int prev2,int prev3,int n){
    if(idx>=n) return 1;

    // try all combinations for the 3 columns for the current row or idx'
    // we will take Red:0 , yellow : 1 and green : 2

    if(dp[idx][prev1+1][prev2+1][prev3+1]!=-1) return dp[idx][prev1+1][prev2+1][prev3+1];
    int res=0;
    for(int c1=0;c1<=2;c1++){
        for(int c2=0;c2<=2;c2++){
            for(int c3=0;c3<=2;c3++){
                if(c1==prev1 || (c2==c1) || (c2==prev2) || (c3==c2) || (c3==prev3)) continue;

                res=(res+solve(idx+1,c1,c2,c3,n))%mod;
            }
        }
    }

    return dp[idx][prev1+1][prev2+1][prev3+1]=res;
}
public:
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,-1,-1,n);
    }
};
