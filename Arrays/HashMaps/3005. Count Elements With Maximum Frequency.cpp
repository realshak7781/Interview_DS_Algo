class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101,0);

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        int maxFreq=*max_element(freq.begin(),freq.end());

        int totalFreq=0;
        for(int i=0;i<101;i++){
            if(freq[i]==maxFreq){
                totalFreq+=maxFreq;
            }
        }

        return totalFreq;
    }
};
