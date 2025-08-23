const int inf=INT_MAX;
class Solution {
private:
int minArea(int rs,int re,int cs,int ce,vector<vector<int>>&grid){

        int totalArea=0;
        int rowMin=50;
        int rowMax=-1;
        int colMin=50;
        int colMax=-1;

        for(int i=rs;i<re;i++){
            for(int j=cs;j<ce;j++){
                if(grid[i][j]==0) continue;

                rowMin=min(rowMin,i);
                rowMax=max(rowMax,i);
                colMin=min(colMin,j);
                colMax=max(colMax,j);
            }
        }

        if(rowMax!=50 && rowMin!=-1 && colMax!=50 && colMin!=-1)totalArea=(rowMax-rowMin+1)*(colMax-colMin+1);
        return totalArea;
}

int solve(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();

    int res=inf;

    // solve the three cases
    // case 1:
    for(int rowSplit=1;rowSplit<m;rowSplit++){
        for(int colSplit=1;colSplit<n;colSplit++){
            int top=minArea(0,rowSplit,0,n,grid);
            int bottomLeft=minArea(rowSplit,m,0,colSplit,grid);
            int bottomRight=minArea(rowSplit,m,colSplit,n,grid);

            res=min(res,top+bottomLeft+bottomRight);
        }
    }

    // case 2:
     for(int rowSplit=1;rowSplit<m;rowSplit++){
        for(int colSplit=1;colSplit<n;colSplit++){
            int topLeft=minArea(0,rowSplit,0,colSplit,grid);
            int topRight=minArea(0,rowSplit,colSplit,n,grid);
            int bottom=minArea(rowSplit,m,0,n,grid);

            res=min(res,topLeft+topRight+bottom);
        }
    }


    // case 3:
    for(int rowSplit1=1;rowSplit1<m;rowSplit1++){
        for(int rowSplit2=1;rowSplit2<m;rowSplit2++){
            int top=minArea(0,rowSplit1,0,n,grid);
            int middle=minArea(rowSplit1,rowSplit2,0,n,grid);
            int last=minArea(rowSplit2,m,0,n,grid);

            res=min(res,top+middle+last);
        }
    }

    return res;
}

auto rotateGrid(vector<vector<int>>&grid){
    int rows=grid.size();
    int cols=grid[0].size();

    vector<vector<int>> rot(cols,vector<int>(rows));

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            rot[j][i]=grid[i][j];
        }
    }

    for(auto &vec:rot){
        reverse(begin(vec),end(vec));
    }

    return rot;
}
public:
    int minimumSum(vector<vector<int>>& grid) {

        int result=inf;
        result=min(result,solve(grid));

        // rotate the grid clockwise 90 degrees
        grid=rotateGrid(grid);

        result=min(result,solve(grid));


        return result;
    }
};
