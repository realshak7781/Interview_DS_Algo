
// Leetcode POTD: 23 july 2025

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.length();

        // creating a two pass gold silver khandani strategy

        bool chooseAb=x>y;
        int maxPoints=max(x,y);
        int minPoints=min(x,y);
        string first=chooseAb?"ab":"ba"; 
        string second=chooseAb?"ba":"ab"; 

        stack<int> st;
        int points=0;
        for(int i=0;i<n;i++){
            char cur=s[i];

            if(!st.empty() && cur==first[1] && st.top()==first[0]){
                st.pop();
                points+=maxPoints;
            }
            else{
                st.push(cur);
            }
        }


        string remStr="";
        while(!st.empty()){
            remStr+=st.top();
            st.pop();
        }

        reverse(begin(remStr),end(remStr));

        for(int i=0;i<remStr.length();i++){
            char cur=remStr[i];

            if(!st.empty() && cur==second[1] && st.top()==second[0]){
                st.pop();
                points+=minPoints;
            }
            else{
                st.push(cur);
            }
        }

        return points;
    }
};
