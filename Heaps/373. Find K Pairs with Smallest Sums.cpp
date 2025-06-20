using p=pair<int,pair<int,int>>;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p> minHeap;

        int m=nums1.size();
        int n=nums2.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=nums1[i]+nums2[j];

                if(minHeap.size()<k){
                    minHeap.push({sum,{i,j}});
                }
                else if(minHeap.size()>=k){
                    if(minHeap.top().first>sum){
                        minHeap.pop();
                        minHeap.push({sum,{i,j}});
                    }else{
                        // taking the help of the sorted nature of given arrays
                        break;
                    }
                }
            }
        }

        vector<vector<int>> res;
        while(!minHeap.empty()){
            int sum=minHeap.top().first;
            int i=minHeap.top().second.first;
            int j=minHeap.top().second.second;
            minHeap.pop();
            res.push_back({nums1[i],nums2[j]});
        }

        return res;
    }
};
