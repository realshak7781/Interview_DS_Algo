// Using Dijkstras ALgorithm : Because the Problem mimicks Single Source Shortest Path


using p=pair<int,pair<int,int>>;
class Solution {
private:
vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        set<pair<int,int>> vis;

        priority_queue<p,vector<p>,greater<p>> pq;

        pq.push({grid[0][0],{0,0}});
        vis.insert({0,0});


        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int time=top.first;
            int x=top.second.first;
            int y=top.second.second;

            if(x==n-1 && y==n-1) return time;

            for(auto d:dir){
                int nx=x+d[0];
                int ny=y+d[1];

                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis.count({nx,ny})){
                    vis.insert({nx,ny});
                    int nextHopTime=max(time,grid[nx][ny]);
                    pq.push({nextHopTime,{nx,ny}});
                }
            }
        }

        return -1;
    }
};



// Using BFS (shortest finding path algo) + Binary Search
class Solution {
private:
int n;
vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
bool isPossible(vector<vector<int>>& grid,int time){
    queue<pair<int,int>> q;
    set<pair<int,int>> vis;
    q.push({0,0});
    vis.insert({0,0});

    while(!q.empty()){
        int size=q.size();

        for(int i=0;i<size;i++){
            auto top=q.front();
            q.pop();
            int x=top.first;
            int y=top.second;

            if(x==n-1 && y==n-1) return true;

            for(auto d:dir){
                int nx=x+d[0];
                int ny=y+d[1];

                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis.count({nx,ny}) && grid[nx][ny]<=time){
                    vis.insert({nx,ny});
                    q.push({nx,ny});
                }
            }
        }
    }

    return false;
}
public:
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();

        int maxHeight=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxHeight=max(maxHeight,grid[i][j]);
            }
        }

        int high=maxHeight;
        int low=grid[0][0];

        int res=-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(isPossible(grid,mid)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return res;
    }
};
