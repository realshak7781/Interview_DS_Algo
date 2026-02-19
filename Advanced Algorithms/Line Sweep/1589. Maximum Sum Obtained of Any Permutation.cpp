// time : O(Req) + O(maxi) + O(maxi*log(maxi)) + O(nlogn)
// space : O(maxi)

const int mod=1e9+7;
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
       
        int maxi=-1;
        for(auto &r:requests){
            maxi=max(maxi,r[1]);
        }
        vector<int> pref(maxi+1,0);

        int size=pref.size();
        // use the difference array technique to solve the range addition issue
        for(auto &req:requests){
            int l=req[0];
            int r=req[1];

            pref[l]+=1;
            if(r+1<size){
                pref[r+1]-=1;
            }
        }

        // take the cumSum
        for(int i=1;i<size;i++){
            pref[i]=pref[i]+pref[i-1];
        }

        // sort both the arrays
        sort(begin(pref),end(pref),greater<>());
        sort(begin(nums),end(nums),greater<>());

        int i=0,j=0;

        long long res=0;
        while(i<pref.size()){
            res=(res+1LL*pref[i]*nums[j])%mod;
            i++;
            j++;
        }

        return res;
    }
};
