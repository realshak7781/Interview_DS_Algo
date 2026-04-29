
// TIME : O(N*26*26)
// SPACE : O(N)
class Solution {
private:
    int dp[302][27][27];
    int solve(int idx, int f1, int f2, string& word, int totalCols) {
        if (idx >= word.length()) {
            return 0;
        }

        if(dp[idx][f1+1][f2+1]!=-1) return dp[idx][f1+1][f2+1];

        int curCharVal = word[idx] - 'A';
        int r = curCharVal / 6;
        int c = curCharVal % 6;

        int minCost = INT_MAX;

        if (f1 == -1) {
            minCost = 0 + solve(idx + 1, curCharVal, f2, word,totalCols);
        } else {
            int prevCharVal = f1;
            int prev_r = prevCharVal / totalCols;
            int prev_c = prevCharVal % totalCols;

            int curCost = abs(r - prev_r) + abs(c - prev_c);

            minCost = curCost + solve(idx + 1, curCharVal, f2, word,totalCols);
        }

        if (f2 == -1) {
            minCost = min(minCost,0 + solve(idx + 1, f1, curCharVal, word,totalCols));
        } else {
            int prevCharVal = f2;
            int prev_r = prevCharVal / totalCols;
            int prev_c = prevCharVal % totalCols;

            int curCost = abs(r - prev_r) + abs(c - prev_c);

            minCost = min(minCost,curCost + solve(idx + 1, f1, curCharVal, word,totalCols));
        }


        return dp[idx][f1+1][f2+1]=minCost;
    }




public:
    int minimumDistance(string word) { 

        memset(dp, -1, sizeof(dp));
        return solve(0, -1, -1, word, 6); 
    }
};
