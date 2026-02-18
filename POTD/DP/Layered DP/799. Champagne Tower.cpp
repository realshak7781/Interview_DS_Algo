
// TIME : O(Q*Q)
// SPACE : O(Q)

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prev(1,poured);

        for(int i=1;i<=query_row;i++){
            vector<double> next(i+1,0.0);

            int prevDpLen=i;
            for(int j=0;j<prevDpLen;j++){
                if(prev[j]>1.0){
                    double surplus=(prev[j]-1.0)/2.0;
                    prev[j]=1.0;
                    next[j]+=surplus;
                    next[j+1]+=surplus;
                }
            }
            prev=next;
        }


        return prev[query_glass]>1.0 ? 1.0 : prev[query_glass];
    }
};
