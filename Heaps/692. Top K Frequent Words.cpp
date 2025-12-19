// Time Complexity : O(NlogK)
// space : O(n+k)
using p=pair<int,string>;
struct MinHeapComparator {
        bool operator()(const p& a, const p& b) {

            if (a.first != b.first)
                return a.first > b.first; 

            return a.second < b.second; 
        }
    };
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(string s:words){
            freq[s]++;
        }

        priority_queue<p,vector<p>,MinHeapComparator> minHeap;

        for(auto it:freq){
            string s=it.first;
            int count=it.second;

            if(minHeap.size()<k){
                minHeap.push({count,s});
            }
            else{
                if(minHeap.top().first<count){
                    minHeap.pop();
                    minHeap.push({count,s});
                }
                else if(minHeap.top().first==count){
                    if(minHeap.top().second > s){
                        minHeap.pop();
                        minHeap.push({count,s});
                    }
                }
            }
        }

        vector<string> res;
        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        sort(res.begin(),res.end(),[&](const string &a,const string &b){
            int aF=freq[a];
            int bF=freq[b];

            if(aF!=bF){
                return aF>bF;
            }

            return a < b;
        });

        return res;
    }
};
