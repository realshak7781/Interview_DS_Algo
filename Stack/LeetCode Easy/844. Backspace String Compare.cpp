// Usibg Rolling Hash Approach to achieve O(1) space
using ll=long long;
class Solution {
private:
ll computeHash(const string &s){
    ll hash=0;
    ll w=1;
    ll p=31;
    const ll mod=1e9+7;
    int skip=0;

    for(int i=s.length()-1;i>=0;i--){
        char c=s[i];
        if(c=='#'){
            skip++;
        }
        else{
            if(skip>0){
                skip--;
            }
            else{
                hash=(hash + (c-'a'+1)*w)%mod;
                w=(w*p)%mod;
            }
        }
    }

    return hash;
}
public:
    bool backspaceCompare(string s, string t) {
        return computeHash(s) == computeHash(t);
    }
};

// Approach 1 : Using O(n) space
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        for(char c:s){
            if(c=='#'){
                if(!st1.empty())st1.pop();
            }
            else{
                st1.push(c);
            }
        }

        string remS="";
        while(!st1.empty()){
            remS+=st1.top();
            st1.pop();
        }
        reverse(remS.begin(),remS.end());


        for(char c:t){
            if(c=='#' ){
                 if(!st1.empty())st1.pop();
            }
            else{
                st1.push(c);
            }
        }

        string remT="";
        while(!st1.empty()){
            remT+=st1.top();
            st1.pop();
        }
        reverse(remT.begin(),remT.end());

        return remT==remS;
    }
};
