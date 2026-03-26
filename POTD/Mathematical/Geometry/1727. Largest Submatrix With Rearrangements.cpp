// without sorting 
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        int resArea=0;
        vector<pair<int,int>> prevHeightPairs;

        for(int i=0;i<rows;i++){
            vector<pair<int,int>> curHeightPairs;
            vector<bool> seen(cols,false);

            for(auto &[h,c]:prevHeightPairs){
                if(matrix[i][c]==0) continue;
                curHeightPairs.push_back({matrix[i][c]+h,c});
                seen[c]=true;
            }


            for(int k=0;k<cols;k++){
                if(!seen[k] && matrix[i][k]!=0){
                    curHeightPairs.push_back({matrix[i][k],k});
                }
            }

            int minHeight=1e9;
            for(int j=0;j<curHeightPairs.size();j++){
                auto [curHeight,c]=curHeightPairs[j];

                minHeight=min(minHeight,curHeight);
                int base=j+1;

                resArea=max(resArea,minHeight*base);
            }


            prevHeightPairs=curHeightPairs;
        }

        return resArea;
    }
};


// Reduce the time complexity from O(rows*cols) --------> O(cols)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();


        vector<int> prevHeight(cols,0);
        int resArea=0;
        for(int i=0;i<rows;i++){
            vector<int> curHeight(cols,0);


            // poplulatimg the curHeight
            for(int k=0;k<cols;k++){
                if(matrix[i][k]==0) continue;

                curHeight[k]=matrix[i][k]+prevHeight[k];
            }

            prevHeight=curHeight;
            sort(begin(curHeight),end(curHeight),greater<int>());
            // sortting logic

            int minHeight=1e9;
            int base=0;

            for(int j=0;j<cols;j++){
                int curHeightVal=curHeight[j];
                if(curHeightVal==0){
                    base=0;
                    minHeight=1e9;
                }else{
                    minHeight=min(curHeightVal,minHeight);
                    base+=1;

                    resArea=max(resArea,base*minHeight);
                }
            }
        }


        return resArea;
    }
};


// Time : O(r*col*log(r))
// space : O(r*c)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<vector<int>> height=matrix;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0) continue;

                int prevColVal= (i>0 ? height[i-1][j] : 0);
                height[i][j]+=prevColVal;
            }
        }

        int resArea=0;
        for(int i=0;i<rows;i++){
            auto vec=height[i];
            sort(begin(vec),end(vec),greater<int>());

            int minHeight=1e9;
            int base=0;

            for(int j=0;j<cols;j++){
                int curHeight=vec[j];
                if(curHeight==0){
                    base=0;
                    minHeight=1e9;
                }else{
                    minHeight=min(curHeight,minHeight);
                    base+=1;

                    resArea=max(resArea,base*minHeight);
                }
            }
        }


        return resArea;
    }
};
