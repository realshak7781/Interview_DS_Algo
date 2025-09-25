class Solution {
private:
int solveMem(int r,int c,int rows,vector<vector<int>>&triangle,vector<vector<int>>&dp){
    if(r==rows-1) return triangle[r][c];

    if(dp[r][c]!=-1) return dp[r][c];

    int downLeft=solveMem(r+1,c,rows,triangle,dp);
    int downRight=solveMem(r+1,c+1,rows,triangle,dp);

    return dp[r][c]= (triangle[r][c]+min(downLeft,downRight));
}

int solveTab(int rows,int maxCol,vector<vector<int>>&triangle){
    vector<vector<int>>dp(rows,vector<int>(maxCol,0));

    for(int i=0;i<maxCol;i++) dp[rows-1][i]=triangle[rows-1][i];

    for(int i=rows-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            int downLeft=dp[i+1][j];
            int downRight=dp[i+1][j+1];

            dp[i][j]= (triangle[i][j]+min(downLeft,downRight));
        }
    }

    return dp[0][0];
}

int spaceOpt(int rows,int maxCol,vector<vector<int>>&triangle){
    vector<int> frontRow(maxCol,0);
     for(int i=0;i<maxCol;i++) frontRow[i]=triangle[rows-1][i];

    for(int i=rows-2;i>=0;i--){
        vector<int> cur(maxCol ,0);
        for(int j=0;j<=i;j++,i){
            int downLeft=frontRow[j];
            int downRight=frontRow[j+1];

            cur[j]= (triangle[i][j]+min(downLeft,downRight));
        }
        frontRow=cur;
    }

    return frontRow[0];
}
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();
        int maxCol=triangle[rows-1].size();

        // vector<vector<int>> dp(rows,vector<int>(maxCol,-1));
        // return solveMem(0,0,rows,triangle,dp);

        return spaceOpt(rows,maxCol,triangle);
    }
};
