


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
