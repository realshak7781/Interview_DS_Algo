class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> brokenChar(26,false);

        for(char c:brokenLetters){
            brokenChar[c-'a']=true;
        }


        stringstream ss(text);
        string token;

        int resCount=0;
        while(getline(ss,token,' ')){
            if(token.empty()) continue;

            bool valid=true;
            for(char c:token){
                if(brokenChar[c-'a']) {
                    valid=false;
                    break;
                }
            }

            if(valid) resCount++;
        }

        return resCount;
    }
};
