
// GREEDY APPROACH : O(N)
using ll=long long;
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();

        string res="";
        for(int i=n-1;i>=0;i--){

            if(s[i]=='0'){
                // adding zerroes to the front wont change value so increase he length
                res=s[i]+res;
                // adding cur char to the front cause for loop is reversed
            }
            else{
                // but add 1 only if it makes the value <=k;
                string org=res;
                res=s[i]+res;
                bitset<64> bt(res);

                if(bt.to_ulong()<=k)continue;

                res=org;
            }
        }

        return res.size();
    }
};




// RECURSION + MEMO : TLE
using ll=long long;
class Solution {
private:
int n;
unordered_map<ll,int> dp[1001];
int lis(int idx,ll num,string &s,int k){
    if(idx>=n){
        return 0;
    }

    if(dp[idx].count(num)) return dp[idx][num];

    int notPick=0+lis(idx+1,num,s,k);

    int bit=s[idx]-'0';
    ll curNo=(num<<1)|bit;

    int pick=0;
    if(curNo<=k){
        pick=1+lis(idx+1,curNo,s,k);
    }

    return dp[idx][num]=max(pick,notPick);
}    
public:
    int longestSubsequence(string s, int k) {
        n=s.length();
        return lis(0,0,s,k);
    }
};
