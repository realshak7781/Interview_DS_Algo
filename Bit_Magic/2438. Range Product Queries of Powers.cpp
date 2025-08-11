const int mod=1e9+7;
using ll=long long;
class Solution {
private:
ll findPower(ll a,ll b,ll mod){
    if(b==0)  return 1;

    ll half=findPower(a,b/2,mod)%mod;
    ll result=(half*half)%mod;

    if(b&1){
        result=(result*a)%mod;
    }

    return result;
}
ll modInv(ll b,ll mod){
    return findPower(b,mod-2,mod)%mod;
}
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;

        for(int i=0;i<32;i++){
            if(n&(1<<i)){
                powers.push_back(1<<i);
            }
        }

        int m=powers.size();
        vector<ll> prefPow(m);
        prefPow[0]=(powers[0]%mod);

        for(int i=1;i<m;i++){
            prefPow[i]=(prefPow[i-1]*(powers[i]%mod))%mod;
        }


        vector<int> res;

        for(auto &it:queries){
            int l=it[0];
            int r=it[1];

            if(l==0){
                res.push_back(prefPow[r]%mod);
                continue;
            }

            // we will have to calculateb mod Inverse
            // int res=(pref[r]/pref[l-1])%mod
            // res=pref[r]*modInv(pref[l-1],mod);

            ll prod=((prefPow[r]%mod)*(modInv(prefPow[l-1],mod)%mod))%mod;

            res.push_back(prod);
        }

        return res;
    }
};
