


// BRUTE FORCE APPROACH
T.C : O(N*M*LOG(K))
S.C : O(K)
using ll=long long;
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        priority_queue<ll> maxHeap;

        int m=nums1.size();
        int n=nums2.size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ll prod=(ll)nums1[i]*nums2[j];

                if(maxHeap.size()==k){
                    if(!maxHeap.empty() && prod<maxHeap.top()){
                        maxHeap.pop();
                        maxHeap.push(prod);
                    }
                }
                else{
                    maxHeap.push(prod);
                }
            }
        }

        return maxHeap.top();
    }
};
