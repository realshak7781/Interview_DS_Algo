class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();

        vector<pair<int,int>> n2P;
        for(int i=0;i<n;i++){
            n2P.push_back({nums2[i],i});
        }
        sort(begin(n2P),end(n2P));
        sort(begin(nums1),end(nums1));

        vector<int> res(n,-1);
        vector<int> notUsed;
        int i=0;
        int j=0;
        while(i<n && j<n){

            if(nums1[i]<=n2P[j].first){
                notUsed.push_back(nums1[i]);
                i++;
            }
            else{
                int idx=n2P[j].second;
                res[idx]=nums1[i];
                i++;
                j++;
            }
        }

         // Fill in the remaining spots with the unused elements
        for (int k = 0; k < n; k++) {
            if (res[k] == -1) {
                res[k] = notUsed.back();
                notUsed.pop_back();
            }
        }
        
        return res;
    }
};
