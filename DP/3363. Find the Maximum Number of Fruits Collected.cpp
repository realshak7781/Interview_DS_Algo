class Solution {
private:
vector<vector<int>> dp;
int solve2(int i,int j,vector<vector<int>>& fruits,int n){
    if(i<0 || i>=n || j<0 || j>=n) return 0;


    if(dp[i][j]!=-1) return dp[i][j];

    int val=fruits[i][j];

    int res=0;

    if(i==j){
        res=max(res,solve2(i+1,j+1,fruits,n));
    }
    else if(i==j-1){
        res=max({res,
             solve2(i+1,j,fruits,n),
             solve2(i+1,j+1,fruits,n)
        });
    }
    else{
        res=max({res,
              solve2(i+1,j+1,fruits,n),
               solve2(i+1,j,fruits,n),
                solve2(i+1,j-1,fruits,n)
        });
    }

    return dp[i][j]=res+val;
}


int solve3(int i,int j,vector<vector<int>>& fruits,int n){
    if(i<0 || i>=n || j<0 || j>=n) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    int val=fruits[i][j];

    int res=0;

    if(i==j){
        res=max(res,solve3(i+1,j+1,fruits,n));
    }
    else if(j==i-1){
        res=max({res,
             solve3(i,j+1,fruits,n),
             solve3(i+1,j+1,fruits,n)
        });
    }
    else{
        res=max({res,
              solve3(i+1,j+1,fruits,n),
               solve3(i,j+1,fruits,n),
                solve3(i-1,j+1,fruits,n)
        });
    }

    return dp[i][j]=res+val;
}
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        // story points:
        // the children 1 will always move diagonally and collect all the fruits
        // the other two children will never visit the diagonal even though they can ,but greedily they wont because the fruits would have been taken by first child so going there wont get you anything
        // and also by observation you will see that since the no of moves is limited to (n-1) the other two child will never cross the digaonal regions that are upper triangular region and lower triangular region : so each children can have their own dp
        // The 3 children's paths no matter how they move will touch the main diagonal atleast once.

        // ACTION POINTS:

        // for the FIRST CHILDREN COLLECT ALL FRUITS ON THE DIAGONAL
        int i=0,j=0;
        int totalFruits=0;
        while(i<n && j<n){
            totalFruits+= fruits[i][j];
            fruits[i][j]=0;
            i+=1;
            j+=1;
        }

        dp=vector<vector<int>> (n+1,vector<int>(n+1,-1));

        // for the upper triangular matric and its child at top right corner 
        // perform dp to get the max collected

        totalFruits+=solve2(0,n-1,fruits,n);


        totalFruits+=solve3(n-1,0,fruits,n);

        return totalFruits;
    }
};
