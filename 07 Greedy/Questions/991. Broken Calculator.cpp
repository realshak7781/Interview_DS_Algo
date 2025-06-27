


// BFS APPROACH : TLE
using ll=long long;
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        queue<pair<ll,ll>> q;
        q.push({startValue,0});

        unordered_set<ll> vis;
        while(!q.empty()){
            ll val=q.front().first;
            ll steps=q.front().second;
            q.pop();

            if(val==target) return steps;

            if(val-1>0 && !vis.count(val-1)){
                q.push({val-1,steps+1});
                vis.insert(val-1);
            }

            if((ll)2*val<=(ll)2*target && !vis.count(2*val)){
                 q.push({2*val,steps+1});
                 vis.insert(2*val);
            }
        }

        return -1;
    }
};
