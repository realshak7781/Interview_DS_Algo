
// Approach 2: Iterative Stack based approach 
class Solution {
public:
    int calculate(string s) {
        // to avoid the recursion call stack we will explicitly use stack data structure

        stack<int> st;
        int res=0;
        int number=0;
        int sign=1;

        for(int i=0;i<s.size();i++){
            char cur=s[i];

            if(isdigit(cur)){
                number=number*10+(cur-'0');
            }
            else if(cur=='+'){
                res+= sign*number;
                sign=1;
                number=0;
            }
            else if(cur=='-'){
                res+=sign*number;
                sign=-1;
                number=0;
            }
            else if(cur=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(cur==')'){
                res+=sign*number;
                number=0;

                res=res*st.top();
                st.pop();

                res+=st.top();
                st.pop();
            }
            else{
                // spaces
                continue;
            }
        }

        res+=sign*number;
        return res;
    }
};



// Approach 1: Recursion
class Solution {
private:
    int idx;
    int solve(string& s) {
        int res = 0;
        int number = 0;
        int sign = 1;

        while (idx < s.size()) {
            char cur = s[idx];
            if (isdigit(cur)) {
                number = number * 10 + (cur - '0');
                idx++;
            } else if (cur == '+') {
                res += sign * number;
                number = 0;
                sign = 1;
                idx++;
            } else if (cur == '-') {
                res += sign * number;
                number = 0;
                sign = -1;
                idx++;
            } else if (cur == '(') {
                idx++;
                res += sign * solve(s);
            } else if (cur == ')') {
                idx++;
                res += sign * number;
                return res;
            } else if (cur == ' ') {
                idx++;
            }
        }

        res += sign * number;
        return res;
    }

public:
    int calculate(string s) {
        idx = 0;
        return solve(s);
    }
};
