// using No extra space and TIME : O(2*log10(num))
class Solution {
private:
int getNum(int num){
    int n=num;
    int sixCount=0;

    while(n>0){
        int dig=n%10;
        if(dig==6){
            sixCount++;
        }
        n/=10;
    }


    n=num;
    int newNum=0;
    int powT=1;
    int cnt=0;
    while(n>0){
        int dig=n%10;
        if(dig==6){
            cnt++;
            if(cnt==sixCount){
                dig=9;
            }
        }
        newNum+=(powT*dig);
        powT*=10;
        n/=10;
    }

    return newNum;
}
public:
    int maximum69Number (int num) {
        return getNum(num);
    }
};



// Using String Conversion
class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);


        for(int i=0;i<s.length();i++){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }

        num=stoi(s);

        return num;
    }
};
