class Solution {
private:
    vector<vector<int>> dirs = {
        {-1, -1}, // top-left
        {-1, 1},  // top-right
        {1, 1},   // bottom-right
        {1, -1}   // bottom-left
    };

    vector<vector<int>> grid;
    int n, m;
    int dp[501][501][4][2][3];


    int solve(int i, int j, int dir, bool canTurn, int expected) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return 0;
        if (grid[i][j] != expected)
            return 0;

        if(dp[i][j][dir][canTurn][expected]!=-1) return dp[i][j][dir][canTurn][expected];

        int nextExpected = (expected == 1 ? 2 : (expected == 2 ? 0 : 2));
        int curLen = 1;

        int ni = i + dirs[dir][0];
        int nj = j + dirs[dir][1];
        curLen = max(curLen, 1 + solve(ni, nj, dir, canTurn, nextExpected));

        if (canTurn) {
            int newDir = (dir + 1) % 4;
            int ti = i + dirs[newDir][0];
            int tj = j + dirs[newDir][1];
            curLen =
                max(curLen, 1 + solve(ti, tj, newDir, false, nextExpected));
        }

        return dp[i][j][dir][canTurn][expected]=curLen;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& g) {
        grid = g;
        n = grid.size();
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));
        // STORY POINTS:

        // FOR EACH 1 WE GET : TRY TO MOVE IN ALL FOUR DIRECTIONS

        // OUR STATES CAN BE :(ROW,COL,DIRECTION,CANTAKETURN)
        // WE WILL BE TRYING ALL POSSIBLE WAYS : SO WE ARE THINKING DP

        // OUR DIRECTION WILL BE NUMBERED FROM 0 TO 3 REPRESENTING FOUR
        // DIRECTIONS SO THAT WHEN WE TAKE A TURN , WE GET THE NEXT ROW, COL IDX
        // USING THE TURN ARRAY

        // TURN ARRAY : {{-1,1} , {+1,+1} , {+1,-1} , {-1,-1}};
        // WHERE IDXES PRESENT THE DIRECTIONS

        // AFTER TAKING A TURN OUR DIRECTION CHANGES : 0-->1
        // 1---> 2 AND  2--->3 AND 3--->0
        // BASICALLY (OLD_DIRECTION + 1)%4

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 1)
                    continue;
                for (int dir = 0; dir < 4; dir++) {
                    maxLen = max(maxLen, solve(i, j, dir, true, 1));
                }
            }
        }
        return maxLen;
    }
};
