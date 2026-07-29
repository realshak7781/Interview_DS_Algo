



// USING BRUTE FORCE APPROACH :
// TIME : O(QLOGQ + Q*Q)
// SPACE : O(Q)
class Solution {
private:
    set<int> obstacles;

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> res;

        for (auto& q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            } else {
                int x = q[1];
                int sz = q[2];

                if (x >= sz) {

                    if(obstacles.empty()){
                        res.push_back(true);
                        continue;
                    }

                    int prev = 0;
                    int maxGap = 0;
                    for (int cur : obstacles) {
                        if (cur > x)
                            break;
                        int gap = cur - prev;
                        maxGap = max(maxGap, gap);
                        prev = cur;
                    }

                    maxGap=max(maxGap,x-prev);
                    // last gap between obtsacles and current object
                    if (maxGap >= sz) {
                        res.push_back(true);
                    }else{
                        res.push_back(false);
                    }
                }
                else{
                    res.push_back(false);
                }
            }
        }
        return res;
    }
};
