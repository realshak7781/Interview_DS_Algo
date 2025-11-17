class Solution {
public:
    string findValidPair(string s) {
        int n=s.length();
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }
        
        for(int i=0;i<(n-1);i++){
            if(s[i]==s[i+1]) continue;

            int curVal=s[i]-'0';
            int nxtVal=s[i+1]-'0';

            if(freq[s[i]]==curVal && freq[s[i+1]]==nxtVal){
                string res=s.substr(i,2);
                return res;
            }
        }

        return "";
    }
};
