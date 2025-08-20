
//Using Binary Search
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();

        sort(begin(citations),end(citations));

        int low=0,high=n-1;
        int res=0;

        while(low<=high){
            int mid=low+(high-low)/2;
            int pC=n-mid;
            int hI=citations[mid];

            if(hI>=pC){
                res=pC;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }


        return res;
    }
};

// Brute force : time : O(n^2)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();

        // the count of papers pblished can be from 1 to n

        for(int pCount=n;pCount>=1;pCount--){
            // the researcher has published pCount papers ,now atleast pCount paper,cites pCount times

            int paperCount=0;
            int citReq=pCount;
            for(int i=0;i<n;i++){
                // count papers where paprr i has been cited paperCount times atleast

                if(citations[i]>=citReq){
                    paperCount++;
                }
            }

            if(paperCount>=pCount) return pCount;
        }

        return 0;
    }
};
