// APPPROACH 2 : USING A MUTLISET AND LINE SWEEP TECHNIQUE

using ll=long long;
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        multiset<pair<ll,ll>> ms;
        sort(begin(segments),end(segments));

        for(auto &seg:segments){
            ms.insert({seg[0],seg[2]});
            ms.insert({seg[1],-seg[2]});
        }
        vector<vector<ll>> res;
        auto it=ms.begin();
        auto firstPair=*it;

        ++it;
        ll sum=firstPair.second;
        ll prevStart=firstPair.first;

        while(it!=ms.end()){

            while(it != ms.end() && it->first == prevStart){
                sum+=it->second;
                ++it;
            }

            if(it==ms.end()) break;

            auto curPair=*it;
            if(sum>0){
                res.push_back({prevStart,curPair.first,sum});
            }
            prevStart=curPair.first;
            sum+=curPair.second;
            ++it;
        }
        return res;
    }
};

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
