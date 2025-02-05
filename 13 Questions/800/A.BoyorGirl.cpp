#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
    FAST_IO;
  string inp;
  cin>>inp;

  sort(inp.begin(),inp.end());
  char prev='/';
  int cnt=0;
  for(char&c:inp){
    if(c!=prev){
        cnt++;
        prev=c;
    }
  }

  if(cnt%2==0){
    cout<<"CHAT WITH HER!\n";
  }
  else{
    cout<<"IGNORE HIM!\n";
  }

  return 0;
}

