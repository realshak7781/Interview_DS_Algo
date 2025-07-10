class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        int size=startTime.size();
        freeTime.push_back(startTime[0]);

        for(int i=1;i<size;i++){
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }

        freeTime.push_back(eventTime-endTime[size-1]);

        int n=freeTime.size();
        vector<int> maxRightFree(n,0);
        vector<int> maxLeftFree(n,0);

        for(int i=n-2;i>=0;i--){
            maxRightFree[i]=max(maxRightFree[i+1],freeTime[i+1]);
        }

        for(int i=1;i<n;i++){
            maxLeftFree[i]=max(maxLeftFree[i-1],freeTime[i-1]);
        }

        // traverse the freeTime array

        // case when we dont rearrange any meetings
        int result=*max_element(freeTime.begin(),freeTime.end());

        // case when we try to reararange a single any meeting:
        for(int i=1;i<n;i++){
            int curEventGap=endTime[i-1]-startTime[i-1];

            if(curEventGap<=max(maxRightFree[i],maxLeftFree[i-1])){
                // case 1 : taking the current meeting out
                result=max(result,freeTime[i-1]+curEventGap+freeTime[i]);
            }

            // case 2: push the meeting left or right side free gap place:
            result=max(result,freeTime[i-1]+freeTime[i]);
        }

        return result;
    }
};
