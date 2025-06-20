
class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();

        unordered_map<char, pair<int, int>> directions = {
            {'N', {0, 1}},   // move up
            {'S', {0, -1}},  // move down
            {'E', {1, 0}},   // move right
            {'W', {-1, 0}}   // move left
        };

        int maxDist = 0;

        for (char ver : {'N', 'S'}) {
            for (char hor : {'E', 'W'}) {
                int curX = 0, curY = 0;
                int altK = k;

                for (int i = 0; i < n; i++) {
                    char pos = s[i];
                    if ((pos == 'E' || pos == 'W') && pos != hor && altK > 0) {
                        // Replace wrong horizontal with desired 'hor'
                        curX += directions[hor].first;
                        curY += directions[hor].second;
                        altK--;
                    } else if ((pos == 'N' || pos == 'S') && pos != ver && altK > 0) {
                        // Replace wrong vertical with desired 'ver'
                        curX += directions[ver].first;
                        curY += directions[ver].second;
                        altK--;
                    } else {
                        // Use the original move
                        curX += directions[pos].first;
                        curY += directions[pos].second;
                    }
                     int manhattanDist = abs(curX) + abs(curY);
                     maxDist = max(maxDist, manhattanDist);
                }

               
            }
        }

        return maxDist;
    }
};
