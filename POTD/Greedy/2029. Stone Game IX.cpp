class Solution {
    bool simulate(multiset<int> ms, bool val1First) {
        int turn = 0;
        int rem_sum = 0;

        while (!ms.empty()) {
            int val1 = (1 - rem_sum + 3) % 3;
            int val2 = (2 - rem_sum + 3) % 3;

            int first = val1First ? val1 : val2;
            int second = val1First ? val2 : val1;

            auto it1 = ms.find(first);
            if (it1 != ms.end()) {
                ms.erase(it1);
                rem_sum = (rem_sum + first) % 3;
                turn += 1;
                continue;
            }

            auto it2 = ms.find(second);
            if (it2 != ms.end()) {
                ms.erase(it2);
                rem_sum = (rem_sum + second) % 3;
                turn += 1;
                continue;
            }

            if (turn & 1) {
                return true;
            } else {
                return false;
            }
        }

        return false;
    }

public:
    bool stoneGameIX(vector<int>& stones) {
        multiset<int> ms;
        for (int st : stones) {
            ms.insert(st % 3);
        }

        return simulate(ms, true) || simulate(ms, false);
    }
};
