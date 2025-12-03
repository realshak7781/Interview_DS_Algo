class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();

        // slope->{intercepts}
        unordered_map<float,vector<float>> slopeIntercepts;
        unordered_map<int,vector<float>> midPointMap;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];

                int dy=y2-y1;
                int dx=x2-x1;
                float slope,intercept;

                if(dx==0){
                    slope=1e9+7;
                    intercept=x1;
                }
                else{
                    slope=(float)dy/dx;
                    intercept=(float)(y1*dx-x1*dy)/dx;
                }

                int midPoint=(x1+x2)*10000+(y1+y2);
                slopeIntercepts[slope].push_back(intercept);
                midPointMap[midPoint].push_back(slope);
            }
        }

        int result=0;
        for(auto &it:slopeIntercepts){
            map<float,int>mp;

            for(float intercept:it.second){
                mp[intercept]++;
            }

            int prevHorizontalLines=0;
            for(auto &it:mp){
                int count=it.second;
                result+=(count*prevHorizontalLines);
                prevHorizontalLines+=count;
            }
        }

        for(auto &it:midPointMap){
            map<float,int>mp;

            for(float slope:it.second){
                mp[slope]++;
            }

            int prevHorizontalLines=0;
            for(auto &it:mp){
                int count=it.second;
                result-=(count*prevHorizontalLines);
                prevHorizontalLines+=count;
            }
        }

        return result;
    }
};
