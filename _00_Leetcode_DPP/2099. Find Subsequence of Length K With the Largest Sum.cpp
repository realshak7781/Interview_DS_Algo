// OPTIMAL : O(N) AVERAGE

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> temp=nums;

        nth_element(temp.begin(),temp.begin()+k-1,temp.end(),greater<int>());

        int kthLargest=temp[k-1];
        int count=0;

        for(int i=0;i<k;i++){
            if(temp[i]==kthLargest) count++;
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(res.size()==k) break;

            if(nums[i]>kthLargest){
                res.push_back(nums[i]);
            }
            else if(nums[i]==kthLargest){
                if(count>0){
                    res.push_back(nums[i]);
                    count--;
                }
            }
        }
        return  res;
    }
};





// BRUTE FORCE : O(NLOGK)
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
