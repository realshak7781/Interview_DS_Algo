

//  A little optimised by finding the upper limit of numerically balanced Integer :
class Solution {
private:
bool isBalanced(int num){
    vector<int> freq(10,0);

    while(num>0){
        int dig=num%10;
        freq[dig]++;
        num/=10;
    }

    for(int i=0;i<10;i++){
        if(freq[i]!=0 && freq[i]!=i) return false;
    }

    return true;
}
public:
    int nextBeautifulNumber(int n) {

        if(n==0) return 1;
        if(n<21) return 22;
        
        int maxPossible=1224444;
        int num=n+1;
        while(num<=maxPossible){

            if(isBalanced(num)){
                return num;
            }
            else{
                num++;
            }
        }

        return maxPossible;
    }
};

// Time : O(maxLimit*log(num))
// Brute force approach :
class Solution {
private:
bool isBalanced(int num){
    vector<int> freq(10,0);

    while(num>0){
        int dig=num%10;
        freq[dig]++;
        num/=10;
    }

    for(int i=0;i<10;i++){
        if(freq[i]!=0 && freq[i]!=i) return false;
    }

    return true;
}
public:
    int nextBeautifulNumber(int n) {
        int num=n+1;
        while(true){

            if(isBalanced(num)){
                return num;
            }
            else{
                num++;
            }
        }

        return -1;
    }
};
