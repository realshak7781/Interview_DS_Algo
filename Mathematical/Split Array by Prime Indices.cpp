using ll=long long;
class Solution {
private:
vector<bool> isPrime;
void sieve(int n){
    isPrime[0]=isPrime[1]=false;

    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
}
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        isPrime.resize(n+1,true);

        sieve(n);

        ll sumA=0;
        ll sumB=0;

        for(int i=0;i<n;i++){
            if(isPrime[i]){
                sumA+=nums[i];
            }
            else{
                sumB+=nums[i];
            }
        }

        ll res=abs(sumA-sumB);

        return res;
    }
};
