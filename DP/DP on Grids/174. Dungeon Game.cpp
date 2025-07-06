// BOTTOM UP:
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // state definition for bottom up approach'
        //  dp[i][j]=minHealth required to reach from (i,j) to (m,n)
        // dp[0][0]=minHealth required to reach from (0,0) to (m,n)

        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));


        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    dp[i][j]= dungeon[i][j]>=0?1:(1-dungeon[i][j]);
                }
                else{
                    int down=INT_MAX;
                    if(i+1<m){
                        down=dp[i+1][j];
                    }

                    int right=INT_MAX;
                    if(j+1<n){
                        right=dp[i][j+1];
                    }

                    int need=min(down,right);

                    if(dungeon[i][j]>=need){
                        need=1;
                    }
                    else{
                        need-=dungeon[i][j];
                    }

                    dp[i][j]=need;
                }
            }
        }

        return dp[0][0];
    }
};


// RECURSION + MEMO
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
