class Solution {
int getPreLen(string &a,string &b){
    int n=a.length(),m=b.length();

    int i=0,j=0;
    int count=0;
    while(i<n && j<m && a[i]==b[j]){
        i++;
        j++;
        count++;
    }
    return count;
}
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        vector<int> res(n,0);
        if(n<=1) return res;

        vector<int> pfLen(n-1,0);
        for(int i=0;i<n-1;i++){
            pfLen[i]=getPreLen(words[i],words[i+1]);
        }

        vector<int> pfMax(n-1);
        pfMax[0]=pfLen[0];
        for(int i=1;i<n-1;i++){
            pfMax[i]=max(pfMax[i-1],pfLen[i]);
        }
        vector<int> suffMax(n-1);
        suffMax[n-2]=pfLen[n-2];

        for(int i=n-3;i>=0;i--){
            suffMax[i]=max(suffMax[i+1],pfLen[i]);
        }


        for(int i=0;i<n;i++){
            int best=0;
            if(i==0){
                if(i+1<n-1)best=max(best,suffMax[i+1]);
            }
            else if(i==n-1){
               if(i-2>=0)best=max(best,pfMax[i-2]);
            }
            else{
                best=max(best,getPreLen(words[i-1],words[i+1]));
               if(i-2>=0)best=max(best,pfMax[i-2]);
                if(i+1<n-1) best=max(best,suffMax[i+1]);
            }

            res[i]=best;
        }

        return res;
    }
};
