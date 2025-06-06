#define ll long long
class Solution {
private:
ll radix1=26;
ll radix2=27;
ll mod1=1e9+7;
ll mod2=1e9+33;

pair<ll,ll> hashPair(string &s,int m){
    ll hash1=0,hash2=0,factor1=1,factor2=1;

    for(ll i=m-1;i>=0;i--){
        hash1+= ((s[i]-'a')*factor1)%mod1;
        factor1=(factor1*radix1)%mod1;
        hash2+= ((s[i]-'a')*factor2)%mod2;
        factor2=(factor2*radix2)%mod2;
    }

    return {hash1%mod1,hash2%mod2};
}
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        if(n<10) return {};
        int m=10;
        // window len
        unordered_set<string> freq;
        unordered_set<string> added;
        vector<string> res;
        ll mxwt1=1,mxwt2=1;
        for(ll i=0;i<m;i++){
            mxwt1=(mxwt1*radix1)%mod1;
            mxwt2=(mxwt2*radix2)%mod2;
        }
        pair<ll,ll> hashHay={0,0};
        for(ll i=0;i<=n-m;i++){
            if(i==0){
                hashHay=hashPair(s,m);
            }
            else{
               hashHay.first = ((hashHay.first*radix1)%mod1 - ((s[i-1]-'a')*mxwt1)%mod1 + (s[i+m-1]-'a')*1 + mod1)%mod1;
hashHay.second = ((hashHay.second*radix2)%mod2 - ((s[i-1]-'a')*mxwt2)%mod2 + (s[i+m-1]-'a')*1 + mod2)%mod2;
            }

            string key=to_string(hashHay.first)+"#"+to_string(hashHay.second);
            if(freq.count(key)){
              string sub = s.substr(i, m);
             if (!added.count(sub)) {
             res.push_back(sub);
             added.insert(sub);
            }
        }
        else{
            freq.insert(key);
        }
            
               
            
        }

        return res;
    }
};
