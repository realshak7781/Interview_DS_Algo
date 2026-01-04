// Approach 2 : Using square root mathematics : O(n*sqrt(val))
class Solution {
private:
    int getSum(int val) {
        int sum = 0;
        int count = 0;

        for (int i = 1; i * i <= val; i++) {
            if (val % i == 0) {
                int div1 = i;
                int div2 = val / i;

                if (div1 == div2) {
                    sum += div1;
                    count += 1;
                } else {
                    sum += div1 + div2;
                    count += 2;
                }
            }

            if (count > 4)
                return 0;
        }

        return count == 4 ? sum : 0;
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int val : nums) {
            totalSum += getSum(val);
        }

        return totalSum;
    }
};


// approach 1 : O(N*max(nums))
class Solution {
private:
int getSum(int val){
    int sum=0;
    int count=0;

    for(int i=1;i<=val;i++){
        if(val%i==0){
            sum+=i;
            count++;
        }
        if(count>4) return 0;
    }

    return count==4 ? sum : 0;
}
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum=0;

        for(int val:nums){
            totalSum+=getSum(val);
        }

        return totalSum;
    }
};
