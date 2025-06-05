class Solution {
public:
    int findComplement(int num) {
        int pos=0;
        int cur=num;

        while(cur>0){
            num=num^(1<<pos);
            pos++;
            cur/=2;
        }

        return num;
    }
};
