// Using Tabulation approach:
// time : O(n*m)
// apace :O(n*m)
class Solution {
private:

    int bot(string &s1, string &s2) {
        if (s1.length() < s2.length()) {
            swap(s1, s2);
            // always keep s1 longer than s2
        }

        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // state definition :dp[i][j]: be the answer for string s1 [i:] and
        // string s2[j:]
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int curAsciiSum = 0;
                // two values i,j are equal
                // we will take that value in our sub sequence and try to
                // maximize this ascii value sum
                if (s1[i] == s2[j]) {
                    curAsciiSum =
                        max(curAsciiSum, int(s1[i]) + dp[i + 1][j + 1]);
                }
                // they are not equal
                else {
                    curAsciiSum = max(curAsciiSum, dp[i + 1][j]);
                    curAsciiSum = max(curAsciiSum, dp[i][j + 1]);
                }

                dp[i][j] = curAsciiSum;
            }
        }

        return dp[0][0];
    }

public:
    int minimumDeleteSum(string s1, string s2) {

        int lenToKeep = bot(s1,s2);

        int len1 = 0;
        for (char c : s1) {
            len1 += int(c);
        }

        int len2 = 0;
        for (char c : s2) {
            len2 += int(c);
        }

        int len2Del = len1 + len2 - 2 * lenToKeep;

        return len2Del;
    }
};


// Using Recursion + Memoization
// time : O(n*m)
// apace : O(n+m) recursion call stack  + O(n*m)
class Solution {
private:
int dp[1001][1001];
int solve(int i,int j,string &s1,string &s2){
    if(i>=s1.length() || j>=s2.length()){
        return 0;
    }

    if(dp[i][j]!=-1) return dp[i][j];
    // base cases set h

    int curAsciiSum=0;
    // two values i,j are equal
    // we will take that value in our sub sequence and try to maximize this ascii value sum
    if(s1[i]==s2[j]){
        curAsciiSum=max(curAsciiSum,int(s1[i])+solve(i+1,j+1,s1,s2));
    }
    // they are not equal
    else{
       curAsciiSum=max(curAsciiSum,solve(i+1,j,s1,s2));
       curAsciiSum=max(curAsciiSum,solve(i,j+1,s1,s2));
    }

    return dp[i][j]=curAsciiSum;
}
public:
    int minimumDeleteSum(string s1, string s2) {
        if(s1.length()<s2.length()){
            swap(s1,s2);
            // always keep s1 longer than s2
        }

        memset(dp,-1,sizeof(dp));
        int lenToKeep=solve(0,0,s1,s2);

        int len1=0;
        for(char c:s1){
            len1+=int(c);
        }

        int len2=0;
        for(char c:s2){
            len2+=int(c);
        }

        int len2Del=len1+len2-2*lenToKeep;


        return len2Del;
    }
};
