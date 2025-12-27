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
