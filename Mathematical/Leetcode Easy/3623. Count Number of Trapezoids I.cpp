const int mod=1e9+7;
using ll=long long;
class Solution {
private:
long long modPow(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    long long half = modPow(a, b / 2, mod);
    long long res = (half * half) % mod;
    if (b&1)
        res = (res * a) % mod;
    return res;
}
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,vector<int>> coord;

        for(auto &pt:points){
            int x=pt[0],y=pt[1];
            coord[y].push_back(x);
        }

        // each group based on y coord must have atleasst two points to forma line
        vector<ll> ways;
        for(auto &it:coord){
            if(it.second.size()>=2){
                int p=it.second.size();

                ll w=1LL*p*(p-1)/2;
                ways.push_back(w);
            }
        }

        if(ways.size()<=1) return 0;

        ll sum=0,sqSum=0;
        // this reduces the two for loops into a single loop but works only for pairwise products:
        for(ll &w:ways){
            sum=(sum+w)%mod;
            sqSum=(sqSum+w*w%mod)%mod;
        }

        ll inv2=modPow(2,mod-2,mod);
        // using fermat theorem
        ll totalWays=((((sum*sum)%mod -sqSum+mod)%mod)*inv2)%mod;

        return totalWays;
    }
};
