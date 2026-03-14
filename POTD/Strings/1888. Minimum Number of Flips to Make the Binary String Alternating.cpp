
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
