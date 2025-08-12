class Solution {
private:
    string getHex(int n) {
        if (n == 0)
            return "0";

        string res = "";
        while (n > 0) {
            int dig = n % 16;

            if (dig <= 9) {
                res += to_string(dig);
            } else {
                char d = 'A' + (dig-10);
                res += d;
            }

            n /= 16;
        }

        reverse(res.begin(), res.end());

        return res;
    }
    string getHeg(int n) {
        if (n == 0)
            return "0";

        string res = "";
        while (n > 0) {
            int dig = n % 36;

            if (dig <= 9) {
                res += to_string(dig);
            } else {
                char d = 'A' + (dig-10);
                res += d;
            }

            n /= 36;
        }

        reverse(res.begin(), res.end());

        return res;
    }

public:
    string concatHex36(int n) {
        int hDNum = pow(n, 2);
        int hgNum = pow(n, 3);

        string hex = getHex(hDNum);
        string heg = getHeg(hgNum);

        string res = hex + heg;

        return res;
    }
};
