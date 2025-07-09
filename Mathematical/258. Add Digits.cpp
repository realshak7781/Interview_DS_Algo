// OPTIMAL : o(1)
class Solution {
public:
    int addDigits(int num) {
        // read about DIGITAL ROOT OF A NO.
        if(num==0) return num;
        int rem=num%9;

        if(rem==0) return 9;

        return rem;
    }
};

// brute force: O (LOG *LOG)
class Solution {
private:
int getSumDig(int num){
    int agg=0;

    while(num>0){
        int dig=num%10;
        agg+=dig;
        num/=10;
    }

    return agg;
}    
public:
    int addDigits(int num) {
        
        while(num>9){
            num=getSumDig(num);
        }

        return num;
    }
};
