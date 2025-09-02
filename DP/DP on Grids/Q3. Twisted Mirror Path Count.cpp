
class Solution {
private:
int n,m;
const int mod=1e9+7;
vector<vector<vector<int>>> dp;
int solve(int i,int j,vector<vector<int>>& grid,int dir){
    if(i<0 || i>=n || j<0 || j>=m) return 0;
    if(i==n-1 && j==m-1){
        return 1;
    }


    if(dp[i][j][dir]!=-1) return dp[i][j][dir];
    // check if its a  mirror
    int ways=0;
    if(grid[i][j]==1){
       if(dir==1){
            // coming from right
            // sen down
           ways=ways+ solve(i+1,j,grid,2);
        }
        else if(dir==2){
            // coming from up
            // send right
            ways=ways+solve(i,j+1,grid,1);
        }
    }
    else{
         ways=ways+solve(i,j+1,grid,1);
        ways=ways+solve(i+1,j,grid,2);
    }

    ways=ways%mod;

    return dp[i][j][dir]=ways;
}
public:
    int uniquePaths(vector<vector<int>>& grid) {
        // maintain i,j,dir to enter

        n=grid.size();
        m=grid[0].size();

       dp=vector<vector<vector<int>>> (n+1,vector<vector<int>>(m+1,vector<int>(3,-1)));
        return solve(0,0,grid,0);
    }
};
