// Using only O(1) space
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // if we use the brute force approach then we are not using the sorted
        // nature of the arrays given to us , since linear time is not
        // acceptable , we will think for logarithmic time and specially binary
        // search :

        // story points:
        // we need to find out the numbers of elements from nums1 and nums2 that
        // we can have on left side of median and right side of median

        //   to equally split on left and right side of median
        // left side count of elements=(m+n+1)/2;

        int size = (m + n);
        int idx1 = (size / 2) - 1;
        int idx2 = (size / 2);
        int elem1 = -1, elem2 = -1;
        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                if (k == idx1) {
                    elem1 = nums1[i];
                } else if (k == idx2) {
                    elem2 = nums1[i];
                }
                i++;
            } else {
                if (k == idx1) {
                    elem1 = nums2[j];
                } else if (k == idx2) {
                    elem2 = nums2[j];
                }
                j++;
            }
            k++;
        }

        while (i < m) {
            if (k == idx1) {
                elem1 = nums1[i];
            } else if (k == idx2) {
                elem2 = nums1[i];
            }
            i++;
            k++;
        }

        while (j < n) {
            if (k == idx1) {
                elem1 = nums2[j];
            } else if (k == idx2) {
                elem2 = nums2[j];
            }
            j++;
            k++;
        }


        if(size&1){
            // size is odd
            return (double)elem2;
        }

        return (double)(elem1+elem2)/2.0;
    }
};


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
