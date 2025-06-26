// OPTIMAL :  O(N)

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.length();
        if(n==1) return "";
        
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }

        palindrome[n-1]='b';

        return palindrome;
    }
};


//  BRUTE FORCE ; O(N*26*N)
class Solution {    
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.length();
        if(n==1) return "";

        string res="";
        for(int i=0;i<n;i++){
            char cur=palindrome[i];

            for(char rep='a';rep<='z';rep++){
                palindrome[i]=rep;
                if(!checkPal(palindrome)){
                    if(res.empty() || palindrome<res){
                        res=palindrome;
                    }
                }
            }
            palindrome[i]=cur;
        }

        return res;
    }

    private:
    bool checkPal(string &s){
        int left=0,right=s.length()-1;

        while(left<=right){
            if(s[left]!=s[right]) return false;

            left++;
            right--;
        }

        return true;
    }
};
