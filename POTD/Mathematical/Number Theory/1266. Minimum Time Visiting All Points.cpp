
// Using Maths : Time : O (n)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        // the best stratgey is to move diagonally and then cover steps one unit at a time veritcally or horizontally
        int totalTime=0;

        for(int i=1;i<n;i++){
            int prevX=points[i-1][0];
            int prevY=points[i-1][1];

            // trying to reach from prev to cur point in min time
            int curX=points[i][0];
            int curY=points[i][1];

            int mini=min(abs(curX-prevX),abs(curY-prevY));
            int maxi=max(abs(curX-prevX),abs(curY-prevY));

            totalTime=totalTime+mini/*this is diagonal dist*/+(maxi-mini) /*this is rem vertical or horizontal dist*/;
        }

        return totalTime;
    }
};

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
