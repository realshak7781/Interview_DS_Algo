

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
