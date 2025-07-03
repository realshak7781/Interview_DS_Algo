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
