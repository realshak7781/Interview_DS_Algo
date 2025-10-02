class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int fullBottles=numBottles;
        int emptyBottles=0;
        int totalDrunk=0;

        while(fullBottles>0){

            // ddrinnking phase
            totalDrunk+=fullBottles;
            emptyBottles+=fullBottles;
            fullBottles=0;


             // fulling phase ya exhangng phase 
            while(emptyBottles>=numExchange){
                fullBottles+=1;
                emptyBottles-=numExchange;
                numExchange++;
            }
           
        }

        if(fullBottles>0){
            totalDrunk+=fullBottles;
            fullBottles=0;
        }

        return totalDrunk;
    }
};
