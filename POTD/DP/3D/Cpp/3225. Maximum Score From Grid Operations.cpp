// TIME : O(N^N  * N)
// SPACE : O(N*N + N + N)

// USING OPTIMIZED BRUTE FORCE APPROACH :
using ll = long long;
class Solution {
private:
    vector<vector<ll>> colCumSum;
    ll solve(int col, vector<int>& heights, vector<vector<int>>& grid, int n) {

        if (col >= n) {
            ll score = getScore(heights, grid, n);

            return score;
        }

        ll result = 0;
        for (int h = -1; h < n; h++) {
            heights[col] = h;

            result = max(result, solve(col + 1, heights, grid, n));
        }
        return result;
    }

    ll getScore(vector<int>& heights, vector<vector<int>>& grid, int n) {

        ll score = 0;

        for (int j = 0; j < n; j++) {
            int c = j;
            int left_h = (c > 0) ? heights[c - 1] : -1;
            int right_h = (c < n - 1) ? heights[c + 1] : -1;
            int y = max({left_h, right_h, -1});
            int x = heights[j];
            if (y <= x)
                continue;

            score = score + (colCumSum[y + 1][c + 1] - colCumSum[x + 1][c + 1]);
        }
        return score;
    }

public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        colCumSum.resize(n + 2, vector<ll>(n + 2, 0));

        for (int col = 1; col <= n; col++) {
            for (int row = 1; row <= n; row++) {
                colCumSum[row][col] =
                    colCumSum[row - 1][col] + grid[row - 1][col - 1];
            }
        }

        vector<int> heights(n, -1);
        return solve(0, heights, grid, n);
    }
};
