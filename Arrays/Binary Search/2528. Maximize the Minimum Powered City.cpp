using ll=long long;
class Solution {
private:
bool check(ll mid,vector<int>&stations,vector<ll>&diff,ll k,int r){
    // we need to make sure here the minStation whose power is mid;
    vector<ll> temp_diff=diff;

    int totalStations=diff.size();

    ll cumSum=0;
    for(int i=0;i<totalStations;i++){
        cumSum+=temp_diff[i];

        if(cumSum<mid){
            ll need=mid-cumSum;
            if(need>k) return false;

            k -= need;
            cumSum += need;
            if((i+2*r+1)<totalStations){
                temp_diff[i+2*r+1]-=need;
            }
        }
    }

    return true;
}
public:
    long long maxPower(vector<int>& stations, int r, int k) {

        int totalStations=stations.size();

        vector<ll> diff(totalStations,0);
        for(int i=0;i<totalStations;i++){
            diff[max(0,i-r)]+=stations[i];
            if(i+r+1<totalStations){
                diff[i+r+1]-=stations[i];
            }
        }

        ll low=*min_element(begin(stations),end(stations));
        ll high=accumulate(begin(stations),end(stations),0LL)+k;
        ll result=0;
        while(low<=high){
            ll mid=low+(high-low)/2;

            if(check(mid,stations,diff,k,r)){
                result=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return result;
    }
};
