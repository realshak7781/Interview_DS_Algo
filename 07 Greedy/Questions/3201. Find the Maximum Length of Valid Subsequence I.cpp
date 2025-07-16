class Solution {
private:
int solveSame(vector<int>&nums,int parity){
    int len=0;

    for(int val:nums){
        if(val%2==parity) len++;
    }
    return len;
}

int solveAlt(vector<int>&nums,int startParity){
    int len=0;
    int expected=startParity;

    for(int num:nums){
        if(num%2==expected){
            len++;
            expected^=1;
        }
    }

    return len;
}
public:
    int maximumLength(vector<int>& nums) {
        // the mod value is 2 : so any( sub[i]+sub[i+1])%2 will result in either zero or 1;
        // and there will be just 4 cases:
        //  0 remainder cases : all number in seq even, e,e,e...
                                // all no in seq odd : o,o,o...
        // 1 rem case : e,o,e,o
                    //    o,e,o,e
        // try out all cases and take the max 

        int allEven=solveSame(nums,0);

        int allOdd=solveSame(nums,1);

        int oddEven=solveAlt(nums,1);

        int evenOdd=solveAlt(nums,0);


        return max({allEven,allOdd,oddEven,evenOdd});
    }
};
