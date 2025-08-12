
// Brute force approach : Using extra space because of Powers array:
const int mod=1e9+7;
class Solution {
private:
vector<vector<int>> dp;
int findWays(int idx,vector<int>&arr,int target){
    if(target==0){
        return 1;
    }

    if(idx>=arr.size()){
        return 0;
    }

    string key=to_string(idx)+"#"+to_string(target);

    if(dp[idx][target]!=-1) return dp[idx][target];

    int pick=0;
    if(arr[idx]<=target){
        pick=(pick + (findWays(idx+1,arr,target-arr[idx]))%mod)%mod;
    }

    int notPick=findWays(idx+1,arr,target)%mod;

    return dp[idx][target]=(pick+notPick)%mod;
}
public:
    int numberOfWays(int n, int x) {
        int maxRange=pow(n,1.0/x);
        vector<int> powers;

        for(int i=1;i<=(maxRange+1);i++){
            int powVal=(int)pow(i,x)%mod;
            powers.push_back(powVal);
        }

        // Now its basically like subset sum
        // ways to form a target from a iven arrray
        int m=powers.size();
        dp=vector<vector<int>> (m+1,vector<int>(n+1,-1));
        return findWays(0,powers,n)%mod;
    }

};
