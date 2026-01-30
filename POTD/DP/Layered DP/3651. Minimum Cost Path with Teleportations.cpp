
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
