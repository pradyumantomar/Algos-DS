#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;


int multiply(int a , int b){
    int res = 0;
    while(b){
    if(b&1)res += a; res%=mod;
    a = 2*a; a%=mod;
    b/=2;
    }
    return res;
}


int main(){
    int a,b;
    cin>>a>>b;
    int ans = multiply(a,b);
    cout<<ans;
}