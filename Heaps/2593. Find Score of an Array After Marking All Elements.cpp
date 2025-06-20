using ll = long long;


class Solution {
private:
ll approach2(vector<int>&nums){
    int n=nums.size();
    vector<bool> vis(n,false);
    vector<vector<ll>> arr;

    for(int i=0;i<n;i++){
        arr.push_back({nums[i],i});
    }

    sort(arr.begin(),arr.end());

    ll score=0;
    for(int i=0;i<n;i++){
        ll val=arr[i][0];
        ll idx=arr[i][1];

        if(vis[idx]) continue;
        score+=val;
        vis[idx]=true;

        if(idx+1<n){
            vis[idx+1]=true;
        }
        if((idx-1)>=0) vis[idx-1]=true;
    }

    return score;
} 

public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        multiset<pair<ll, ll>> ms;

        for (int i = 0; i < n; i++) {
            ms.insert({nums[i], i});
        }

        ll score = 0;
        while (!ms.empty()) {
            auto sm = ms.begin();
            ll val = sm->first; 
            ll idx = sm->second;

            ms.erase(sm);
            score += val;

            if (idx - 1 >= 0) {
                auto it = ms.find({nums[idx - 1], idx - 1});
                if (it != ms.end()) ms.erase(it);
            }

            if (idx + 1 < n) {
                auto it = ms.find({nums[idx + 1], idx + 1});
                if (it != ms.end()) ms.erase(it);
            }
        }

        // return score;

        return approach2(nums);
    }
};
