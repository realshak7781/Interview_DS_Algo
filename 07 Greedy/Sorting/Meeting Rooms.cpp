/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

using p=pair<int,int>;
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        vector<P> intrvl;

        for(auto it:intervals){
            intrvl.push_back({it->start,it->end});
        }

        sort(begin(intrvl),end(intrvl));

        int end=intrvl[0].second;

        for(int i=1;i<n;i++){
            int curStart=intrvl[i].first;

            if(curStart<end) return false;

            end=intrvl[i].second;
        }

        return true;
    }
};
