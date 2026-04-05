// USING DYNAMIC PROGRAMMING AND MATHS DEVELOPED BY ME
// TIME : O(M*N)
// SPACE : O(M*N) + O(MAX(M,N))(RECURSION DEPTH)))
using ll = long long;
using p = pair<ll, ll>;
const int mod=1e9+7;
class Solution {
private:

    unordered_map<int,unordered_map<int,p>> dp;
    int m, n;
    p solve(int i, int j, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1) {
            if (grid[i][j] < 0) {
                return {-1e18, grid[i][j]};
            } else if (grid[i][j]>0) {
                return {grid[i][j], 1e18};
            }

            return {0,0};
        }

        if (i >= m || j >= n) {
            return {-1e18, 1e18};
        }

        if(dp[i].count(j)) return dp[i][j];

        p right = solve(i, j + 1, grid);
        p down = solve(i + 1, j, grid);

        p resPair = {-1e18, 1e18};
        ll minNeg = 1e18;
        minNeg = min(minNeg, right.second);
        minNeg = min(minNeg, down.second);

        ll maxPos = -1e18;
        maxPos = max(maxPos, right.first);
        maxPos = max(maxPos, down.first);

        if (grid[i][j] < 0) {
            if (minNeg != 1e18) {
                resPair.first = grid[i][j] * minNeg;
            }

            if (maxPos != -1e18) {
                resPair.second = grid[i][j] * maxPos;
            }
        } else if (grid[i][j] > 0) {
            if (maxPos != -1e18) {
                resPair.first = grid[i][j] * maxPos;
            }

            if (minNeg != 1e18) {
                resPair.second = grid[i][j] * minNeg;
            }
        } else {
            return {0, 0};
        }

        return dp[i][j]=resPair;
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        auto res = solve(0, 0, grid);

        if (res.first == -1e18)
            return -1;

        return res.first%mod;
    }
};
