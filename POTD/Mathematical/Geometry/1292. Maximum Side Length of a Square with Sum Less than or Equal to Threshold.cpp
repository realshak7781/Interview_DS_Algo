
// USING OPTIMAL BINARY SEARCH + PREFIX SUMS + SLIDING WINDOW
// TIME : O(M*N*LOG(LEN))
// SPACE : O(M*N)
class Solution {
private:
vector<vector<int>> pref;

int getSum(int r1,int c1,int r2,int c2){
    return (pref[r2+1][c2+1] - pref[r2+1][c1]-pref[r1][c2+1] + pref[r1][c1]);
}

bool check(int r1,int r2,int c1,int c2,vector<vector<int>>& mat, int threshold){
    int sqSubMatSum=getSum(r1,c1,r2,c2);
    return sqSubMatSum<=threshold;
}

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();

        pref.resize(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pref[i][j]=mat[i-1][j-1]+pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }

        int maxSideLen=min(m,n);

        int low=1;
        int high=maxSideLen;
        int res=0;

        while(low<=high){
            int mid=low + (high-low)/2;
            int len=mid;

            bool possible=false;
            for(int i=0;i<=(m-len);i++){
                // sliding window on rows
                for(int j=0;j<=(n-len);j++){
                    // sliding windows on cols
                    int rS=i;
                    int rE=i+len-1;
                    int cS=j;
                    int cE=j+len-1;

                    if(check(rS,rE,cS,cE,mat,threshold)){
                        possible=true;
                        break;
                    }
                }

                if(possible) break;
            }

            if(possible){
                res=len;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
};


// Using Brute Force + Prefix sum +SLIDING WINDOW
// TIME : o(LEN*M*N)
// SPACE : O(M*N)
class Solution {
private:
vector<vector<int>> pref;

int getSum(int r1,int c1,int r2,int c2){
    return (pref[r2+1][c2+1] - pref[r2+1][c1]-pref[r1][c2+1] + pref[r1][c1]);
}

bool check(int r1,int r2,int c1,int c2,vector<vector<int>>& mat, int threshold){
    int sqSubMatSum=getSum(r1,c1,r2,c2);


    return sqSubMatSum<=threshold;
}
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();

        pref.resize(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pref[i][j]=mat[i-1][j-1]+pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }

        int maxSideLen=min(m,n);
        
        for(int len=maxSideLen;len>=1;len--){
           for(int i=0;i<=(m-len);i++){
                // sliding window on rows
                for(int j=0;j<=(n-len);j++){
                    // sliding windows on cols
                    int rS=i;
                    int rE=i+len-1;
                    int cS=j;
                    int cE=j+len-1;

                    if(check(rS,rE,cS,cE,mat,threshold)) return len;
                }
            }
        }

        return 0;
    }
};
