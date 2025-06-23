class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();

        // bottom up approach
        unordered_map<int,int> dp;
        int maxLen=0;
        for(int i=0;i<n;i++){
            // for(int j=i-1;j>=0;j--){
            //     if((arr[i]-arr[j])==difference){
            //         dp[i]=max(dp[i],dp[j]+1);
            //     }
            // }

            int prev=arr[i]-difference;
            int cur=arr[i];

            if(dp.count(prev)){
                dp[cur]=max(dp[cur],dp[prev]+1);
            }
            else{
                dp[cur]=1;
            }

            maxLen=max(maxLen,dp[cur]);
        }

        return maxLen;
    }
};



class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();

        // bottom up approach

        vector<int> dp(n,1);

        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if((arr[i]-arr[j])==difference){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }


        int maxLen=*max_element(dp.begin(),dp.end());

        return maxLen;
    }
};
