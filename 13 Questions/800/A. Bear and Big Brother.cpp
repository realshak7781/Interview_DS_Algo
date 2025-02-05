#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
  FAST_IO;
  int a,b;
  cin>>a>>b;
  int cnt=0;
  while(a<=b){
    a*=3;
    b*=2;
    cnt++;
  }

  cout<<cnt<<endl;

  return 0;
}

