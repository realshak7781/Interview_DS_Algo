// OPTIMAL APPROACH:
// TIME : O(Q*SQRT(N))

const int mod=1e9+7;
using ll=long long;
struct Node{
    int l, r, v;

    Node(int l, int r, int v) : l(l), r(r), v(v) {}
};

class Solution {
private:
ll findPow(ll a,ll b){
    if(b==0) return 1;

    ll half=findPow(a,b/2)%mod;
    ll result=(1LL*half*half)%mod;

    if(b&1){
        result=(1LL*result*a)%mod;
    }
    return result;
}
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        unordered_map<int,vector<Node>> mp;
        // a map of {k,diff vector array}

        // processing the queries
        int T=floor(sqrt(n));

        for(auto &q:queries){
            int l=q[0];
            int r=q[1];
            int k=q[2];
            int v=q[3];

            if(k<T){
                mp[k].emplace_back(l,r,v);
            }else{
                // the time complexity here can be at max O(n*sqrt(n));
                int idx=l;
                while(idx<=r){
                    nums[idx]=(1LL*nums[idx]*v)%mod;
                    idx+=k;
                }
            }
        }


        // now processing the difference array for each k
        for(auto &it:mp){
            int k=it.first;
            auto vec=it.second;
            // now this vec contains {l,r,v};
            // we will create the difference array and do the math
            // then save the changes to nums
            vector<int> diff(n,1);

            for(auto &node:vec){
                int l=node.l;
                int r=node.r;
                int v=node.v;
                int stopIdx= l + (floor((r-l)/k)+1)*k;
                diff[l]=(1LL*diff[l]*v)%mod;

                if(stopIdx<n){
                    int vInv=findPow(v,mod-2);
                    diff[stopIdx]=(1LL*diff[stopIdx]*vInv)%mod;
                }
            }

            // now lets build the diff arrray first
            for(int i=0;i<n;i++){
                int prevIdx=i-k;
                if(prevIdx<0) continue;

                diff[i]=(1LL*diff[i]*diff[i-k])%mod;
            }
            // now make those changes for this k to nums

             for(int i=0;i<n;i++){
                nums[i]=(1LL*nums[i]*diff[i])%mod;
            }
        }


        int xorVal=0;
        for(int val:nums){
            xorVal=xorVal^val;
        }
        return xorVal;
    }
};

// Brute force Approach
// TIME : O(Q*N)

const int mod=1e9+7;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
         for(auto &q:queries){
            int l=q[0];
            int r=q[1];
            int k=q[2];
            int v=q[3];

            int idx=l;
            while(idx<=r){
                nums[idx]=(1LL*nums[idx]*v)%mod;
                idx+=k;
            }
        }

        int xorVal=0;
        for(int n:nums){
            xorVal^=n;
        }
        return xorVal;
    }
};
