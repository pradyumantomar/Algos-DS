#include<bits/stdc++.h>
using namespace std;


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif	

	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];

	for(int i = 0 ; i < m ; i++){
		int u , v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}

	for(int j = 1 ; j <= n ; j++){
		cout<<j<<"->";
		cout<<"{";
	for(auto i : adj[j]){
		cout<<i<<",";
	}
	cout<<"}"<<endl;
	}
}