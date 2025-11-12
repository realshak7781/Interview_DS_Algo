using ll=long long;
class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<ll> F(32, 0);
        F[0] = 1;
        for (int i = 1; i <= 31; i++) {
            F[i]=2*F[i-1]+1;
        }


        bool pos=true;
        int totalSteps=0;

        for(int i=31;i>=0;i--){
            if(n&(1<<i)){
                totalSteps=totalSteps + (pos ? F[i] : -1LL*F[i]);
                pos^=1;
            }
        }

        return totalSteps;
    }
};
