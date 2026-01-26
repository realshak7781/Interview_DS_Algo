
// BRUTE FORCE APPROACH : TIME : O(N*N)+O(NLOGN)
// SPACE : O(1)
class Solution {
private:
int getMinAbsDiff(vector<int>& arr,int n){
    int minDiff=INT_MAX;

    for(int i=0;i<n-1;i++){
        int low=i;
        int high=i+1;

        minDiff=min(minDiff,arr[high]-arr[low]);
    }
    return minDiff;
}
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        int minAbsDiff=getMinAbsDiff(arr,n);

        vector<vector<int>> res;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curDiff=arr[j]-arr[i];

                if(curDiff==minAbsDiff){
                    res.push_back({arr[i],arr[j]});
                }
            }
        }

        return res;
    }
};
