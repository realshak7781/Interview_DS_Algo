class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();

        int maxi=INT_MIN;

        int count=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,weight[i]);

            if(weight[i]>=maxi) continue;

            count++;
            maxi=INT_MIN;
        }

        return count;
    }
};
