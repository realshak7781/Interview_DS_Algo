
// Using Recursion
// Time : O(n^2)
// Space : O(n) stack space + O(n) for subprobs
class Solution {
private:
string solve(string s){
    if(s.length()<=0){
        return "";
    }

    int start=0;
    int sum=0;
    // a given special string can have a lot of internal special substrings
    // each substring should be solved individually to get the lexico largest version for 
    // for that substring
    // then out of all the solved substrings,concantenate them in such a way,to get the lexico largest for the current string
    // clearly a recursive problem
    vector<string> subProbs; 
    for(int i=0;i<s.length();i++){
        sum+=(s[i]=='1' ? 1 : -1);

        if(sum==0){
            // innerSubtring has starting at start+1 and length of i-start-1
            string innerSubstring=s.substr(start+1,i-start-1);
            string innerSolved="1" + solve(innerSubstring) + "0";
            subProbs.push_back(innerSolved);
            start=i+1;
        }
    }

    sort(begin(subProbs),end(subProbs),greater<>());

    string res="";
    for(string s:subProbs){
        res+=s;
    }

    return res;
}
public:
    string makeLargestSpecial(string s) {
        return solve(s);
    }
};
