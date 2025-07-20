using ll=long long;
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();

        vector<ll> leftMax(n);
        vector<ll> leftMin(n);

        leftMax[n-1]=leftMin[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            leftMax[i]=max((ll)nums[i],leftMax[i+1]);
            leftMin[i]=min((ll)nums[i],leftMin[i+1]);
        }

        ll res=LLONG_MIN;
        for(int i=0;i<n;i++){
            ll val=(ll)nums[i];
            int nextIdx=i+m-1;

            if(nextIdx>=n) break;

            ll prod1=val*leftMax[nextIdx];
            ll prod2=val*leftMin[nextIdx];

            res=max({res,prod1,prod2});
        }

        return res;
    }
};
