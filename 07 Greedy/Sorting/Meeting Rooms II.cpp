// approach 1 : Time : O(n^2)
using p=pair<int,int>;
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n==0 || n==1) return n;

        vector<p> ranges;
        for(auto it:intervals){
            ranges.push_back({it.start,it.end});
        }

       int min_start,max_end;
       for(auto it:ranges){
        min_start=min(min_start,it.first);
        max_end=max(max_end,it.second);
       }


       int max_meetings=INT_MIN;
       for(int t=min_start;t<=max_end;t++){
           int concurrent_meetings=0;

           for(auto it:ranges){
            int start=it.first;
            int end=it.second;
            if(t>=start && t<end) concurrent_meetings++;
           }

           max_meetings=max(max_meetings,concurrent_meetings);
       }


    // approach 2:

using p=pair<int,int>;
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n==0 || n==1) return n;

        vector<int> startV,endV;
        for(auto it:intervals){
            startV.push_back(it.start);
            endV.push_back(it.end);
        }

        sort(begin(startV),end(startV));
        sort(begin(endV),end(endV));

        int s=0,e=0;
        int maxRoom=-1,meetings=0;
        while(s<startV.size() &&  e<endV.size()){

            if(startV[s]<endV[e]){
                meetings++;
                s++;
            }
            else{
                meetings--;
                e++;
            }

            maxRoom=max(maxRoom,meetings);
        }

        return maxRoom;
    }
};


       return max_meetings;
    }
};
