// TIME : O(n)
// space : O(1)

class Solution {
private:
bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    return false;
}
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);

        for(char c:s){
            freq[c-'a']++;
        }

        int maxVow=0;
        int maxCons=0;

        for(char c:s){
            if(isVowel(c)){
                maxVow=max(maxVow,freq[c-'a']);
            }
            else{
                maxCons=max(maxCons,freq[c-'a']);
            }
        }

        return maxVow+maxCons;
    }
};
