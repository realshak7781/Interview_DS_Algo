#include <bits/stdc++.h>
using namespace std;

class BIT {
private:
    vector<int> bit;
    int n;
    
public:
    BIT(vector<int>& arr) {
        n = arr.size();
        bit.resize(n + 1, 0);  // BIT uses 1-based indexing
        build(arr);
    }

    void update(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += (i & -i);  // Move to next index
        }
    }

    int sum(int i) {
        int ans = 0;
        while (i > 0) {
            ans += bit[i];  
            i -= (i & -i);  // Move to parent index
        }
        return ans;
    }

    int range_sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void build(vector<int>& arr) {
        for (int i = 0; i < n; i++) {
            update(i + 1, arr[i]);  // Convert 0-based to 1-based
        }
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};  // Example array
    BIT fenwick(arr);

    cout << "Prefix sum up to index 3: " << fenwick.sum(3) << "\n";  // Sum from 1 to 3
    cout << "Range sum (2 to 4): " << fenwick.range_sum(2, 4) << "\n"; // Sum from 2 to 4
}
