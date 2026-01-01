// Approach 2 : Using Multisource BFS + Binary Search over days + Lazy processing for days 
// C: Cells.size
// time : O(Log(C)*(M*N)
// space : O(M*n)
using p = pair<int, int>;
class Solution {
private:
    vector<p> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool possible(int row, int col, vector<vector<int>>& grid,int curDay) {
        // basically usign Multi source BFS because of having many source initially and since it is grid problem
        // and the q was talking about source and destination : thought of dijkstra but since the grid is unweighted
        // each move {left,right,up,down} has the same weight : so using  a BFS from multiple sources
        
        queue<p> q;
        vector<vector<bool>> vis(row, vector<bool>(col, false));

        for (int c = 0; c < col; c++) {
            if (grid[0][c]>curDay) {
                q.push({0, c});
                vis[0][c] = true;
            }
        }

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                if (r == row - 1)
                    return true;

                for (auto d : dir) {
                    int nx = r + d.first;
                    int ny = c + d.second;

                    if (nx >= 0 && nx < row && ny >= 0 && ny < col &&
                        grid[nx][ny]>curDay && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {


        vector<vector<int>> timeGrid(row,vector<int>(col,INT_MAX));
        for(int d=0;d<cells.size();d++){
            int r=cells[d][0]-1;
            int c=cells[d][1]-1;
            // 1 based

            timeGrid[r][c]=d+1;
            // using time based Lazy analysis
        }

        int resDay=0;
        int low=1,high=cells.size();

        while(low<=high){
            int mid=low+(high-low)/2;

            if(possible(row,col,timeGrid,mid)){
                resDay=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return resDay;
    }
};

// Approach 1 : Using Multisource BFS + simple loop over days
// time : O(C*(M*N)
// space : O(M*n)

using p = pair<int, int>;
class Solution {
private:
    vector<p> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool possible(int row, int col, vector<vector<int>>& grid) {
        // basically usign Multi source BFS because of having many source initially and since it is grid problem
        // and the q was talking about source and destination : thought of dijkstra but since the grid is unweighted
        // each move {left,right,up,down} has the same weight : so using  a BFS from multiple sources
        
        queue<p> q;
        vector<vector<bool>> vis(row, vector<bool>(col, false));

        for (int c = 0; c < col; c++) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                vis[0][c] = true;
            }
        }

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                if (r == row - 1)
                    return true;

                for (auto d : dir) {
                    int nx = r + d.first;
                    int ny = c + d.second;

                    if (nx >= 0 && nx < row && ny >= 0 && ny < col &&
                        grid[nx][ny] == 0 && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {


        vector<vector<int>> grid(row,vector<int>(col,0));
        int resDay=0;
        for(int d=0;d<cells.size();d++){
            int r=cells[d][0]-1;
            int c=cells[d][1]-1;

            grid[r][c]=1;

            if(possible(row,col,grid)){
                resDay=d+1;
            }
            else{
                return resDay;
            }
        }

        return resDay;
    }
};
