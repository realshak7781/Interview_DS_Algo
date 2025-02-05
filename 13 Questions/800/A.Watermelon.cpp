#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main(){
    FAST_IO

    int w;
    cin>>w;

    if(w>2 && w%2==0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    
    return 0;
}