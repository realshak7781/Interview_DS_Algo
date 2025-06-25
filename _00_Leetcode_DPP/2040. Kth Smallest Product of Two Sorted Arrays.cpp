// T.C: O(LOG(RANGE)*N*LOG(M))
// S.C: O(1)


using ll = long long;
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        int m = nums1.size();
        int n = nums2.size();

        // we need to make use of the sorted nature of the arrays
        //  we are not making the use of that in the heap approach
        // using the concept of binary search on answers
        ll low = -1e10, high = 1e10;

        ll res;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll count = getCount(nums1, nums2, k, mid);

            if (count>=k) {
               high=mid-1;
               res=mid;
            }
            else{
                low=mid+1;
            }
           
        }

        return res;
    }

private:
    ll getCount(vector<int>& nums1, vector<int>& nums2, long long k,
                ll reqProd) {
        ll totalCount = 0;

        for (int& num : nums1) {
            if (num >= 0) {
                ll left = 0, right = nums2.size() - 1;

                while (left <= right) {
                    ll mid = left + (right - left) / 2;
                    ll prod = 1LL * nums2[mid] * num;

                    if (prod <= reqProd) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                totalCount += left;
            } else {
                ll left = 0, right = nums2.size() - 1;

                while (left <= right) {
                    ll mid = left + (right - left) / 2;
                    ll prod = 1LL * nums2[mid] * num;

                    if (prod <= reqProd) {
                       right=mid-1;
                    } else {
                        left = mid +1;
                    }
                }

                totalCount += (nums2.size()-left);
            }
        }

        return totalCount;
    }
};


// BRUTE FORCE APPROACH : TLE
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
