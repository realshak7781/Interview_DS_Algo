class Solution {
private:
vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
vector<vector<int>> dp;
int dfs(int i,int j,vector<vector<int>>& matrix,int m,int n){

    if(dp[i][j]!=0) return dp[i][j];
    int maxLen=1;
    for(auto &it:dir){
        int dx=i+it[0];
        int dy=j+it[1];

        if(dx<0 || dx>=m || dy<0 || dy>=n || matrix[dx][dy]<=matrix[i][j]) continue;

        int len=1+dfs(dx,dy,matrix,m,n);
        maxLen=max(maxLen,len);
    }

    return dp[i][j]=maxLen;
}
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        int maxLen=1;
        dp.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxLen=max(maxLen,dfs(i,j,matrix,m,n));
            }
        }

        return maxLen;
    }
};
