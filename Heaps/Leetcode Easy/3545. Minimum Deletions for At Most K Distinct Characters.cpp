// Optimised Approach :
// T.c : 
class Solution {
public:
    int minDeletion(string s, int k) {
       priority_queue<int,vector<int>,greater<int>> pq;
       unordered_map<char,int> freq;

       for(char c:s) freq[c]++;

       for(auto it:freq){
           // O(nlogn)
        pq.push(it.second);
       }

       int totalDel=0;
       while(pq.size()>k){
        totalDel+=pq.top();
        pq.pop();
       }

       return totalDel;
    }
};

// Brute force : O(k*n)
class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> freq;

        for(char c:s) freq[c]++;;

        int totalDel=0;
        
        while(freq.size()>k){

            int minFreq=INT_MAX;
            char c;
            for(auto it:freq){
                if(it.second<minFreq){
                    minFreq=it.second;
                    c=it.first;
                }
            }
            freq.erase(c);
            totalDel+=minFreq;
        }

        return totalDel;
    }
};
