#include<bits/stdc++.h>
using namespace std;



int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif	
	
	int n,m;
	cin>>n>>m;
	int adj[n+1][n+1];
	memset(adj , 0 , sizeof(adj)); 
	for (int i = 0; i < m; ++i)
	{
		int u , v;
		cin>>u>>v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	for (int i = 0; i < m; ++i)
	{
		for(int j = 0 ; j < m ; j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}


}