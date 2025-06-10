/OPTIMISE USING BINARY SEARCH
// T.C : O(LOGK*LOG(NUM))

using ll=long long;
class Solution {
private:
vector<ll>bitCount;

void getBitCount(ll num){

    // base cases(the cases u know and can solve without the algorithm)
    if(num==0){
        return;
    }
    if(num==1){
        bitCount[0]++;
        return;
    }
    if(num==2){
        bitCount[0]++;
        bitCount[1]++;
        return;
    }
    
    ll bitNo=log2(num)+1;
    ll nearPow2=1ll<<(bitNo-1);

    bitCount[bitNo-1]+=(num-nearPow2+1);

    for(ll i=0;i<(bitNo-1);i++){
        bitCount[i]+=(nearPow2/2);
    }

    num=num-nearPow2;
    getBitCount(num);
}
public:
    long long findMaximumNumber(long long k, int x) {
        ll left=0,right=1e15;

        ll res=0;
        while(left<=right){
            ll mid=left+(right-left)/2;

            bitCount=vector<ll>(65,0);
            getBitCount(mid);

            ll totalPrice=0;
            for(ll i=0;i<(log2(mid)+1);i++){
                if((i+1)%x==0){
                    totalPrice+=bitCount[i];
                }
            }

            if(totalPrice<=k){
                res=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }

        return res;
    }
};















//BRUTE FORCE : o(K*LOG(NUM))  : TLE

using ll=long long;
class Solution {
private:
ll getPrice(ll num,ll x){
    ll count=0;

    while(num){
        int xthBit=(num & (1LL << (x - 1)));
        if(xthBit>0) count++;
        num=(num>>x);
    }

    return count;
}    
public:
    long long findMaximumNumber(long long k, int x) {
        
        int cur=1;
        int accSum=0;
        while(true){
            int price=getPrice(cur,x);
            if(accSum+price <=k){
                accSum+=price;
            }else{
                break;
            }
            cur++;
        }

        return  cur-1;
    }
};
