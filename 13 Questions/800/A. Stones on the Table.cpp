#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
  FAST_IO;
  int n;
  cin>>n;

  char colour[n+1];

  for(int i=1;i<=n;i++){
    cin>>colour[i];
  }

  int ans=0;
  for(int i=1;i<n;i++){
    if(colour[i]==colour[i+1]) ans++;
  }

cout<<ans<<"\n";

  return 0;
}

