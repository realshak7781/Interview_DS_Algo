class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalBottles=0;

        while(numBottles>=numExchange){
            totalBottles+=numExchange;
            numBottles=numBottles-numExchange+1;
        }

        if(numBottles==0) numBottles=1;
        return totalBottles+numBottles;
    }
};
