// optimal : O(n)
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        int n=s.length();

        for(int i=0;i<n;i++){
            char cur=s[i];
            if(cur>='0' && cur<='9'){
                if(st.empty()){
                    st.push(cur);
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push(cur);
            }
        }

        string res="";

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};


// brute force: o(n^2)
class Solution {
public:
    string clearDigits(string s) {

        int n=s.length();
        vector<bool> take(n,true);
        for(int i=0;i<n;i++){
            char cur=s[i];
            if(cur>='0' && cur<='9'){
                for(int j=i-1;j>=0;j--){
                    if(take[j] && s[j]>='a' && s[j]<='z'){
                        take[j]=false;
                        take[i]=false;
                        break;
                    }
                }
            }
        }


        string res="";
        for(int i=0;i<n;i++){
            if(take[i]){
                res+=s[i];
            }
        }

        return res;
    }
};
