
// Using Recursion and Memoization
class Solution {
private:
int m,n;
vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
const int mod=1e9+7;

int dp[51][51][51];
int solveRecur(int i,int j,int maxMove){
    if(i<0 || i>=m || j<0 || j>=n) return 1;

    if(maxMove==0) return 0;

    if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove];
    int total=0;

    for(auto d:dir){
        int nx=i+d[0];
        int ny=j+d[1];

        total=(total+solveRecur(nx,ny,maxMove-1)%mod)%mod;
    }

    return dp[i][j][maxMove]=total%mod;
}
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m=m;
        this->n=n;

        memset(dp,-1,sizeof(dp));
        return solveRecur(startRow,startColumn,maxMove);
    }
};
