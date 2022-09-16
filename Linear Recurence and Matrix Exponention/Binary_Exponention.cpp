#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int pow(int a, int b){
    int res = 1;
    while(b>0){
        if(b&1)res *= a; res%=mod;
        a = a*a; a%=mod;
        b/=2;
    }
    return res;
}

int main(){

    int a,b;
    cin>>a>>b;
    int ans = pow(a,b);
    cout<<ans;
}