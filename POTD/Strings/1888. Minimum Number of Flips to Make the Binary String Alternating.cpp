// SLIDING WINDOW APPROACH
class Solution {
public:
    int minFlips(string s) {
        int len = s.length();

        string cur = s + s;
        string s1 = "0";
        string s2 = "1";

        for (int i = 1; i < 2 * len; i++) {
            if (i & 1) {
                s1 += '1';
                s2 += '0';
            } else{
                s1 += '0';
                s2 += '1';
            }
        }

        // find the flips for the current window
        int flip1 = 0;
        int flip2 = 0;
        int minSteps = INT_MAX;

        for (int i = 0; i < len; i++) {
            if (cur[i] != s1[i]) {
                flip1++;
            }
            else if(cur[i] != s2[i]) {
                flip2++;
            }
        }

        minSteps = min(flip1, flip2);

        // done now next window
        int i = 1;
        int j = len;

        while (i < len) {
            // cur window

            int prevIdx = i - 1;
            if (cur[prevIdx] != s1[prevIdx]) {
                flip1--;
            } else {
                flip2--;
            }

            int curIdx = j;

            if (cur[curIdx] != s1[curIdx]) {
                flip1++;
            } else {
                flip2++;
            }

            minSteps=min({minSteps,flip1,flip2});
            i++;
            j++;
        }

        return minSteps;
    }
};


// Using Brute force Approach
// Time : O(len*len)
// space : O(len)
class Solution {
private:
    int solve(string& s) {
        int resOps = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                resOps++;
                char org = s[i];
                s[i] = (org == '1' ? '0' : '1');
            }
        }

        return resOps;
    }

    int applyFlips(string s) {
        string original = s;
        int ops = solve(s);

        s = original;
        char org = s[0];
        s[0] = (org == '1' ? '0' : '1');
        ops = min(ops, 1 + solve(s));
        s[0] = org;

        return ops;
    }

public:
    int minFlips(string s) {
        int len=s.length();

        int minSteps=applyFlips(s);

        for(int l=1;l<=len;l++){
            string cur=s.substr(l)+s.substr(0,l);

            minSteps=min(minSteps,applyFlips(cur));
        }

        return minSteps;
    }
};
