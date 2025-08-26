class Solution {
private:
int gcd(int a,int b){
    if(b==0) return a;

    return gcd(b,a%b);
}
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0;
        int sumEven=0;

        int k=n;
        int odd=1;
        int even=2;
        while(k){
            sumOdd+=odd;
            sumEven+=even;
            odd+=2;
            even+=2;
            k--;
        }


        return gcd(max(sumOdd,sumEven),min(sumEven,sumOdd));
    }
};
