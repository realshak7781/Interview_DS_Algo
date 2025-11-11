
// Using Bottom Up Approach: 
using p=pair<int,int>;
class Solution {
private:
vector<p> count;
int size;


int solveTab(int m,int n){
    int dp[601][101][101];
    memset(dp,0,sizeof(dp));

    for(int i=size-1;i>=0;i--){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=n;k++){
                int curZeroCount=count[i].first;
                int curOneCount=count[i].second;

                int len=0;

                if(curZeroCount<=j && curOneCount<=k){
                    len=1+dp[i+1][j-curZeroCount][k-curOneCount];
                }

                len=max(len,dp[i+1][j][k]);

                dp[i][j][k]=len;
            }
        }
    }

    return dp[0][m][n];
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

        size=count.size();
        return solveTab(m,n);
    }
};


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
