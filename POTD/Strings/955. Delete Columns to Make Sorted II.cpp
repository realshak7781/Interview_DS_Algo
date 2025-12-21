// Time : O(rows*cols)
// space : O(rows)

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cols=strs[0].length();
        int rows=strs.size();
        vector<bool> alreadySorted(rows-1,false);

        int ansSize=0;
        for(int col=0;col<cols;col++){
            bool deleted=false;

            for(int row=0;row<rows-1;row++){
                if(!alreadySorted[row] && strs[row][col] > strs[row+1][col]){
                    deleted=true;
                    ansSize++;
                    break;
                }
            }

            if(deleted) continue;

            for(int i=0;i<rows-1;i++){
                alreadySorted[i]=alreadySorted[i] | (strs[i][col] < strs[i+1][col]);
            }
        }

        return ansSize;
    }
};
