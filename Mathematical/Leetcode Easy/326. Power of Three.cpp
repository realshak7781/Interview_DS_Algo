// Optimal Approach :

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        if(n==1) return true;

        double logVal=log10(n)/log10(3);

        return logVal==(int)logVal;
    }
};



// Brute force approach : O(log3(N))
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        if(n==1) return true;

        if(n%3!=0) return false;


        return isPowerOfThree(n/3);
    }
};
