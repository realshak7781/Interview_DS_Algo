


// brute force approach :

using ll=__int128;
class Solution {
private:
ll getFact(int n){
    ll res=1;

    for(int i=n;i>=1;i--){
        res=(ll)res*i;
    }
    return res;
}

int countTrailingZeros(ll n){
    int count=0;

    while(n>0){
        int dig=n%10;

        if(dig>0) return count;

        count++;
        n/=10;
    }

    return count;
}
public:
    int trailingZeroes(int n) {
        ll fact=getFact(n);

        return countTrailingZeros(fact);
    }
};
