class Solution {
private:
    bool row[10][10];
    bool col[10][10];
    bool box[10][10];
    bool solve(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.')
                    continue;

                for (int num = 1; num <=9; num++) {
                    board[i][j] = '0' + num;

                    int boxIdx=3*(i/3) + (j/3);
                    if(row[board[i][j]-'0'][i] ||  col[board[i][j]-'0'][j] || box[board[i][j]-'0'][boxIdx]) continue;


                    row[board[i][j]-'0'][i]=true;
                    col[board[i][j]-'0'][j]=true;
                    box[board[i][j]-'0'][boxIdx]=true;

                    if (solve(board)) return true;

                    row[board[i][j]-'0'][i]=false;
                    col[board[i][j]-'0'][j]=false;
                    box[board[i][j]-'0'][boxIdx]=false;
                }
                board[i][j] = '.';
                return false;
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {


        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        memset(box,false,sizeof(box));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                row[board[i][j]-'0'][i]=true;
                col[board[i][j]-'0'][j]=true;
                int boxIdx=3*(i/3) + (j/3);
                box[board[i][j]-'0'][boxIdx]=true;
            }
        }

        solve(board);
    }
};
