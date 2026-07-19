// using dynamic programming approach

// TIME : o(M*N)
// SPACE : O(M*N) + o(MIN(M,N))
class Solution {
private:
vector<vector<int>> dp;
int getLen(int num1,int num2){
    string s1=to_string(num1);
    string s2=to_string(num2);
    int m=s1.length();
    int n=s2.length();
    int i=0;
    while(i<min(m,n) && s1[i]==s2[i]){
        i+=1;
    }
    return i;
}
int solve(int i,int j,int m,int n,vector<int>&arr1,vector<int>&arr2){
    if(i>=m || j>=n){
        return 0;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    // compare the current
    int res=getLen(arr1[i],arr2[j]);

    res=max(res,solve(i+1,j+1,m,n,arr1,arr2));
    res=max(res,solve(i+1,j,m,n,arr1,arr2));
    res=max(res,solve(i,j+1,m,n,arr1,arr2));

    return dp[i][j]=res;
}
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int m=arr1.size();
        int n=arr2.size();

        dp.resize(m,vector<int>(n,-1));
        int res=solve(0,0,m,n,arr1,arr2);

        return res;
    }
};
