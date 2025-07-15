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
