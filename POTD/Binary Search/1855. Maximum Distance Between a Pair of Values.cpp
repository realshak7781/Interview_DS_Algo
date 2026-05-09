// Python colution


// CPP solution
class Solution {
private:
int getIdx(int low,int n,vector<int>& arr,int target){
    if(low>=n) return -1;

    int high=n-1;
    int idx=-1;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]>=target){
            idx=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return idx;
}
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();

        int maxDist=0;
        for(int i=0;i<m;i++){
            int j=getIdx(i,n,nums2,nums1[i]);

            if(j!=-1){
                maxDist=max(maxDist,j-i);
            }
        }
        return maxDist;
    }
};
