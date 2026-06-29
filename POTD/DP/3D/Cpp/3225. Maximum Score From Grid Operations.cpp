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

// OPTIMAL APPROACH :
// TIME : O(N*N*N)
// SPACE : O(N*N*N)

using ll=long long;
class Solution {
private:
vector<vector<ll>> colPrefSum;

ll memo[102][102][2];
ll solve(int prev_h,int col,bool prev_taken,vector<vector<int>>& grid,int n){
    if(col>=n){
        return 0;
    }

    if(memo[prev_h+1][col][prev_taken]!=-1) return memo[prev_h+1][col][prev_taken];
    ll result=0;
    for(int height=-1;height<n;height++){
        int cur_h=height;

        ll prevScore=0,curScore=0;

        if(prev_h>cur_h){
            curScore=colPrefSum[prev_h+1][col+1]-colPrefSum[cur_h+1][col+1];
        }

        if(!prev_taken && cur_h>prev_h){
            prevScore=colPrefSum[cur_h+1][col]-colPrefSum[prev_h+1][col];
        }

        ll curTaken=curScore+prevScore+solve(cur_h,col+1,true,grid,n);
        ll curNotTaken=prevScore+solve(cur_h,col+1,false,grid,n);

        result=max({result,curTaken,curNotTaken});
    }

    return memo[prev_h+1][col][prev_taken]=result;
}
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n=grid.size();
        colPrefSum.resize(n+1,vector<ll>(n+1,0));

        memset(memo, -1, sizeof(memo));
        for(int col=1;col<=n;col++){
            for(int row=1;row<=n;row++){
                colPrefSum[row][col]=colPrefSum[row-1][col]+grid[row-1][col-1];
            }
        }
        return solve(-1,0,false,grid,n);
    }
};



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
