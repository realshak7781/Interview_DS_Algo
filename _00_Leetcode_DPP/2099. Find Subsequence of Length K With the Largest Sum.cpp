using p=pair<int,int>;
class Solution {  
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) return {};

        priority_queue<p,vector<p>,greater<p>> minHeap;

        for(int i=0;i<n;i++){
            int curElem=nums[i];

            if(minHeap.size()>=k){
                if(minHeap.top().first<curElem){
                    minHeap.pop();
                    minHeap.push({curElem,i});
                }
            }
            else{
                minHeap.push({curElem,i});
            }  
        }

        vector<int> res(n,INT_MIN);

        while(!minHeap.empty()){
            res[minHeap.top().second]=minHeap.top().first;
            minHeap.pop();
        }

        vector<int> result;
        for(int i=0;i<n;i++){
            if(res[i]!=INT_MIN){
                result.push_back(res[i]);
            }
        }

        return result;
    }

};
