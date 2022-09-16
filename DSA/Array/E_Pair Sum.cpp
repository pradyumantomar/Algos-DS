//https://www.codingninjas.com/codestudio/problems/pair-sum_697295

#include <bits/stdc++.h>
#define pb push_back
#define sort(a) sort(a.begin(),a.end())

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ans;

    int n = arr.size();

   for(int i = 0;i<n;i++){
    for(int j =i+1;j<n;j++){
        if(arr[i]+arr[j]==s){
            vector<int> temp;
            temp.pb(arr[i]);
            temp.pb(arr[j]);
            sort(temp);
            ans.pb(temp);
        }
    }
   }
   return ans;
}