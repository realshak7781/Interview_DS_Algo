//Approach - Recursion
//T.C : O(log^2(k))
//S.C : O(log(k))) of system stack
using ll=long long;
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1){
            return 'a';
        }
        int n=operations.size();
        ll len=1;

        ll opType;
        ll newK;
        for(int i=0;i<n;i++){
            len*=2;
            if(len>=k){
                opType=operations[i];
                newK=k-len/2;
                break;
            }
        }

        char ch=kthCharacter(newK,operations);
        if(opType==1){
            if(ch=='z'){
                ch='a';
            }
            else{
                ch=ch+1;
            }
        }

        return ch;
    }
};
