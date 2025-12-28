// approach 2 :Using Binary search : 
// time : O(r*logc)
class Solution {
private:
int bs(int low,int high,vector<int>&arr){

    int res=-1;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]<0){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return res;
}
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int res=0;
        for(int r=0;r<m;r++){
            int idx=bs(0,n-1,grid[r]);

            if(idx!=-1){
                res+=(n-idx);
            }
        }

        return res;
    }
};

// approach 1 : Using simple brute force
// time : O(r*c)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int res=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]<0) res++;
            }
        }

        return res;
    }
};
