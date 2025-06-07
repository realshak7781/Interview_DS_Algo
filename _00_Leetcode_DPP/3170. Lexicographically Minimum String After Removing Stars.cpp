//T.C : O(nlogn)
// S.C : O(n)+O(n)



struct cmp{
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) const {
        if (a.first != b.first)
            return a.first > b.first; // min heap by char
        return a.second < b.second;   // max index if chars equal
    }
};
class Solution {
public:
    string clearStars(string s) {
        size_t pos = s.find('*');
        if (pos == string::npos)
            return s;

        int n = s.length();
        vector<bool> vis(n, true);

        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> minHeap;

        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                minHeap.push({s[i], i});
                continue;
            }

            // star mil gya
            if (!minHeap.empty()) {
                int indexToDel = minHeap.top().second;
                minHeap.pop();
                vis[indexToDel] = false;
            }
            vis[i] = false;
        }

        string res = "";

        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                res += s[i];
            }
        }

        return res;
    }
};
