using ll=long long;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        int sign_num=(numerator>0) ? 0 : 1;
        int sign_den=(denominator>0) ? 0 : 1;

        int sign=sign_num^sign_den;
        // 0 for pos and 1 for neg

        ll num=(abs)((ll)numerator);
        ll den=abs((ll)denominator);

        string res="";
        res+=to_string((ll)num/den);
        ll rem=num%den;

        if(rem==0){
            return sign == 1 ? "-" + res : res;
        }
        else{
            res+=".";
        }

        unordered_map<ll,ll> seen;

        while(rem>0){
            if(seen.count(rem)){
                ll pos=seen[rem];

                res.insert(pos,"(");
                res+=")";

                if(sign==1){
                    res="-"+res;
                }
                return res;
            }

            seen[rem]=res.length();
            rem*=10;

            res+=to_string((ll)rem/den);
            rem%=den;
        }

        return sign == 1 ? "-" + res : res;
    }
};
