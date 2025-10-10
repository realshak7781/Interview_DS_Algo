class Solution {
private:
vector<vector<bool>> vis;
int res;

bool check(int x,int y,int n){
    // check upper diagonal left
    int i=x;
    int j=y;

    while(i>=0 && j>=0){
        if(vis[i][j]) return false;
        i--;
        j--;
    }
    // check lower diagonal left
    i=x;
    j=y;
    while(i<n && j>=0){
        if(vis[i][j]) return false;
        i++;
        j--;
    }
    // check left side
    i=x;
    j=y;
    while(j>=0){
        if(vis[i][j]) return false;
        j--;
    }

    return true;
}
void solve(int col,int n,int k){
    // base case
    if(k<=0){
        res++;
        return;
    }
    if(col>=n) return;

    for(int r=0;r<n;r++){
        if(check(r,col,n)){
            vis[r][col]=true;
            solve(col+1,n,k-1);
            vis[r][col]=false;
        }
    }
}
public:
    int totalNQueens(int n) {
        vis.resize(n,vector<bool>(n,false));
        res=0;

        solve(0,n,n);

        return res;
    }
};
