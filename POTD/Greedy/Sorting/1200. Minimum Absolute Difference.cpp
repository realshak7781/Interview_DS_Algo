// USING A HASHSET INSTEAD OF MAP

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
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            // b-a=diff
            int b=arr[i];
            int a=b-minAbsDiff;

            if(st.find(a)!=st.end()){
                res.push_back({a,b});
            }

            st.insert(b);
        }
        return res;
    }
};


// USING HASHMAP TO REDUCE THE BRUTE FORCE
// TIME : O(NLOGN)
// SPACE : O(N)
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
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            // b-a=diff
            int b=arr[i];
            int a=b-minAbsDiff;

            if(mp.count(a)){
                res.push_back({a,b});
            }

            mp[b]=i;
        }
        return res;
    }
};



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
