

// USING APPROACH 1 : BRUTE FORCE 
// TIME : O(N*N)
// SPACE : O(N)
using ll=long long;
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n=segments.size();
        set<ll> pointsSet;

        for(auto &seg:segments){
            pointsSet.insert(seg[0]);
            pointsSet.insert(seg[1]);
        }

        vector<ll> points;
        for(auto p:pointsSet) points.push_back(p);

        vector<vector<ll>> res;
        for(int i=0;i<points.size()-1;i++){
            ll start=points[i];
            ll end=points[i+1];

            ll sum=0;
            for(auto &seg:segments){
                ll u=seg[0];
                ll v=seg[1];
                ll col=seg[2];

                if(u>=end || v<=start) continue;

                sum+=col;
            }

            if(sum>0){
                res.push_back({start,end,sum});
            }
        }

        return res;
    }
};
