// time : O(1)
// space : O(1)
class Solution {
private:
string genString(int n){
    string res="";

    while(n>0){
        int dig=n%10;
        res+= to_string(dig);
        n/=10;
    }

    sort(res.begin(),res.end());

    return res;
}
public:
    bool reorderedPowerOf2(int n) {
        string target=genString(n);

        for(int i=0;i<=30;i++){
            string powerOfTwoString=genString(1<<i);

            if(powerOfTwoString==target) return true;
        }


        return false;
    }
};
