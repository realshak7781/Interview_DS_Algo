
class Solution {
private:
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> state=grid;

        int mins=0;
        queue<vector<int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(state[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }


        while(!q.empty()){
            int x=q.front()[0];
            int y=q.front()[1];
            int t=q.front()[2];
            q.pop();

            mins=max(mins,t);

            for(auto &it:dir){
                int nx=x+it[0];
                int ny=y+it[1];

                if(nx>=0 && nx<m && ny>=0 && ny<n && state[nx][ny]==1){
                    // make it rooten
                    state[nx][ny]=2;
                    q.push({nx,ny,t+1});
                }
            }
        }

        bool hasFresh=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(state[i][j]==1){
                    hasFresh=true;
                    break;
                }
            }
        }

        return hasFresh?-1:mins;
    }
};
