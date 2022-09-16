//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> sum_pair(vector<int> arr,int sum){
unordered_set<int> s;  // set 
vector<int> result;
for(int i=0;i<arr.size();i++)
{
int x= sum-arr[i];
if(s.find(x)!=s.end())//search
{
	result.push_back(x);
	result.push_back(arr[i]);
	return result;
}
s.insert(arr[i]);//insertion after search
}
return {};

}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

vector<int> arr ={10,5,2,3,-6,9,11};
int Sum=4;
auto p = sum_pair(arr,Sum);

if(p.size()==0)//if empty
	cout<<"Empty"<<"\n";
else
	cout<<p[0]<<" , "<<p[1];
return 0; 
}