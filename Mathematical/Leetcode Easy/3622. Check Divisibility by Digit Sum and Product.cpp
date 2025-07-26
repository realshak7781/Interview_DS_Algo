using ll=long long;
class Solution {
public:
    bool checkDivisibility(int n) {
        ll num=1LL*n;

        ll digSum=0;
        ll digProd=1;

        while(n>0){
            ll dig=n%10;
            digSum+=dig;
            digProd=1LL*digProd*dig;
            n/=10;
        }

        ll sum=digSum+digProd;

        if(num%sum==0) return true;

        return false;
    }
};
