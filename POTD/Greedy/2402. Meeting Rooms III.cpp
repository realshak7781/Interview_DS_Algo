// approach 2 : using minHeap 
using ll=long long;
using p=pair<ll,int>;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> used(n,0);

        sort(begin(meetings),end(meetings));
        // sorting based on start time

        priority_queue<int,vector<int>,greater<int>> available;
        // minHeap for available rooms
        priority_queue<p,vector<p>,greater<p>> nextAvailable;

        // push initially all the available rooms
        for(int r=0;r<n;r++){
            available.push(r);
        }

        for(auto m:meetings){
            int start=m[0];
            int end=m[1];

            // remember the range is not inclusive for the end part : [start,end)

            // empty the rooms for this start Time
            while(!nextAvailable.empty() && nextAvailable.top().first<=start){
                available.push(nextAvailable.top().second);
                nextAvailable.pop();
            }

            if(!available.empty()){
                // rooms are available : so pick the smallest numbered available room
                int roomIdx=available.top();
                available.pop();
                used[roomIdx]++;

                nextAvailable.push({end,roomIdx});
            }
            else{
                // no rooms were available just pick the next smallest  or earliest time when the rooms will be available
                auto [endTime,roomIdx]=nextAvailable.top();
                nextAvailable.pop();

                used[roomIdx]++;
                int duration=end-start;
                ll nextAvailTime=endTime+duration;
                nextAvailable.push({nextAvailTime,roomIdx});
            }
        }


        // just find the smallest idx room most used
        int resIdx=INT_MAX;
        int maxVal=INT_MIN;
        for(int r=0;r<n;r++){
            if(used[r]>maxVal){
                maxVal=used[r];
                resIdx=r;
            }
            else if(used[r]==maxVal){
                resIdx=min(resIdx,r);
            }
        }

        return resIdx;
    }
};

// using simple story points + sorting
// time : O(n*m)
// space : O(n)
using ll=long long;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int totalMeetings=meetings.size();
        vector<ll> freeTime(n,-1);
        vector<int> useCount(n,0);

        sort(begin(meetings),end(meetings),[](const vector<int>&a,const vector<int>&b){
            return a[0] < b[0];
        });

        for(int i=0;i<totalMeetings;i++){
            int start=meetings[i][0];
            int end=meetings[i][1];

            // free the rooms for this start time
            for(int r=0;r<n;r++){
                if(freeTime[r]<=start){
                    freeTime[r]=-1;
                }
            }

            // find the first smallest place where the meeting will end
            int idx=0;
            ll minVal=freeTime[0];
            for(int r=1;r<n;r++){
                if(freeTime[r]<minVal){
                    // finding lowest idx free room
                    minVal=freeTime[r];
                    idx=r;
                }
            }

            // i am using the idx room
            if(freeTime[idx]==-1){
                freeTime[idx]=end;
            }
            else{
                int duration=end-start;
                freeTime[idx]+=duration;
            }

            useCount[idx]++;
        }


        int res=0;
        int maxVal=useCount[0];

        for(int r=1;r<n;r++){
            if(useCount[r]>maxVal){
                maxVal=useCount[r];
                res=r;
            }
        }

        return res;
    }
};
