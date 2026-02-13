
// Using segment Trees

class Solution {
private:
int n;
vector<int> segMax,segMin,lazy;

void buildSegmentTree(int nodeIdx,int l,int r,vector<int>&nums){
    if(l==r){
        segMax[nodeIdx]=nums[l];
        segMin[nodeIdx]=nums[l];
        return;
    }

    int mid=l+(r-l)/2;
    buildSegmentTree(2*nodeIdx+1,l,mid,nums);
    buildSegmentTree(2*nodeIdx+2,mid+1,r,nums);

    segMax[nodeIdx]=max(segMax[2*nodeIdx+1],segMax[2*nodeIdx+2]);
    segMin[nodeIdx]=min(segMin[2*nodeIdx+1],segMin[2*nodeIdx+2]);
}

void propagate(int nodeIdx,int l,int r){
    if(lazy[nodeIdx]!=0){
        segMax[nodeIdx]+=lazy[nodeIdx];
        segMin[nodeIdx]+=lazy[nodeIdx];

        if(l!=r){
            lazy[2*nodeIdx+1]+=lazy[nodeIdx];
            lazy[2*nodeIdx+2]+=lazy[nodeIdx];
        }
        lazy[nodeIdx]=0;
    }

}
void updateRange(int ql,int qr,int nodeIdx,int l,int r,int upVal){
    // propagation logic
    propagate(nodeIdx,l,r);

    if(ql>r || qr<l) return;

    if(l>=ql && r<=qr){
        segMax[nodeIdx]+=upVal;
        segMin[nodeIdx]+=upVal;

        if(l!=r){
            lazy[2*nodeIdx+1]+=upVal;
            lazy[2*nodeIdx+2]+=upVal;
        }
        return;
    }

    // partial overlap

    int mid=l+(r-l)/2;

    updateRange(ql,qr,2*nodeIdx+1,l,mid,upVal);
    updateRange(ql,qr,2*nodeIdx+2,mid+1,r,upVal);

    segMax[nodeIdx] = max(segMax[2 * nodeIdx + 1], segMax[2 * nodeIdx + 2]);
    segMin[nodeIdx] = min(segMin[2 * nodeIdx + 1], segMin[2 * nodeIdx + 2]);
}

int getLeftMostZeroIdx(int nodeIdx,int l,int r){
    propagate(nodeIdx,l,r);

    int maxi=segMax[nodeIdx];
    int mini=segMin[nodeIdx];

    if(maxi<0 || mini >0) return -1;

    if(l==r){
        return l;
    }

    int mid=l+(r-l)/2;
    int leftIdx=getLeftMostZeroIdx(2*nodeIdx+1,l,mid);
    if(leftIdx!=-1) return leftIdx;

    return getLeftMostZeroIdx(2*nodeIdx+2,mid+1,r);
}
public:
    int longestBalanced(vector<int>& nums) {
        n=nums.size();

        vector<int>cumSum(n,0);
        segMax.resize(4*n,0);
        segMin.resize(4*n,0);
        lazy.resize(4*n,0);
        buildSegmentTree(0,0,n-1,cumSum);

        unordered_map<int,int> mp;
        int maxLen=0;
        for(int r=0;r<n;r++){
            int val=(nums[r]&1) ? -1 : 1;

            int prev=-1;
            if(mp.count(nums[r])){
                prev=mp[nums[r]];
            }

            if(prev!=-1){
                // found the element previously
                // adding -val in the range [0...prev];
               updateRange(0,prev,0,0,n-1,-val);
            }

            // now add the val to cumSum int the range [0....r]
            updateRange(0,r,0,0,n-1,val);

            // we are trying to find the leftmost zero in the range [0....r]
            int leftIdx=getLeftMostZeroIdx(0,0,n-1);

            if(leftIdx!=-1){
                maxLen=max(maxLen,r-leftIdx+1);
            }

            mp[nums[r]]=r;
        }

        return maxLen;
    }
};


// approach 1 : Using brute force 
// time : O(n^2)
// space : O(n)
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();

        vector<int> cumSum(n,0);
        unordered_map<int,int> mp;

        int maxLen=0;

        for(int r=0;r<n;r++){
            int val=(nums[r]&1) ? -1 : 1;

            int prev=-1;
            if(mp.count(nums[r])){
                prev=mp[nums[r]];
            }

            if(prev!=-1){
                // found the element previously
                for(int l=0;l<=prev;l++){
                    cumSum[l]-=val;
                }
            }

            // now add the val to cumSum
            for(int l=0;l<=r;l++){
                cumSum[l]+=val;

                if(cumSum[l]==0){
                    maxLen=max(maxLen,r-l+1);
                }
            }

            mp[nums[r]]=r;
        }

        return maxLen;
    }
};
