

// Brute Force : o(n*25*n)
class Solution {
private:
    int doPartition(string s, int k) {

        int p = 1;
        unordered_set<char> st;
        for (int i = 0; i < s.length(); i++) {

            st.insert(s[i]);
            if (st.size() > k) {
                p++;
                st.clear();
                st.insert(s[i]);
            }
        }

        return p;
    }

    int bruteForce(string s, int k) {
        int n = s.length();

        int partition = 0;
        for (int i = 0; i < n; i++) {
            char org = s[i];

            for (char c = 'a'; c <= 'z'; c++) {
                s[i] = c;
                partition = max(partition, doPartition(s, k));
            }
            s[i] = org;
        }

        return partition;
    }

public:
    int maxPartitionsAfterOperations(string s, int k) {
        
    }
};
