// MATHEMATICAL :
using ll=long long;
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int N=n*n;

        ll sum=(N*(N+1))/2;
        ll gridSum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                gridSum+=grid[i][j];
            }
        }

        // first equation
        // sum+a-b=gridSum;
        // a-b=gridSum-sum= gs;

        // second equations similarly : two variables need two equations:
        // a^2-b^2=gridSQSUm-sqSum=gsq;

        ll sqSum=((ll)N*(N+1)*(2*N+1))/6;
        ll gridSqSum=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                gridSqSum+=(ll)(grid[i][j]*grid[i][j]);
            }
        }

        ll gs=gridSum-sum;
        ll gsq=gridSqSum-sqSum;

        // so b=(gsq-gs^2)/(2*gs)

        int b=(gsq-gs*gs)/(2*gs);
        int a=b+gs;

        return {a,b};

    }
};

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
