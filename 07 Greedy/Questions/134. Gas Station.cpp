
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
