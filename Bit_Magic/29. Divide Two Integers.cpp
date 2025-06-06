// T.C  : O(LOG(N));
// N = dividend / divisor
// S.C   : o(32);

using ll = long long;
class Solution {
private:
    vector<ll> powers;
    void preCompute() {
        powers[0] = 1;
        for (int i = 1; i <= 32; ++i) {
            powers[i] = powers[i - 1] * 2;
        }
    }

    ll getHighestPowerToSub(ll dvd, ll dvs) {

        ll res = 1;
        for (int i = 0; i <= 32; i++) {
            ll mul = dvs * powers[i];

            if (mul > dvd) {
                res = powers[i - 1];
                break;
            }
        }
        return res;
    }

public:
    int divide(int dvd, int dvs) {
        // precompute powers of 2 till 32
        powers.resize(33);
        preCompute();

        bool firstSign=false;
        bool secondSign=false;

        if(dvd>0) firstSign=true;
        if(dvs>0) secondSign=true;

        bool sign = !(firstSign^secondSign);

        ll dividend = abs((ll)dvd);
        ll divisor = abs((ll)dvs);

        ll sum = 0;

        while (dividend >= divisor) {
            ll fp = getHighestPowerToSub(dividend, divisor);
            sum += fp;
            dividend -= (divisor)*fp;
        }

        if (sign) {
            // positive
            if (sum >= INT_MAX)
                return INT_MAX;
        } else {
            sum = -1ll * sum;

            if (sum <= INT_MIN)
                return INT_MIN;
        }

        return (int)sum;
    }
};
