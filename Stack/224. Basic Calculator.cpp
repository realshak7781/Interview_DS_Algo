



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
