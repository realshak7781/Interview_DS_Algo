class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int prev_rem=0;

        int count=0;
        while(count<=k){
            count++;
            int cur_rem=(10*prev_rem+1)%k;
            if(cur_rem==0) return count;
            prev_rem=cur_rem;
        }

        return -1;
    }
};
