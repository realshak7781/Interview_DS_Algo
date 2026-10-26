// TIME : O(Q*LOG(M))
// SPACE : O(M)

class Solution {
private:
    void buildTree(int node, int low, int high, vector<int>& seg,
                   vector<int>& pairSum) {
        if (low == high) {
            seg[node] = pairSum[low];
            return;
        }

        int mid = low + (high - low) / 2;

        buildTree(2 * node + 1, low, mid, seg, pairSum);
        buildTree(2 * node + 2, mid + 1, high, seg, pairSum);

        seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
    }

    int RMQ(int node, int low, int high, int ql, int qr, vector<int>& seg) {
        if (low > qr || high < ql)
            return INT_MIN;

        if (low >= ql && high <= qr) {
            return seg[node];
        }

        int mid = low + (high - low) / 2;

        int left = RMQ(2 * node + 1, low, mid, ql, qr, seg);
        int right = RMQ(2 * node + 2, mid + 1, high, ql, qr, seg);

        return max(left, right);
    }

public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {
        int n = s.length();
        int initialActiveSections = count(begin(s), end(s), '1');

        vector<int> blockStart;
        vector<int> blockEnd;

        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int j = i;

                while (j < n && s[j] == '0') {
                    j += 1;
                }
                blockStart.push_back(i);
                blockEnd.push_back(j - 1);
                i = j;
            } else {
                i++;
            }
        }

        if(blockStart.size()<2){
            return vector<int>(queries.size(), initialActiveSections);
        }
        vector<int> blockSize;
        for (int i = 0; i < blockStart.size(); i++) {
            int sizeofblock = blockEnd[i] - blockStart[i] + 1;
            blockSize.push_back(sizeofblock);
        }

        vector<int> pairSum;
        for (int i = 0; i < blockSize.size() - 1; i++) {
            pairSum.push_back(blockSize[i] + blockSize[i + 1]);
        }

        int m = pairSum.size();
        vector<int> seg(4 *m, 0);
        buildTree(0, 0, m - 1, seg, pairSum);

        vector<int> res;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int low = lower_bound(begin(blockEnd), end(blockEnd), l) -
                      begin(blockEnd);
            int high = upper_bound(begin(blockStart), end(blockStart), r) -
                       begin(blockStart) - 1;

            if (low > high) {
                res.push_back(initialActiveSections);
                continue;
            }
            int startingBlockSize = blockEnd[low] - max(l, blockStart[low]) + 1;
            int endingBlockSize = min(r, blockEnd[high]) - blockStart[high] + 1;

            int maxActiveSection = 0;
            if (low<high && (high - low)== 1) {
                maxActiveSection = startingBlockSize + endingBlockSize;
            } else if(low<high) {
                int pairSumFirst = startingBlockSize + blockSize[low + 1];
                int pairSumLast = endingBlockSize + blockSize[high - 1];

                int RMQMax = RMQ(0, 0, m - 1, low + 1, high - 2, seg);

                maxActiveSection = max({RMQMax, pairSumLast, pairSumFirst});
            }
            res.push_back(initialActiveSections + maxActiveSection);
        }

        return res;
    }
};
