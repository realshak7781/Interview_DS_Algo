
// Brute force : O(m+n)
// space : O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        int i=0,j=0;
        vector<int> res;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                res.push_back(nums1[i++]);
            }
            else{
               res.push_back(nums2[j++]); 
            }
        }

        while(i<n){
             res.push_back(nums1[i++]);
        }

        while(j<m){
             res.push_back(nums2[j++]); 
        }


        int totalSize=res.size();

        double med;
        int idx=totalSize/2;
        if(totalSize%2==0){
            med=(double)(res[idx]+res[idx-1])/2.0;
        }
        else{
            med=(double)res[idx];
        }

        return med;
    }
};
