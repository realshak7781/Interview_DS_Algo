#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
    FAST_IO;
    int n,k;
    cin>>n>>k;

    int count=0;
    int score[n+1];
    for(int i=1;i<=n;i++){
        cin>>score[i];
    }

    int kthScore=score[k];
    for(int i=1;i<=n;i++){
        if(score[i]>0 && score[i]>=kthScore)count++;
    }
    cout<<count<<"\n";
   
    return 0;
}