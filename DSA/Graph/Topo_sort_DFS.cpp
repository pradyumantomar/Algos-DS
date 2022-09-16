#include<bits/stdc++.h>
using namespace std;

void topoSort(int node , vector<int> adj[], int vis[], stack<int> &st){

    vis[node] = 1;

    for(auto it : adj[node]){
      if(!vis[it]){
        topoSort(it,adj,vis,st);
      }
    }

// isert in stack at dfs end
    st.push(node);
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
      int vis[n+1] ;
      memset(vis ,  0 , sizeof(vis));

      vector<int> adj[n+1];
      while(m--){
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
      }

/// stack is the main thing here
      // concept is simple .. dfs ends insert that node in stack
      stack<int> st;
      for (size_t i = 0; i < n; i++) {
        if(!vis[i]){
          topoSort(i, adj,vis,st);
          }
        }

        vector<int> ans;

        while(!st.empty()){
          ans.push_back(st.top());
          st.pop();
        }

        for(auto it : ans)cout<<it<<" ";
        cout<<endl;
    }

}
