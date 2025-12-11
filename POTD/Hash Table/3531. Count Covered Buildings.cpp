class Solution {
private:
    int bruteForce(vector<vector<int>>& buildings) {
        int res = 0;
        int size = buildings.size();
        for (int i = 0; i < size; i++) {
            int x = buildings[i][0];
            int y = buildings[i][1];

            bool left = false;
            bool right = false;
            bool up = false;
            bool down = false;

            for (int j = 0; j < size; j++) {
                if (j == i)
                    continue;
                int nx = buildings[j][0];
                int ny = buildings[j][1];

                if (ny == y && nx < x)
                    left = true;
                if (ny == y && nx > x)
                    right = true;
                if (nx == x && ny < y)
                    down = true;
                if (nx == x && ny > y)
                    up = true;
            }

            if (up && down && left && right)
                res++;
        }

        return res;
    }

public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> xMap;
        unordered_map<int, set<int>> yMap;

        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            xMap[x].insert(y);
            yMap[y].insert(x);
        }

        int res=0;
        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            auto xIter = xMap[x].find(y);
            bool isNotTopOrBottom = false;
            if (xIter != xMap[x].begin() && xIter != --xMap[x].end()) {
                isNotTopOrBottom = true;
            }

            auto yIter = yMap[y].find(x);
            bool isNotLeftOrRight = false;
            if (yIter != yMap[y].begin() && yIter != --yMap[y].end()) {
                isNotLeftOrRight = true;
            }

            if (isNotTopOrBottom && isNotLeftOrRight) {
                res++;
            }
        }

        return res;
    }
};
