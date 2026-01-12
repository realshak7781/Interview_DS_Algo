

// extreme brute force using BFS
class Solution {
private:
vector<pair<int,int>> dir = {
    {1,0}, {-1,0}, {0,1}, {0,-1},
    {1,1}, {1,-1}, {-1,1}, {-1,-1}
};
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        // we have to process the points in order
        int idx=0;

        queue<tuple<int,int,int>> q;
        q.push({points[0][0],points[0][1],0});
        set<pair<int,int>> vis;
        vis.insert({points[0][0],points[0][1]});


        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                auto [curCorX,curCorY,curTime]=q.front();
                q.pop();
                if (curCorX == points[idx][0] && curCorY == points[idx][1])idx++;

                if(idx>=n) return curTime;

                // now traverse all possible directions

                for(auto [dx,dy]:dir){
                    int nx=curCorX+dx;
                    int ny=curCorY+dy;

                    if(vis.find({nx,ny})==vis.end()){
                        vis.insert({nx,ny});
                        q.push({nx,ny,curTime+1});
                    }
                }
            }
        }

        return -1;
    }
};
