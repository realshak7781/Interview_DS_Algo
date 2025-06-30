// optimal
// o(n)
// o(1)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int left=0;
        int right=0;
        int maxLen=0;

        while(right<n){
            int diff=nums[right]-nums[left];
            if(diff==1){
                maxLen=max(maxLen,right-left+1);
                right++;
            }
            else if(diff<1){
                right++;
            }
            else{
                left++;
            }
        }

        return maxLen;
    }
};




// BETTER : O(NLOGN)
// space : o(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        unordered_map<int,int> occ;
        int maxLen=0;
        for(int i=0;i<n;i++){
            // we want max -min=1
            // take the cur element as max then min=max-1;
            int mini=nums[i]-1;
            // try to find does mini exist in the map
            if(occ.count(mini)){
                int len=i-occ[mini]+1;
                maxLen=max(maxLen,len);
            }

            // put the current nums[i] into map but if it already exists dont 

            if(!occ.count(nums[i])) occ[nums[i]]=i;
        }

        return maxLen;
    }
};

// BRUTE FORCE: O(N^2) +O(NLOGN)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int maxLen=INT_MIN;
        for(int i=n-1;i>=0;i--){
            int len=0;

            for(int j=i-1;j>=0;j--){
                if((nums[i]-nums[j])==1){
                    len=max(len,i-j+1);
                }
                else if((nums[i]-nums[j])>1) break;
            }
            maxLen=max(len,maxLen);
        }

        return maxLen;
    }
};
