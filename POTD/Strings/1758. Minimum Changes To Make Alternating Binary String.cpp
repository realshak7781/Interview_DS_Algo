// Iterative approach 

class Solution {
private:
int solve(string &s){
    int resOps=0;

    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
            resOps++;
            char org=s[i];
            s[i]=(org=='1' ? '0' : '1');
        }
    }

    return resOps;
}
public:
    int minOperations(string s) {
        string original=s;
        int ops=solve(s);

        s=original;
        char org=s[0];
        s[0]=(org=='1' ? '0' : '1');
        ops=min(ops,1+solve(s));
        s[0]=org;

        return ops;
    }
};

// APPROACH  1: USING RECURSION + MEMOIZATION
// TIME : O(N)
// SPACE : O(N)
class Solution {
private:
unordered_map<int,int> dp;
int solve(int idx,string &s){
    if(idx>=s.length()){
        return 0;
    }

    if(dp.count(idx)) return dp[idx];
    int resOps=INT_MAX;
    int prevIdx=idx-1;

    if(s[idx]==s[prevIdx]){
        // flip is necessary
        char org=s[idx];
        s[idx]=(org=='1' ? '0' : '1');
        resOps=min(resOps,1+solve(idx+1,s));
        s[idx]=org;
    }
    else{
        // dont flip
        resOps=min(resOps,solve(idx+1,s));
    }

    return dp[idx]=resOps;
}
public:
    int minOperations(string s) {
        
        int ops=solve(1,s);

        char original=s[0];
        s[0]=(original=='1' ? '0' : '1');
        dp.clear();
        ops=min(ops,1+solve(1,s));
        s[0]=original;

        return ops;
    }
};
