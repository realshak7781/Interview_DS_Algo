

//BRUTE FORCE : O(N*2) EXTRA SPACE
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> pres(n*n+1,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pres[grid[i][j]]++;
            }
        }

        int a,b;

        for(int i=1;i<=n*n;i++){
            if(pres[i]==0){
                b=i;
            }
            else if(pres[i]==2){
                a=i;
            }
        }


        return {a,b};
    }
};
