// Approach 2: just simple intuition after dry running
class Solution {
private:

bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i'|| c=='o' || c=='u')return true;
    return false;
}

int getCountVowels(string &s){
    int count=0;

    for(char c:s){
        if(isVowel(c)) count++;
    }
    return count;
}
public:
    bool doesAliceWin(string s) {
        int vowCount=getCountVowels(s);

        int n=s.length();
        if(vowCount==0){
            return false;
        }
        else if(vowCount&1){
            return true;
        }
        else{
            // chooose the largest substring for bob to have a substring 
           return true;
        }

        return false;
    }
};


// Approach 1: Mathematical Approach
class Solution {
private:

bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i'|| c=='o' || c=='u')return true;
    return false;
}

int getCountVowels(string &s){
    int count=0;

    for(char c:s){
        if(isVowel(c)) count++;
    }
    return count;
}
public:
    bool doesAliceWin(string s) {
        int vowCount=getCountVowels(s);

        int n=s.length();
        if(vowCount==0){
            return false;
        }
        else if(vowCount&1){
            return true;
        }
        else{
            // chooose the largest substring for bob to have a substring 
            int count=0;
            int i=0;

            while(i<n){
                char c=s[i];

                if(isVowel(c)){
                    count++;
                }

                if(count==(vowCount-1)) break;
                i++;
            }

            int remLen=n-i-1;

            if(remLen>=1) return true;
        }

        return false;
    }
};
