// Using Power of Two
class Solution {
public:
    int smallestNumber(int n) {
        int totalBits=floor(log2(n))+1;

        int res=1<<(totalBits);
        res=res-1;

        return res;
    }
};

// Brute force
class Solution {
public:
    int smallestNumber(int n) {
        int res=n;

        int totalBits=floor(log2(n))+1;
        for(int i=0;i<totalBits;i++){
            if(!(res&(1<<i))){
                res=res|(1<<i);
            }
        }

        return res;
    }
};
