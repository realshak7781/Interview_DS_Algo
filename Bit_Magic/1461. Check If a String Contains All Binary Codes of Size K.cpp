using ll=long long;
const int MOD = 1e9 + 7;
class Solution {
private:
int radix;
int findPower(ll a,ll b){
    if(b==0) return 1;
    ll res=1;
    while(b>0){
        if(b&1){
            res*=a;
        }
        a*=a;
        b>>=1;
    }

    return (int)res;
}
ll hashGen(string &s,int k,ll &fact){
    ll hash=0;
    for(int i=k-1;i>=0;i--){
        hash=(hash + (s[i] - '0') * fact % MOD) % MOD;
        fact=(fact*radix)%MOD;
    }

    return hash;
}
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<=k) return false;
        int n=s.length();
        radix=3;

        /*siding window approach
        // unordered_set<string> vis;
        // string res="";
        // for(int i=0;i<k;i++){
        //     res+=s[i];
        // }

        // vis.insert(res);
        // int i=k;

        // while(i<n){
        //     char cur=s[i];
        //     res=s.substr(i-k+1,k-1)+s[i];

        //     if(!vis.count(res)) vis.insert(res);
        //     i++;
        // }

        // int totalSubsets=findPower(2,k);

        // return vis.size()==totalSubsets;
        */

        // Hashing approach below
        unordered_set<ll> vis;
        ll fact=1;
        ll initialWindowHash=hashGen(s,k,fact);
        vis.insert(initialWindowHash);
        int i=k;
        while(i<n){
            char cur=s[i];
            initialWindowHash=(initialWindowHash*radix)%MOD;
            initialWindowHash=(initialWindowHash-(s[i-k]-'0')*fact+MOD)%MOD;
            initialWindowHash=(initialWindowHash+(s[i]-'0'))%MOD;

            if(!vis.count(initialWindowHash)) vis.insert(initialWindowHash);
            i++;
        }

        int totalSubsets=findPower(2,k);

        return vis.size()==totalSubsets;
    }
};

//  THE FIRST APPROACH IS A SLIDING WINDOW APPROACH USING A SET DATA STUCTURE
// THE SECOND OPTIMISATION INSTEAD OF STORING THE STRINS IN SET ,TRY TO STORE THE HASH VALUES (USE ROLLING HASHES TO GENERATE UNIQUE HASHES SO THAT THERE ARE NO SPURIOUS HITS)
