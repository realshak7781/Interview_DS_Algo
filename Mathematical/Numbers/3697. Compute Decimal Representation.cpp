class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res;
        long long pow10=1;

        while(n>0){
            long long dig=n%10;
            n/=10;

            if(1LL*dig*pow10>0)res.push_back(dig*pow10);
            pow10*=10;
        }

        reverse(res.begin(),res.end());

        return res;
    }
};
