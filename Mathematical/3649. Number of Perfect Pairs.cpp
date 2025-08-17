// Using Binary Search and discarding the O(k) time taken by distance function
class Solution {
private:
int getCount(int low,int high,vector<int>&nums,int target){

    int idx=-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(2*nums[mid]>=target){
            idx=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return idx;
}
public:
    long long perfectPairs(vector<int>& nums) {
        // on solving the both cases for all four conditions
        // a>=0 && b>=0 
        // a>=0 && b<=0
        // a<=0 && b>=0
        // a<=0 && b<=0

        // conclusion max(x1,y1)<=2*min(x1,y1)
        // x1=mod(a) and y1=mod(b)
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }

        sort(begin(nums),end(nums));

        // after sorting the cur elem is max just need to find the elements smaller than cur element that is >=curElem/2
        // we can use a multiset

        long long count=0;
        for(int i=0;i<n;i++){ 
            int idx=getCount(0,i-1,nums,nums[i]);

            if(idx==-1) continue;
            count+=(i-idx);
        }

        return count;
    }
};


// Brute force :
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        // on solving the both cases for all four conditions
        // a>=0 && b>=0 
        // a>=0 && b<=0
        // a<=0 && b>=0
        // a<=0 && b<=0

        // conclusion max(x1,y1)<=2*min(x1,y1)
        // x1=mod(a) and y1=mod(b)
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }

        sort(begin(nums),end(nums));

        // after sorting the cur elem is max just need to find the elements smaller than cur element that is >=curElem/2
        // we can use a multiset

        multiset<int> ms;
        int count=0;
        for(int i=0;i<n;i++){
            auto it=lower_bound(begin(ms),end(ms),nums[i]);

            if(it!=ms.end()){
                count+=distance(it,ms.end());
            }

            ms.insert(2*nums[i]);
        }

        return count;
    }
};
