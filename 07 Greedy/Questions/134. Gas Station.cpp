// greedy : O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int> diff(n);

        for(int i=0;i<n;i++){
            diff[i]=gas[i]-cost[i];
            // this is the difference we will be carrying to next station
        }

        // traverse the diff array:
        // if at any point the agg sum of difference array becomes neg:
        // conclusion is: the path from the assumed starting point to the cur has becomes <0, so if you dry run a few examples like : {-2,-,2,-2,3,3} : you will see that the starting point will always be the index+1 where your agg sum has become -ve ;
        // dry run:
        // If the fuel tank becomes negative at any point, all stations visited so far in the current attempt can be discarded as potential starting points.

        int curr_tank=0;
        int totalDiff=0;
        int start=0;
        for(int i=0;i<n;i++){
            totalDiff+=diff[i];
            curr_tank+=diff[i];

            if(curr_tank<0){
                start=i+1;
                curr_tank=0;
            }
        }

        return totalDiff>=0?start:-1;
    }
};
// Brute force approach:
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();

        for(int i=0;i<n;i++){
            int s_no=i;
            // try to reach the same station : complete circular tour
            int petrol=gas[i];

            while(true){
                int balance=petrol-cost[s_no];
                if(balance<0) break;

                s_no=(s_no+1)%n;
                petrol=balance+gas[s_no];
                if(s_no==i) return i;
            }
        }

        return -1;
    }
};
