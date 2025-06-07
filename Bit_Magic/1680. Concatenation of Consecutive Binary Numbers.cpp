const int mod = 1e9 + 7;
using ll=long long;
class Solution {
public:
    int concatenatedBinary(int n) {
        if (n == 1)
            return 1;

        ll res=1;
        for (int i = 2; i <= n; i++) {
            ll num_of_dig = log2(i) + 1;

            res=((res*(1<<num_of_dig))%mod+i)%mod;

        }
        return res;
    }
};

// T.C : O(NLOGN)
// S.C : O(1)
