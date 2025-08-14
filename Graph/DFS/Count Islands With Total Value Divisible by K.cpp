using ll=long long;
class Solution {
private:
vector<vector<bool>> vis;
vector<vector<int>> dir;
ll dfs(int i,int j,vector<vector<int>>& grid,int m,int n){
    
    vis[i][j]=true;
    ll sum=grid[i][j];
    for(auto &d:dir){
        int nx=i+d[0];
        int ny=j+d[1];

        if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=0 && vis[nx][ny]==false){
            sum+=dfs(nx,ny,grid,m,n);
        }
    }

    return sum;
}
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vis=vector<vector<bool>> (m,vector<bool>(n,false));
        dir={{-1,0},{0,1},{1,0},{0,-1}};
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false && grid[i][j]!=0){
                    ll sumLandVal=dfs(i,j,grid,m,n);

                    if(sumLandVal%k==0){
                        res++;
                    }
                }
            }
        }

        return res;
    }
};
