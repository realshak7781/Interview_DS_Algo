
class Solution {
private:
vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>> heights(m,vector<int>(n,-1));


        // multisoucre bfs
        queue<vector<int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    // water and set height=0;
                    heights[i][j]=0;
                    q.push({i,j,0});
                }
            }
        }


        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            int h=q.front()[2];
            q.pop();


            for(auto &it:dir){
                int nx=i+it[0];
                int ny=j+it[1];

                if(nx>=0 && nx<m && ny>=0 && ny<n && heights[nx][ny]==-1){
                    heights[nx][ny]=h+1;
                    q.push({nx,ny,h+1});
                }
            }
        }

        return heights;
    }
};
