//Approach-1 (Using Xor Property)
//T.C : O(n)
//S.C : O(1)

Code:
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xorRes = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        // traverse the first array and see the elements which contribute to
        // xorRes if for each first array elem ,size2 is even it doesnt
        // contribute else it does

        if (size2 & 1) {
            for (int i = 0; i < size1; i++) {
                xorRes ^= nums1[i];
            }
        }

        if (size1 & 1) {
            for (int i = 0; i < size2; i++) {
                xorRes ^= nums2[i];
            }
        }

        return xorRes;
    }
};
