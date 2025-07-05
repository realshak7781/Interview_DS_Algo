class Solution {
public:
    int findLucky(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());

        int j=0;

        int maxiVal=-1;
        while(i<n){
            int val=arr[i];
            int count=0;
            while(j<n && arr[j]==arr[i]){
                j++;
                count++;
            }
            i=j;
            if(count==val){
                maxiVal=max(maxiVal,val);
            }
        }


        return maxiVal;
    }
};
