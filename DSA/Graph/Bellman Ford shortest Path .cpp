
// tc - o
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n+1, 1e9+10);
	    int src = 0;
	    dist[src] = 0;

	    // u -> v with wt
	    vector<pair<int, pair<int,int>>> adj;

	    for(int i = 0 ;i<edges.size(); i++){
	            adj.push_back({edges[i][0] ,{edges[i][1],edges[i][2]}});
	    }

      // running n-1 times
	    for(int i  = 0 ; i<n-1; i++){
	        for(auto it : adj){
	            if(dist[it.first] + it.second.second < dist[it.second.first]){
	                dist[it.second.first] = dist[it.first] + it.second.second ;
	            }
	        }
	    }

      // running nth time for negative cycle
	    int flag = 0;
	    for(auto it : adj){
	            if(dist[it.first] + it.second.second < dist[it.second.first]){
	                flag = 1;
	                break;
	            }
	        }

	        return flag;
	    }

};
