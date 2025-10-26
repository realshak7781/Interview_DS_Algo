

// Using the proability theory : Recursive Approach :
class Solution {
private:
vector<vector<int>> dir={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
const double p=1/8.0;
double solve(int i,int j,int n,int maxMove){
    if(i<0 || i>=n || j<0 ||j>=n) return 0;

    if(maxMove==0) return 1.0;

    double totalProb=0;

    for(auto d:dir){
        int nx=i+d[0];
        int ny=j+d[1];

        totalProb=(totalProb + p*solve(nx,ny,n,maxMove-1));
    }

    return totalProb;
}
public:
    double knightProbability(int n, int k, int row, int column) {
        return solve(row,column,n,k);
    }
};
