
// TIME: EXPONENTIAL
// SPACE : O(M*N)
class Solution {
private:
    unordered_map<int, unordered_set<char>> possibleDir;
    unordered_map<int, pair<int, int>> coordMp;

char getOpposite(char dir) {
    if (dir == 'L') return 'R';
    if (dir == 'R') return 'L';
    if (dir == 'U') return 'D';
    return 'U'; 
}
bool dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>& grid,int m,int n){
    if(i==m-1 && j==n-1) return true;

    vis[i][j]=true;

    for(auto &dir:possibleDir[grid[i][j]]){
        char oppositeDir=getOpposite(dir);
        int nx=i+coordMp[dir].first;
        int ny=j+coordMp[dir].second;
        if(nx<0 || nx>=m || ny<0 || ny>=n || vis[nx][ny]) continue;

        if(possibleDir[grid[nx][ny]].count(oppositeDir)){
            if(dfs(nx,ny,vis,grid,m,n)) return true;
        }
    }

    vis[i][j]=false;
    return false;
}
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        possibleDir = {{1, {'L', 'R'}}, {2, {'U', 'D'}}, {3, {'L', 'D'}},
                       {4, {'R', 'D'}}, {5, {'L', 'U'}}, {6, {'R', 'U'}}};

        coordMp = {
            {'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}};

        vector<vector<bool>> vis(m,vector<bool>(n,false));
        return dfs(0,0,vis,grid,m,n);
    }
};
