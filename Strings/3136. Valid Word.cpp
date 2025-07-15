class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3) return false;
        bool vwl=false;
        bool cns=false;

        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        vowels.insert('A');
        vowels.insert('E');
        vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');
        for(char c:word){
            if(isalpha(c) || isdigit(c)){
                if(vowels.count(c)){
                    vwl=true;
                }
                else if(isalpha(c)){
                    cns=true;
                }
            }
            else{
                return false;
            }
        }

        return vwl && cns;
    }
};
