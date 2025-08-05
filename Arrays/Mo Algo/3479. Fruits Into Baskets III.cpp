
// Time : O(m* sqrt())
// space : O(m/sqrt(m))
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        //  we will use the concept of square root decomposition:

        int m = baskets.size();

        int sect_size = (int)sqrt(m);

        vector<int> sect_max;

        int cnt = 0;
        int maxi = 0;

        // building the sector max for each sectors :
        for (int i = 0; i < m; i++) {
            if (cnt == sect_size) {
                sect_max.push_back(maxi);
                maxi = baskets[i];
                cnt = 1;
            } else {
                maxi = max(maxi, baskets[i]);
                cnt++;
            }
        }

        sect_max.push_back(maxi);

        // now choosing the sector where current fruit can be placed
        int totalPlaced = 0;
        for (int i = 0; i < fruits.size(); i++) {

            int k = 0;
            bool placed = false;
            for (int j = 0; j < m; j += sect_size) {
                // choosing the sector
                if (fruits[i] > sect_max[k]) {
                    k++;
                    continue;
                }

                // finally foudn the sector
                // find the place inside the sector where it needs to be placed

                for (int r = j; r < min(j + sect_size, m); r++) {

                    if (baskets[r] >= fruits[i]) {
                        // found a place inside the sector
                        placed = true;
                        baskets[r] = 0;
                        break;
                    }
                }

                if (placed) {
                    sect_max[k]=0;
                    // find the neew max for the sector
                    for (int r = j; r < min(j + sect_size, m); r++) {
                        sect_max[k]=max(sect_max[k],baskets[r]);
                    }
                    break;
                }
            }

            if(placed){
                totalPlaced++;
            }
        }


        int notPlaced=fruits.size()-totalPlaced;

        return notPlaced;
    }
};
