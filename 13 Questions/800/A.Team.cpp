#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FAST_IO;
    int n;
    cin>>n;

    int count=0;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        bitset<3> bits;
        bits[0]=a,bits[1]=b,bits[2]=c;
        if(bits.count()>=2) count++;
    }

    cout<<count<<"\n";
    return 0;
}