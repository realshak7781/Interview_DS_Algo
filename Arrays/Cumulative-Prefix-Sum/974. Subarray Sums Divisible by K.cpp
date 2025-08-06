// approach 2:
// optimal approach :

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // divisible by k means modulo k==0
        int m = k;

        int n = nums.size();
        int K=0;

        // using the cumulative sum technique
        unordered_map<int,int> cumSum;
        cumSum[0]=1;

        int runSum=0;
        int count=0;
        for(int i=0;i<n;i++){
            runSum+=nums[i];

            int r1=runSum%m;
            int r2=(r1-K+m)%m;

            count+=cumSum[r2];

            if(r1<0) r1+=m;
            // to avoid -1%2 in c++ is -1 not +1
            cumSum[r1]++;
        }
        return count;
    }
};





// approach 1:
// brute force : O(n^2)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // divisible by k means modulo k==0
        int m = k;

        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];

                if (sum % m == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
