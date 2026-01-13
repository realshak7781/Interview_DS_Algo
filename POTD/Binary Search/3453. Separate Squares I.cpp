// Using BInary search and Precision Maths
// time : O(log(rangeOfAns)*sq.len())
// space : O(1)

class Solution {
bool check(vector<vector<int>>& squares,double totalArea,double mid_y){
    double bottomArea=0.0;

    for(auto &sq:squares){
        double y = sq[1];
        double l = sq[2];

        double boty = y;
        double topy = y + l;

        if(mid_y>=topy){
            bottomArea+=l*l;
        }
        else if(mid_y>boty){
            bottomArea+=(mid_y-boty)*l;
        }
    }

    return bottomArea>=totalArea/2.0;
}
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low=INT_MAX;
        double high=INT_MIN;

        double totalArea=0.0;
        for(auto &sq:squares){
            double x = sq[0];
            double y = sq[1];
            double l = sq[2];
            totalArea+=l*l;

            low=min(low,y);
            high=max(high,y+l);
        }

        double res=0.0;

        while((high-low) > 1e-5){
            double mid_y=low+(high-low)/2.0;

            
            if(check(squares,totalArea,mid_y)){
                high=mid_y;
                res=mid_y;
            }
            else{
                low=mid_y;
            }
        }

        return res;
    }
};
