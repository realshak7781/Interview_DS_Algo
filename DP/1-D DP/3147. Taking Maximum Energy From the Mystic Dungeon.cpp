class Solution {
    int bruteForce(vector<int>& energy, int k) {
        int n = energy.size();

        int maxEnergy = INT_MIN;
        for (int start = 0; start < n; start++) {
            int curEnergy = energy[start];

            int next = start + k;
            while (next < n) {
                curEnergy += energy[next];
                next += k;
            }

            maxEnergy = max(maxEnergy, curEnergy);
        }

        return maxEnergy;
    }

int optimal(vector<int>& energy, int k){
    int n=energy.size();
    vector<int> dp(n,INT_MIN);

    dp[n-1]=energy[n-1];

    for(int start=n-2;start>=0;start--){
        int next=start+k;

        if(next<n){
            dp[start]=energy[start]+dp[next];
        }
        else{
            dp[start]=energy[start];
        }
    }

    // check every i as starting point;

    int res=*max_element(begin(dp),end(dp));

    return res;
}
public:
    int maximumEnergy(vector<int>& energy, int k) {
        return optimal(energy,k);
    }
};
