#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main(){
    FAST_IO

    int n;
    cin>>n;

    while(n--){
        string word;
        cin>> word;

        if(word.length()>10){
            int n=word.length()-2;
            cout<<word[0]<<n<<word[word.length()-1]<<"\n";
        }
        else{
            cout<<word<<"\n";
        }
    }

    return 0;
}