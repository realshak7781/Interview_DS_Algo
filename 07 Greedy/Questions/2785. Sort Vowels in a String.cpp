


// Approach 1:
// Brute force : O(n*logv)  where v : vowels in strings
// space : o(v)
class Solution {
private:
bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;

    return false;
}
public:
    string sortVowels(string s) {
        priority_queue<char,vector<char>,greater<char>>minHeap;

        for(char c:s){
            if(isVowel(c)){
                minHeap.push(c);
            }
            else{
                continue;
            }
        }

        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i]=minHeap.top();
                minHeap.pop();
            }
        }


        return s;
    }
};
