class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        if(n<=1) return 0;

        int prev=0;
        int minTime=0;
        for(int cur=1;cur<n;cur++){
            char curCol=colors[cur];
            char prevCol=colors[prev];

            if(curCol==prevCol){

                if(neededTime[prev]<=neededTime[cur]){
                    minTime+=neededTime[prev];
                    prev=cur;
                }
                else{
                    minTime+=neededTime[cur];
                }
            }
            else{
                prev=cur;
            }
        }

        return minTime;

        // Greedy approach solves this problem
    }
};
