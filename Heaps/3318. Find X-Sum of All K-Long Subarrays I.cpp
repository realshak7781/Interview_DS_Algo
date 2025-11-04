


// Brute force (O(N*(N+N*logx))
using p=pair<int,int>;
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans(n-k+1,0);

        for(int i=0;i<(n-k+1);i++){
            unordered_map<int,int> freq;

            for(int j=i;j<(i+k);j++){
                freq[nums[j]]++;
            }

            priority_queue<p,vector<p>,greater<p>> minHeap;

            for(auto it:freq){
                if(minHeap.size()<x){
                    minHeap.push({it.second,it.first});
                }
                else{
                    int curFreq=it.second;

                    if(it.second>minHeap.top().first){
                        minHeap.pop();
                        minHeap.push({it.second,it.first});
                    }
                    else if(it.second==minHeap.top().first){
                        if(minHeap.top().second<it.first){
                            minHeap.pop();
                            minHeap.push({it.second,it.first});
                        }
                    }
                }
            }

            int xSum=0;
            while(!minHeap.empty()){
                auto tp=minHeap.top();
                xSum+=(tp.second*tp.first);
                minHeap.pop();
            }

            ans[i]=xSum;
        }

        return ans;
    }
};
