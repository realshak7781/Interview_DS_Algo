// Optimal : O(N^2)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();

        int res=0;
        sort(begin(points),end(points),[&](auto &a,auto &b){
            if(a[0]==b[0]) return a[1]>b[1];

            return a[0]<b[0];
        });


        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            // upper left

            int ySoFar=INT_MIN;
            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];

                if(y2>y1) continue;
                // bottom right
                if(y2>ySoFar){
                    ySoFar=y2;
                    res++;
                }
            }
        }

        return res;
    }
};

// Brute force : O(N^3)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
          int n=points.size();
        // A is on the upper left side of B, and
        // to achieve this we need to sort the point based on x

        sort(points.begin(), points.end(), [](auto &a, auto &b){
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int ans=0;
        for(int x2=n-1;x2>=0;x2--){
            for(int x1=0;x1<x2;x1++){
                // check for pair

                if (points[x1][1] < points[x2][1]) continue;

                bool hasMiddle=false;
                for(int x=x1+1;x<x2;x++){
                   if (points[x][0] >= points[x1][0] && 
                        points[x][0] <= points[x2][0] &&
                        points[x][1] <= points[x1][1] && 
                        points[x][1] >= points[x2][1]) {
                        hasMiddle = true;
                        break;
                    }
                }

                if(!hasMiddle){
                    ans++;
                }
            }
        }


        return ans;

    }
};
