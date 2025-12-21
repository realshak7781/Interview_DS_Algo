// Time : O(N)
// O(no of digits)

class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        stack<int> st;
        long long curNum=0;
        char lastOp='+';

        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                curNum=curNum*10+(s[i]-'0');
            }


            if((!isdigit(s[i]) && s[i]!=' ') || i==n-1){
                if(lastOp=='+'){
                    st.push(curNum);
                }
                else if(lastOp=='-'){
                    st.push(-curNum);
                }
                else if(lastOp=='*'){
                    int top=st.top();
                    st.pop();
                    st.push(curNum*top);
                }
                else if(lastOp=='/'){
                    int top=st.top();
                    st.pop();
                    st.push(top/curNum);
                }

                lastOp=s[i];
                curNum=0;
            }
        }

        int res=0;

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        return res;
    }
};
