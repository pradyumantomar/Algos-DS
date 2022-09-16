#include<bits/stdc++.h>
using namespace std;

vector<bool> vis(100000,0);
vector<vector<int>> conn_cc;
vector<int> cc;

void bfs(int v , vector<int> adj[]){
	queue<int> qt;
	qt.push(v);
	vis[v] = true;

	while(!qt.empty()){
		int node = qt.front();
		qt.pop();
		cc.push_back(node);

		for(auto it : adj[node]){
			if(!vis[it]){
				qt.push(it);
				vis[it] = true;
			}
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
	vector<int> adj[n+1];

	for(int i = 0 ; i < m ; i++){
		int u , v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int cnt = 0;
	for(int i=1; i<= n; i++){
		if(!vis[i]){
			bfs(i,adj);
			cnt++;
			conn_cc.push_back(cc);
		}
		cc.clear();
	}
	cout<<cnt;

	cout<<endl;
	cout<<conn_cc.size()<<endl;
	for(auto i : conn_cc){
		for(auto y : i)
			cout<<y<<" ";
		cout<<endl;
	}


	
}