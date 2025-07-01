class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        used = vector<bool>(n + 1, false);
        vector<int> temp = vector<int>(2 * n - 1, 0);
        found=false;
        genSeq(0, n, temp);

        return res;
    }

private:
    vector<bool> used;
    vector<int> res;
    bool found;

    // vector<int> findLexLarge(vector<int>& res, vector<int>& temp) {
    //     if (res.size() > temp.size())
    //         return res;
    //     else if (res.size() < temp.size())
    //         return temp;

    //     for (int i = 0; i < res.size(); i++) {
    //         if (res[i] > temp[i])
    //             return res;
    //         else if (res[i] < temp[i])
    //             return temp;
    //     }
    //     return res;
    // }

    void genSeq(int idx, int n, vector<int>& temp) {
        if(found) return;  /*  Early pruning *//
        if (idx >= (2 * n - 1)) {
            if (res.empty() || temp>res) {
                res = temp;
                found=true;
            }
            return;
        }

        if (temp[idx] != 0) {
            genSeq(idx + 1, n, temp);
            return;
        }

        for (int i = n; i >= 1; i--) {
            // starting from n helps in forming lex large early
            if (used[i])
                continue;

            if (i == 1) {
                temp[idx] = 1;
                used[1] = true;
                genSeq(idx + 1, n, temp);
                used[1] = false;
                temp[idx] = 0;
            } else {
                int j = idx + i;
                if (j < temp.size() && temp[j] == 0) {
                    temp[idx] = temp[j] = i;
                    used[i] = true;
                    genSeq(idx + 1, n, temp);
                    temp[idx] = temp[j] = 0;
                    used[i] = false;
                }
            }
        }
    }
};
