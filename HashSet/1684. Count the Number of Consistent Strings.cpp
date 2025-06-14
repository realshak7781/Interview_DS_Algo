class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allw;
        for(char c:allowed){
            allw.insert(c);
        }

        int count=0;
        for(string &s:words){
            bool isGood=true;

            for(char c:s){
                if(!allw.count(c)){
                    isGood=false;
                    break;
                }
            }

            if(isGood) count++;
        }

        return count;
    }
};
