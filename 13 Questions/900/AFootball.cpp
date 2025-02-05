#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
  FAST_IO;
 string inp;
 cin>>inp;

 int count=1;
 for(int i=1;i<inp.size();i++){
    if(inp[i]==inp[i-1]){
      count++;
      if(count==7){
        cout<<"YES\n";
        return 0;
      }   
 }
  else{
        count=1;
      }
 }

 cout<<"NO\n";

  return 0;
}

