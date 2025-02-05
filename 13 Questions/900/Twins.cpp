#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
  FAST_IO;
  int n;
  cin>>n;

  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  sort(a.begin(),a.end(),greater<int>());
  int totSum=accumulate(a.begin(),a.end(),0);

  int sum1=0;
  
  for(int i=0;i<n;i++){
    sum1+=a[i];
    if(sum1>totSum-sum1){
      cout<<i+1<<'\n';
      break;
    }
  }
  return 0;
}

