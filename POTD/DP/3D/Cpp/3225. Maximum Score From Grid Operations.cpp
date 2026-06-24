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
