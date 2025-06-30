class Solution {
private:
vector<bool> vis;
    int countWays(int i, int n) {
        if (i > n) {
            return 1;
        }

        int totalWays = 0;
        for (int val = 1; val <= n; val++) {
            if (!vis[val] && (val % i == 0 || i % val == 0)) {
                vis[val]=true;
                totalWays += countWays(i + 1, n);
                vis[val]=false;
            }
        }

        return totalWays;
    }

public:
    int countArrangement(int n) {
        vis=vector<bool>(n+1,false);
        return countWays(1, n);
    }
};
