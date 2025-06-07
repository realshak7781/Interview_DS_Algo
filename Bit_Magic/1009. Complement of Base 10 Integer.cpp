class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int res=0;
        int bitPos=0;
        while(n>0){
            if(!(n&1)){
                // do nothing
                res=res^(1<<bitPos);
            }
            bitPos++;
            n>>=1;
        }

        return res;
    }
};
