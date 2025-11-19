class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length();
        vector<int> next(n,1e5);
        vector<int> prev(n,1e5);

        int prevIdx=-1;
        for(int i=0;i<n;i++){

            if(s[i]==c){
                prevIdx=i;
            }
            if(prevIdx!=-1)prev[i]=prevIdx;
        }

        int nextIdx=-1;
        for(int i=n-1;i>=0;i--){

            if(s[i]==c){
                nextIdx=i;
            }
            if(nextIdx!=-1)next[i]=nextIdx;
        }

        vector<int> res(n);

        for(int i=0;i<n;i++){
            int leftD=abs(i-prev[i]);
            int rightD=abs(i-next[i]);

            res[i]=min(leftD,rightD);
        }

        return res;
    }
};
