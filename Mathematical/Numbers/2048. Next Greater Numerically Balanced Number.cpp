

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
