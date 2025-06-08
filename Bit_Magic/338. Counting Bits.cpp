class Solution {
private:
// T.C : o(NLOGN)
// OPTIMISE IT FURTHER TO O(N)
int countSetBits(int n){
    int count=0;

    while(n>0){
        if(n&1) count++;
        n>>=1;
    }

    return count;
}    
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);

        // O(N) SOLUTION BELOW:
        res[0]=0;

        for(int i=1;i<=n;i++){
            if(i&1){
                // odd
                res[i]=res[i/2]+1;
            }
            else{
                res[i]=res[i/2];
            }
        }

        return res;
    }
};
