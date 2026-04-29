// bottom Up approach:
class Solution {
private:

    int bottomUp(string& word) {
        int n=word.size();
        int totalCols=6;


        // state definition : dp[idx][f1][f2]
        // min Cost to type letters of word from idx to n-1 when both fingers are free!
        // final ans : dp[0][26][26]
        int dp[302][27][27];
        memset(dp, 0, sizeof(dp));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int f1 = 26; f1 >=0; f1--) {
                for (int f2 = 26; f2>=0; f2--) {
                    int curCharVal = word[idx] - 'A';
                    int r = curCharVal / 6;
                    int c = curCharVal % 6;

                    int minCost = INT_MAX;

                    if (f1 == 26) {
                        minCost =
                            0 + dp[idx + 1][curCharVal][f2];
                    } else {
                        int prevCharVal = f1;
                        int prev_r = prevCharVal / totalCols;
                        int prev_c = prevCharVal % totalCols;

                        int curCost = abs(r - prev_r) + abs(c - prev_c);

                        minCost = curCost + dp[idx + 1][curCharVal][f2];
                    }

                    if (f2 == 26) {
                        minCost =
                            min(minCost, 0 + dp[idx + 1][f1][curCharVal]);
                    } else {
                        int prevCharVal = f2;
                        int prev_r = prevCharVal / totalCols;
                        int prev_c = prevCharVal % totalCols;

                        int curCost = abs(r - prev_r) + abs(c - prev_c);

                        minCost = min(minCost,
                                      curCost + dp[idx + 1][f1][curCharVal]);
                    }

                    dp[idx][f1][f2] = minCost;
                }
            }
        }

        return dp[0][26][26];
    }

public:
    int minimumDistance(string word) { return bottomUp(word); }
};


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
