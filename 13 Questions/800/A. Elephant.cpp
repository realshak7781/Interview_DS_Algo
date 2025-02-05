#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
  FAST_IO;
  int x;
  cin>>x;

  int rem=x%5;
  int q=x/5;

  if(q==0){
    cout<<1<<"\n";
  }
  else{
    if(rem==0){
        cout<<q<<"\n";
    }
    else{
        cout<<q+1<<"\n";
    }
  }

  

  return 0;
}

