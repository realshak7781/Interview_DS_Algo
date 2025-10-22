

// Better Intuitive Approach : Using Difference Array technique
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
         int maxVal = *max_element(begin(nums), end(nums)) + k;

        vector<int> diff(maxVal+2, 0);
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i]-k, 0);
            int r = min(nums[i]+k, maxVal);

            diff[l]++;
            diff[r+1]--;
        }


        int result = 1;

        for(int target = 0; target <= maxVal; target++) {
            diff[target] += (target > 0 ? diff[target-1] : 0);

            int targetFreq     = freq[target];
            int needConversion = diff[target] - targetFreq;

            int maxPossibleFreq = min(needConversion, numOperations);

            result = max(result, targetFreq + maxPossibleFreq);
        }

        return result;
    }
};













// Optimal Approach : Using the concept of Cumulative Sum :
// Time : O(maxi)
// space : o(maxi)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());

        vector<int> freq(maxi+1,0);

        for(int val:nums){
            freq[val]++;
        }

        for(int i=1;i<=maxi;i++){
            freq[i]=freq[i]+freq[i-1];
        }

        int maxFreq=0;
        for(int target=0;target<=maxi;target++){

            int l=max(0,target-k);
            int r=min(maxi,target+k);

            int count=freq[r]-(l>0 ? freq[l-1]:0);

            int targetFreq=freq[target]-(target>0 ? freq[target-1]:0);

            int needToConvert=min(count-targetFreq,numOperations);
            int freqInc=targetFreq+needToConvert;

            maxFreq=max(maxFreq,freqInc);
        }

        return maxFreq;
    }
};



// Brute force : O(maxElem*n)
// space : O(n) : worst case all elements can have an entry in the map
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());

        unordered_map<int,int> freq;
        for(int val:nums) freq[val]++;

        int maxFreq=0;
        for(int target=0;target<=maxi;target++){

            int rangeMin=max(0,target-k);
            int rangeMax=target+k;

            int count=0;
            for(int j=0;j<nums.size();j++){

                if(nums[j]>=rangeMin && nums[j]<=rangeMax){
                    count++;
                }
            }

            int needToConvert=min(count-freq[target],numOperations);
            int freqInc=freq[target]+needToConvert;

            maxFreq=max(maxFreq,freqInc);
        }

        return maxFreq;
    }
};
