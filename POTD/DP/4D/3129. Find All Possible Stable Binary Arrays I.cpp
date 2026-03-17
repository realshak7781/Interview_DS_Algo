

// using brute force approach : Memo + Recur
const int mod = 1e9 + 7;
class Solution {
private:
    int dp[201][201][201][2];
    int solve(int idx, int zero, int one, int zeroOrOne, int limit, int size) {
        if (idx >= size) {
            return 1;
        }

        if(dp[idx][zero][one][zeroOrOne]!=-1) return dp[idx][zero][one][zeroOrOne];
        long long resCnt = 0;
        // for the current idx i can put atmost limit 1s one 0s

        // try to place the 0s
        if (zeroOrOne == 0) {
            for (int zCount = 1; zCount <= limit; zCount++) {
                if (zCount > zero)
                    break;
                resCnt = (resCnt + solve(idx + zCount, zero - zCount, one,1,
                                         limit, size)) %
                         mod;
            }
        }

        if (zeroOrOne == 1) {
            for (int oneCount = 1; oneCount <= limit; oneCount++) {
                if (oneCount > one)
                    break;

                resCnt = (resCnt + solve(idx + oneCount, zero, one - oneCount,0,
                                         limit, size)) %
                         mod;
            }
        }

        return dp[idx][zero][one][zeroOrOne]=resCnt%mod;
    }

public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int size = zero + one;
        memset(dp, -1, sizeof(dp));
        int res1=solve(0, zero, one, 0, limit, size)%mod;
        int res2=solve(0,zero,one,1,limit,size)%mod;

        return (res1+res2)%mod;
    }
};
