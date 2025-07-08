// Optimal:

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed=numBottles;
        int emptyBottles=numBottles;

        while(emptyBottles>=numExchange){
            int newBottles=emptyBottles/numExchange;
            int remEmpty=emptyBottles%numExchange;

            consumed+=newBottles;
            emptyBottles=newBottles+remEmpty;
        }

        return consumed;
    }
};

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
