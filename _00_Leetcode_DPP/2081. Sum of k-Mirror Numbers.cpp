using ll = long long;
class Solution {
public:
    long long kMirror(int k, int n) {
        int L = 1;

        ll sum = 0;
        while (n > 0) {
            // generate the palindromes of the given length

            int half_len = (L + 1) / 2;
            ll minNo = pow(10, half_len - 1);
            ll maxNo = pow(10, half_len) - 1;

            for (ll num = minNo; num <= maxNo; num++) {
                string first_half = to_string(num);
                string second_half = first_half;

                reverse(second_half.begin(), second_half.end());
                string finalVal;

                if (L & 1)
                    finalVal = first_half + second_half.substr(1);
                else
                    finalVal = first_half + second_half;

                ll val = stoll(finalVal);

                if (checkKMirror(val, k)) {
                    sum += val;
                    n--;
                }

                if (n <= 0)
                    return sum;
            }
            L++;
        }

        return sum;
    }

private:
    bool checkKMirror(ll num, int k) {
        vector<ll> digits;

        while (num > 0) {
            digits.push_back(num % k);
            num /= k;
        }

        int l = 0, r = digits.size() - 1;

        while (l <= r) {
            if (digits[l] != digits[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
};
