const int MOD = 1e9 + 7;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int dp[2001][2001][3];
        for (int preVal = l; preVal <= r; preVal++) {
            dp[n][preVal][0] = 1;
            dp[n][preVal][1] = 1;
            dp[n][preVal][2] = 1;
        }
        vector<vector<int>> pref1(n + 1, vector<int>(r + 1, 0));
        // for direction one pfSum[idx+1][]
        vector<vector<int>> pref2(n + 1, vector<int>(r + 1, 0));
        // for direction two

        for (int v = l; v <= r; ++v) {
            pref1[n][v] = (pref1[n][v - 1] + dp[n][v][1]) % MOD;
            pref2[n][v] = (pref2[n][v - 1] + dp[n][v][2]) % MOD;
        }

        for (int idx = n - 1; idx >= 1; idx--) {
            for (int preVal = l; preVal <= r; preVal++) {
                for (int dir = 0; dir <= 2; dir++) {
                    long long totalWays = 0;

                    if (idx == 1) {
                        // need sum from range [preVal+1...r]
                        long long wayUp =
                            (preVal < r)
                                ? (pref1[2][r] - pref1[2][preVal] + MOD) % MOD
                                : 0;
                        // need sum from [l...preVal-1]
                        long long wayDown = (preVal > l)
                                                ? (pref2[2][preVal - 1] -
                                                   pref2[2][l - 1] + MOD) %
                                                      MOD
                                                : 0;

                        totalWays = (wayUp + wayDown) % MOD;
                    } else if (idx >= 2) {
                        long long ways = 0;
                        if (dir == 1) {
                            ways = (pref2[idx + 1][preVal - 1] -
                                    pref2[idx + 1][l - 1] + MOD) %
                                   MOD;
                        } else if (dir == 2) {
                            ways = (pref1[idx + 1][r] - pref1[idx + 1][preVal] +
                                    MOD) %
                                   MOD;
                        }
                        totalWays = (totalWays + ways) % MOD;
                    }

                    dp[idx][preVal][dir] = totalWays;
                    if (dir == 1) {
                        pref1[idx][preVal] =
                            (pref1[idx][preVal - 1] + totalWays) % MOD;
                    } else if (dir == 2) {
                        pref2[idx][preVal] =
                            (pref2[idx][preVal - 1] + totalWays) % MOD;
                    }
                }
            }
        }

        // process the 0th idx here
        long long ans = 0;
        for (int cur = l; cur <= r; cur++) {
            ans = (ans + dp[1][cur][0]) % MOD;
        }
        dp[0][l][0]=ans;
        // state definition state[idx][]

        return dp[0][l][0];
    }
};
