

//Approach (Using Primes, BinaryExponentiation, NextGreater, PrevGreater, Sorting)
//T.C : O(mloglogm + nlogm + nlogn + nlogk)
//S.C : O(m+n), where m = maxElement, n = nums.size()


using ll=long long;
const int mod=1e9+7;
class Solution {
private:
vector<int> primeScore;
vector<int> primes;
vector<int> nextGreater;
vector<int> prevGreater;

void sieveOfEras(int n){
    // o(nloglogn)
    vector<bool> isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;

    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }

    for(int k=2;k<=n;k++){
        if(isPrime[k]){
            primes.push_back(k);
        }
    }
}

void buildPrimeScore(vector<int>&nums){
    // o(nlogm)
    int n=nums.size();
    for(int i=0;i<n;i++){
        int num=nums[i];

        for(int prime:primes){
            if(prime*prime>num) break;

            if(num%prime!=0) continue;

            primeScore[i]+=1;
            while(num%prime==0){
                num/=prime;
            }
        }
        if(num>1){
            primeScore[i]+=1;
        }
    }
}

void buildNxtGreat(vector<int>&nums){
    // o(n)
    stack<int> st;
    int n=nums.size();
    for(int i=n-1;i>=0;i--){

        while(!st.empty() &&  primeScore[st.top()]<=primeScore[i]){
            st.pop();
        }

        nextGreater[i]=st.empty()?n:st.top();

        st.push(i);
    }
}

void buildPvGreat(vector<int>&nums){
    //O(n)
    int n=nums.size();
    stack<int> st;

    for(int i=0;i<n;i++){

        while(!st.empty() && primeScore[st.top()]<primeScore[i]){
            st.pop();
        }

        prevGreater[i]=st.empty()?-1:st.top();
        st.push(i);
    }
}

ll findPower(ll a,ll b){
    // O(logb)
    if(b==0) return 1;

    ll half=findPower(a,b/2);
    ll result=(half*half)%mod;

    if(b&1){
        result=(result*a)%mod;
    }

    return result;
}

public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        primeScore=vector<int>(n);
        int limit=*max_element(nums.begin(),nums.end());
        sieveOfEras(limit);
        buildPrimeScore(nums);


        // now builld the next greater and prev greater
        nextGreater.resize(n,n);
        prevGreater.resize(n,-1);

        buildNxtGreat(nums);
        buildPvGreat(nums);

        vector<ll> subarrCount(n);

        for(int i=0;i<n;i++){
            subarrCount[i]=(long long)(nextGreater[i]-i)*(i-prevGreater[i]);
        }

        // now a sorted nums with num and index;
        vector<pair<int,int>> sortedNums(n);

        for(int i=0;i<n;i++){
            sortedNums[i]={nums[i],i};
        }

        sort(sortedNums.begin(),sortedNums.end(),greater<>());
        // sort in desc to get max element first

        ll score=1;
        int idx=0;
        while(k>0){
            auto [num,i]=sortedNums[idx];

            ll ops=min((long long)k,subarrCount[i]);

            score=(score*findPower(num, ops))%mod;
            k=k-ops;
            idx++;
        }

        return score;
    }
};
