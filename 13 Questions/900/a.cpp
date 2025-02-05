#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MOD=998244353;

long long power(long long b,long long e,long long mod){
    long long result=1;
    b=b%mod;
    while(e>0){
        if(e%2==1){
            result=(result*b)%mod;
        }
        b=(b*b)%mod;
        e/=2;
    }

    return result;
}

int solve(int n,int m){

    
    if((n>1 && m==1) || (m>1 && n==1)) return 0; 
    long long c=power(n,m,MOD);
    long long r=power(m,n,MOD);


    return (r%MOD)*(c%MOD)%MOD;
}

int main() {
   int n,m;
   cin>>n>>m;
   cout<<solve(n,m)<<"\n";
    return 0;
}