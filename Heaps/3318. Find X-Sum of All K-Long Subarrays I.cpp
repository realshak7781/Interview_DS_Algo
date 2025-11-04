// O((n-k)*(logk+logk + k))
using p=pair<int,int>;
class Solution {
private:
multiset<p> ms;
unordered_map<int,int> freq;
int calculateXSum(int x){
    int xSum=0;
    int count=0;
    for(auto it=ms.rbegin();it!=ms.rend()&& count<x;it++){
        int freq=it->first;
        int elem=it->second;

        xSum+=(freq*elem);
        count++;
    }

    return xSum;
}
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();

        for(int i=0;i<k;i++){
            freq[nums[i]]++;
        }
        for(auto it:freq){
            ms.insert({it.second,it.first});
        }

        vector<int> ans(n-k+1,0);
        ans[0]=calculateXSum(x);


        for(int i=1;i<(n-k+1);i++){
            int prevIdx=i-1;
            int nextIdx=i+k-1;

            // first erase both the prev elem and next elem
            int prevElem=nums[prevIdx];
            int nextElem=nums[nextIdx];
            int prevFreq=freq[prevElem];

            if (prevElem == nextElem) {
            ans[i] = ans[i-1];
            continue; 
            }

            auto prevP=ms.find({prevFreq,prevElem});
            if(prevP!=ms.end()){
                ms.erase(prevP);
            }

            
            int nextFreq=freq[nextElem];
            auto nextP=ms.find({nextFreq,nextElem});

            if(nextP!=ms.end()){
                ms.erase(nextP);
            }

            // now add new freq of both prev and next elem
            freq[prevElem]--;

            if(freq[prevElem]==0){
                freq.erase(prevElem);
            }
            else{
                ms.insert({freq[prevElem],prevElem});
            }

            freq[nextElem]++;
            ms.insert({freq[nextElem],nextElem});

            ans[i]=calculateXSum(x);
        }


        return ans;
    }
};


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
