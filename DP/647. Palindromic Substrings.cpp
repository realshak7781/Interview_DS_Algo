
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
