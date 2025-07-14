//  time :O(nlogn)
// space : O(n)
using p=pair<int,int>;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<p> ms;
        // O(n) space
        int start=0;
        int n=nums.size();

        int len=0;

        for(int end=0;end<n;end++){

            ms.insert({nums[end],end});
            // o(logn) time

            int mini=ms.begin()->first;
            int maxi=ms.rbegin()->first;
            while(!ms.empty() && maxi-mini>limit){
                ms.erase({nums[start],start});
                // O(logn) time
                start++;

                if(!ms.empty()){
                    mini=ms.begin()->first;
                    maxi=ms.rbegin()->first;
                }
            }
            len=max(len,end-start+1);
        }

        return len;
    }
};
