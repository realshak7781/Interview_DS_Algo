class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        int totalMeetings=startTime.size();
        int i=0;
        int prevEnd=0;
        if(startTime[0]==0){
            prevEnd=endTime[0];
            i=1;
        }
        for(;i<totalMeetings;i++){
            int start=startTime[i];
            freeTime.push_back(start-prevEnd);
            prevEnd=endTime[i];
        }

        if(endTime[totalMeetings-1]!=eventTime){
            freeTime.push_back(eventTime-prevEnd);
        }

        // freetime array created
        // do a sliding window of size k+1 on freeTime array:

        int windowSize=k+1;
        int st=0,j=0;
        int n=freeTime.size();

        // edge case: when freetime size is less than window size
        if(windowSize>n){
            windowSize=freeTime.size();
        }
        int maxSum=0;
        int sum=0;
        while(j<n){
            int curWindowSize=j-st+1;
            sum+=freeTime[j];
            if(curWindowSize>=windowSize){
                maxSum=max(maxSum,sum);
                sum-=freeTime[st];
                st++;
            }
            j++;
        }

        return maxSum;
    }
};
