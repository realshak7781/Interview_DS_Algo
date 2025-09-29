const int inf=INT_MAX;
using ll=long long;
class Solution {
private:
int dp[51][51];
int solve(int i,int j,vector<int>&values){
    if(j-i<2) return 0;

    ll result=inf;

    if(dp[i][j]!=-1)  return dp[i][j];
    for(int k=i+1;k<j;k++){
        ll curWt=values[i]*values[k]*values[j];
        ll wt=solve(i,k,values)+curWt+solve(k,j,values);

        result=min(result,wt);
    }

    return dp[i][j]=result;
}
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();

        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,values);
    }
};
