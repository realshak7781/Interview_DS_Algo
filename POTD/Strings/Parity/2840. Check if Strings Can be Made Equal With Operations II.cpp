class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int size=s1.size();

        // the cols represent the parity and 
        vector<int> s1Odd(26,0);
        vector<int> s1Even(26,0);
        vector<int> s2Odd(26,0);
        vector<int> s2Even(26,0);

        // process s1
        for(int i=0;i<size;i++){
            int parity=i%2;
            if(parity==0){
                s1Even[s1[i]-'a']++;
            }
            else{
                s1Odd[s1[i]-'a']++;
            }
        }

        // process s2
        for(int i=0;i<size;i++){
            int parity=i%2;
            if(parity==0){
                s2Even[s2[i]-'a']++;
            }
            else{
                s2Odd[s2[i]-'a']++;
            }
        }

        return (s1Even==s2Even && s1Odd==s2Odd);
    }
};
