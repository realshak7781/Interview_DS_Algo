// USING LAYERED DP AND DECOUPLING 
class Solution {
private:
    int solve(vector<vector<int>> grid, int m, int n, int k) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m - 1][n - 1] = 0;

        int maxVal=-1e9;
        for (auto& row : grid) {
            for (int &val:row){
                maxVal=max(maxVal,val);
            }
        }

        vector<int> teleportations(maxVal+1,INT_MAX);

        for(int tPort=0;tPort<=k;tPort++){
            for(int i=m-1;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    if(i==m-1 && j==n-1) continue;

                    // moving right
                    if(j+1<n){
                        dp[i][j]=min(dp[i][j],grid[i][j+1]+dp[i][j+1]);
                    }

                    // moving down
                    if(i+1<m){
                        dp[i][j]=min(dp[i][j],grid[i+1][j]+dp[i+1][j]);
                    }

                    // trying to teleport
                    if(tPort>0){
                        dp[i][j]=min(dp[i][j],teleportations[grid[i][j]]);
                    }
                }
            }


            // updating the teleportations array
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    teleportations[grid[i][j]]=min(teleportations[grid[i][j]],dp[i][j]);
                }
            }

            // also updating  through prefix mins
            for(int i=1;i<=maxVal;i++){
                teleportations[i]=min(teleportations[i],teleportations[i-1]);
            }
        }

        return dp[0][0];
    }

public:
    int minCost(vector<vector<int>>& grid, int k) {
        // the rrecursive call returns me (0,0) to (m-1,n-1) min total cost ?
        int m = grid.size();
        int n = grid[0].size();

        return solve(grid, m, n, k);
    }
};


// USING BOTTOM UP APPROACH : TLE
class Solution {
private:

    int solve(vector<vector<int>> grid, int m, int n,int k) {
        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));

        for (int tPort = 0; tPort <= k; tPort++) {
            dp[m - 1][n - 1][tPort] = 0;
        }

        // state definition:
        // min Cost to reach from any (i,j) to (m-1,n-1) using 0 teleports

        for (int tPort = k; tPort >= 0; tPort--) {
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1)
                        continue;

                    int minCost = 1e9;
                    // normal move
                    // right and down
                    if (j + 1 < n) {
                        minCost =
                            min(minCost, grid[i][j + 1] + dp[i][j+1][tPort]);
                    }
                    if (i + 1 < m) {
                        minCost =
                            min(minCost, grid[i + 1][j] + dp[i+1][j][tPort]);
                    }

                    // trying to telepor

                    if (tPort < k) {
                        for (int x = 0; x < m; x++) {
                            for (int y = 0; y < n; y++) {
                                // (i,j) ---> (x,y) : grid[x][y]<=grid[i][j
                                if (x == i && y == j)
                                    continue;

                                if (grid[x][y] <= grid[i][j]) {
                                    minCost =
                                        min(minCost, dp[x][y][tPort+1]);
                                }
                            }
                        }
                    }
                  dp[i][j][tPort] = minCost;
                }
            }
        }


        return dp[0][0][0];
    }

public:
    int minCost(vector<vector<int>>& grid, int k) {
        // the rrecursive call returns me (0,0) to (m-1,n-1) min total cost ?
        int m = grid.size();
        int n = grid[0].size();

        return solve(grid,m,n,k);
    }
};


// Using Recursion + Memoization : TLE
class Solution {
private:
    vector<vector<vector<int>>> dp;
    int solve(int i, int j, int tPort, int k, vector<vector<int>>& grid, int m,
              int n) {
        if (i == m - 1 && j == n - 1) {
            return 0;
        }

        if (dp[i][j][tPort] != -1)
            return dp[i][j][tPort];

        int minCost = 1e9;
        // normal move
        // right and down
        if (j + 1 < n) {
            minCost = min(minCost,
                          grid[i][j+1] + solve(i, j + 1, tPort, k, grid, m, n));
        }
        if (i + 1 < m) {
            minCost = min(minCost,
                          grid[i+1][j] + solve(i + 1, j, tPort, k, grid, m, n));
        }

        // trying to telepor

        if (tPort<k) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    // (i,j) ---> (x,y) : grid[x][y]<=grid[i][j
                    if(x==i && y==j) continue;

                    if (grid[x][y] <= grid[i][j]) {
                        minCost = min(
                            minCost, solve(x,y,tPort + 1, k, grid, m, n));
                    }
                }
            }
        }
        return dp[i][j][tPort] = minCost;
    }

public:
    int minCost(vector<vector<int>>& grid, int k) {
        // the rrecursive call returns me (0,0) to (m-1,n-1) min total cost ?
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return solve(0, 0, 0, k, grid, m, n);
    }
};
