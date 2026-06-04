// Time : O(log(side)*n*k*log(n))
// Space : O(2*n)
using ll = long long;
class Solution {
private:
    ll perimeter;
    bool check(int mid, vector<ll>& flattened, int k) {
        int n = flattened.size();
        for (int i = 0; i < n; i++) {
            ll startPos = flattened[i];
            int cnt = 1;

            ll lastPos = startPos;

            while (cnt < k) {
                ll target=lastPos+mid;
                auto it = lower_bound(flattened.begin() + i + 1,
                                      flattened.end(),target);

                if (it == flattened.end()) {
                    break;
                }

                cnt++;
                lastPos=*it;
            }

            if(cnt==k && (startPos+perimeter-lastPos)>=mid){
                return true;
            }
        }

        return false;
    }

public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {

        perimeter = 1LL*4 * side;
        vector<ll> flattened;

        for (auto& p : points) {
            int x = p[0];
            int y = p[1];

            ll dist;
            if (y == 0) {
                dist = x;
            } else if (x == side) {
                dist = side + y;
            } else if (y == side) {
                dist = 1LL*3 * side - x;
            } else if (x == 0) {
                dist = 1LL*4 * side - y;
            }

            flattened.push_back(dist);
            flattened.push_back(dist + perimeter);
        }

        sort(begin(flattened), end(flattened));

        ll low = 0, high = 2 * side;
        ll res;
        while (low <= high) {
            ll mid = low + (high - low) / 2;


            if (check(mid, flattened, k)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};
