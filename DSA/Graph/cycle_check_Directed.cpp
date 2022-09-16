#include<bits/stdc++.h>
using namespace std;

bool check_dfs(int node , vector<int> adj[], int vis[], int dfsVis[]){

    // mark the vis and dfsvis array
    vis[node] = 1;
    dfsVis[node] = 1;

    // do regular dfs
    for(auto it : adj[node]){
      if(!vis[it]){
        return check_dfs(it,adj,vis,dfsVis);
      }
      // if we encounter already traversed dfs[it] return true , means
      // we are still in stack and find an node which is still in stack
      else if(dfsVis[it])return true;
    }

    // unmark recursive dfsvis array for further check 
    dfsVis[node] = 0;
    return false;


}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif

    int tc;
    cin>>tc;
    while(tc--){
      int n,m;
      cin>>n>>m;
      // two array 1st for visited and second for dfs visited
      int vis[n+1] , dfsVis[n+1];
      memset(vis ,  0 , sizeof(vis));
      memset(dfsVis, 0 , sizeof(dfsVis));

      vector<int> adj[n+1];
      while(m--){
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
      }

      bool flag = false;
      for (size_t i = 1; i <= n; i++) {
        if(!vis[i]){
          if(check_dfs(i,adj,vis,dfsVis)){
          	flag = true;
          	break;

        }
    }
      }

      if(flag)cout<<"True";
      else cout<<"False";
      cout<<endl;

    }

}
