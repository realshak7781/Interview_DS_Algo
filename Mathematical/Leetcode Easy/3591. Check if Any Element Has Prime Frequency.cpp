class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int val:nums) freq[val]++;
        sieveOfEras();
        for(auto &it:freq){
            if(isPrime[it.second]) return true;
        }

        return false;
    }
    private:
    vector<bool>isPrime;

    void sieveOfEras(){
        isPrime.resize(101,true);
        isPrime[0]=false;
        isPrime[1]=false;


        for(int i=2;i*i<=100;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=100;j+=i){
                    isPrime[j]=false;
                }
            }
        }
    }
};
