
// simple simulation:
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total=0;

        int consumed=0;
        while(numBottles>=numExchange){
            consumed+=numExchange;
            numBottles-=numExchange;
            numBottles+=1;
        }

        return consumed+numBottles;
    }
};
