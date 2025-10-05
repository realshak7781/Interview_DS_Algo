class Solution {
private:
    void clear(queue<pair<int, int>>& q) {
        while (!q.empty())
            q.pop();
    }
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int n,m;
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& grid,
             vector<vector<int>>& heights, set<pair<int, int>>& vis) {

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int x = q.top().first;
                int y = q.top().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && !vis.count({nx,ny}) && heights[nx][ny]>=heights[x][y]){
                        grid[nx][ny]=true;
                        q.push({nx,ny});
                        vis.insert({nx,ny});
                    }
                }
            }
        }
    }
public : 
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        this->n=n;
        this->m=m;

        vector<vector<bool>> pacificVis(n, vector<bool>(m, false));
        vector<vector<bool>> atlantaVis(n, vector<bool>(m, false));

        queue<pair<int, int>> q;
        set<pair<int, int>> st;
        // first row and first col
        for (int j = 0; j < m; j++) {
            q.push({0, j});
            st.insert({0, j});
            pacificVis[0][j] = true;
        }
        for (int i = 0; i < n; i++) {
            q.push({i, 0});
            st.insert({i, 0});
            pacificVis[i][0] = true;
        }
        bfs(q, pacificVis, heights, st);

        clear(q);
        st.clear();
        // last col and last row
        for (int i = 0; i < n; i++) {
            q.push({i, m - 1});
            st.insert({i, m - 1});
            atlantaVis[i][m - 1] = true;
        }
        for (int j = 0; j < m; j++) {
            q.push({n - 1, j});
            st.insert({n - 1, j});
            atlantaVis[n - 1][j] = true;
        }

        bfs(q, atlantaVis, heights, st);
    }
};
