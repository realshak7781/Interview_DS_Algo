#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
  FAST_IO;
  int k,n,w;
  cin>>k>>n>>w;

  int total_money_req=k*w*(w+1)/2;

  int ans=total_money_req-n;

  cout<<max(0,ans)<<"\n";

  return 0;
}

