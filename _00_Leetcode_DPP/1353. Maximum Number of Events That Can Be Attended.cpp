// optimal:
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();

        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int day=events[0][0];
        int res=0;

        int i=0;
        while(i<n || !pq.empty()){

            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }
            // remove events whose last day to be attended has passed
            while(!pq.empty() && pq.top()<day) pq.pop();

            if(!pq.empty()){
                pq.pop();
                res++;
            }

            day++;
        }

        return res;
    }
};


// brute force:
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int eventCount = 0;
        set<int> usedDays;

        sort(events.begin(), events.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        for (int i = 0; i < n; i++) {
            int startDay = events[i][0];
            int endDay = events[i][1];

            // now we can attend this currentEvent on any day no from below
            for (int d = startDay; d <= endDay; d++) {
                if (usedDays.find(d) == usedDays.end()) {
                    usedDays.insert(d);
                    eventCount++;
                    break;
                }
            }
        }

        return eventCount;
    }
};
