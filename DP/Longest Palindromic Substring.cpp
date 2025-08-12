


// Brute force approach : o(n^3) sol
class Solution {
private:
bool isPalindrome(int i,int j,string &s){
    
    while(i<=j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    
    return true;
}
public:
    string longestPalindrome(string s) {
        int n=s.length();
        
        string res="";
        int minLen=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int len=j-i+1;
                
                if(isPalindrome(i,j,s)){
                    if(len>minLen){
                        res=s.substr(i,len);
                        minLen=len;
                    }
                }
            }
        }
        
        return res;
    }
};
