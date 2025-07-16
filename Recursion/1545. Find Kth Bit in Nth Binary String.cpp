// optimal: O(N)time and O(N) space

class Solution {
private:
int findPower(int a,int b){
    if(b==0) return 1;
    int half=findPower(a,b/2);
    int result=half*half;
    if(b&1){
        result=a*result;
    }

    return result;
}
public:
    char findKthBit(int n, int k) {
         if(n == 1) {
            return '0';
        }
        int len=findPower(2,n)-1;

        if(k<ceil(len/2.0)){
            return findKthBit(n-1,k);
        }
        else if(k==ceil(len/2.0)){
            return '1';
        }
        else{
            char c=findKthBit(n-1,len-(k-1));
            return c=='1'?'0':'1';
        }

        return '/0';
    }
};


// brute force : o(2^N)
class Solution {
private:
string recur(int n){
    if(n==1){
        return "0";
    }
    else if(n==2){
        return "011";
    }
    else if(n==3){
        return "0111001";
    }
    else if(n==4){
        return "011100110110001";
    }

    string sub=recur(n-1);

    string res=sub+"1";
    // now invert the sub string;
    for(int i=0;i<sub.length();i++){
        if(sub[i]=='1'){
            sub[i]='0';
        }
        else{
            sub[i]='1';
        }
    }

    reverse(sub.begin(),sub.end());

    res=res+sub;

    return res;
}
public:
    char findKthBit(int n, int k) {
        string res=recur(n);

        return res[k-1];
    }
};
