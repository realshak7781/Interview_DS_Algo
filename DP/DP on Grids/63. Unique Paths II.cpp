class Solution {
private:
vector<vector<int>> dp;
int solve(int i,int j,int m,int n,vector<vector<int>>& obstacleGrid){
    if(obstacleGrid[i][j]==1) return 0;
    if(i==m-1 && j==n-1){
        return 1;
    }

    if(dp[i][j]!=-1) return dp[i][j];
    int down=0;
    if(i+1<m){
        down=solve(i+1,j,m,n,obstacleGrid);
    }

    int right=0;
    if(j+1<n){
        right=solve(i,j+1,m,n,obstacleGrid);
    }

    return dp[i][j]=down+right;
}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        dp.resize(m,vector<int>(n,-1));
        return solve(0,0,m,n,obstacleGrid);
    }
};
