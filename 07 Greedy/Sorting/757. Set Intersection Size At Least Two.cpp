class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(begin(intervals),end(intervals),[](const vector<int>&a,const vector<int>&b){
            if(a[1]==b[1]){
                return a[0]>b[0];
            }
            return a[1]<b[1];
        });
        int first=intervals[0][1]-1;
        int second=intervals[0][1];
        int res=2;


        for(int i=1;i<n;i++){
            int l=intervals[i][0];
            int r=intervals[i][1];

          if(l<=first) continue;

           if(l>second){
                res+=2;
                first=r-1;
                second=r;
            }
            else if(l>first){
                res+=1;
                first=second;
                second=r;
            }
        }

        return res;
    }
};
