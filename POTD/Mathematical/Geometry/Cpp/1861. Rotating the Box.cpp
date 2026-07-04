
// SIUUING BRUTE FORCE APPROACH
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();

        vector<vector<char>> res(m,vector<char>(n,'.'));

        for(int i=0;i<m;i++){
            int stones=0;
            for(int j=0;j<n;j++){
                if(boxGrid[i][j]=='#') stones++;

                if(boxGrid[i][j]=='*'){
                    // populate 
                    res[i][j]='*';
                    int col=j-1;
                    while(stones>0 && col>=0){
                        res[i][col]='#';
                        col--;
                        stones--;
                    }
                }
            }


            // checking if we have some stones left
            int col=n-1;
            while(stones>0 && col>=0){
                res[i][col]='#';
                col--;
                stones--;
            }
        }


        // rotate it by 90 degrees
        vector<vector<char>> rotatedRes(n,vector<char>(m));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rotatedRes[j][m-i-1]=res[i][j];
            }
        }

        return rotatedRes;
    }
};
