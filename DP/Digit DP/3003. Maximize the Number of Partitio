// Using DIGIT DP:
//T.C : Without memoization - )(2^n * 26) , With Memoization - O(n*uniqueChars*2)
using ll=long long;
class Solution {
private:
string s;
int k;
unordered_map<ll,int> dp;
int solve(ll idx,ll currentChars,bool replace){

    ll key=((idx<<27)|(currentChars<<1)|replace);

    if(dp.count(key)) return dp[key];

    if(idx>=s.length()) return 0;

    int charIdx=s[idx]-'a';
    int updatedChars=(currentChars|(1<<charIdx));
    int charCnt= __builtin_popcount(updatedChars);

    int res=0;
    if(charCnt>k){
        res=1+solve(idx+1,1<<charIdx,replace);
    }
    else{
        res=solve(idx+1,updatedChars,replace);
    }

    if(replace){
        for(int newIdx=0;newIdx<26;newIdx++){
            int newSet= (currentChars | (1<<newIdx));
            int newCharCnt= __builtin_popcount(newSet);

            if(newCharCnt>k){
                res=max(res,1+solve(idx+1,1<<newIdx,false));
            }
            else{
                res=max(res,solve(idx+1,newSet,false));
            }
        }
    }

    return dp[key]=res;
}
public:
    int maxPartitionsAfterOperations(string s, int k) {
        this->s=s;
        this->k=k;
        return 1+solve(0,0,true);
    }
};

// Brute Force : o(n*25*n)
class Solution {
private:
    int doPartition(string s, int k) {

        int p = 1;
        unordered_set<char> st;
        for (int i = 0; i < s.length(); i++) {

            st.insert(s[i]);
            if (st.size() > k) {
                p++;
                st.clear();
                st.insert(s[i]);
            }
        }

        return p;
    }

    int bruteForce(string s, int k) {
        int n = s.length();

        int partition = 0;
        for (int i = 0; i < n; i++) {
            char org = s[i];

            for (char c = 'a'; c <= 'z'; c++) {
                s[i] = c;
                partition = max(partition, doPartition(s, k));
            }
            s[i] = org;
        }

        return partition;
    }

public:
    int maxPartitionsAfterOperations(string s, int k) {
        
    }
};
