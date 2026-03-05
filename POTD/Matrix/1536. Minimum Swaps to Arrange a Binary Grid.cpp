// Time : O(m*n)
// space : o(m)

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int> trailZeroes(m,0);

        for(int i=0;i<m;i++){
            int zeroCount=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1) break;
                zeroCount++;
            }
            trailZeroes[i]=zeroCount;
        }

        int minSteps=0;

        for(int i=0;i<m;i++){
            int zeroNeeds=n-i-1;
            if(trailZeroes[i]>=zeroNeeds) continue;

            // else try to find the closest neighbour
            int idx=-1;
            for(int j=i+1;j<n;j++){
                if(trailZeroes[j]>=zeroNeeds){
                    idx=j;
                    break;
                }
            }

            if(idx==-1) return -1;

            minSteps+=(idx-i);

            while(idx>0){
                swap(trailZeroes[idx],trailZeroes[idx-1]);
                idx--;
            }
        }

        return minSteps;
    }
};
