

// Brute Force : O(n^2) : TLE
class Solution {
private:
const int mod=1e9+7;
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();

        int count=0;
        for(int i=0;i<n;i++){
            int first=nums[i];

            unordered_map<int,int> freq;
            for(int j=i+1;j<n;j++){
                int last=nums[j];

                int mid=first/2;
                if(first==last && mid*2==first){
                    if(freq.count(mid)){
                        count=(count+freq[mid])%mod;
                    }
                }
                freq[last]++;
            }
        }

        return count;
    }
};
