class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string lp="";

        for(char c:licensePlate){
            if(isalpha(c)){
                lp+=tolower(c);
            }
        }
        sort(begin(lp),end(lp));
        unordered_map<char,int> mp;
        for(char c:lp) mp[c]++;

        int minLen=15;
        string res="";
        for(string cur:words){
            unordered_map<char,int> curMap;
            string w="";

            for(char c:cur){
                if(mp.count(c) && curMap[c]<mp[c]){
                    w+=c;
                    curMap[c]++;
                }
            }

            sort(begin(w),end(w));

            if(w==lp){
                if(cur.length()<minLen){
                    minLen=cur.length();
                    res=cur;
                }
            }
        }

        return res;
    }
};
