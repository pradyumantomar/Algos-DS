#include<bits/stdc++.h>
using namespace std;

void solve(){
	int cnt = 1;
	int n;
	cin>>n;
		cnt *= __builtin_popcount(n)*2;

	cout<<cnt;
	
}                 

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif	

	int tc = 1;
//	cin >> tc;
	while(tc--){
		solve();
		cout<<endl;
	}
}