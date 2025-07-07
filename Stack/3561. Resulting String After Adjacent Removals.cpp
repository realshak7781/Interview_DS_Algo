class Solution {
public:
    string resultingString(string s) {
        int n=s.length();
        stack<char> st;

        for(int i=0;i<n;i++){
           char cur=s[i];

           char leftCur=cur=='a'?'z':cur-1;
           char rightCur=cur=='z'?'a':cur+1;

            if(!st.empty() && (st.top()==leftCur|| st.top()==rightCur)){
                st.pop();
            }
            else{
                st.push(cur);
            }
        }


        string res="";

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
