// Time : O(m*n)
// space : O(1)
class Solution {
private:
    bool isMagic(int sr, int er, int sc, int ec, vector<vector<int>>& grid) {
        vector<int> freq(16, 0); 
        for (int i = sr; i <= er; i++) {
            for (int j = sc; j <= ec; j++) {
                int val = grid[i][j];
                
                if (val < 1 || val > 9) return false;
                
                freq[val]++;
                if (freq[val] > 1) return false;
            }
        }

        for (int v = 1; v <= 9; v++) {
            if (freq[v] != 1) return false;
        }

        int targetSum = grid[sr][sc] + grid[sr][sc+1] + grid[sr][sc+2];

        for (int i = sr; i <= er; i++) {
            int currentSum = 0;
            for (int j = sc; j <= ec; j++) {
                currentSum += grid[i][j];
            }
            if (currentSum != targetSum) return false;
        }

        for (int j = sc; j <= ec; j++) {
            int currentSum = 0;
            for (int i = sr; i <= er; i++) { 
                currentSum += grid[i][j];
            }
            if (currentSum != targetSum) return false;
        }

        int diag1 = grid[sr][sc] + grid[sr+1][sc+1] + grid[sr+2][sc+2];
        int diag2 = grid[sr][sc+2] + grid[sr+1][sc+1] + grid[sr+2][sc];

        if (diag1 != targetSum || diag2 != targetSum) return false;

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m < 3 || n < 3) return 0;

        int count = 0;
        for (int r = 0; r <= m - 3; r++) {
            for (int c = 0; c <= n - 3; c++) {
                if (isMagic(r, r + 2, c, c + 2, grid)) {
                    count++;
                }
            }
        }

        return count; 
    }
};
