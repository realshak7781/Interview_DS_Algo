
// Brute Force : 
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        int m=shifts.size();
        for(int i=0;i<m;i++){
            int shiftCount=i+1;
            int shiftVal=shifts[i];

            for(int j=0;j<min(shiftCount,n);j++){
                int curIdx=s[j]-'a';
                int newIdx=(curIdx+shiftVal)%26;

                s[j]='a'+newIdx;
            }
        }

        return s;
    }
};
