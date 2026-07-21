// TIME : o(N*N*D)
// SPACE : o(N)

class Solution {
private:
bool check(vector<int>& arr,int i, int j){
    int ithVal=arr[i];
    int minIdx=min(i,j);
    int maxIdx=max(i,j);

    for(int k=minIdx;k<=maxIdx;k++){
        if(k!=i && arr[k]>=ithVal){
            return false;
        }
    }
    return true;
}
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();

        vector<pair<int,int>> jumpArr;
        vector<int> dp(n,1);

        for(int i=0;i<n;i++){
            jumpArr.push_back({arr[i],i});
        }

        sort(begin(jumpArr),end(jumpArr),greater<pair<int, int>>());

        for(int j=0;j<n;j++){
            int jth=jumpArr[j].second;
            int jthVal=jumpArr[j].first;

            int minRange=jth-d;
            int maxRange=jth+d;

            // we will jump from ith to jth
            int maxValJump=0;
            for(int i=0;i<j;i++){
                int ith=jumpArr[i].second;

                if(ith>=minRange && ith<=maxRange){
                    if(check(arr,ith,jth)){
                        maxValJump=max(maxValJump,1+dp[ith]);
                    }
                }
            }
            dp[jth]=max(dp[jth],maxValJump);
        }


        int maxi=*max_element(begin(dp),end(dp));

        return maxi;
    }
};
