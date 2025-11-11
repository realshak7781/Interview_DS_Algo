
// Recursion + Memoization
using p=pair<int,int>;
class Solution {
private:
vector<p> count;
int dp[601][101][101];
int solve(int idx,int m,int n){
    if(idx>=count.size()){
        return 0;
    }

    if(dp[idx][m][n]!=-1) return dp[idx][m][n];
    int curZeroCount=count[idx].first;
    int curOneCount=count[idx].second;

    int len=0;
    if(curZeroCount<=m && curOneCount<=n){
        // pick strateggy
        len=1+solve(idx+1,m-curZeroCount,n-curOneCount);
    }

    // not pick strategy
    len=max(len,solve(idx+1,m,n));

    return dp[idx][m][n]=len;
}
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        for(string s:strs){
            int zeroes=0;
            for(char c:s){
                if(c=='0') zeroes++;
            }
            int ones=s.length()-zeroes;
            count.push_back({zeroes,ones});
        }

        memset(dp,-1,sizeof(dp));
        return solve(0,m,n);
    }
};
