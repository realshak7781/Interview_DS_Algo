using ll = long long;
class Solution {
bool isPrime(ll num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (ll i = 5; i * i <= num; i ++) {
        if (num % i == 0 )
            return false;
    }

    return true;
}

public:
    long long sumOfLargestPrimes(string s) {
        int size = s.length();
        int k = 3;
        priority_queue<ll, vector<ll>, greater<ll>> minHeap;
        unordered_set<ll> vis;
        for (int i = 0; i < size; i++) {
            string n = "";
            for (int j = i; j < size; j++) {
                n += s[j];
                if (n.length() >=1 && n[0] == '0') break;
                ll num = stoll(n);

                if (!vis.count(num) && isPrime(num)) {
                    if(minHeap.size()<k){
                        minHeap.push(num);
                        vis.insert(num);
                    }
                    else if(minHeap.top()<num){
                        vis.erase(minHeap.top());
                        minHeap.pop();
                        minHeap.push(num);
                        vis.insert(num);
                    }
                }
            }
        }

        ll res = 0;

        while (!minHeap.empty()) {
            res += minHeap.top();
            minHeap.pop();
        }

        return res;
    }
};
