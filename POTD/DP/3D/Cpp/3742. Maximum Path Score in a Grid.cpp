// USING BOTTOM UP DP:
// TIME : O(N*N*N)
// SPACE : O(N*N*N) no recursion space stack


class Solution {
private:
    bool check(int i, int j, vector<vector<int>>& grid, int k) {
        if (grid[i][j] == 1 || grid[i][j] == 2)
            return k >= 1;
        return grid[i][j] == 0 && k >= 0;
    }

    int solve(int i, int j, int k, vector<vector<int>>& grid, int m, int n) {

        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN)));

        for (int k_val = 0; k_val <= k; k_val++) {
            if (check(m - 1, n - 1, grid, k_val)) {
                memo[m - 1][n - 1][k_val] = grid[m - 1][n - 1];
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int k_val = 0; k_val <= k; k_val++) {

                    if(i==m-1 && j==n-1) continue;

                    int totalScore = INT_MIN;
                    // going right : idk
                    if (j + 1 < n && check(i, j, grid, k_val)) {
                        int new_k =
                            k_val - ((grid[i][j] == 1 || grid[i][j] == 2) ? 1 : 0);
                        int right_res = memo[i][j+1][new_k];
                        if (right_res != INT_MIN) {
                            totalScore =
                                max(totalScore, grid[i][j] + right_res);
                        }
                    }

                    // bcoming left, wdym
                    if (i + 1 < m && check(i, j, grid, k_val)) {
                        int new_k =
                            k_val - ((grid[i][j] == 1 || grid[i][j] == 2) ? 1 : 0);
                        int down_res = memo[i+1][j][new_k];
                        if (down_res != INT_MIN) {
                            totalScore = max(totalScore, grid[i][j] + down_res);
                        }
                    }

                    memo[i][j][k_val]=totalScore;
                }
            }
        }

        return memo[0][0][k];
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int res = solve(0, 0, k, grid, m, n);
        return res == INT_MIN ? -1 : res;
    }
};
