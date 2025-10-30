using ll=long long;
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        ll ops=0;
        int n=nums.size();

        ll prev=0;
        for(int i=0;i<n;i++){
            ll cur=target[i]-nums[i];

            if((prev>0 && cur<0) || (prev<0 && cur>0)){
                ops+=abs(cur);
            }
            else if(abs(cur)>abs(prev)){
                ops+=(abs(cur)-abs(prev));
            }
            prev=cur;
        }

        return ops;
    }
};
