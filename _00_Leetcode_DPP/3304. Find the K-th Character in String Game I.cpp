// OPTIMAL:
class Solution {
public:
    char kthCharacter(int k) {
        if(k==1) return 'a';

        int len=1;
        while(len*2<k) len*=2;

        char cur=kthCharacter(k-len);

        return (cur-'a'+1)%26+'a';
        
    }
};

// brute force: O(K*LOGK)
class Solution {
public:
    char kthCharacter(int k) {
        string word="a";

        while(word.size()<k){
            string later="";
            for(char c:word){
                int nextIndex=(c-'a'+1)%26;
                char next=nextIndex+'a';
                later=later+next;
            }
            word=word+later;
        }

        return word[k-1];
    }
};
