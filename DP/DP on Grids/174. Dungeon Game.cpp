class Solution {
private:
int m,n;  
int dp[201][201];  
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        memset(dp,-1,sizeof(dp));
        return recur(0,0,dungeon);
    }

    private:
    int recur(int i,int j,vector<vector<int>>& dungeon){
        if(i==m-1 && j==n-1){
            return dungeon[i][j]>=0?1:abs(dungeon[i][j])+1;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        // go down
        int up=INT_MAX;
        if(i+1<m){
            up=recur(i+1,j,dungeon);
        }
        //  go left
        int left=INT_MAX;
        if(j+1<n){
            left=recur(i,j+1,dungeon);
        }

        int res= max(1, min(up, left) - dungeon[i][j]);

        return dp[i][j]=res;
    }
};
