#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FAST_IO;
    int n;
    cin>>n;

    int x=0;
    while(n--){
      string statement;
      cin>>statement;

      if(statement.find("++")!=string::npos){
        ++x;
      }
      else{
        --x;
      }
    }

    cout<<x<<"\n";
    return 0;
}