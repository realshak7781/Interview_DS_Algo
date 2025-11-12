class Solution {
private:
int getGcd(int a,int b){
    if(b==0) return a;

    return getGcd(b,a%b);
}
int getOneCount(vector<int>& nums){
    int cnt=0;
    for(int val:nums){
        if(val==1) cnt++;
    }
    return cnt;
}
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        int ones=getOneCount(nums);

        if(ones>0){
            return n-ones;
        }

        // taking each nums[i] && nums[i+1] gcd as candidate;
        int minSteps=INT_MAX;
        for(int i=0;i<(n-1);i++){

            int gcd=getGcd(max(nums[i],nums[i+1]),min(nums[i],nums[i+1]));
            if(gcd==1) return n;
            int steps=1;
     
            for(int j=i+2;j<n;j++){
                gcd=getGcd(max(gcd,nums[j]),min(gcd,nums[j]));
                steps++;
                 if(gcd==1){
                    minSteps=min(steps,minSteps);
                    break;
                }
            }
        }

        if(minSteps!=INT_MAX){
            return (n-1+minSteps);
        } 
        return -1;
    }
};
