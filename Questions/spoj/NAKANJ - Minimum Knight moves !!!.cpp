/*
https://www.spoj.com/problems/NAKANJ/
*/

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;

int vis[8][8];  // create vis array of chess Board
int level[8][8]; // create level of chess Board bcoz level helps
//to find the shortest distance for destination

// movements of knights in chess (dhaii chal)
vector<pair<int,int>> movements = {{-2,-1},{-2,1},{2,-1},{2,1},
                                   {-1,-2},{-1,2},{1,-2},{1,2}};

// safe function for checkibg valid co-ordinates
bool isSafe(int x, int y){
  if(x >= 0  and x < 8 and y >=0 and y < 8) return true;
  else return false;
}

// reseting the level and vis array for each testcase
void reset(){
    for(int i = 0 ; i<8 ;i++){
      for (int j = 0; j < 8; j++) {
        vis[i][j] = 0;
        level[i][j] = INF;
      }
    }
  }


// simple bfs
int bfs(string src, string dest){

  // find source x , y and destination x ,y
  int src_X = src[0]-'a';
  int src_Y = src[1]-'1';
  int dest_X = dest[0] -'a';
  int dest_Y = dest[1] -'1';

// queue for  storing pairs with marking vis and level array
queue<pair<int,int>> q;
q.push({src_X,src_Y});
vis[src_X][src_Y] = 1;
level[src_X][src_Y] = 0;

while(!q.empty()){
  auto it = q.front();
  q.pop();
  int x = it.first;
  int y = it.second;

  // all possible movements for knights
  for(int i = 0 ; i < 8 ;i++){
    int new_X = x + movements[i].first;
    int new_Y = y + movements[i].second;

// check if  new coordinate x and y is safe and not visited using array
    if(!isSafe(new_X,new_Y))continue;
    if(!vis[new_X][new_Y]){
      vis[new_X][new_Y] = 1;
      level[new_X][new_Y] = level[x][y] + 1; // increase level of new x and y
      q.push({new_X,new_Y});
    }
  }

  if(level[dest_X][dest_Y] != INF){ // if we find the ans break and return
    break;
  }
}

return level[dest_X][dest_Y];
}



int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif


  int tc = 1;
  cin>>tc;
  while(tc--){
    reset();
    string s1,s2;
    cin>>s1>>s2;
    int ans = bfs(s1,s2);
    cout<<ans;
    cout<<endl;
  }
}
