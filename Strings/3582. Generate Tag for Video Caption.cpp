class Solution {
public:
    string generateTag(string caption) {
        string res="#";

        stringstream ss(caption);
        string word;
        int count=1;
        while(getline(ss,word,' ')){
            if(word.empty()) continue;
            for(int i=0;i<word.length();i++){
                if(count>1){
                    if(i==0){
                        word[i]=toupper(word[i]);
                    }
                    else{
                        word[i]=tolower(word[i]);
                    }
                }
                else {
                    word[i]=tolower(word[i]);
                }
            }
            res+=word;
            count++;
        }

        string result="#";
        for(int i=1;i<res.length();i++){
            if(isalpha(res[i])){
                result+=res[i];
            }
        }

        result=result.substr(0,100);

        return result;
        
    }
};
