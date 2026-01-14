
// Using Coordinate Compression and Binary Search But still a brute force approach
class Solution {
private:
double getUnionArea(vector<vector<double>> &rects){
    set<double> uniqueX;
    for(auto &r:rects){
        uniqueX.insert(r[0]);
        uniqueX.insert(r[1]);
    }

    vector<double> xCord(begin(uniqueX),end(uniqueX));
    double totalArea = 0;

    for(int i=0;i<xCord.size()-1;i++){
        double x1=xCord[i];
        double x2=xCord[i+1];
        double width = x2 - x1;

        if(width==0) continue;

        vector<pair<double, double>> intervals;
        for(auto &r:rects){
            if(r[0]<=x1 && r[1]>=x2){
                intervals.push_back({r[2], r[3]});
            }
        }

        if (intervals.empty()) continue;
        sort(intervals.begin(), intervals.end());

        double start = intervals[0].first;
        double end = intervals[0].second;

        for (int k = 1; k < intervals.size(); k++) {
            if (intervals[k].first < end) {
                end = max(end, intervals[k].second);
            } else {
                totalArea += width * (end - start); 
                start = intervals[k].first;
                end = intervals[k].second;
            }
        }
        totalArea += width * (end - start);
    }

    return totalArea;
}
bool check(vector<vector<int>>& squares,double &mid_y,double &totalArea){
    vector<vector<double>> clippedArea;
    for(auto &sq:squares){
        double x=(double)sq[0];
        double y=(double)sq[1];
        double l=(double)sq[2];

        if(y>=mid_y) continue;

        double clipped_top = min(y + l, mid_y);

        clippedArea.push_back({x, x + l, y, clipped_top});
    }

    double bottomArea=getUnionArea(clippedArea);

    return bottomArea>=totalArea/2.0;
}
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9;
        double high = -1e9;
        
        vector<vector<double>> all_rects;

        for(auto &sq : squares){
            double x = (double)sq[0];
            double y = (double)sq[1];
            double l = (double)sq[2];

            all_rects.push_back({x, x + l, y, y + l});
            low = min(low, y);
            high = max(high, y + l);
        }
        double totalArea = getUnionArea(all_rects);

        double res = high;

        while((high - low) > 1e-5){
            double mid_y = low + (high - low) / 2.0;

            if(check(squares, mid_y, totalArea)){
                res = mid_y;
                high = mid_y; 
            }
            else{
                low = mid_y;
            }
        }

        return res;
    }
};
