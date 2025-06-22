class Solution {
private:
vector<vector<int>> dp;
bool checkPalindrome(string &s,int i,int j){
    if(i>j) return true;

    if(dp[i][j]!=-1) return dp[i][j];
    bool ans=false;
    if(s[i]==s[j]){
        ans=checkPalindrome(s,i+1,j-1);
    }

    return dp[i][j]=ans;
}    
public:
    int countSubstrings(string s) {
        int n=s.length();
        
        dp=vector<vector<int>>(1001,vector<int>(n+1,-1));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(checkPalindrome(s,i,j)) count++;
            }
        }

        return count;
    }
};



//brute force o(n^3)
class Solution {
private:
bool checkPalindrome(string &s,int i,int j){

    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }

    return true;
}    
public:
    int countSubstrings(string s) {
        int n=s.length();

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(checkPalindrome(s,i,j)) count++;
            }
        }

        return count;
    }
};
