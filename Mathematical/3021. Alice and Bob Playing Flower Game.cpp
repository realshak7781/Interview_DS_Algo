using ll=long long;
class Solution {
public:
    long long flowerGame(int n, int m) {

        

        // ll res=0;

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if((i+j)&1){
        //             res++;
        //         }
        //     }
        // } 

        // return res;

        ll evenCount=0;
        ll oddCount=0;

        for(int y=1;y<=m;y++){
            if(y&1){
                oddCount++;
            }
            else{
                evenCount++;
            }
        }


        ll count=0;
        for(int x=1;x<=n;x++){
            if(x&1){
                count+=evenCount;
            }
            else{
                count+=oddCount;
            }
        }

        return count;
    }
};
