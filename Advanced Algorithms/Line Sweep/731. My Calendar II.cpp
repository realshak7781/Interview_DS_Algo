// USING THE LINE SWEEP TECHNIQUE
// TIME : O(ELOGE + E*E)
// SPACE : O(E)


using p = pair<int, int>;
class MyCalendarTwo {
private:
    multiset<p> events;

public:
    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
        events.insert({startTime, 1});
        events.insert({endTime, -1});

        if (isPossibleToAddCurrentEvent()) {
            return true;
        }

        auto it1 = events.find({startTime, 1});
        events.erase(it1);
        auto it2 = events.find({endTime, -1});
        events.erase(it2);

        return false;
    }

    bool isPossibleToAddCurrentEvent() {
        int intersections = 0;

        for (auto e : events) {
            int eventVal=e.second;
            intersections+=eventVal;

            if(intersections>=3) return false;
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
