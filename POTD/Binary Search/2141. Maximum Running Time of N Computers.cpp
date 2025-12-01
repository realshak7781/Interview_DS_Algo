using ll=long long;
class Solution {
private:
bool isPossible(int compCount,vector<int>& batteries,ll time){
    ll needed=compCount*time;

    ll availEnergy=0;
    for(int i=0;i<batteries.size();i++){
        ll currentEnergy=(long long)batteries[i];
        availEnergy+=(min(currentEnergy,time));
    }

    return availEnergy>=needed;
}
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        ll totalEnergy=accumulate(begin(batteries),end(batteries),0LL);
        ll low=1;
        ll high=(totalEnergy/n);

        ll res=0;
        while(low<=high){
            ll mid=low+(high-low)/2;

            if(isPossible(n,batteries,mid)){
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }


        return res;
    }
};
