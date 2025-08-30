class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.') continue;

                string row=to_string(i)+"ROW"+to_string(board[i][j]);
                string col=to_string(j)+"COL"+to_string(board[i][j]);
                string box=to_string(i/3)+to_string(j/3) +"BOX"+to_string(board[i][j]);

                if(seen.count(row)|| seen.count(col) || seen.count(box)) return false;

                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }

        seen.clear();

        return true;
    }
};
