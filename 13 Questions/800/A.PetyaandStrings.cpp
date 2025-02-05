#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void toLowerCase(string &s){
    for(char &c:s){
        c=tolower(c);
    }
}

int main(){
    FAST_IO;
    string s1,s2;
    cin>>s1>>s2;

    toLowerCase(s1);
    toLowerCase(s2);

    if(s1==s2){
        cout<<"0\n";
    }
    else if(s1>s2){
        cout<<"1\n";
    }
    else{
        cout<<"-1\n";
    }
    return 0;
}