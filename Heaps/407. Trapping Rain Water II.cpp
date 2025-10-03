using p=pair<int,pair<int,int>>;
class Solution {
private:
vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,false));

        priority_queue<p,vector<p>,greater<p>>minHeap;

        // push first row and last row;
        for(int j=0;j<n;j++){
            minHeap.push({heightMap[0][j],{0,j}});
            minHeap.push({heightMap[m-1][j],{m-1,j}});

            vis[m-1][j]=true;
            vis[0][j]=true;
        }

        // push the first and last col
        for(int i=1;i<(m-1);i++){
            minHeap.push({heightMap[i][0],{i,0}});
            minHeap.push({heightMap[i][n-1],{i,n-1}});

            vis[i][0]=true;
            vis[i][n-1]=true;
        }

        int totalWater=0;
        while(!minHeap.empty()){
            auto top=minHeap.top();
            minHeap.pop();

            int height=top.first;
            int x=top.second.first;
            int y=top.second.second;

            for(auto d:dir){
                int nx=x+d[0];
                int ny=y+d[1];

                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                    totalWater+=max(0,height-heightMap[nx][ny]);
                    vis[nx][ny]=true;
                    minHeap.push({max(height,heightMap[nx][ny]),{nx,ny}});
                }
            }
        }

        return totalWater;
    }
};
