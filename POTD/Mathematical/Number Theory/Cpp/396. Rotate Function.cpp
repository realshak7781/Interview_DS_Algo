// APPROACH 2 : USING MATHEMATICAL EQUATIONS
// TME : O(N)

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        long long f0=0;
        int sum_of_nums=0;
        for(int idx=0;idx<n;idx++){
            f0+=1LL*(idx*nums[idx]);
            sum_of_nums+=nums[idx];
        }

        long long prev_f=f0;
        long long maxRes=f0;

        for(int k=1;k<n;k++){
            long long fk=prev_f + sum_of_nums -n*nums[n-k];

            maxRes=max(maxRes,fk);
            prev_f=fk;
        }

        return maxRes;
    }
};


//APPROACH 1: USING BRUTE FORCE APPROACH
//TIME : O(N*N)
class Solution {
private:
int getFk(vector<int>&nums,int k,int n){
    int sum=0;

    for(int idx=0;idx<n;idx++){
        int actual_idx=(idx+k)%n;
        sum=sum + actual_idx*nums[idx];
    }
    return sum;
}
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();

        int res=getFk(nums,0,n);

        for(int i=1;i<n;i++){
            res=max(res,getFk(nums,i,n));
        }
        return res;
    }
};
