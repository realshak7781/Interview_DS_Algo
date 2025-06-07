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

// T.C : O(N)
// S.C : O(1)


✅ 1. Logarithmic Functions

cout << log(10);      // Natural log of 10
cout << log10(100);   // log base 10 => 2
cout << log2(8);      // log base 2 => 3
cout << log1p(0.0001); // more accurate than log(1 + 0.0001)

✅ 2. Exponential Functions
🔹 Examples:

cout << exp(1);       // e^1 ≈ 2.718
cout << exp2(3);      // 2^3 = 8
cout << expm1(0.001); // more accurate than exp(0.001) - 1




all standard C++ <cmath> logarithmic and exponential functions are considered O(1) time complexity


