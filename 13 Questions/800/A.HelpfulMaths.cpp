#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
    FAST_IO;
   string s;
   cin>>s;

   string test="";
   for(char&c:s){
    if(c!='+')test+=c;
   }

   sort(test.begin(),test.end());

   string result="";
   for(size_t i=0;i<test.length();i++){
    result+=test[i];
    if(i!=test.length()-1) result+='+';
   }

   cout<<result<<'\n';
    return 0;
}