class Solution {
private:
void sieve(vector<int>&isPrime,int maxi){
    isPrime[0]=isPrime[1]=false;

    for(int i=2;i*i<=maxi;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=maxi;j+=i){
                isPrime[j]=false;
            }
        }
    }
}

vector<int> getPrimeFactors(int x,vector<int>&isPrime){
    vector<int> prime;

    for(int i=2;i*i<=x;i++){

        if(isPrime[i] && x%i==0){
            prime.push_back(i);

            while(x%i==0){
                x/=i;
            }
        }
    }


    if(x>1) prime.push_back(x);

    return prime;
}
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();

        int maxi=*max_element(begin(nums),end(nums));
        vector<int> isPrime(maxi+1,true);
        sieve(isPrime,maxi);


        unordered_map<int,vector<int>> teleMp;
        for(int i=0;i<n;i++){
            int x=nums[i];
            vector<int> primes=getPrimeFactors(x,isPrime);


            for(int p:primes){
                teleMp[p].push_back(i);
            }
        }


        queue<pair<int,int>> q;
        q.push({0,0});
        unordered_set<int> vis;
        vis.insert(0);


        while(!q.empty()){
            int idx=q.front().first;
            int steps=q.front().second;

            q.pop();

            if(idx==n-1) return steps;

            if(idx-1>=0 && !vis.count(idx-1)){
                q.push({idx-1,steps+1});
                vis.insert(idx-1);
            }

            if(idx+1<n && !vis.count(idx+1)){
                q.push({idx+1,steps+1});
                vis.insert(idx+1);
            }

            if(!isPrime[nums[idx]])continue;

            if(teleMp.count(nums[idx])){
                for(int pos:teleMp[nums[idx]]){
                    if(!vis.count(pos)){
                        q.push({pos,steps+1});
                        vis.insert(pos);
                    }
                }

                teleMp.erase(nums[idx]);
            }    
        }

        return -1;
    }
};
