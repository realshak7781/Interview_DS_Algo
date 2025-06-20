using p=pair<int,pair<int,int>>;
class Solution {
private:
vector<vector<int>> optimised(vector<int>& nums1, vector<int>& nums2, int k){
    int m=nums1.size();
    int n=nums2.size();

    priority_queue<p,vector<p>,greater<p>> minHeap;
    int initialSum=nums1[0]+nums2[0];
    minHeap.push({initialSum,{0,0}});

    set<pair<int,int>> vis;
    vis.insert({0,0});

    vector<vector<int>> res;
    while(k && !minHeap.empty()){
        int i=minHeap.top().second.first;
        int j=minHeap.top().second.second;
        int sum=minHeap.top().first;

        minHeap.pop();
        k--;
        res.push_back({nums1[i],nums2[j]});


        if(i+1<m && !vis.count({i+1,j})){
            int newSum=nums1[i+1]+nums2[j];
            minHeap.push({newSum,{i+1,j}});
            vis.insert({i+1,j});
        }

          if(j+1<n && !vis.count({i,j+1})){
            int newSum=nums1[i]+nums2[j+1];
            minHeap.push({newSum,{i,j+1}});
            vis.insert({i,j+1});
        }
    }

    return res;
}    
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

        // return res;


        return optimised(nums1,nums2,k);
    }
};
