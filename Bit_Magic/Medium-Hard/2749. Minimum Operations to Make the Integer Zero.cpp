


// Approach 1:
class Solution {
private:
int getSetBitsCount(long n){
    int count=0;

    while(n){
        n=n & (n-1);
        count++;
    }
    return count;
}
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t=1;

        while(true){
            long long val=(long)num1-(long)t*num2;

            if(val<0) return -1;

            int min_bits=getSetBitsCount(val);
            // minimum powers needed to make val 0
            if(min_bits<=t && t<=val){
                return t;
            }
            t++;
        }

        return -1;
    }
};
