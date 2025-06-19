using ll=long long;
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<
        pair<int,int>,int>> arr;

        for(int i=0;i<n;i++){
            arr.push_back({{nums1[i],nums2[i]},i});
        }

        sort(arr.begin(),arr.end());

        vector<ll> res(n);
        multiset<ll> st;

        ll sum=0;
        for(int i=0;i<n;i++){
            int n1Val=arr[i].first.first;
            int n2Val=arr[i].first.second;
            int idx=arr[i].second;

            // check for duplocate elements:

            if(i>0 && arr[i-1].first.first==n1Val){
                res[idx]=res[arr[i-1].second];
            }else{
                res[idx]=sum;
            }
            st.insert(n2Val);
            sum+=n2Val;

            if(st.size()>k){
                sum-= *st.begin();
                st.erase(st.begin());
            }
        }

        return res;
    }
};
