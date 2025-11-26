
// Time Complexity : O(m*n*k)
// Space Complexity : O(m*n*k + (m+n))
class Solution {
private:
    int m, n;
    vector<vector<vector<int>>> dp;
    const int mod = 1e9 + 7;
    int solve(int i, int j, int rem, vector<vector<int>>& grid, int k) {
        if (i >= m || j >= n)
            return 0;

        int curRem = (rem + grid[i][j]) % k;

        if (i == m - 1 && j == n - 1) {
            return (curRem == 0) ? 1 : 0;
        }

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        int totalWays = 0;

        totalWays=(totalWays+solve(i+1,j,curRem,grid,k))%mod;
        totalWays=(totalWays+solve(i,j+1,curRem,grid,k))%mod;

        return dp[i][j][rem] = totalWays % mod;
    }

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0, 0, 0, grid, k);
    }
};
