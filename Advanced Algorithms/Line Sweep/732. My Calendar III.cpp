
// using Multiset and line sweep technique
// time : O(n*logn + n*n)
// space : O(n)
using delta=pair<int,int>;
class MyCalendarThree {
private:
multiset<delta> st;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        st.insert({startTime,1});
        st.insert({endTime,-1});

        // using a line sweep technique
        int maxIntersections=0;
        int curIntersecs=0;

        for(auto &it:st){
            int deltaVal=it.second;
            curIntersecs+=deltaVal;

            maxIntersections=max(maxIntersections,curIntersecs);
        }

        return maxIntersections;
    }
};
