class Solution {
public:
    int earliestFinishTime(vector<int>& a, vector<int>& b, vector<int>& c,
                           vector<int>& d) {
        int n = a.size();
        int res = INT_MAX;

        // take the land ride first--> water ride:
        int minLandEnd=INT_MAX;

        for(int i=0;i<n;i++){
            minLandEnd=min(minLandEnd,a[i]+b[i]);
        }

        int m=c.size();

        for(int j=0;j<m;j++){
            res=min(res,d[j]+max(minLandEnd,c[j]));
        }

        // water ride first and then land ride
        int minWaterEnd=INT_MAX;

        for(int i=0;i<m;i++){
            minWaterEnd=min(minWaterEnd,c[i]+d[i]);
        }


        for(int j=0;j<n;j++){
            res=min(res,b[j]+max(minWaterEnd,a[j]));
        }

        return res;
    }
};
