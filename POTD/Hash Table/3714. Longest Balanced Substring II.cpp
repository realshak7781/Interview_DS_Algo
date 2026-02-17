class Solution {
private:
int getMaxLenBalanceofTwoSize(char first,char second,string &s){
    int n=s.length();
    int countFirst=0,countSecond=0;

    unordered_map<int,int> mp;
    mp[0]=-1;
    int maxLen=0;
    for(int i=0;i<n;i++){
        char cur=s[i];

        if(cur!=first && cur!=second){
            mp.clear();
            mp[0]=i;
            countFirst=0;
            countSecond=0;
            continue;
        }

        if(cur==first){
            countFirst++;
        }
        else if(cur==second){
            countSecond++;
        }

        int diff=countFirst-countSecond;

        if(mp.count(diff)){
            maxLen=max(maxLen,i-mp[diff]);
        }
        else{
            mp[diff]=i;
        }
    }

    return maxLen;
}

int getMaxLenBalanceofThreeSize(string &s){
    int n=s.length();
    int cntA=0,cntB=0,cntC=0;

    unordered_map<string,int> mp;
    int maxLen=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            cntA++;
        }
        else if(s[i]=='b'){
            cntB++;
        }
        else{
            cntC++;
        }

        if(cntA==cntB && cntA==cntC){
            maxLen=max(maxLen,cntA+cntB+cntC);
        }

        string diffAB=to_string(cntA-cntB);
        string diffAC=to_string(cntA-cntC);

        string key=diffAB+"_"+diffAC;

        if(mp.count(key)){
            maxLen=max(maxLen,i-mp[key]);
        }
        else{
            mp[key]=i;
        }
    }
    return maxLen;
}

int getMaxLenBalanceofOneSize(string &s){
    int n=s.length();

    int maxLen=1;
    int i=0;

    while(i<n){
        int count=1;
        char cur=s[i];

        int j=i+1;
        while(j<n && s[j]==cur){
            count++;
            j++;
        }

        maxLen=max(maxLen,count);
        i=j;
    }

    return maxLen;
}
public:
    int longestBalanced(string s) {
        int maxLen=getMaxLenBalanceofOneSize(s);

        maxLen=max(maxLen,getMaxLenBalanceofTwoSize('a','b',s));
        maxLen=max(maxLen,getMaxLenBalanceofTwoSize('b','c',s));
        maxLen=max(maxLen,getMaxLenBalanceofTwoSize('a','c',s));

        maxLen=max(maxLen,getMaxLenBalanceofThreeSize(s));

        return maxLen;
    }
};
