


// Brute force Approach : (exponential time complexity)
using ll=long long;
class Solution {
private:
unordered_map<ll,ll> freq;
ll solve(int idx,int prev,int lastPrev,vector<int>&v){
    if(idx>=v.size()){
        return 0;
    }


    ll pick=0;
    if(prev==-1){
        pick=freq[v[idx]]*v[idx]+solve(idx+1,idx,prev,v);
    }
    else if(lastPrev==-1 && v[idx]!=v[prev]+1 && v[idx]!=v[prev]+2){
        pick=freq[v[idx]]*v[idx]+solve(idx+1,idx,prev,v);
    }
    else if((v[idx]!=v[prev]+1 && v[idx]!=v[prev]+2) && (v[idx]!=v[lastPrev]+1 && v[idx]!=v[lastPrev]+2)){
        pick=freq[v[idx]]*v[idx]+solve(idx+1,idx,prev,v);
    }


    ll notPick=solve(idx+1,prev,lastPrev,v);

    return max(pick,notPick);
}
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n=power.size();

        for(ll val:power) freq[val]++;
        vector<int> v;
        for(auto it:freq) v.push_back(it.first);
        sort(begin(v),end(v));

        return solve(0,-1,-1,v);
    }
};
