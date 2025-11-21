
// Approach 1 : Using O(n) space
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        for(char c:s){
            if(c=='#'){
                if(!st1.empty())st1.pop();
            }
            else{
                st1.push(c);
            }
        }

        string remS="";
        while(!st1.empty()){
            remS+=st1.top();
            st1.pop();
        }
        reverse(remS.begin(),remS.end());


        for(char c:t){
            if(c=='#' ){
                 if(!st1.empty())st1.pop();
            }
            else{
                st1.push(c);
            }
        }

        string remT="";
        while(!st1.empty()){
            remT+=st1.top();
            st1.pop();
        }
        reverse(remT.begin(),remT.end());

        return remT==remS;
    }
};
