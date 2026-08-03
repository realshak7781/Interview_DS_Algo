using ll = long long;
class Solution {
private:
    ll dpCount[18][12][12][2];
    ll dpScore[18][12][12][2];

    pair<ll, ll> solve(int pos, int prevPrv, int prev, bool isLeadingZero,
                       bool isPartEqual, string& s) {
        if (pos >= s.length()) {
            return {1, 0};
        }

        int ppIdx = prevPrv + 1;
        int pIdx = prev + 1;
        int leadIdx = isLeadingZero ? 1 : 0;

        if (!isPartEqual && dpCount[pos][ppIdx][pIdx][leadIdx] != -1) {
            return {dpCount[pos][ppIdx][pIdx][leadIdx],
                    dpScore[pos][ppIdx][pIdx][leadIdx]};
        }
        ll totalNumbers = 0;
        ll totalWaveScore = 0;

        int digitLimit = isPartEqual ? (s[pos] - '0') : 9;

        for (int digit = 0; digit <= digitLimit; digit++) {
            bool isNewLeadingZero = isLeadingZero && (digit == 0);
            int newPrvPrv = prev;
            int newPrev = isNewLeadingZero ? -1 : digit;

            auto [remTotalCount, remTotalScore] =
                solve(pos + 1, newPrvPrv, newPrev, isNewLeadingZero,
                      isPartEqual && (digit == digitLimit), s);

            if (!isNewLeadingZero && prev >= 0 && prevPrv >= 0) {
                bool isPeak = (prev > digit && prev > prevPrv);
                bool isVall = (prev < digit && prev < prevPrv);

                if (isPeak || isVall) {
                    totalWaveScore += (1 * remTotalCount);
                }
            }

            totalNumbers += remTotalCount;
            totalWaveScore += remTotalScore;
        }

        if (!isPartEqual) {
            dpCount[pos][ppIdx][pIdx][leadIdx] = totalNumbers;
            dpScore[pos][ppIdx][pIdx][leadIdx] = totalWaveScore;
        }
        return {totalNumbers, totalWaveScore};
    }
    ll func(long long num) {
        if (num < 100) {
            return 0;
        }

        string s = to_string(num);
        memset(dpCount, -1, sizeof(dpCount));
        memset(dpScore, -1, sizeof(dpScore));
        auto [totalNumbers, totalWaveScore] = solve(0, -1, -1, true, true, s);

        return totalWaveScore;
    }

public:
    long long totalWaviness(long long num1, long long num2) {

        
        return func(num2) - func(num1 - 1);
    }
};
