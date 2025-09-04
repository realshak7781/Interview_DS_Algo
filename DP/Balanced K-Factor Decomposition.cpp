class Solution {
private:
    vector<int> res;
    int mini = INT_MAX;

    void solve(int i, int n, vector<int>& divs, vector<int> temp, int k) {
        if (k == 1) {
            temp.push_back(n);
            int maxim = INT_MIN;
            int minim = INT_MAX;

            // Calculate the maximum and minimum from temp
            for (int i = 0; i < temp.size(); i++) {
                maxim = max(maxim, temp[i]);
                minim = min(minim, temp[i]);
            }

            // Calculate the difference between the max and min
            int diff = maxim - minim;
            if (diff < mini) {
                mini = diff;
                res = temp;
            }

            return;
        }

        if (i >= divs.size()) return;

        // Pick strategy: If the divisor divides n, include it in the current sequence
        if (n % divs[i] == 0) {
            temp.push_back(divs[i]);
            solve(i, n / divs[i], divs, temp, k - 1);
            temp.pop_back(); // Backtrack
        }

        // Not pick strategy: Move to the next divisor
        solve(i + 1, n, divs, temp, k);
    }

public:
    vector<int> minDifference(int n, int k) {
        vector<int> divs;

        // Find all divisors of n
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                divs.push_back(i);
            }
        }

        vector<int> temp;
        solve(0, n, divs, temp, k);

        return res;
    }
};
