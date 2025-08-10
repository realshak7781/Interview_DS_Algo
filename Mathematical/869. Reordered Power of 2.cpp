// Generating a Unique Hash:
class Solution {
private:
vector<int> primeKeys={2,3,5,7,11,13,17,19,23,29};
int generateHash(int n){
    long long hashVal=1;

    while(n>0){
        int dig=n%10;

        hashVal*=(long long)primeKeys[dig];

        n=n/10;
    }

    return hashVal;
}
public:
    bool reorderedPowerOf2(int n) {
        int target=generateHash(n);


        for(int i=0;i<=30;i++){
            int pow2Hash=generateHash(1<<i);

            if(pow2Hash==target) return true;
        }

        return false;
    }
};




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
