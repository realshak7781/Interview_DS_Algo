class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea=0;
        int diagSq=0;

        for(auto &it:dimensions){
            int l=it[0];
            int b=it[1];

            int diagLenSq=l*l + b*b;

            if(diagLenSq>diagSq){
                diagSq=diagLenSq;
                maxArea=l*b;
            }
            else if(diagLenSq==diagSq){
                maxArea=max(maxArea,l*b);
            }
        }

        return maxArea;
    }
};
