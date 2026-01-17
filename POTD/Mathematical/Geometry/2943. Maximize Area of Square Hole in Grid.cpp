// Using Pure Maths and Brains
class Solution {
private:
int getMaxSideLen(vector<int> bars){
    int size=bars.size();
    sort(begin(bars),end(bars));

    int curLen=1;
    int maxLen=1;

    for(int i=1;i<size;i++){
        if(bars[i]==bars[i-1]+1){
            curLen++;
        }
        else{
            curLen=1;
        }

        maxLen=max(maxLen,curLen);
    }

    return maxLen+1;
}
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // theory for the question
        // we will start with the max Height that is achievable : min(n+1,m+1);
        // then for height h we need to be able to :
            //   ---> remove continuous h-1 rods from hBars;
            // ------> remove continuous h-1 rods from Vbars;
        // FOR CONTINUITY SORT BOTH THE ARRAYS

        int verticalSideLen=getMaxSideLen(vBars);
        int horizontalSideLen=getMaxSideLen(hBars);

        int side=min(verticalSideLen,horizontalSideLen);

        return side*side;
    }
};
