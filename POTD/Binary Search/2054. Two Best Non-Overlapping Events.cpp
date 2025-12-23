// Approach 2: Using Binary Search and sorting and suffix max
// time : O(nlogn
// space : O(n)

class Solution {
private:
int find(int low,int high,vector<vector<int>>& events,int end1){
    
    int res=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int start=events[mid][0];

        if(start>end1){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return res;
}
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();

        sort(events.begin(),events.end());
        vector<int> suffMax(n);
        suffMax[n-1]=events[n-1][2];

        for(int i=n-2;i>=0;i--){
            suffMax[i]=max(suffMax[i+1],events[i][2]);
        }

        int maxVal=0;
        for(int i=0;i<n;i++){
            int r1=events[i][0];
            int r2=events[i][1];
            int val=events[i][2];

            maxVal=max(maxVal,val);
            // find first non overlapping index
            int idx=find(i+1,n-1,events,r2);
            if(idx!=-1){
                int nextVal=suffMax[idx];
                maxVal=max(maxVal,val+nextVal);
            }
        }

        return maxVal;
    }
};

// approach 1: Brute force
// time : O(n^2)
// space : O(1)
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();

        int maxVal=0;
        for(int i=0;i<n;i++){
            int r1=events[i][0];
            int r2=events[i][1];
            int val1=events[i][2];

            maxVal=max(val1,maxVal);
            for(int j=i+1;j<n;j++){
                int r3=events[j][0];
                int r4=events[j][1];
                int val2=events[j][2];

                if(r3 > r2 || r1>r4 )maxVal=max(maxVal,val1+val2);  
            }
        }

        return maxVal;
    }
};
