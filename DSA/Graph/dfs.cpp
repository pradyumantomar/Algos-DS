#include<bits/stdc++.h>
using namespace std;

#define endl cout<<'\n'
#define pb push_back

vector<bool> vis(10000 , false);
vector<int> adj[10000];
vector<vector<int>> conn_cc;
vector<int> cc;

void dfs(int v){
	vis[v] = true;
	cc.pb(v);

	for(auto it : adj[v]){
		if(!vis[it]){
			dfs(it);
		}
	}
}



int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif	

	int n,m;
	cin>>n>>m;

	for(int i = 0; i <=m; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1 ; i<=n; i++){
		if(!vis[i]){
			dfs(i);
			conn_cc.pb(cc);
			cc.clear();
		}
	}

	cout<<conn_cc.size();
	endl;

	for(auto i : conn_cc){
		for(auto y : i){
			cout<<y<<" ";
		}
		endl;
	}

}