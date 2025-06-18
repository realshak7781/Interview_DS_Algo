class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict(dictionary.begin(),dictionary.end());

        stringstream ss(sentence);
        string word;

        string res="";
        while(getline(ss,word,' ')){
            string cur="";

            bool notFound=true;
            for(int i=0;i<word.length();i++){
                cur+=word[i];
                if(dict.count(cur)){
                    notFound=false;
                    res=res+cur+" ";
                    break;
                }
            }

            if(notFound){
                res=res+word+" ";
            }
        }

        res.pop_back();

        return res;
    }
};
