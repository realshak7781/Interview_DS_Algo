// time : o(rows*cols*maxLen*min(rows,cols))
// space : O(1)


class Solution {
private:
    set<int> sums;
    void balanceSums(int val, int k) {
        sums.insert(val);

        if(sums.size()>k) sums.erase(sums.begin());
    }

    void doSum(int k, vector<vector<int>>& grid, int bX, int bY, int lX, int lY,
               int rX, int rY, int tX, int tY) {
        int sum = 0;

        // first side from boottom to leftSide
        int i = bX, j = bY;

        while (i >= lX && j >= lY) {
            sum += grid[i][j];
            i--;
            j--;
        }

        // summing the left to top
        i = lX, j = lY;

        while (i >=tX && j <= tY) {
            sum += grid[i][j];
            i--;
            j++;
        }

        // summing from right to top
        i = rX, j = rY;
        while (i >= tX && j >= tY) {
            sum += grid[i][j];
            i--;
            j--;
        }

        // summing from bottom to right
        i = bX, j = bY;

        while (i >= rX && j <= rY) {
            sum += grid[i][j];
            i--;
            j++;
        }

        // remove the extra additioms
        sum = sum - grid[bX][bY] - grid[lX][lY] - grid[tX][tY] - grid[rX][rY];

        balanceSums(sum, k);
    }

public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int maxPossibleLen = max(rows, cols);
        int k = 3;
        // lets maintain  set for storing three biggest distinct rhombus sums
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // for the current cell try all possible rhombus lens
                balanceSums(grid[i][j], k);
                for (int len = 1; len <= maxPossibleLen; len++) {
                    int x = i;
                    int y = j;
                    int leftX = x - len;
                    int leftY = y - len;
                    int rightX = x - len;
                    int rightY = y + len;
                    int topX = x - 2 * len;
                    int topY = y;

                    if (leftX < 0 || leftY < 0 || rightY >= cols || topX < 0)
                        break;

                    doSum(k, grid, x, y, leftX, leftY, rightX, rightY, topX,
                          topY);
                }
            }
        }

        vector<int> res;
        for (auto it = sums.rbegin(); it != sums.rend(); ++it) {
            res.push_back(*it);
        }

        return res;
    }
};
