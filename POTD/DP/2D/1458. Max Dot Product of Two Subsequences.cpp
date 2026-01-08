// approach 2 : Using tabulation dp approach

class Solution {
private:

    int tab(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1e9));
        for (int j = 0; j <= n; j++)
            dp[m][j] = -1e9;
        for (int i = 0; i <=m; i++)
            dp[i][n] = -1e9;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int maxDotProdSum = nums1[i] * nums2[j] +
                                    max(0, dp[i+1][j+1]);
                ;
                // skip i
                maxDotProdSum =
                    max(maxDotProdSum, dp[i+1][j]);
                // skip j
                maxDotProdSum =
                    max(maxDotProdSum, dp[i][j+1]);
                // skip both
                maxDotProdSum =
                    max(maxDotProdSum, dp[i+1][j+1]);

                dp[i][j] = maxDotProdSum;
            }

        }

        return dp[0][0];
    }

public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
       return tab(nums1,nums2);
    }
};


// approach 1 : Using recursion + memoization
// time : o(m*n)
// space : O(m*n) + recursive call stack O(max(m,n))
class Solution {
private:
int dp[501][501];
int solve(int i,int j,vector<int>& nums1, vector<int>& nums2){
    if(i>=nums1.size() || j>=nums2.size()){
        return -1e9;
    }

    if(dp[i][j]!=-1) return dp[i][j];
    // pick both and take dot prod;
    int maxDotProdSum=nums1[i]*nums2[j] + max(0, solve(i + 1, j + 1, nums1, nums2));;
    // skip i
    maxDotProdSum=max(maxDotProdSum,solve(i+1,j,nums1,nums2));
    // skip j
    maxDotProdSum=max(maxDotProdSum,solve(i,j+1,nums1,nums2));
    // skip both
    maxDotProdSum=max(maxDotProdSum,solve(i+1,j+1,nums1,nums2));


    return dp[i][j]=maxDotProdSum;

}
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums1,nums2);
    }
};
