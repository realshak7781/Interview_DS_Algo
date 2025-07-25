class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // walls be shown by : 1
        // and gaurds be shown by 2
        // and empty cells shown by -1;
        // the places wherre gaurds will be able to see is marked as : 0
        vector<vector<int>> vec(m,vector<int>(n,-1));

        for(auto &it:guards){
            int i=it[0];
            int j=it[1];
            vec[i][j]=2;
        }

          for(auto &it:walls){
            int i=it[0];
            int j=it[1];
            vec[i][j]=1;
        }
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(auto &it:guards){
            int i=it[0];
            int j=it[1];

            for(auto &d:dir){
                int nx=i+d[0];
                int ny=j+d[1];

                while(nx>=0 && nx<m && ny>=0 && ny<n && vec[nx][ny]!=1 && vec[nx][ny]!=2){
                    vec[nx][ny]=0;
                    nx=nx+d[0];
                    ny=ny+d[1];
                }
            }
        }


        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vec[i][j]==-1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
